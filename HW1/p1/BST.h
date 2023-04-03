#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

typedef struct node{
    void* dataPtr;
    node* left;
    node* right;
}node;

class BST{
    private:
        int count;
        int (*compare) (void* argu1, void* argu2);  //use in constructor
        node* root;

    public:
        BST(int (*compare) (void* argu1, void* argu2));
        ~BST();
        bool BST_Insert(void* dataPtr);
        bool BST_Delete(void* dltKey);
        void BST_Traverse(void (*process) (void* dataPtr));
        bool BST_Empty();
        bool BST_Full();
        int BST_Count();
        node* _insert(node* root, node* newPtr); //Call by BST_Insert


    private:
        void freeBST(node *root);                               //helper function in destructor
        node *createNode(void *dataPtr);                        //helper function to dynamic allocate memory for node
        void inorderTraversal(node *root);                      //perform inorder traversal in BST
        node *remove(node *root, void *dltKey, bool *found);    //helper function in BST_Delete
        node *minValueNode(node *n);

};
#endif