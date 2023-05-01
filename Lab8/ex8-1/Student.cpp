#include "Student.h"
#include "Course.h"
#include <iostream>

Student::Student(string id, string name, string email, string password, string degree, int tuition): Personnel(id, name, email, password){
    this->degree = degree;
    this->tuition = tuition;
}

void Student::printInfo(){
    cout << "\t";Personnel::printInfo();
    cout << "\tDegree: " << degree << "\tTuition: " << tuition << endl;
    cout << "\tAttend Courses: ";
    for(size_t i = 0; i < attendedCourses.size(); i++){
        cout << "\"" << attendedCourses[i]->getName() << "\" "; 
    }
    cout << endl;
}

void Student::addAttendCourse(Course* course){
    attendedCourses.push_back(course);
}