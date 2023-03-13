#include "lec03-1.h"
#include "cstring"

//Constructors
/* version 1 */
CScore::CScore(char * iStr, double *aPts)
{	
	strncpy(name, iStr, 20);
	subj[0] = aPts[0];
	subj[1] = aPts[1];
	subj[2] = aPts[2];
}
/* version 2 */
CScore::CScore(char * iStr)
{
	strncpy(name, iStr, 20);
}
/* version 3 */
CScore::CScore(double * aPts)
{	
	subj[0] = aPts[0];
	subj[1] = aPts[1];
	subj[2] = aPts[2];
}
/* version 4 */
CScore::CScore()
{
	;
}

//Destructor
CScore::~CScore()
{
	;
}

//accessor
char * CScore::getName()
{
	return name;	
} 

//mutator
void CScore::setName(char *iStr) 
{
	strncpy(name, iStr, 20);
}

//member function
double CScore::computeAverage()
{
	return ((subj[0]+subj[1]+subj[2])/3.0);
}

void CScore::setValue(char * iStr, double * aPts)
{
	strncpy(name, iStr, 20);
	subj[0] = aPts[0];
	subj[1] = aPts[1];
	subj[2] = aPts[2];
}
