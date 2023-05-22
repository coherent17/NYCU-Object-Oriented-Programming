#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Student {
    private:
        string id;
        string name;
        vector<int> Scores;  // store 3 score {Calculus, English, Physics}

    public:
        Student(string, string, vector<int>);  // (ID, Name, Scores)
        ~Student();
        friend ostream &operator<<(ostream &out, const Student a);
        string getid();
        string getname();
        friend class Group;
        friend bool idcmp(Student a, Student b);
        friend bool namecmp(Student a, Student b);
        // add any function you need
};

#endif