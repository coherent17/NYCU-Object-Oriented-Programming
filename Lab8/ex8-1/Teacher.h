#ifndef _PERSONNEL_H_
#define _PERSONNEL_H_
#include "Personnel.h"
#endif


#include <string>
#include <vector>


using namespace std;

class Course;

class Teacher : public virtual Personnel {
   protected:
    int salary;
    vector<Course*> taughtCourses;

   public:
    Teacher(string id, string name, string email, string password, int salary);
    void printInfo();
    void addTaughtCourse(Course* course);
};