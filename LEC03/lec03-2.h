#ifndef _LEC03_2_H__
#define _LEC03_2_H__

class CStr
{
private:
    char * line;			//default access is private 
public:    
    CStr();				//default constructor
	CStr(char *);		//A
    CStr(const CStr &); //B
	~CStr();
    void ShowCStr();
};

#endif
