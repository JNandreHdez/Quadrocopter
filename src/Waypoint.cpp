#include "Waypoint.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <cwchar>
#include <iomanip>

WayPoint::WayPoint()
{
	this->set_name("<Empty>");
	std::cout << "WayPoint::WayPoint()" << std::endl;
}

WayPoint::WayPoint(std::string name, double latitude, double longitude)
{
	if (latitude < -90 || latitude > 90)
		throw std::out_of_range("Latitude must be between -90 and 90");
	if (longitude < -180 || longitude > 180)
		throw std::out_of_range("Longitude must be between -180 and 180");
	// std::cout << "WayPoint::WayPoint(std::string name, double latitude, double longitude)" << std::endl;
	this->set_latitude(latitude);
	this->set_longitude(longitude);
	this->set_name(name);
}

WayPoint::~WayPoint()
{
	//std::cout << "WayPoint::~WayPoint()" << std::endl;
}

std::string WayPoint::get_name() const
{
	return this->name;
}

double WayPoint::get_latitude() const
{
	return this->latitude;
}

double WayPoint::get_longitude() const
{
	return this->longitude;
}

void WayPoint::set_name(const std::string& name)
{
	this->name = name;
}

void WayPoint::set_latitude(double latitude)
{
	this->latitude = latitude;
}

void WayPoint::set_longitude(double longitude)
{
	this->longitude = longitude;
}

std::string WayPoint::to_string() const
{
	std::string result;

	// Convert latitude to DMS notation
	double absLatitude = std::abs(latitude);
	int degreesLat = static_cast<int>(absLatitude);
	double minutesLat = (absLatitude - degreesLat) * 60;
	int secondsLat = static_cast<int>((minutesLat - static_cast<int>(minutesLat)) * 60);

	// Convert longitude to DMS notation
	double absLongitude = std::abs(longitude);
	int degreesLon = static_cast<int>(absLongitude);
	double minutesLon = (absLongitude - degreesLon) * 60;
	int secondsLon = static_cast<int>((minutesLon - static_cast<int>(minutesLon)) * 60);

	// Format the DMS notation
	result += std::to_string(degreesLat) + "°" + std::to_string(static_cast<int>(minutesLat)) + "'" +
		std::to_string(secondsLat) + "\"";
	result += (latitude >= 0 ? "N " : "S ");
	result += std::to_string(degreesLon) + "°" + std::to_string(static_cast<int>(minutesLon)) + "'" +
		std::to_string(secondsLon) + "\"";
	result += (longitude >= 0 ? "E" : "W");

	return result;
}

double WayPoint::distance(const WayPoint& from, const WayPoint& to)
{
	//std::cout << from.to_string() << " to " << to.to_string() << std::endl;
	//std::cout << "from.get_latitude()" << from.get_latitude();
	//std::cout << "from.get_longitude()" << from.get_longitude() << std::endl;
	//std::cout << "to.get_latitude()" << to.get_latitude();
	//std::cout << "to.get_longitude()" << to.get_longitude() << std::endl;
	double lat = radians((from.get_latitude() + to.get_latitude()) / 2.0);
	//std::cout << lat << std::endl;
	double dx = 111.3 * cos(lat) * (from.get_longitude() - to.get_longitude());
	//std::cout << dx << std::endl;
	double dy = 111.3 * (from.get_latitude() - to.get_latitude());
	//std::cout << dy << std::endl;	
	//std::cout << "distance: " << std::sqrt(dx * dx + dy * dy) << std::endl;
	return std::sqrt(dx * dx + dy * dy);

}

std::ostream& operator<<(std::ostream& os, const WayPoint& waypoint) {
	os << waypoint.to_string();
	return os;
}