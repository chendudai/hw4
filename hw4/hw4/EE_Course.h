#ifndef EE_COURSE_H
#define EE_COURSE_H

#include "Course.h"
#include <string.h>

class EE_Course :public Course {
public:
	EE_Course(int num = 0,const char* name = NULL, int hw_num = 0, double hw_weigh = 0, int factor = 0);
	virtual ~EE_Course();
	int getFactor() const;
	int setFactor(int factor);
	int getCourseGrade() const;
	

protected:
	int factor_;
};


#endif
