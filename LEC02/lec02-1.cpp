#include <iostream> 
using namespace std; 
  
void autoStorageClass() { 
  
    cout << "Demonstrating auto class\n"; 
    // Declaring an auto variable; No data-type declaration needed 
    auto a = 13; 
    auto b = 1.3; 
    auto c = "Auto Class"; 
    auto d = 'F'; 
  
    // printing the auto variables 
    cout << a << ": " << sizeof(a) << endl; 
    cout << b << ": " << sizeof(b) << endl; 
    cout << c << ": " << sizeof(c) << " " << sizeof(char *) << endl; 
    cout << d << ": " << sizeof(d) << endl; 
} 
  
int main() { 

    // To demonstrate auto Storage Class 
    autoStorageClass(); 
  
    return 0; 
} 
