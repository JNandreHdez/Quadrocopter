#include "QuadroCopter.h"
#include <iostream>
#include <string>

QuadroCopter::QuadroCopter(const std::string& name, const WayPoint& home, const std::string& model, double range) {
    m_name = name;
	m_home = home;
	m_model = model;
	m_range = range;
}

void QuadroCopter::add(const WayPoint& arg)
{
    m_container.add(arg);
}

double QuadroCopter::distance() const
{
    return m_container.distance();
}

void QuadroCopter::print() const
{
    // Set the global C++ locale to the user's default locale
    std::locale::global(std::locale(""));

    // Enable the Unicode output for the console
    std::wcout.imbue(std::locale());

    std::cout << std::endl << "QuadroCopter: " << m_name << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "Modell: " << m_model << std::endl;
    std::cout << "Reichweite: " << m_range << " km" << std::endl;
    std::cout << "Heimatort: " << m_home.get_name() << std::endl;
    std::cout << "------------" << std::endl;    
    
    double home_to_first = m_home.distance(m_home, *m_container.waypoints[0]);
    double last_to_home = m_container.waypoints[m_container.getCount() - 1]->distance(*m_container.waypoints[m_container.getCount() - 1], m_home);
    double total_distance = home_to_first + distance() + last_to_home;
    m_container.print();

    if (m_container.getCount() > 1) {
        double totalDistance = distance();
        std::cout << std::endl << "Gesamte Distanz: " << total_distance << std::endl;
    }    
}