#ifndef BLOCKCOURSE_H
#define BLOCKCOURSE_H

#include "Course.h"
#include <string>
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include <iostream>
#include <sstream>

// Course with a block schedule.
class BlockCourse: public Course
{
private:
	Poco::Data::Date startDate;    // Start date of the course.
	Poco::Data::Date endDate;     // End date of the course.
	Poco::Data::Time startTime;  // Start time of the course.
	Poco::Data::Time endTime;   // End time of the course.

public:
	BlockCourse();

	BlockCourse(unsigned int coursekey, std::string title, std::string major,
			float creditPoints, Poco::Data::Date startDate,
			Poco::Data::Date endDate, Poco::Data::Time startTime,
			Poco::Data::Time endTime);

	BlockCourse(BlockCourse &&oldCourse);

	virtual ~BlockCourse();

	const Poco::Data::Date& getEndDate() const;

	const Poco::Data::Time& getEndTime() const;

	const Poco::Data::Date& getStartDate() const;

	const Poco::Data::Time& getStartTime() const;

	std::string getCourseDetail() const override;

	void write(std::ostringstream &os) const override;

	void read(std::istringstream &is) override;
};

#endif // BLOCKCOURSE_H
