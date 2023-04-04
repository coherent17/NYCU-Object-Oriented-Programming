#include "BST.h"
using namespace std;


//if num1 < num2 return 0, else return 1
int compareInt(void* num1, void* num2){
    if(*(int *)num1 < *(int *)num2) return 0;
    else if(*(int *)num1 > *(int *)num2) return 1;
    return 2;
}

void printBST(void* num1){
    cout << *(int *)num1;
}

void printMenu(){
    cout << "The following are six options for your BST:" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Print the BST" << endl;
    cout << "4. Check the BST is full or not" << endl;
    cout << "5. Print the number of nodes in BST" << endl;
    cout << "6. Exit" << endl;
    cout << "Please enter: ";
}


int main(){
    BST myBST(compareInt);

    bool looping = true;

    while(looping){
        int choice;
        printMenu();    
        cin >> choice;
        
        switch(choice){
            
            case(1):{
                int *iptr = new int;
                cout << "Enter an integer: "; cin >> *iptr;
                myBST.BST_Insert((void *)iptr);
                break;
            }

            case(2):{
                int *delptr = new int;
                cout << "Enter the integer: "; cin >> *delptr;
                if(myBST.BST_Delete((void *)delptr)){
                    cout << "New BST: ";
                    myBST.BST_Traverse(printBST);
                }
                else{
                    cout << "The number is not in BST." << endl;
                }
                delete delptr;
                break;
            }

            case(3):
                myBST.BST_Traverse(printBST);
                break;

            case(4):
                if(myBST.BST_Full())
                    cout << "BST is full" << endl;
                else
                    cout << "BST is not full yet" << endl;
                break;

            case(5):
                cout << "There are " << myBST.BST_Count() << " nodes in BST." << endl;
                break;
            
            case(6):
                looping = false;
                break;
        }
    }
    return 0;
}