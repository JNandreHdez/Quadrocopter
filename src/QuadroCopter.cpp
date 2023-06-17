#include "QuadroCopter.h"
#include <iostream>
#include <string>
#include <iomanip>

QuadroCopter::QuadroCopter(const std::string& name, const WayPoint& home, const std::string& model, double range) {
    m_name = name;
	m_home = home;
	configure(model, range);
}

void QuadroCopter::configure(const std::string& model, double range)
{
	m_model = model;
	m_range = range;
}

void QuadroCopter::add(const WayPoint& arg)
{
    m_container.add(arg);
}

double QuadroCopter::distance() const
{
    double total_distance = 0.0;
    int count = m_container.getCount();
    if (count) {        
        double home_to_first = WayPoint::distance(m_home, *m_container.waypoints[0]);
        double last_to_home = WayPoint::distance(*m_container.waypoints[m_container.getCount() - 1], m_home);
        // mehr als ein Wegpunkt? Geamtdistanz als Startpunkt -> alle Wegpunkte -> Startpunkt
        // sonst: Shtartpunkt -> Wegpunkt -> Startpunkt
        total_distance += (count > 1) ? (home_to_first + m_container.distance() + last_to_home) : 2 * home_to_first;
    }
    
    return total_distance;
}

void QuadroCopter::print(bool contentFlag) const
{
    // Set the global C++ locale to the user's default locale
    std::locale::global(std::locale(""));

    // Enable the Unicode output for the console
    std::wcout.imbue(std::locale());

    std::cout << std::endl << "QuadroCopter: " << m_name << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "    Modell: " << m_model << std::endl;
    std::cout << "Reichweite: " << m_range << " km" << std::endl;
    std::cout << " Heimatort: " << m_home.name() << std::endl;
    std::cout << "------------" << std::endl;    
    
    int count = m_container.getCount();
    if (!count) {		
        std::cout << "Keine Wegpunkte vorhanden!" << std::endl;
    }
    
    m_container.print(contentFlag);

    if (contentFlag && (m_container.getCount() >= 1)) {
        double _distance = distance();
        std::cout << std::endl << "Gesamte Distanz: " << _distance << std::endl;
        if (_distance < this->m_range) {
            std::cout << "Strecke kann geflogen werden!" << std::endl;
        }
        else {
            std::cout << "Reichweite: " << this->m_range << "km" << std::endl;
			std::cout << "Strecke von " << _distance << "km ist zu lang!" << std::endl;
		}
    }    
}