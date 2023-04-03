#include "BST.h"

BST::BST(int (*compare) (void* argu1, void* argu2)){
    this->compare = compare;
    count = 0;
    root = nullptr;
}

//helper function for destructor
void BST::freeBST(node *root){
    if(root == nullptr) return;
    freeBST(root->left);
    freeBST(root->right);
    delete (int *)root->dataPtr;
    delete root;
}

BST::~BST(){
    freeBST(root);
}


node *BST::createNode(void *dataPtr){
    node *newNode = new node;
    newNode->dataPtr = dataPtr;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

//helper function for BST_Insert
node* BST::_insert(node* r, node* newPtr){
    if(r == nullptr){
        r = newPtr;
    }

    else if(compare(newPtr->dataPtr, r->dataPtr) == 0){
        r->left = _insert(r->left, newPtr);
    }
    else{
        r->right = _insert(r->right, newPtr);
    }
    return r;
}

bool BST::BST_Insert(void* dataPtr){
    node *newNode = createNode(dataPtr);
    root = _insert(root, newNode);
    count++;
    return true;
}

node *BST::minValueNode(node *n){
    node *temp = n;
    while(temp && temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

node *BST::remove(node *r, void *dltKey, bool *found){

    if(r == nullptr){
        return r;
    }

    if(compare(dltKey, r->dataPtr) == 0){
        r->left = remove(r->left, dltKey, found);
    }
    else if(compare(dltKey, r->dataPtr) == 1){
        r->right = remove(r->right, dltKey, found);
    }

    else{
        *found = true;
        if(r->left == nullptr){
            node *temp = r->right;
            delete (int *)r->dataPtr;
            delete r;
            return temp;
        }
        else if(r->right == nullptr){
            node *temp = r->left;
            delete (int *)r->dataPtr;
            delete r;
            return temp;
        }

        node *temp = minValueNode(r->right);
        r->dataPtr = temp->dataPtr;
        r->right = remove(r->right, temp->dataPtr, found);
    }
    return r;
}

bool BST::BST_Delete(void* dltKey){
    bool found = false;
    root = remove(root, dltKey, &found);
    if(found){
        count--;
        return true;
    }
    return false;
}

void BST::inorderTraversal(node *r){
    if(r == nullptr) return;
    inorderTraversal(r->left);
    cout << *((int *)r->dataPtr) << " ";
    inorderTraversal(r->right);
}

void BST::BST_Traverse(void (*process) (void* dataPtr)){
    if(BST_Empty()){
        cout << "The BST is empty." << endl;
        return;
    }
    inorderTraversal(root);
    cout << endl;
}

bool BST::BST_Empty(){
    return count == 0;
}

bool BST::BST_Full(){
    struct node *temp = new node;
    bool ret = temp == nullptr ? true : false;
    delete temp;
    return ret;
}

int BST::BST_Count(){
    return count;
}