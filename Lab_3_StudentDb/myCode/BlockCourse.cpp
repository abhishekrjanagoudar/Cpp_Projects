// Block course implementation.
#include "BlockCourse.h"

using namespace std;

BlockCourse::BlockCourse(unsigned int coursekey, std::string title,
		std::string major, float creditPoints, Poco::Data::Date startDate,
		Poco::Data::Date endDate, Poco::Data::Time startTime,
		Poco::Data::Time endTime) :
		Course(coursekey, title, major, creditPoints), startDate(startDate), endDate(
				endDate), startTime(startTime), endTime(endTime)
{

}

BlockCourse::~BlockCourse()
{

}

BlockCourse::BlockCourse(BlockCourse &&oldCourse) :
		Course(std::move(oldCourse)), startDate(
				std::move(oldCourse.getStartDate())), endDate(
				std::move(oldCourse.getEndDate())), startTime(
				std::move(oldCourse.getStartTime())), endTime(
				std::move(oldCourse.getEndTime()))
{
}

const Poco::Data::Date& BlockCourse::getEndDate() const
{
	return endDate;
}

const Poco::Data::Time& BlockCourse::getEndTime() const
{
	return endTime;
}

const Poco::Data::Date& BlockCourse::getStartDate() const
{
	return startDate;
}

const Poco::Data::Time& BlockCourse::getStartTime() const
{
	return startTime;
}

BlockCourse::BlockCourse()
{
}

std::string BlockCourse::getCourseDetail() const
{
	ostringstream oStream;
	oStream << Course::getCourseDetail();

	oStream << endl << "Start date(dd.mm.yyyy): " << startDate.day() << "."
			<< startDate.month() << "." << startDate.year();
	oStream << endl << "End date(dd.mm.yyyy): " << endDate.day() << "."
			<< endDate.month() << "." << endDate.year();
	oStream << endl << "Start Time (HH:MM): " << startTime.hour() << ":"
			<< startTime.minute();
	oStream << endl << "End Time (HH:MM): " << endTime.hour() << ":"
			<< endTime.minute();

	return oStream.str();
}

void BlockCourse::write(std::ostringstream &os) const
{
	os << "B;";
	Course::write(os);
	os << ';';
	os << startDate.day() << '.' << startDate.month() << '.' << startDate.year()
			<< ';' << endDate.day() << '.' << endDate.month() << '.'
			<< endDate.year() << ';' << startTime.hour() << ':'
			<< startTime.minute() << ';' << endTime.hour() << ':'
			<< endTime.minute();
}

void BlockCourse::read(std::istringstream &is)
{
	string startDateDD, startDateMM, startDateYY, endDateDD, endDateMM,
			endDateYY, startTimeHH, startTimeMM, endTimeHH, endTimeMM;
	Course::read(is);
	getline(is, startDateDD, '.');
	getline(is, startDateMM, '.');
	getline(is, startDateYY, ';');
	getline(is, endDateDD, '.');
	getline(is, endDateMM, '.');
	getline(is, endDateYY, ';');

	getline(is, startTimeHH, ':');
	getline(is, startTimeMM, ';');
	getline(is, endTimeHH, ':');
	getline(is, endTimeMM, '\n');

	this->startDate = Poco::Data::Date(stoi(startDateYY), stoi(startDateMM),
			stoi(startDateDD));
	this->endDate = Poco::Data::Date(stoi(endDateYY), stoi(endDateMM),
			stoi(endDateDD));
	this->startTime = Poco::Data::Time(stoi(startTimeHH), stoi(startTimeMM), 0);
	this->endTime = Poco::Data::Time(stoi(endTimeHH), stoi(endTimeMM), 0);
}
