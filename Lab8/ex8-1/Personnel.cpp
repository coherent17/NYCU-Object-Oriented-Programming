#include "Personnel.h"
#include <iostream>
    
Personnel::Personnel(){
    id = "";
    name = "";
    email = "";
    password = "";
}

Personnel::Personnel(string id, string name, string email, string password){
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}

void Personnel::printInfo(){
    cout << "id: " << id <<  "\tName: " << name << "\temail: " << email;
}

string Personnel::getId(){
    return id;
}