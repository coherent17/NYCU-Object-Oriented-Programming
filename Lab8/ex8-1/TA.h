#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "Student.h"
#endif

#ifndef _TEACHER_H_
#define _TEACHER_H_
#include "Teacher.h"
#endif


#include <string>
#include <vector>

using namespace std;


class TA : public Student, public Teacher {
   private:
   public:
    TA(string id, string name, string email, string password, string degree, int tuition, int salary);
    void printInfo();
};