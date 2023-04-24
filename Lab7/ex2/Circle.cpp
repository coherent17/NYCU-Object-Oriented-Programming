#include "Circle.h"
#include "Shape.h"

Circle::Circle(int a, int b, int c){
    setL(a);
    setx(b);
    sety(c);
    setSize(20);
}

Circle::Circle(int a, int b, int c, int d){
    setL(a);
    setx(b);
    sety(c);
    setSize(d);
}

void Circle::ComputeArea(){
    cout << "Area: " << PI * double(getL()) * double(getL()) << endl;
}
void Circle::ComputePerimeter(){
    cout << "Perimeter : " << 2 * PI * double(getL()) << endl;
}

void Circle::ComputePoints(){
    int cx = getx();
    int cy = gety();
    int L = getL();

    //upper circle
    for(int j = cy + 1; j <= cy + L + 1; j++){
        appendPoints(round(-sqrt((L * L )- (j - cy) * (j - cy))) + cx, j);
        appendPoints(round(+sqrt((L * L )- (j - cy) * (j - cy))) + cx, j);
    }

    //mid circle
    appendPoints(cx + L, cy);
    appendPoints(cx - L, cy);

    //down circle
    for(int j = cy - 1; j >= cy - L - 1; j--){
        appendPoints(round(-sqrt((L * L )- (j - cy) * (j - cy))) + cx, j);
        appendPoints(round(+sqrt((L * L )- (j - cy) * (j - cy))) + cx, j);
    }
}