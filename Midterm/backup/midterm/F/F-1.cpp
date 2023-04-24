#include <string>
#include <vector>
#include <fstream>
#include "Netlist.h"
using namespace std;

int main(int argc, char *argv[])
{
    string in_file = argv[1];
    Netlist n1;
    n1.Initialize(in_file);
    n1.PrintInfo();
}