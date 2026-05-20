#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include <sstream>
#include <map>

// Base class for all course types.
class Course
{
private:
	unsigned int courseKey;      // Unique identifier for the course
	std::string title;          // Title of the course
	unsigned char major;       // Major ID associated with the course
	float creditPoints;       // Credit points assigned to the course

	//Mapping of major IDs to major name
	static std::map<unsigned char, std::string> majorById;

public:
	Course();

	Course(unsigned int coursekey, std::string title, std::string major,
			float creditPoints);

	Course(Course &&oldCourse);

	Course(Course &oldCourse);

	Course& operator=(const Course &other);

	virtual ~Course() = 0;

	unsigned int getCourseKey() const;

	float getCreditPoints() const;

	std::string getMajor() const;

	const std::string& getTitle() const;

	virtual void write(std::ostringstream &os) const = 0;

	virtual void read(std::istringstream &is) = 0;

	virtual std::string getCourseDetail() const = 0;
};

#endif // COURSE_H
