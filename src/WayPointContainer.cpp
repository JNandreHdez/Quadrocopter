#include "WayPointContainer.h"
#include "WayPoint.h"
#include <iostream>

WayPointContainer::WayPointContainer() : count(0) {
    waypoints.fill(nullptr);
}

WayPointContainer::WayPointContainer(const WayPointContainer& other) : count(0) {
    waypoints.fill(nullptr);
    for (size_t i = 0; i < other.count; i++) {
        add(*(other.waypoints[i]));
    }
}

WayPointContainer& WayPointContainer::operator=(const WayPointContainer& other) {
    if (this == &other) {
        return *this;
    }

    // Free existing waypoints
    for (size_t i = 0; i < count; i++) {
        delete waypoints[i];
    }

    waypoints.fill(nullptr);
    count = 0;

    // Copy waypoints from other
    for (size_t i = 0; i < other.count; i++) {
        add(*(other.waypoints[i]));
    }

    return *this;
}

WayPointContainer::~WayPointContainer() {
    for (size_t i = 0; i < count; i++) {
        delete waypoints[i];
    }
}

size_t WayPointContainer::getCount() const {
    return count;
}

void WayPointContainer::add(const WayPoint& arg) {
    if (count >= MAX_SIZE) {
        throw std::out_of_range("Maximum number of waypoints reached");
    }

    waypoints[count] = new WayPoint(arg);
    count++;
}

void WayPointContainer::print(bool contentFlag) const {
    std::cout << "Anzahl Lieferung: " << this->getCount() << std::endl;
    std::cout << "------------" << std::endl;

    for (size_t i = 0; i < count; i++) {
        std::cout << "[" << i << "] Name: " << waypoints[i]->get_name();
        std::cout << " - (";
        if (contentFlag) {
            std::cout << *(waypoints[i]);
        }
        else {
            std::cout << waypoints[i];
        }
        std::cout << ")" << std::endl;
        //std::cout << std::endl;
    }
}

double WayPointContainer::distance() const {
    if (count < 2) {
        return 0.0;
    }

    double distance = 0;
    for (size_t i = 0; i < count - 1; i++) {
		distance += waypoints[i]->distance(*waypoints[i], *waypoints[i + 1]);
	}
    
    return distance;
}