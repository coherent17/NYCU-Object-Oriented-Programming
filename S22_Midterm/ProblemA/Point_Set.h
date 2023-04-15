#ifndef _POINT_SET_H_
#define _POINT_SET_H_
#include <string>

using namespace std;

struct Point{
    double x = 0;
    double y = 0;
    string name = "";
};

class Point_Set{
    private:
        int num;
        Point *points;
        string name;
    public:
    // A01
    Point_Set();
    ~Point_Set();
    void Parser(string);
    friend void DisplayPointSet(const Point_Set &);

    // A02
    void operator+=(const double &);
    void operator*=(const double &);

    // A03
    void fit(double &, double &);
    double* predict(const double &, const double &);
};

#endif