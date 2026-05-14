// Weekly course implementation.

#include "WeeklyCourse.h"

using namespace std;

WeeklyCourse::WeeklyCourse(unsigned int coursekey, std::string title,
		std::string major, float creditPoints,
		Poco::DateTime::DaysOfWeek dayOfWeek, Poco::Data::Time startTime,
		Poco::Data::Time endTime) :
		Course(coursekey, title, major, creditPoints), dayOfWeek(dayOfWeek),
		startTime(startTime), endTime(endTime)
{
}

WeeklyCourse::~WeeklyCourse()
{
}

WeeklyCourse::WeeklyCourse(WeeklyCourse &&oldCourse) :
		Course(std::move(oldCourse)), dayOfWeek(
				std::move(oldCourse.getDayOfWeek())), startTime(
				std::move(oldCourse.getStartTime())), endTime(
				std::move(oldCourse.getEndTime()))
{
}

Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeek() const
{
	return dayOfWeek;
}

const Poco::Data::Time& WeeklyCourse::getEndTime() const
{
	return endTime;
}

const Poco::Data::Time& WeeklyCourse::getStartTime() const
{
	return startTime;
}

std::string WeeklyCourse::getCourseDetail() const
{
	ostringstream oStream;
	oStream << Course::getCourseDetail();

	oStream << endl << "Day of Week(0 = Sunday): " << dayOfWeek;
	oStream << endl << "Start Time (HH:MM): " << startTime.hour() << ":"
			<< startTime.minute();
	oStream << endl << "End Time (HH:MM): " << endTime.hour() << ":"
			<< endTime.minute();

	return oStream.str();
}

void WeeklyCourse::write(std::ostringstream &os) const
{
	os << "W;";
	Course::write(os);
	os << ';';
	os << dayOfWeek << ';' << startTime.hour() << ':' << startTime.minute()
			<< ';' << endTime.hour() << ':' << endTime.minute();
}

void WeeklyCourse::read(std::istringstream &is)
{
	string dayOfWeek, startTimeHH, startTimeMM, endTimeHH, endTimeMM;
	Course::read(is);
	getline(is, dayOfWeek, ';');
	getline(is, startTimeHH, ':');
	getline(is, startTimeMM, ';');
	getline(is, endTimeHH, ':');
	getline(is, endTimeMM, '\n');

	this->dayOfWeek = Poco::DateTime::DaysOfWeek(stoi(dayOfWeek));
	this->startTime = Poco::Data::Time(stoi(startTimeHH), stoi(startTimeMM), 0);
	this->endTime = Poco::Data::Time(stoi(endTimeHH), stoi(endTimeMM), 0);
}
