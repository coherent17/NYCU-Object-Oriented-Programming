#include<bits/stdc++.h>
#include <cmath>
#include "LineGp.h"

using namespace std;

LineGp::LineGp(){

}

void LineGp::set_L(int i, Line l){
    lines[i] = l;
}

void LineGp::set_lines(){
    for(int i = 0; i < 3; i++){
        double z1, z2, z3, z4;
        cout << "L" << i << ":" << endl;
        cout << "Point 1: "; cin >> z1 >> z2;
        cout << "Point 2: "; cin >> z3 >> z4;
        Point p1, p2;

        if(z1 < z3){
            p1 = {z1, z2};
            p2 = {z3, z4};
        }
        else if(z1 == z3){
            if(z2 < z4){
                p1 = {z1, z2};
                p2 = {z3, z4};
            }
            else{
                p2 = {z1, z2};
                p1 = {z3, z4};
            }
        }
        else{
            p2 = {z1, z2};
            p1 = {z3, z4};
        }
        
        Line ll;
        ll = {p1, p2};        
        set_L(i, ll);
    }
}

void LineGp::printLines(){
    cout << "////LINES////" << endl;
    for(int i = 0; i < 3; i++){
        cout << "L" << i << ": " << "(" << lines[i].p1.x << "," << lines[i].p1.y << ")" << " (" << lines[i].p2.x << "," << lines[i].p2.y << ")" << endl;
    }
    cout << "////LINES////" << endl;
    cout << endl;
}

        
void LineGp::interset(Line l1, Line l2){
    int a1 = l1.p2.y - l1.p1.y;
    int b1 = l1.p2.x - l1.p1.x;
    int c1 = a1 * l1.p1.x - b1 * l1.p1.y;
    cout << a1 << "x" << "-" << b1 << "y" << " = " << c1 << endl;

    int a2 = l2.p2.y - l2.p1.y;
    int b2 = l2.p2.x - l2.p1.x;
    int c2 = a2 * l2.p1.x - b2 * l2.p1.y;
    cout << a2 << "x" << "-" << b2 << "y" << " = " << c2 << endl;

    double delta = a1*(-b2) - a2*(-b1);
    double deltax = c1*(-b2) - c2*(-b1);
    double deltay = a1*c2 - a2*c1;

    if(delta == 0){
        cout << "Two lines are parallel" << endl;
    }

    else if(delta != 0){
        double x = deltax / delta;
        double y = deltay / delta;

        if(x < l1.p1.x || x > l1.p2.x) cout << "Intersect point isn't in range" << endl;
        else{
            cout << "Interset at (" << x << ", " << y << ")" << endl;
            intersectP.push_back({x, y});
        }
    }
    
}


void LineGp::interset_lines(){
    cout << "L0, L1" << endl;
    interset(lines[0], lines[1]);

    cout << "L0, L2" << endl;
    interset(lines[0], lines[2]);

    cout << "L1, L2" << endl;
    interset(lines[1], lines[2]);
    cout << endl;
}


void LineGp::computeArea(){
    interset_lines();

    if(intersectP.size() < 3){
        cout << "No Triangle" << endl;
        return;
    }

    double a = sqrt((intersectP[1].y - intersectP[0].y) * (intersectP[1].y - intersectP[0].y) + (intersectP[1].x - intersectP[0].x) * (intersectP[1].x - intersectP[0].x)); 
    double b = sqrt((intersectP[1].y - intersectP[2].y) * (intersectP[1].y - intersectP[2].y) + (intersectP[1].x - intersectP[2].x) * (intersectP[1].x - intersectP[2].x)); 
    double c = sqrt((intersectP[2].y - intersectP[0].y) * (intersectP[2].y - intersectP[0].y) + (intersectP[2].x - intersectP[0].x) * (intersectP[2].x - intersectP[0].x)); 
    double s = (a+b+c) / 2;
    double area = sqrt(s*(s-a)*(s-b)*(s-c)); 
    cout << "Area is: " << area << endl;
}