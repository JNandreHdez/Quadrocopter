#pragma once
#include <string>

static const double PI = 3.14159265358979323846;
class WayPoint
{
	// Initialization of static const member variable outside the class definition

	private:
		using LOCATION = std::pair<double, double>;
		LOCATION _location;
		std::string _name;

	public :
		// Konstruktor

		WayPoint();
		WayPoint(std::string name, double latitude, double longitude);

		// Destruktor
		~WayPoint() = default;
		
		// Getter
		std::string name() const;
		double latitude() const;
		double longitude() const;

		// Setter
		void name(const std::string&);
		void latitude(double);
		void longitude(double);

		// Methoden
		std::string to_string() const;
		static double distance(const WayPoint& from, const WayPoint& to);
		
		// Operatoren
		// overload << operator to print WayPoint object
		friend std::ostream& operator<<(std::ostream& os, const WayPoint& waypoint);

		static std::string Degree2GMS(double latitude, double longitude) {
			std::string result;
			int lat_deg = static_cast<int>(latitude);
			int lon_deg = static_cast<int>(longitude);
			double lat_min = (latitude - lat_deg) * 60;
			double lon_min = (longitude - lon_deg) * 60;
			double lat_sec = (lat_min - static_cast<int>(lat_min)) * 60;
			double lon_sec = (lon_min - static_cast<int>(lon_min)) * 60;
			result = std::to_string(lat_deg) + "°" + std::to_string(static_cast<int>(lat_min)) + "'" + std::to_string(static_cast<int>(lat_sec)) + "\"N ";
			result += std::to_string(lon_deg) + "°" + std::to_string(static_cast<int>(lon_min)) + "'" + std::to_string(static_cast<int>(lon_sec)) + "\"E";
			return result;
		}
		static double radians(double arg) {
			return arg * PI / 180;
		}		
};
