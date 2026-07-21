#ifndef WEEKLYCOURSE_H
#define WEEKLYCOURSE_H

#include <Poco/Data/Time.h>
#include "Course.h"
#include <string>
#include <iostream>
#include <sstream>
#include <Poco/DateTime.h>

// Course that repeats weekly.
class WeeklyCourse: public Course
{
private:
	Poco::DateTime::DaysOfWeek dayOfWeek; // DoW when the course is held.
	Poco::Data::Time startTime; 		 //Start time of the course.
	Poco::Data::Time endTime; 			// End time of the course.

public:
	WeeklyCourse(unsigned int coursekey, std::string title, std::string major,
			float creditPoints, Poco::DateTime::DaysOfWeek dayOfWeek,
			Poco::Data::Time startTime, Poco::Data::Time endTime);

	virtual ~WeeklyCourse();

	WeeklyCourse(WeeklyCourse &&oldCourse);

	Poco::DateTime::DaysOfWeek getDayOfWeek() const;

	const Poco::Data::Time& getEndTime() const;

	const Poco::Data::Time& getStartTime() const;

	std::string getCourseDetail() const override;

	void write(std::ostringstream &os) const override;

	void read(std::istringstream &is) override;
};

#endif // WEEKLYCOURSE_H
