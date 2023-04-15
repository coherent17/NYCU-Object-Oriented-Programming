#include "Point_Set.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>

Point_Set::Point_Set(){
    num = 0;
    points = nullptr;
    name = "";
}

Point_Set::~Point_Set(){
    delete []points;
}

void Point_Set::Parser(string filename){
    string is;
    ifstream fin(filename);

    //read the name of the point set
    getline(fin, is);
    name = is;

    //read the number of points
    getline(fin, is);
    num = stoi(is);
    points = new Point[num];


    for(int i = 0; i < num; i++){
        //get the point name
        getline(fin, is);

        //get the coordinate
        replace(is.begin(), is.end(), '(', ' ');
        replace(is.begin(), is.end(), ',', ' ');
        replace(is.begin(), is.end(), ')', ' ');

        stringstream ss;
        ss << is;
        
        ss >> points[i].name;
        ss >> points[i].x;
        ss >> points[i].y;
    }

}

bool cmp(Point a, Point b){
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

void DisplayPointSet(const Point_Set &PS){
    cout << PS.name << endl;
    sort(PS.points, PS.points + PS.num, cmp);
    for(int i = 0; i < PS.num; i++){
        cout << PS.points[i].name << ": (" << PS.points[i].x << "," << PS.points[i].y << ")" << endl;
    }
}

void Point_Set::operator+=(const double &shift){
    for(int i = 0; i < num; i++){
        points[i].x += shift;
        points[i].y += shift;
    }
}

void Point_Set::operator*=(const double &shift){
    for(int i = 0; i < num; i++){
        points[i].x *= shift;
        points[i].y *= shift;
    }
}

void Point_Set::fit(double &b1, double &b0){
    double sum_xy = 0, sum_x = 0, sum_y = 0, sum_x2 = 0;

    for(int i = 0; i < num; i++){
        sum_xy += points[i].x * points[i].y;
        sum_x += points[i].x;
        sum_y += points[i].y;
        sum_x2 += points[i].x * points[i].x;
    }

    b1 = (num * sum_xy - sum_x * sum_y) / (num * sum_x2 - sum_x * sum_x);
    b0 = (sum_y - b1 * sum_x) / num;
    cout << "b_0 = " << b0 << endl;
    cout << "b_1 = " << b1 << endl;
}

double* Point_Set::predict(const double &b1, const double &b0){
    cout << "Predicted Data:" << endl;
    for(int i = 0; i < num; i++){
        cout << "(" << points[i].x << "," << b0 + b1 * points[i].x << ")" << endl;
    }
    return nullptr;
}