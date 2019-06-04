#ifndef PERSON_H
#define PERSON_H
#include <string.h>

class Person {
public:
	Person(int id = 0,const char* name = NULL);
	virtual ~Person();
	int getID() const { return id_; }
	char* getName()const { return name_; }


protected:
	int id_;
	char* name_;
};

#endif
