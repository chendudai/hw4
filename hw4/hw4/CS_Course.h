#ifndef CS_COURSE_H
#define CS_COURSE_H

#include "Course.h"
#include <string.h>

class CS_Course :public Course {
public:
	CS_Course(int num = 0,const char* name = NULL, int hw_num = 0, double hw_weigh = 0, bool isTakef = false,const char* book = NULL);
	virtual ~CS_Course();
	int isTakef() const;
	char* getBook() const;
	int setTakef(int isTakef);
	void setBook(const char* book);
	int getCourseGrade() const;


protected:
	bool isTakef_;
	char* book_;
};

#endif