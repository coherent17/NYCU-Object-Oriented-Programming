#include <iostream>
#include "lec03-1.h"
using namespace std;

int main()
{
	double dAry[3] = {66, 70, 80};
	//CScore one("Tom", dAry);	//calling one.CScore("Tom", {66, 70, 80});
	//CScore one("Tom");			//calling one.CScore("Tom");
	//CScore one(dAry);			//calling one.CScore({66, 70, 80});
	CScore one;					//calling one.CScore();
	cout << "[one] " << one.getName() << " : " << one.computeAverage() << endl;

	static CScore two;
	cout << "[two] " << two.getName() << " : " << two.computeAverage() << endl;

	return 0;
}
