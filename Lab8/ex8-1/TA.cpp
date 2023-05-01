#include "TA.h"
#include "Course.h"
#include <iostream>
TA::TA(string id, string name, string email, string password, string degree, int tuition, int salary):Personnel(id, name, email, password), Student(id, name, email, password, degree, tuition), Teacher(id, name, email, password, salary){

}

void TA::printInfo(){
    Teacher::printInfo();
    cout << "\tAttend Courses: ";
    for(size_t i = 0; i < attendedCourses.size(); i++){
        cout << "\"" << attendedCourses[i]->getName() << "\" "; 
    }
    cout << endl;
}