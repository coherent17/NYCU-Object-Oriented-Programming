//lec03-3.cpp

class CPoint {
    int x, y;
public:    
    CPoint() { x=0; y=0; }
    CPoint(int a, int b) { x=a; y=b; } 

	//Q2 Solution B: add copy constructor
	CPoint(const CPoint &old) { x=old.x; y=old.y; } 

    void set(int a, int b) { x=a; y=b; }
    void move(int a, int b) { x+=a; y+=b; }
};

class CRect { 
    CPoint p1;		//original
	CPoint p2;		//original	
    //CPoint p1(0,0);		//Q1@p36
	//CPoint p2(0,0);		//Q1@p36

public:    
    CRect() { 
		p1.set(0,0); 
		p2.set(0,0);
	}
	/*//Q2@p36
    CRect(int a, int b, int c, int d) { 
		p1(a,b);		
		p2(c,d);
	}*/
	
	/*//Q2 Solution A: call mutator and =
    CRect(int a, int b, int c, int d) { 
	    p1.set(a,b);	
		p2.set(c,d);	
	}
    CRect(const CPoint &q1, const CPoint &q2){ 
        p1 = q1;		
		p2 = q2;
	}*/ 

	//Q2 Solution B: use initialization
	CRect(int a, int b, int c, int d) : 
        p1(a,b), p2(c,d) { }
    CRect(const CPoint &q1, const CPoint &q2) :   
		p1(q1), p2(q2) {} 
	
};


