#include <string.h>
#include "Person.h"

Person::Person(int id, const char* name) :
	id_(id) {
	if (name != NULL)
	{
		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);
	}
}

Person::~Person()
{
	if (name_ != NULL)
	{
		delete [] name_;
	}
}
