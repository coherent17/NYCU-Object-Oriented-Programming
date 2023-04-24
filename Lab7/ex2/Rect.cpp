#include "Rect.h"

Rect::Rect(){

}

Rect::Rect(int a, int b, int c, int d){
    setL(a);
    W = b;
    setx(c);
    sety(d);
}

Rect::Rect(int a, int b, int c, int d, int e){
    setL(a);
    W = b;
    setx(c);
    sety(d);
    setSize(e);
}

Rect::~Rect(){

}

void Rect::ComputeArea(){
    cout << "Area: " << getL() * W << endl;
}
void Rect::ComputePerimeter(){
    cout << "Perimeter : " << 2 * (getL() + W) << endl;
}
void Rect::ComputePoints(){

    int cx = getx();
    int cy = gety();
    int L = getL();

    //top layer
    for(int i = cx - L / 2; i <= cx + L / 2; i++){
        appendPoints(i, cy + W / 2);
    }

    //mid layer
    for(int j = cy + W / 2 - 1; j >= cy - W / 2 + 1; j--){
        appendPoints(cx + L / 2, j);
        appendPoints(cx - L / 2, j);
    }

    //bottom layer
    for(int i = cx - L / 2; i <= cx + L / 2; i++){
        appendPoints(i, cy - W / 2);
    }
}