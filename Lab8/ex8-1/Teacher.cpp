#include "Teacher.h"
#include <iostream>
#include "Course.h"

Teacher::Teacher(string id, string name, string email, string password, int salary): Personnel(id, name, email, password){
    this->salary = salary;
}

void Teacher::printInfo(){
    cout << "\t";Personnel::printInfo();
    cout << "\tSalary: " << salary << endl;
    cout << "\tTaught Courses: ";
    for(size_t i = 0; i < taughtCourses.size(); i++){
        cout << "\"" << taughtCourses[i]->getName() << "\" "; 
    }
    cout << endl;
}

void Teacher::addTaughtCourse(Course* course){
    taughtCourses.push_back(course);
}