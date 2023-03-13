#ifndef _LEC03_1_H__
#define _LEC03_1_H__

class CScore {
private:
	char name[20];
	double subj[3];
public:
	//constructor and destructor
	CScore();
	CScore(char *, double *);
	CScore(char *);
	CScore(double *);
	~CScore();
	//accessor and mutator
	char * getName();	 
	void setName(char *);
	//member function
	double computeAverage();
	void setValue(char *, double *);
};

#endif
