/*
 * Student.h
 *
 *  Created on: 19 May 2026
 *      Author: abhir
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>

class Student
{

private:
	int id;
	std::string name;

public:
	Student();
	virtual ~Student();

	Student(int id, const std::string name);

	void display() const;

	int getId() const;

	std::string getName() const;
};

#endif /* STUDENT_H_ */
