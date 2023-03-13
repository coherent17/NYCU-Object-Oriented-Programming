#include <iostream>
#include <string>
#include "Class.h"
using namespace std;

int main(){
    cout << "Math" << endl;
    Class Math;
    Math.initialize();
    Math.students_info();
    Math.add_student(Student{"Jimmy", "A1703", 92});
    Math.students_info();
    Math.score_info();

    cout << "Chinese" << endl;
    Class Chinese(Math);
    Chinese.set_score("Amy", 92);
    Chinese.set_passing_score(50);
    Chinese.remove_student("Zcck");
    Chinese.remove_student("Zack");
    Chinese.students_info();
    Chinese.score_info();

    cout << "Chemistry" << endl;
    Class Chemistry(Chinese);
    Chemistry.add_student(Student{"Bob", "B4320", 54});
    Chemistry.add_student(Student{"Jessica", "A0222", 77});
    Chemistry.set_passing_score(75);
    Chemistry.set_score("Brian", 64);
    Chemistry.remove_student("Nancy");
    Chemistry.remove_student("Roddy");
    Chemistry.students_info();
    Chemistry.score_info();

    

    return 0;
}