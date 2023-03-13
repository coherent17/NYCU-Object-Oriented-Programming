#include<bits/stdc++.h>
using namespace std;
#include "Class.h"

Class::Class(){

}
Class::Class(const Class &old){
    class_size = old.class_size;
    passing_score = old.passing_score;
    students = old.students;
}


void Class::set_class_size(int size){
    class_size = size;
}

void Class::set_students(Student *s){
    students = s;
}

void Class::set_passing_score(int ps){
    passing_score = ps;
}

void Class::initialize(){
    int numStudent;
    int pass_score;
    cout << "Number of students: "; cin >> numStudent;
    cout << "Set Passing Score: "; cin >> pass_score;
    set_class_size(numStudent);
    set_passing_score(pass_score);
    Student *s = new Student[numStudent];
    set_students(s);

    for(int i = 0; i < class_size; i++){
        string name;
        string ID;
        int sc;
        cout << "Student Name: "; cin >> name;
        cout << "Student ID: "; cin >> ID;
        cout << "Score: "; cin >> sc;
        students[i] = {name, ID, sc};
    }
}

void Class::add_student(Student s){
    Student *s_new = new Student[class_size + 1];
    for(int i = 0; i < class_size; i++){
        s_new[i] = students[i];
    }
    delete []students;
    s_new[class_size] = s;
    class_size++;
    students = s_new;
}

bool cmp(Student a, Student b){
    return a.student_id < b.student_id;
}

void Class::students_info(){
    sort(students, students + class_size, cmp);

    for(int i = 0; i < class_size; i++){
        cout << students[i].name << "\t" << students[i].student_id << "\t" << students[i].score << endl;
    }
    cout << endl;
}

double Class::find_average(){
    double total = 0;
    for(int i = 0; i < class_size; i++){
        total += students[i].score;
    }
    return total / class_size;
}


double Class::find_median(){
    int *scores = new int[class_size];
    for(int i = 0; i < class_size; i++){
        scores[i] = students[i].score;
    }
    sort(scores, scores + class_size);
    if (class_size % 2 != 0)
        return (double)scores[class_size/2];
    return (double)(scores[(class_size-1)/2] + scores[class_size/2])/2.0;
}

int Class::find_fail(){
    int count = 0;
    for(int i = 0; i < class_size; i++){
        if(students[i].score < passing_score) count++;
    }
    return count;
}

void Class::score_info(){
    cout << "Average Score: " << find_average() << endl;
    cout << "Median Score: " << find_median() << endl;
    cout << "Fail Student Number: " << find_fail() << endl;
    cout << endl;
}


void Class::set_score(string name, int sc){
    bool found = false;
    for(int i = 0; i < class_size; i++){
        if(students[i].name == name){
            students[i].score = sc;
            found = true;
            break;
        }
    }
    if(found == false){
        cout << "student doesn't exist!" << endl;
    }
}


void Class::remove_student(string name){
    bool found = false;
    for(int i = 0; i < class_size; i++){
        if(students[i].name == name){
            Student temp = students[class_size-1];
            students[class_size-1] = students[i];
            students[i] = temp;

            Student *s = new Student[class_size-1];
            for(int i = 0; i < class_size-1; i++){
                s[i] = students[i];
            }
            students = s;
            class_size--;
            found = true;
            break;
        }
    }
    if(found == false){
        cout << "student doesn't exist!" << endl;
    }
}