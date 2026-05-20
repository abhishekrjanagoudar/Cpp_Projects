/*
 * Course.h
 *
 *  Created on: 19 May 2026
 *      Author: abhir
 */

#ifndef COURSE_H_
#define COURSE_H_
#include "Student.h"
#include <vector>
#include <set>
#include <list>
#include <map>

class Course
{
public:
	Course();
	virtual ~Course();

public:

	std::vector<Student> students;
	std::set<std::string> courseCodes;
	std::list<int> attendanceQueue;
	std::map<int, int> studentMarks;
};

#endif /* COURSE_H_ */
