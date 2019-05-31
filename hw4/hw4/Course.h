#ifndef COURSE_H
#define COURSE_H

class Course {
public:
	Course (int num, char* name, int hw_num, double hw_weigh);
	virtual ~Course();
	int getNum() const;
	char* getName() const;
	int getExamGrade() const;
	int getHwGrade(int hw_num) const;
	int getHwNum() const;
	double  getHwWeigh() const;
	double getHwAverage() const;
	virtual int getCourseGrade() const;
	int setExamGrade(int grade);
	int setHwGrade(int hw_num, int grade);

protected:
	int num_;
	char* name_;
	int hw_num_;
	double hw_weigh_;
	int exam_grade_;
	int* hw_grades_;
};

#endif
