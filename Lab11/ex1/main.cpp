#include <iostream>
#include <vector>
#include "Student.h"
#include "Group.h"
#include "EEE.h"

using namespace std;

int main() {
    Student s1("311511000", "Samuel", vector<int>{90, 80, 95});
    Student s2("411511000", "Lowry", vector<int>{81, 92, 73});
    Student s3("310511000", "Jimmy", vector<int>{79, 71, 60});
    Student s4("311511001", "Brian", vector<int>{65, 82, 77});
    Student s5("311511002", "Amy", vector<int>{92, 89, 85});
    Student s6("310511001", "Sandy", vector<int>{60, 73, 94});
    Student s7("312511000", "Meg", vector<int>{49, 68, 77});
    Student s8("411511001", "Nicholas", vector<int>{88, 60, 92});
    Student s9("312511001", "Zack", vector<int>{99, 55, 37});
    Student s10("312511002", "Ben", vector<int>{78, 89, 64});
    Student s11("312511003", "Mark", vector<int>{32, 46, 88});
    Student s12("311511003", "Ariel", vector<int>{78, 97, 91});
    Student s13("411511002", "Jason", vector<int>{20, 38, 30});
    Student s14("411511003", "Larry", vector<int>{64, 99, 50});
    Student s15("410511000", "Bob", vector<int>{37, 88, 94});
    Student s16("410511001", "Nancy", vector<int>{50, 63, 83});
    Student s17("410511002", "Zoe", vector<int>{92, 95, 55});
    Student s18("410511003", "Rober", vector<int>{83, 74, 79});
    Student s19("410511004", "Frank", vector<int>{75, 31, 88});
    Student s20("411511004", "Lily", vector<int>{69, 10, 99});

    EEE A;
    cout << "/////// cls_A ////////" << endl;
    A.addStudent("cls_A", s5);
    A.addStudent("cls_A", s20);
    A.addStudent("cls_A", s2);
    A.addStudent("cls_A", s13);
    A.gradeDistribution("cls_A");
    A.removeStudentByID("cls_A", "311511001");  // s4
    A.removeStudentByID("cls_A", "311511002");  // s5
    A.viewInfo("cls_A", 1);
    A.gradeDistribution("cls_A");
    cout << "/////// cls_A ////////" << endl
         << endl;

    cout << "/////// cls_B ////////" << endl;
    A.addStudent("cls_B", s12);
    A.addStudent("cls_B", s5);
    A.addStudent("cls_B", s3);
    A.viewInfo("cls_B", 0);
    A.removeStudentByName("cls_B", "Jimmy");
    A.viewInfo("cls_B", 2);
    A.gradeDistribution("cls_B");
    cout << "/////// cls_B ////////" << endl
         << endl;

    cout << "/////// cls_C ////////" << endl;
    A.viewInfo("cls_C", 2);
    A.removeStudentByName("cls_C", "Zoe");
    A.gradeDistribution("cls_C");
    A.addStudent("cls_C", s10);
    A.addStudent("cls_C", s1);
    A.addStudent("cls_C", s3);
    A.addStudent("cls_C", s9);
    A.gradeDistribution("cls_C");
    A.removeStudentByName("cls_C", "Zack");
    A.viewInfo("cls_C", 1);
    A.addStudent("cls_C", s20);
    A.gradeDistribution("cls_C");
    A.viewInfo("cls_C", 2);
    cout << "/////// cls_C ////////" << endl
         << endl;

    return 0;
}