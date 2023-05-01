#ifndef _E3_H_
#define _E3_H_
#include "E3.h"
#endif
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string personnelsFilename = string(argv[1]);
    string coursesFilename = string(argv[2]);

    E3 e3;
    e3.importPersonnelsFromCsv(personnelsFilename);
    e3.importCoursesFromCsv(coursesFilename);

    cout << "All Personnels:" << endl;
    e3.printAllPersonnel();
    cout << endl;

    cout << "All Course:" << endl;
    e3.printAllCourse();
    cout << endl;

}