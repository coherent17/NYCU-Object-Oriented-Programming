#ifndef NETLIST_H
#define NETLIST_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Netlist
{
    friend class Gate;

private:
    class Gate
    {
    private:
        string Name;
        string Type;
        int Value;
        int Delay;
        vector<Gate *> Input_list;  // store all fanin
        vector<Gate *> Output_list; // store all fanout

    public:
        // Level 1
        Gate(string Name, string Type);
        ~Gate();

        void AddInput_list(Gate *gptr);
        void AddOutput_list(Gate *gptr);
        string GetName();
        string GetType();
        int GetOutput_list_Size();
        // Level 2
        int GetValue();
        void SetValue(int);
        // Level 3
        int GetDelay();
        void SetDelay(int);
        vector<Gate *> &GetInput_list() { return Input_list; }
        vector<Gate *> &GetOutput_list() { return Output_list; }
    };

    vector<Gate *> Gatelist; // Store all gates
    vector<Gate *> PIlist;   // Store all input gates
    vector<Gate *> POlist;   // Store all output gates

    // Level 1
    void FanOutList();
    int No_Gate();
    int No_PI();
    int No_PO();
    void FindMaxFanout();
    void CheckpointThm();
    // Level 2
    void SetNodeValue(Gate *gptr);

public:
    // Level 1
    Netlist();
    ~Netlist();
    void Initialize(string inputFile);
    void PrintInfo();
    // Level 2
    void Simulate(string inputFile);
    void DelayAssignment(string inputFile);
    // Level 3
    void Traversal(string PI, string PO);
    int Trace(Gate *gptr, string PI, int &pathCount, vector<string> &path);
};

#endif