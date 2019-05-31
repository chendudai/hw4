#ifndef EE_COURSE_H
#define EE_COURSE_H

#include "Course.h"

class EE_Course :public Course {
public:
	EE_Course(int num, char* name, int hw_num, double hw_weigh, int factor);
	virtual ~EE_Course();
	int getFactor() const;
	int setFactor(int factor);
	int getCourseGrade() const;
	

protected:
	int factor_;
};


#endif
