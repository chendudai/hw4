#ifndef STARRAY_H
#define STARRAY_H

#include "Student.h"

class StArray {
public:
	StArray();
	virtual ~StArray();
	int addStudent(int id, char* name);
	int addEE_Course(int id, int course_num, char* course_name, int hw_num, double hw_weigh);
	int addCS_Course(int id, int course_num, char* course_name, int hw_num, double hw_weigh, bool isTakef, char* book);
	int setHwGrade(int id, int course_num, int hw_num_order, int grade);
	int setExamGrade(int id, int course_num, int exam_grade);
	int setFactor(int course_num, int factor);
	int printStudent(int id);
	void printAll();
	void resetStArray();

private:
	Student** pSt_arr_;
	int St_num_;
};

#endif 
