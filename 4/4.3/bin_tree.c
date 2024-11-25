#include "bin_tree.h"

void init_person(person_t* prs) {
    char def_str[STR_SIZE] = "_default";

    prs->id = 0;
    strncpy(prs->name, def_str, STR_SIZE);
    strncpy(prs->surname, def_str, STR_SIZE);
    strncpy(prs->patronimic, def_str, STR_SIZE);
    strncpy(prs->phone, def_str, STR_SIZE);
    init_work(&prs->work);
    init_social_network(&prs->socialNetwork);
}

void init_work(work_t* work) {
    char def_str[STR_SIZE] = "_default";

    strncpy(work->company, def_str, STR_SIZE);
    strncpy(work->post, def_str, STR_SIZE);
}

void init_social_network(social_network_t* sn) {
    char def_str[STR_SIZE] = "_default";

    strncpy(sn->name, def_str, STR_SIZE);
    strncpy(sn->link, def_str, STR_SIZE);
}

void set_name(person_t* prs, const char* _name) {
    strncpy(prs->name, _name, STR_SIZE - 1); // Оставляем место для завершающего нуля
    prs->name[STR_SIZE - 1] = '\0';          // Убеждаемся, что строка завершается нулевым символом
}

void set_surname(person_t* prs, const char* _surname) {
    strncpy(prs->surname, _surname, STR_SIZE - 1);
    prs->surname[STR_SIZE - 1] = '\0';
}

void set_patronimic(person_t* prs, const char* _patronimic) {
    strncpy(prs->patronimic, _patronimic, STR_SIZE - 1);
    prs->patronimic[STR_SIZE - 1] = '\0';
}

void set_phone(person_t* prs, const char* _phone) {
    strncpy(prs->phone, _phone, STR_SIZE - 1);
    prs->phone[STR_SIZE - 1] = '\0';
}

void set_work(person_t* prs, work_t* _work) {
    set_work_company(&prs->work, _work->company);
    set_work_post(&prs->work, _work->post);
}

void set_social_network(person_t* prs, social_network_t* _sn) {
    set_soc_net_name(&prs->socialNetwork, _sn->name);
    set_soc_net_link(&prs->socialNetwork, _sn->link);
}

void set_work_company(work_t* work, const char* _company) {
    strncpy(work->company, _company, STR_SIZE - 1);
    work->company[STR_SIZE - 1] = '\0';
}

void set_work_post(work_t* work, const char* _post) {
	strncpy(work->post, _post, STR_SIZE);
}

void set_soc_net_name(social_network_t* sn, const char* _name)  {
	strncpy(sn->name, _name, STR_SIZE);
}

void set_soc_net_link(social_network_t* sn, const char* _link)  {
	strncpy(sn->link, _link, STR_SIZE);
}

// A utility function to get the height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
person_t* max_p(person_t* a, person_t* b)
{
    return (strcmp(a->surname, b->surname) == 1) ? a : b;
}

int max(int a, int b) 
{
	return (a > b) ? a : b;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(person_t* person)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->person = person;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node* insert(struct Node* node, person_t* person)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(person));

    if (strcmp(person->surname, node->person->surname) < 0)
        node->left  = insert(node->left, person);
    else if (strcmp(person->surname, node->person->surname) > 0)
        node->right = insert(node->right, person);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                        height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && strcmp(person->surname, node->left->person->surname) > 0)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && strcmp(person->surname, node->left->person->surname) < 0)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && strcmp(person->surname, node->left->person->surname) < 0)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && strcmp(person->surname, node->left->person->surname) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the
   node with minimum key value found in that tree.
   Note that the entire tree does not need to be
   searched. */
struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* root, person_t* person)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( strcmp(person->surname, root->person->surname) < 0  )
        root->left = deleteNode(root->left, person);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( strcmp(person->surname, root->person->surname) > 0 )
        root->right = deleteNode(root->right, person);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            strncpy(root->person->surname, temp->person->surname, strlen(temp->person->surname));

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->person);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%s ", root->person->surname);
        preOrder(root->left);
        preOrder(root->right);
    }
}
