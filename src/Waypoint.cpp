#include "WayPoint.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <cwchar>
#include <iomanip>

WayPoint::WayPoint()
{
	this->name("<Empty>");
}

WayPoint::WayPoint(std::string name, double latitude, double longitude)
{
	if (latitude < -90 || latitude > 90)
		throw std::out_of_range("Latitude must be between -90 and 90");
	if (longitude < -180 || longitude > 180)
		throw std::out_of_range("Longitude must be between -180 and 180");
	
	this->latitude(latitude);
	this->longitude(longitude);
	this->name(name);
}

std::string WayPoint::name() const
{
	return this->_name;
}

double WayPoint::latitude() const
{
	return this->_location.first;
}

double WayPoint::longitude() const
{
	return this->_location.second;
}

void WayPoint::name(const std::string& name)
{
	this->_name = name;
}

void WayPoint::latitude(double latitude)
{
	this->_location.first = latitude;
}

void WayPoint::longitude(double longitude)
{
	this->_location.second = longitude;
}

std::string WayPoint::to_string() const
{
	std::string result;

	// Convert latitude to DMS notation
	double absLatitude = std::abs(this->latitude());
	int degreesLat = static_cast<int>(absLatitude);
	double minutesLat = (absLatitude - degreesLat) * 60;
	int secondsLat = static_cast<int>((minutesLat - static_cast<int>(minutesLat)) * 60);

	// Convert longitude to DMS notation
	double absLongitude = std::abs(this->longitude());
	int degreesLon = static_cast<int>(absLongitude);
	double minutesLon = (absLongitude - degreesLon) * 60;
	int secondsLon = static_cast<int>((minutesLon - static_cast<int>(minutesLon)) * 60);

	// Format the DMS notation
	result += std::to_string(degreesLat) + "°" + std::to_string(static_cast<int>(minutesLat)) + "'" +
		std::to_string(secondsLat) + "\"";
	result += (latitude() >= 0 ? "N " : "S ");
	result += std::to_string(degreesLon) + "°" + std::to_string(static_cast<int>(minutesLon)) + "'" +
		std::to_string(secondsLon) + "\"";
	result += (longitude() >= 0 ? "E" : "W");

	return result;
}

double WayPoint::distance(const WayPoint& from, const WayPoint& to)
{
	// check if from and to are valid

	double lat = radians((from.latitude() + to.latitude()) / 2.0);
	double dx = 111.3 * cos(lat) * (from.longitude() - to.longitude());
	double dy = 111.3 * (from.latitude() - to.latitude());
	return std::sqrt(dx * dx + dy * dy);

}

std::ostream& operator<<(std::ostream& os, const WayPoint& waypoint) {
	// Prüfe ob longitude und latitude gültige Werte haben
	if (waypoint.latitude() < -90 || waypoint.latitude() > 90 || waypoint.longitude() < -180 || waypoint.longitude() > 180) {
		// if waypoint has a name, print it
		if (waypoint.name() != "<Empty>") {
			os << waypoint.name() << ": ";
		}
		os << "Invalid latitude or longitude";
	}
	else {
		os << waypoint.to_string();
	}
	return os;
}
