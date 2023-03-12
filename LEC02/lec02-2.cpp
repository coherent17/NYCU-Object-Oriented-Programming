#include <iostream> 
using namespace std; 
  
// declaring the variable which is to be made extern an intial value can 
// also be initialized to x 
int x; 

void externStorageClass() { 
    cout << "Demonstrating extern class\n";   
    // telling the compiler that the variable x is an extern variable 
    // and has been defined elsewhere (above the main function) 
    extern int x; 
  
    // printing the extern variables 'x' 
    cout << "Extern x = " << x << "\n"; 
    // value of extern variable x modified 
    x = 2; 
    // printing the modified values of extern variables 'x' 
    cout << "Modified extern x = " << x << endl;
} 
  
int main() { 
    // To demonstrate extern Storage Class 
    externStorageClass(); 
  
    return 0; 
} 