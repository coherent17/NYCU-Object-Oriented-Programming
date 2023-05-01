#include "Course.h"
#ifndef _TEACHER_H_
#define _TEACHER_H_
#include "Teacher.h"
#endif

#ifndef _TA_H_
#define _TA_H_
#include "TA.h"
#endif

#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "Student.h"
#endif

#include <iostream>
Course::Course(string id, string name, Teacher* teacher){
    this->id = id;
    this->name = name;
    this->teacher = teacher;
}

void Course::addTA(TA* ta){
    TAs.push_back(ta);
}

void Course::addStudent(Student* student){
    students.push_back(student);
}

void Course::printInfo(){
    cout << "id: " << id << "\t" << "Name: " << name << endl;
    cout << "Teacher:" << endl;
    teacher->printInfo();

    cout << "TAs: " << endl;
    for(size_t i = 0; i < TAs.size(); i++){
        TAs[i]->printInfo();
        cout << endl;
    }

    cout << "Students: " << endl;
    for(size_t i = 0; i < students.size(); i++){
        students[i]->printInfo();
        cout << endl;
    }
}

string Course::getName(){
    return name;
}