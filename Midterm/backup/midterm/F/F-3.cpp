#include <string>
#include <vector>
#include <fstream>
#include "Netlist.h"
using namespace std;

int main(int argc, char *argv[])
{
    string in_file = argv[1];
    string delay_file = argv[2];
    Netlist n1;
    n1.Initialize(in_file);
    n1.DelayAssignment(delay_file);
    string PI, PO;
    cout << "PI: ";
    cin >> PI;
    cout << "PO: ";
    cin >> PO;
    n1.Traversal(PI, PO);

    return 0;
}