// Course base-class implementation.
#include "Course.h"
#include <iostream>
std::map<unsigned char, std::string> Course::majorById =
{ };

using namespace std;

Course::Course(unsigned int coursekey, std::string title, std::string major,
		float creditPoints) :
		courseKey(coursekey), title(title), creditPoints(creditPoints)
{
	bool isMajorFound = false;
	for (const auto &entry : majorById)
	{
		if (major == entry.second)
		{
			isMajorFound = true;
			this->major = entry.first;
		}
	}

	if (!isMajorFound)
	{
		majorById['a' + (int) (majorById.size())] = major;
		for (const auto &entry : majorById)
		{
			if (major == entry.second)
			{
				isMajorFound = true;
				this->major = entry.first;
			}
		}
	}

}

Course::Course(Course &&oldCourse) :
		courseKey(std::move(oldCourse.courseKey)), title(
				std::move(oldCourse.title)), major(std::move(oldCourse.major)), creditPoints(
				std::move(oldCourse.getCreditPoints()))
{
}

Course::~Course()
{

}

unsigned int Course::getCourseKey() const
{
	return courseKey;
}

float Course::getCreditPoints() const
{
	return creditPoints;
}

string Course::getMajor() const
{
	return majorById.at(major);
}

const std::string& Course::getTitle() const
{
	return title;
}

Course::Course()
{
}

Course::Course(Course &oldCourse)
{
	this->courseKey = oldCourse.courseKey;
	this->creditPoints = oldCourse.creditPoints;
	this->major = oldCourse.major;
	this->title = oldCourse.title;
}

Course& Course::operator=(const Course &oldCourse)
{
	this->courseKey = oldCourse.courseKey;
	this->creditPoints = oldCourse.creditPoints;
	this->major = oldCourse.major;
	this->title = oldCourse.title;

	return *this;
}

std::string Course::getCourseDetail() const
{
	ostringstream oStream;

	oStream << endl << "Course Key: " << courseKey;
	oStream << endl << "Course Title: " << title;
	oStream << endl << "Course Major: " << getMajor();
	oStream << endl << "Course Credit Points: " << creditPoints;

	return oStream.str();
}

void Course::write(ostringstream &os) const
{
	os << courseKey << ';' << title << ';' << getMajor() << ';' << creditPoints;
}

void Course::read(std::istringstream &is)
{
	string courseKey, major, title, creditPoints;

	getline(is, courseKey, ';');
	getline(is, title, ';');
	getline(is, major, ';');
	getline(is, creditPoints, ';');

	this->courseKey = stoul(courseKey);

	this->title = title;

	bool isMajorFound = false;
	for (const auto &entry : majorById)
	{
		if (major == entry.second)
		{
			isMajorFound = true;
			this->major = entry.first;
		}
	}

	if (!isMajorFound)
	{
		majorById['a' + (int) (majorById.size())] = major;
		for (const auto &entry : majorById)
		{
			if (major == entry.second)
			{
				isMajorFound = true;
				this->major = entry.first;
			}
		}
	}

	this->creditPoints = stof(creditPoints);
}
