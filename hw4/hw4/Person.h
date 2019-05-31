#ifndef PERSON_H
#define PERSON_H

class Person {
public:
	Person(int id, char* name);
	virtual ~Person();
	int getID() const { return id_; }
	char* getName()const { return name_; }


protected:
	int id_;
	char* name_;
};

#endif
