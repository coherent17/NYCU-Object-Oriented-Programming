#include "Student.h"

Student::Student(string _id, string _name, vector<int> _Scores){
    id = _id;
    name = _name;
    Scores = _Scores;
}

Student::~Student(){

}

ostream &operator<<(ostream &out, const Student a){
    out << "ID: " << a.id << ", Name: " << a.name << endl;
    out << "Scores >" << endl;
    out << "\tCalculus: " << a.Scores[0] << endl;
    out << "\tEnglish: " << a.Scores[1] << endl;
    out << "\tPhysics: " << a.Scores[2] << endl;
    return out;
}

string Student::getid(){
    return id;
}

string Student::getname(){
    return name;
}