#include <iostream>
#include "Proj.h"
#include "Course.h"
#include "EE_Course.h"
#include "CS_Course.h"

using std::cout;
using std::endl;

int main() {
	// default Course c'tor TEST
	char* str;
	Course C2;
	cout << "C2 Num: "<< C2.getNum() << endl;
	str = C2.getName(); 
	//cout << "C2 Name: " << str << endl;
	//delete[] str;
	// c'tor TEST
	Course C(445, "my course", 5, 0.35);
	C.setExamGrade(90);
	C.setHwGrade(0,100); C.setHwGrade(1,100); C.setHwGrade(2,80);
	C.setHwGrade(3,80); C.setHwGrade(4,50);
	cout << "C Num: " << C.getNum() << endl;

	str = C.getName();  cout << "C Name: " << str << endl; delete[] str;
	cout << "C hw num: " << C.getHwNum() << endl;
	cout << "C hw weigh: " << C.getHwWeigh() << endl;
	cout << "C exam grade: " << C.getExamGrade() << endl;
	cout << "C hw second grade: " << C.getHwGrade(1) << endl;
	cout << "C hw average: " << C.getHwAverage() << endl;
	cout << "C course grade: " << C.getCourseGrade() << endl;
	cout << "C END" << endl << endl;
	
	// default EE_Course c'tor TEST
	EE_Course EEC2;
	cout << "EEC2 Num: " << EEC2.getNum() << endl;
	//str = EEC2.getName();  cout << "EEC2 Name: " << str << endl<< endl; delete[] str;

	//EE c'tor TEST
	EE_Course EEC(151, "bla bla", 5, 0.35);
	EEC.setExamGrade(90);
	EEC.setHwGrade(0, 100); EEC.setHwGrade(1, 100); EEC.setHwGrade(2, 80);
	EEC.setHwGrade(3, 80); EEC.setHwGrade(4, 50);
	cout << "EEC Num: " << EEC.getNum() << endl;
	str = EEC .getName();  cout << "EEC Name: " << str << endl; delete[] str;
	cout << "EEC hw num: " << EEC.getHwNum() << endl;
	cout << "EEC hw weigh: " << EEC.getHwWeigh() << endl;
	cout << "EEC exam grade: " << EEC.getExamGrade() << endl;
	cout << "EEC hw second grade: " << EEC.getHwGrade(1) << endl;
	cout << "EEC hw average: " << EEC.getHwAverage() << endl;
	cout << "EEC factor: " << EEC.getFactor() << endl;
	cout << "EEC course grade (no factor): " << EEC.getCourseGrade() << endl;
	EEC.setFactor(5);
	cout << "EEC factor: " << EEC.getFactor() << endl;
	cout << "EEC course grade (with factor): " << EEC.getCourseGrade() << endl;
	EEC.setFactor(15);
	cout << "EEC factor: " << EEC.getFactor() << endl;
	cout << "EEC course grade>100 (with factor): " << EEC.getCourseGrade() << endl;
	cout << "EEC END" << endl << endl;
	
	//CS c'tor TEST
	CS_Course CSC(3008, "mashmo", 5, 0.35, 0,"book of bullshit");
	CSC.setExamGrade(90);
	CSC.setHwGrade(0, 100); CSC.setHwGrade(1, 100); CSC.setHwGrade(2, 80);
	CSC.setHwGrade(3, 80); CSC.setHwGrade(4, 50);
	cout << "CSC Num: " << CSC.getNum() << endl;
	str = CSC.getName(); cout << "CSC Name: " << str << endl; delete[] str;
	str = CSC.getBook(); cout << "CSC Book: " << str << endl; delete[] str;
	cout << "CSC hw num: " << CSC.getHwNum() << endl;
	cout << "CSC hw weigh: " << CSC.getHwWeigh() << endl;
	cout << "CSC exam grade: " << CSC.getExamGrade() << endl;
	cout << "CSC hw second grade: " << CSC.getHwGrade(1) << endl;
	cout << "CSC hw average: " << CSC.getHwAverage() << endl;
	cout << "CSC Magen or Takef: " << CSC.isTakef() << endl;
	cout << "CSC course grade (magen): " << CSC.getCourseGrade() << endl;
	CSC.setBook("bambuzled"); 
	str = CSC.getBook();
	cout << "CSC Book: " << str << endl;
	delete[] str;
	CSC.setTakef(1);
	cout << "CSC Magen or Takef: " << CSC.isTakef() << endl;
	cout << "CSC course grade (takef): " << CSC.getCourseGrade() << endl;
	cout << "CSC END" << endl << endl;
	
	return 0;
}