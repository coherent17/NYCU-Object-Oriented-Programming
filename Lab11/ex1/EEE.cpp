#include "EEE.h"

EEE::EEE(){
    ;
}

EEE::~EEE(){
    ;
}

void EEE::addStudent(string group_name, Student S){
    //if the group didn't exist -> create a group
    auto iter = groups.find(group_name);
    if(iter == groups.end()){
        Group g;
        groups[group_name] = g;
    }

    groups[group_name].addStudent(S);
}

void EEE::removeStudentByID(string group_name, string id){
    auto it = groups.find(group_name);  
    if(it == groups.end()){
        cout << "Group doesn't exist" << endl;
        return;
    }
    groups[group_name].removeStudentByID(id);
}

void EEE::removeStudentByName(string group_name, string name){
    auto it = groups.find(group_name);  
    if(it == groups.end()){
        cout << "Group doesn't exist" << endl;
        return;
    }
    groups[group_name].removeStudentByName(name);
}

void EEE::gradeDistribution(string group_name){
    auto it = groups.find(group_name);  
    if(it == groups.end()){
        cout << "Group doesn't exist" << endl;
        return;
    }
    groups[group_name].gradeDistribution();
}

// 0: sort by insertion time, 1: sort by ID, 2: sort by name
void EEE::viewInfo(string group_name, int mode){
    auto it = groups.find(group_name);  
    if(it == groups.end()){
        cout << "Group doesn't exist" << endl;
        return;
    }

    if(mode == 0){
        groups[group_name].printStudentsInOrder();
    }
    else if(mode == 1){
        groups[group_name].printStudentsInId();
    }
    else{
        groups[group_name].printStudentsInName();
    }
}