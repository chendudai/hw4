#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "EE_Course.h"
#include "CS_Course.h"
#include <string.h>

class Student : public Person {
public:
	Student(int id = 0,const char* name = NULL, int EE_course_num = 0, int CS_course_num = 0);
	virtual ~Student();
	int getCourseCnt() const;
	int addEE_Course(EE_Course* p_EE_Course);
	int addCS_Course(CS_Course* p_CS_Course);
	int remCourse(int course_num);
	EE_Course* getEE_Course(int EE_course_num) const;
	CS_Course* getCS_Course(int CS_course_num) const;
	int getAvg() const;
	void print() const;

private:
	EE_Course** pEE_courses_arr_;
	int EE_course_num_;
	CS_Course** pCS_courses_arr_;
	int CS_course_num_;


};
#endif
