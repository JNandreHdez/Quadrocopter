#pragma once
#include <array>
#include "WayPoint.h"
#include <vector>

class WayPointContainer 
{
    template <typename T, size_t n>
    using Container = std::array<T, n>;
    private:
        static const size_t MAX_SIZE = 100;        
        size_t count;

    public:
        Container<WayPoint*, MAX_SIZE> waypoints;
        WayPointContainer();
        WayPointContainer(const WayPointContainer& other);
        WayPointContainer& operator=(const WayPointContainer& other);
        ~WayPointContainer();

        size_t getCount() const;
        void add(const WayPoint& arg);
        void print(bool contentFlag = true) const;
        double distance() const;
        WayPoint& operator[](int index) {
            return *(waypoints[index]);
        }

        // Helper function to set the name of a waypoint at a specific index
        WayPointContainer& name(int index, const std::string& newName) {
            if (index >= 0 && index < count) {
                (*waypoints[index]).name(newName);
            }
            return *this;
        }
};