#ifndef BIN_TREE_H_
#define BIN_TREE_H_

/* All compares using person->sername!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STR_SIZE 32

typedef struct social_network_t {
    char name[STR_SIZE];
    char link[STR_SIZE];
} social_network_t;

typedef struct work_t {
    char company[STR_SIZE];
    char post[STR_SIZE];
} work_t;

typedef struct person_t {
    int id;
    char name[STR_SIZE];
    char surname[STR_SIZE];
    char patronimic[STR_SIZE];
    char phone[STR_SIZE];
    work_t work;
    social_network_t socialNetwork;
    
    struct person_t* next;
    struct person_t* prev;
} person_t;

// An AVL tree node
struct Node
{
    person_t* person;
    struct Node *left;
    struct Node *right;
    int height;
};

void init_person(person_t* prs);
void init_work(work_t* work);
void init_social_network(social_network_t* sn);

void set_name(person_t* prs, const char* _name);
void set_surname(person_t* prs, const char* _surname);
void set_patronimic(person_t* prs, const char* _patronimic);
void set_phone(person_t* prs, const char* _phone);
void set_work(person_t* prs, work_t* _work);
void set_social_network(person_t* prs, social_network_t* _sn);
void set_work_company(work_t* work, const char* _company);
void set_work_post(work_t* work, const char* _post);
void set_soc_net_name(social_network_t* sn, const char* _name) ;
void set_soc_net_link(social_network_t* sn, const char* _link) ;

// A utility function to get the height of the tree
int height(struct Node *N);

// A utility function to get maximum of two persons
person_t* max_p(person_t* a, person_t* b);

int max(int a, int b);

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(person_t* person);

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y);

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x);

// Get Balance factor of node N
int getBalance(struct Node *N);

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node* insert(struct Node* node, person_t* person);

/* Given a non-empty binary search tree, return the
   node with minimum key value found in that tree.
   Note that the entire tree does not need to be
   searched. */
struct Node * minValueNode(struct Node* node);

// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* root, person_t* person);

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root);

#endif // BIN_TREE_H_
