#include "Shape.h"

Shape::Shape(){
    canvas_size = 20;
}

Shape::Shape(int a, int b, int c){
    L = a;
    pos_x = b;
    pos_y = c;
    canvas_size = 20;
}

Shape::~Shape(){
    ;
}

void Shape::setL(int a){
    L = a;
}

void Shape::setx(int a){
    pos_x = a;
}

void Shape::sety(int a){
    pos_y = a;
}

void Shape::setSize(int a){
    canvas_size = a;
}

int Shape::getL()const{
    return L;
}

int Shape::getx()const{
    return pos_x;
}

int Shape::gety()const{
    return pos_y;
}

int Shape::getSize()const{
    return canvas_size;
}

void Shape::appendPoints(int x, int y){
    points.push_back({x, y});
}

bool Shape::findPoint(int x, int y){

    for(size_t i = 0; i < points.size(); i++){
        if(points[i].x == x && points[i].y == y) return true;
    }
    return false;
}

void Shape::draw(){
    cout << "Draw:" << endl;
    cout << "|";
    for(int i = 0; i < canvas_size; i++){
        cout << i % 10;
    }
    cout << "|" << endl;
    for(int j = canvas_size - 1; j >= 0; j--){
        cout << j % 10;
        for(int i = 0; i < canvas_size; i++){
            if(findPoint(i, j)) cout << "*";
            else cout << " ";
        }
        cout << j % 10 << endl;
    }
    cout << "|";
    for(int i = 0; i < canvas_size; i++){
        cout << i % 10;
    }
    cout << "|" << endl;
}

vector<Point> Shape::getPoints(){
    return points;
}