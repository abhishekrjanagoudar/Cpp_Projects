#ifndef SIMPLEUI_H
#define SIMPLEUI_H

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include "StudentDb.h"
#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include "WeeklyCourse.h"
#include "BlockCourse.h"

// Small command-line UI wrapper.
class SimpleUI
{
private:
	StudentDb *database;

	Poco::Data::Date getDateFromUser(std::string str) const;

	Poco::Data::Time getTimeFromUser(std::string str) const;

	void addCourse();

	void listCourses() const;

	void addStudent();

	void addEnrollment();

	void printStudent(int matrikelNo) const;

	void searchStudent() const;

	void updateStudent();

	void saveDatabase() const;

	void loadDatabase();

public:
	SimpleUI(StudentDb *db);

	void run();
};

#endif // SIMPLEUI_H
