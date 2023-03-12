#include <iostream> 
using namespace std; 
  
void registerStorageClass() {
    cout << "Demonstrating register class\n"; 
    // declaring a register variable x 
    register char x = 'M';
  
    // printing the register variable x 
    cout << "register variable x = " << x << endl; 
} 

int main() { 
    // To demonstrate register Storage Class 
    registerStorageClass(); 

    return 0; 
} 
