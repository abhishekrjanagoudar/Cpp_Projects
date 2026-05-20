/*
 * University.h
 *
 *  Created on: 19 May 2026
 *      Author: abhir
 */

#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_
#include "Course.h"
#include <memory>

class University
{

private:
	std::unique_ptr<Course> course;
	std::shared_ptr<Student> topper;

public:
	University();
	virtual ~University();

	void setup();

	void display();
};

#endif /* UNIVERSITY_H_ */
