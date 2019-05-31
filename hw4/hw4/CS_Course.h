#ifndef CS_COURSE_H
#define CS_COURSE_H

#include "Course.h"

class CS_Course :public Course {
public:
	CS_Course(int num, char* name, int hw_num, double hw_weigh, bool isTakef, char* book);
	virtual ~CS_Course();
	int isTakef() const;
	int setTakef(int isTakef);
	void setBook(char* book);
	int getCourseGrade() const;


protected:
	bool isTakef_;
	char* book_;
};

#endif