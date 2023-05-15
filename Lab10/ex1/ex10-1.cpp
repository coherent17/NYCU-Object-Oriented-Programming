// ex10-1.cpp
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Point2D{
    private:
        int x;
        int y;
    public:
        void setX(int _x){x = _x;};
        void setY(int _y){y = _y;};
        bool operator>(const Point2D& P)const{
            if (x > P.x) 
                return true;
            else if (x == P.x && y > P.y)
                return true;
            else{
                return false;
            }
        }

        friend ostream& operator<<(ostream& out, const Point2D& P){
            out << "(" << P.x << ", " << P.y << ")";
            return out;
        }
};

template <class T>
T *new1D(int n){
    T *ret = new T[n];
    return ret;
}

template <class T>
void rand1D(T *vec, int n){
    for(int i = 0; i < n; i++){
        vec[i] = rand() % 10;
    }
}

//for int
template <>
void rand1D(int *vec, int n){
    for(int i = 0; i < n; i++){
        vec[i] = rand() % 10;
    }
}

//for double
template <>
void rand1D(double *vec, int n){
    for(int i = 0; i < n; i++){
        vec[i] = rand()%1000/100.0;
    }
}

//for char
template <>
void rand1D(char *vec, int n){
    for(int i = 0; i < n; i++){
        vec[i] = 65 + rand() % 26;
    }
}

//for Point2D
template <>
void rand1D(Point2D *vec, int n){
    for(int i = 0; i < n; i++){
        vec[i].setX(rand() % 10);
        vec[i].setY(rand() % 10);
    }
}

template <class T>
void display1D(T *vec, int n){
    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

template <>
void display1D(double *vec, int n){
    for(int i = 0; i < n; i++){
        cout << std::fixed << std::setprecision(2) << vec[i] << " ";
    }
    cout << endl;
}

template <class T>
void sort1D(T *vec, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(vec[j] > vec[j + 1]){
                T tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }
}

template<class T>
void analysis(int n){
    T *vec = new1D<T>(n);
    rand1D<T>(vec, n);         
    // for int, 0~9
    // for double, 0.00~9.99, i.e., rand()%1000/100.0
    // for char, A~Z 
    // for Point2D, x: 0~9 y: 0~9
    display1D<T>(vec, n);
    // for double, set the precision with 2
    sort1D<T>(vec, n);
    display1D<T>(vec, n);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    srand(1);
    
    analysis<int>(n);
    analysis<double>(n);
    analysis<char>(n);
    analysis<Point2D>(n);

    return 0;
}
