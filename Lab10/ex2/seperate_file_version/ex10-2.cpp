// ex10-2.cpp
#include "Vector.h"
#include "Point2D.h"
#include <iostream>

using namespace std;

template <class T>
void rand1D(T* a,int n){
    for(int i=0;i<n;i++){
        int x = rand() % 10;
        int y = rand() % 10;
        a[i] = T(x,y);
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
     
    Vector<double> dvec(n,1);
    
    double *b = new double[n];
    for (int i=0;i<n;i++) b[i] = i;
    Vector<double> dvec2(n,b);
   
    cout << "dvec = "; dvec.display();  
    cout << "dvec2 = "; dvec2.display(); 
    dvec2 += dvec;
    cout << "new dvec2 = "; dvec2.display(); 
    
    double c = dot(dvec, dvec2); //dot operation
    cout << "dot(dvec, dvec2) = " << c << endl << endl;

    srand(1);    

    Vector<Point2D> vp1(n, Point2D());// Point2D() (x,y) = (1,1)
    Point2D *v = new Point2D[n];
    rand1D<Point2D>(v,n);   //0~9
    Vector<Point2D> vp2(n,v);
    
    cout << "vp1 = "; vp1.display();
    cout << "vp2 = "; vp2.display();
    
    vp2 += vp1; 
    
    cout << "new vp2 = "; vp2.display();
    
    Point2D d = dot(vp1, vp2);
    cout << "dot(vp1, vp2) = " << d << endl;
    
   return 0;
}
