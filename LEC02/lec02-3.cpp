#include <iostream> 
using namespace std; 
  
// Function containing static variables; memory is retained during execution 
int staticFun() { 
    cout << "For static variables: "; 
    static int count = 0; 
    count++; 
    return count; 
} 
  
// Function containing non-static variables; memory is destroyed 
int nonStaticFun() { 
    cout << "For Non-Static variables: "; 
    int count = 0; 
    count++; 
    return count; 
} 
  
int main() { 
  
    // Calling the static parts 
    cout << staticFun() << "\n"; 
    cout << staticFun() << "\n";  
  
    // Calling the non-static parts 
    cout << nonStaticFun() << "\n"; 
    cout << nonStaticFun() << "\n"; 
    
    return 0; 
} 