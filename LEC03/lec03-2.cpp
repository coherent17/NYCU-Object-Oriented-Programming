#include <iostream>
#include "lec03-2.h"

CStr::CStr() { 
	line = NULL; 
} 

/*CStr::CStr(char* cline) { 
	line = cline; 
}*/ 
CStr::CStr(char * word)			//A 
{
    line = new char [strlen(word)+1];
    strcpy(line, word);	
} 

CStr::CStr(const CStr & old)	//B
{
    line = new char [strlen(old.line)+1];
    strcpy(line, old.line);	
}

//CStr::~CStr() {}
CStr::~CStr() 
{
	if (line) 
		delete [] line;
	line = NULL;
	std::cout << "done" << std::endl;
}

void CStr::ShowCStr(){
    std::cout << line << std::endl;
}

