#include "bin_tree.h"

//* Driver program to test above function*/
int main()
{
  struct Node *root = NULL;

  /* Constructing tree given in the above figure */
  	
  person_t person[] = {
    {
        .name = "John",
        .surname = "Silver",
        .patronimic = "Batkovich",
        .phone = "88005553535",
        .work.company = "PiratesInc.",
        .work.post = "Captain",
        .socialNetwork.name = "telegram",
        .socialNetwork.link = "@theDeath"
    },
    {
        .name = "Jim",
        .surname = "Hawkins",
        .patronimic = "",
        .phone = "+12345678901",
        .work.company = "Adventurers",
        .work.post = "Explorer",
        .socialNetwork.name = "facebook",
        .socialNetwork.link = "/jimhawkins"
    },
    {
        .name = "Long",
        .surname = "John",
        .patronimic = "Silver",
        .phone = "+98765432109",
        .work.company = "Blackbeard's Crew",
        .work.post = "First Mate",
        .socialNetwork.name = "twitter",
        .socialNetwork.link = "@silverhand"
    },
    {
        .name = "Ben",
        .surname = "Gunn",
        .patronimic = "",
        .phone = "+55555555555",
        .work.company = "Treasure Hunters",
        .work.post = "Scout",
        .socialNetwork.name = "instagram",
        .socialNetwork.link = "@bengunntreasures"
    },
    {
        .name = "Billy",
        .surname = "Bones",
        .patronimic = "",
        .phone = "+66666666666",
        .work.company = "Pirate's Guild",
        .work.post = "Navigator",
        .socialNetwork.name = "linkedin",
        .socialNetwork.link = "/billybones"
    },
    {
        .name = "Flint",
        .surname = "",
        .patronimic = "",
        .phone = "+77777777777",
        .work.company = "Legendary Pirates",
        .work.post = "Leader",
        .socialNetwork.name = "reddit",
        .socialNetwork.link = "/captainflint"
    },
    {
        .name = "Israel",
        .surname = "Hands",
        .patronimic = "",
        .phone = "+88888888888",
        .work.company = "Rogue Pirates",
        .work.post = "Gunner",
        .socialNetwork.name = "tiktok",
        .socialNetwork.link = "@israelhands"
    },
    {
        .name = "George",
        .surname = "Merry",
        .patronimic = "",
        .phone = "+99999999999",
        .work.company = "Mutineers",
        .work.post = "Quartermaster",
        .socialNetwork.name = "youtube",
        .socialNetwork.link = "/georgemerry"
    },
    {
        .name = "Tom",
        .surname = "Redruth",
        .patronimic = "",
        .phone = "+44444444444",
        .work.company = "Privateers",
        .work.post = "Deckhand",
        .socialNetwork.name = "snapchat",
        .socialNetwork.link = "@tomredruth"
    },
    {
        .name = "Alan",
        .surname = "Pordage",
        .patronimic = "",
        .phone = "+33333333333",
        .work.company = "Shipwrights",
        .work.post = "Cabin Boy",
        .socialNetwork.name = "whatsapp",
        .socialNetwork.link = "+33333333333"
    }
};
  	
  	printf("log 1\n");
  	
    root = insert(root, &person[0]);
    root = insert(root, &person[1]);
    root = insert(root, &person[2]);
    root = insert(root, &person[3]);
    root = insert(root, &person[4]);
    root = insert(root, &person[5]);
    root = insert(root, &person[6]);
    root = insert(root, &person[7]);
    root = insert(root, &person[8]);
    
    printf("log 2\n");

    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preOrder(root);

    root = deleteNode(root, &person[3]);

    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */

    printf("\nPreorder traversal after deletion of 10 \n");
    preOrder(root);

    return 0;
}
