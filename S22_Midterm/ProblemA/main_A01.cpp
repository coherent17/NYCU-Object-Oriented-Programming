#include "Point_Set.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    if (argc != 4){
        cout << "Usage: ./main_A01 <input_file_1> <input_file_2> <input_file_3>" << endl;
        return 1;
    } 

    string file1, file2, file3;
    file1 = argv[1];
    file2 = argv[2];
    file3 = argv[3];
    Point_Set ps1, ps2, ps3;
    ps1.Parser(file1);
    ps2.Parser(file2);
    ps3.Parser(file3);
    DisplayPointSet(ps1);
    cout << endl;
    DisplayPointSet(ps2);
    cout << endl;
    DisplayPointSet(ps3);
    return 0;
}