#include<bits/stdc++.h>
using namespace std;

#ifndef _CLASS_H_
#define _CLASS_H_

typedef struct _Student{
    string name;
    string student_id;
    int score;
}Student;

class Class{
    private:
        int class_size;
        int passing_score;
        Student *students;
        void set_class_size(int size);
        void set_students(Student * );
        double find_average();
        double find_median();
        int find_fail();

    public:
        Class();
        Class(const Class &);
        void initialize();
        void students_info();
        void score_info();
        void set_passing_score(int);
        void set_score(string, int);
        void add_student(Student);
        void remove_student(string);
};

#endif