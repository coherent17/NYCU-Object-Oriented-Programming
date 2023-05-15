#include "Point2D.h"
#include <iostream>

using namespace std;

// Default constructor
Point2D::Point2D() {
    x = 1;
    y = 1;
}

// Constructor with one argument
Point2D::Point2D(int val) {
    x = val;
    y = val;
}

// Constructor with two arguments
Point2D::Point2D(int x_val, int y_val) {
    x = x_val;
    y = y_val;
}

// Destructor
Point2D::~Point2D() {
    // No dynamic memory allocation, so nothing to do here
}

// Overloaded assignment operator
void Point2D::operator=(const Point2D& other) {
    x = other.x;
    y = other.y;
}

// Setter for x
void Point2D::set_x(int val) {
    x = val;
}

// Setter for y
void Point2D::set_y(int val) {
    y = val;
}

// Getter for x
int Point2D::get_x() {
    return x;
}

// Getter for y
int Point2D::get_y() {
    return y;
}

// Overloaded "+=" operator
void Point2D::operator+=(const Point2D& other) {
    x += other.x;
    y += other.y;
}

// Overloaded "*" operator
Point2D& Point2D::operator*(const Point2D& other) {
    int new_x = x * other.x;
    int new_y = y * other.y;
    Point2D* result = new Point2D(new_x, new_y);
    return *result;
}

// Friend function to overload the "<<" operator for output streams
ostream& operator<<(ostream& os, const Point2D& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
