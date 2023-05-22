#ifndef _CLASS_H_
#define _CLASS_H_

#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;
class Student;

class Group {
    private:
        vector<Student> students;
        int student_num;

        int sum_score_Calculus;
        int high_Calculus;
        int low_Calculus;

        int sum_score_English;
        int high_English;
        int low_English;

        int sum_score_Physics;
        int high_Physics;
        int low_Physics;


    public:
        Group();
        ~Group();
        void addStudent(Student);
        void removeStudentByID(string);
        void removeStudentByName(string);
        void gradeDistribution();  // print out Avg, Max, Min Score of each subject

        void printStudentsInOrder();
        void printStudentsInId();
        void printStudentsInName();
    // add any function you need
};

#endif