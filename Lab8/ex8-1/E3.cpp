#include "E3.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

#ifndef _TA_H_
#define _TA_H_
#include "TA.h"
#endif

#ifndef _COURSE_H_
#define _COURSE_H_
#include "Course.h"
#endif

void E3::importPersonnelsFromCsv(string csvFilename){
    string line;
    ifstream fin(csvFilename);

    //read the first line
    getline(fin, line);

    while(getline(fin, line)){
        replace(line.begin(), line.end(), ' ', '_');
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        string id, name, email, password, position, degree;
        int tuition, salary;
        ss >> id >> name >> email >> password >> position;
        if(position == "Student"){
            ss >> degree >> tuition;
            Personnel* x= new Personnel(id, name, email, password);
            Student* y = new Student(id, name, email, password, degree, tuition);
            personnels.push_back(x);
            students.push_back(y);
        }

        if(position == "TA"){
            ss >> degree >> tuition >> salary;
            Personnel* x= new Personnel(id, name, email, password);
            TA* z = new TA(id, name, email, password, degree, tuition, salary);
            personnels.push_back(x);
            TAs.push_back(z);
        }

        if(position == "Teacher"){
            ss >> salary;
            replace(name.begin(), name.end(), '_', ' ');
            Personnel* x= new Personnel(id, name, email, password);
            Teacher* y = new Teacher(id, name, email, password, salary);
            personnels.push_back(x);
            teachers.push_back(y);
        }
    }
    fin.close();
}

void E3::importCoursesFromCsv(string csvFilename){
    string line;
    ifstream fin(csvFilename);

    //read the first line
    getline(fin, line);
    while(getline(fin, line)){
        replace(line.begin(), line.end(), ' ', '_');
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        string id, name, prof_id;
        ss >> id >> name >> prof_id;
        replace(name.begin(), name.end(), '_', ' ');
        Course *c = nullptr;
        //find the pointer point to professor
        for(size_t i = 0; i < teachers.size(); i++){
            if(teachers[i]->getId() == prof_id){
                c = new Course(id, name, teachers[i]);
                teachers[i]->addTaughtCourse(c);
                break;
            }
        }
        
        string TA_IDS;
        ss >> TA_IDS;
        replace(TA_IDS.begin(), TA_IDS.end(), '|', ' ');
        stringstream TA_STREAM(TA_IDS);
        string TA_ID;
        while(TA_STREAM >> TA_ID){
            //find the pointer point to TA
            for(size_t i = 0; i < TAs.size(); i++){
                if(TAs[i]->getId() == TA_ID){
                    TAs[i]->addTaughtCourse(c);
                    c->addTA(TAs[i]);
                    break;
                }
            }
        }

        string STU_IDS;
        ss >> STU_IDS;
        replace(STU_IDS.begin(), STU_IDS.end(), '|', ' ');
        stringstream STU_STREAM(STU_IDS);
        string STU_ID;
        while(STU_STREAM >> STU_ID){
            //find the pointer point to student
            for(size_t i = 0; i < students.size(); i++){
                if(students[i]->getId() == STU_ID){
                    students[i]->addAttendCourse(c);
                    c->addStudent(students[i]);
                    break;
                }
            }

            //TA can also be the student
            for(size_t i = 0; i < TAs.size(); i++){
                if(TAs[i]->getId() == STU_ID){
                    TAs[i]->addAttendCourse(c);
                    c->addStudent(TAs[i]);
                    break;
                }
            }
        }
        courses.push_back(c);
    }
    fin.close();
}

void E3::printAllPersonnel(){
    for(size_t i = 0; i < personnels.size(); i++){
        personnels[i]->printInfo();
        cout << endl;
    }
}

void E3::printAllCourse(){
    for(size_t i = 0; i < courses.size(); i++){
        courses[i]->printInfo();
    }
    
}

E3::~E3(){
    for(size_t i = 0; i < personnels.size(); i++){
        delete personnels[i];
    }

    for(size_t i = 0; i < students.size(); i++){
        delete students[i];
    }

    for(size_t i = 0; i < teachers.size(); i++){
        delete teachers[i];
    }

    for(size_t i = 0; i < TAs.size(); i++){
        delete TAs[i];
    }

    for(size_t i = 0; i < courses.size(); i++){
        delete courses[i];
    }
}