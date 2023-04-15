#include "Point_Set.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
if (argc != 2){
    cout << "Usage: ./main_A03 <input_file_1>" << endl;
    return 1;
}

    double b_0, b_1;
    string file1;
    file1 = argv[1];
    Point_Set ps1;
    ps1.Parser(file1);
    ps1.fit(b_1, b_0);
    cout << endl;
    ps1.predict(b_1, b_0);
    return 0;
}