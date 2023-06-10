#include "Point2D.h"
#include "Hash_table.h"
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    Hash_table<int> inttable;
    Hash_table<string> strtable;
    Hash_table<Point2D> Point2Dtable;
    ifstream intfile(argv[1]);
    int int_data, x, y;
    string string_data;
    Point2D Point2D_data;

    while(!intfile.eof()) {
        intfile >> int_data;
        inttable.insert(int_data);
    }
    intfile.close();
    inttable.show();
    cout << endl;
    ifstream strfile(argv[2]);
    while(!strfile.eof()) {
        strfile >> string_data;
        strtable.insert(string_data);
    }
    strfile.close();
    strtable.search("abw");
    strtable.show();
    cout << endl;

    ifstream Point2Dfile(argv[3]);
    while(!Point2Dfile.eof()) {
        Point2Dfile >> x >> y;
        Point2D_data.SetXY(x, y);
        Point2Dtable.insert(Point2D_data);
    }
    Point2Dfile.close();
    Point2Dtable.search(Point2D(4,1));
    Point2Dtable.show();

    return 0;
}
