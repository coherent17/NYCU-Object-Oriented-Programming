#ifndef _PERSONNEL_H_
#define _PERSONNEL_H_
#include "Personnel.h"
#endif

#include <string>
#include <vector>

using namespace std;

class Course;

class Student : public virtual Personnel {
   protected:
    string degree;
    int tuition;
    vector<Course*> attendedCourses;

   public:
    Student(string id, string name, string email, string password, string degree, int tuition);
    void printInfo();
    void addAttendCourse(Course* course);
};