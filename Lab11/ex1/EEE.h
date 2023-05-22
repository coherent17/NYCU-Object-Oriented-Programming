#ifndef _EEE_H_
#define _EEE_H_

#include <map>
#include <string>
#include <vector>
#include "Student.h"
#include "Group.h"
using namespace std;


class EEE {
   private:
      map<string, Group> groups;

   public:
      EEE();
      ~EEE();
      void addStudent(string, Student);          // add student to the group
      void removeStudentByID(string, string);    // remove student from the group by ID
      void removeStudentByName(string, string);  // remove student from the group by Name
      void gradeDistribution(string);            // show grade distribution of the group
      void viewInfo(string, int);                // view student info of the group, int represent diff mode
                                                // 0: sort by insertion time, 1: sort by ID, 2: sort by name
};

#endif