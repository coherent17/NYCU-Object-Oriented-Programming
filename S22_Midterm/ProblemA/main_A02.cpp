#include "Point_Set.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    if (argc != 3){
        cout << "Usage: ./main_A02 <input_file_1> <input_file_2>" << endl;
        return 1;
    }
        
    string file1, file2;
    file1 = argv[1];
    file2 = argv[2];
    Point_Set ps1, ps2;
    ps1.Parser(file1);
    ps2.Parser(file2);
    DisplayPointSet(ps1);
    cout << endl;
    DisplayPointSet(ps2);
    cout << endl;
    ps1 += 2.6;
    DisplayPointSet(ps1);
    cout << endl;
    ps2 *= 1.2;
    DisplayPointSet(ps2);
    return 0;
}