#include <iostream>
#include <string>
#include "WayPoint.h"
class Test
 {
   private:
     static const Waypoint[] sample_waypoints;
     QuadroCopterTest qctest;
     WaypointTest wptst;
     WaypointContainerTest wpctst;
      
   public:
     Test();
     ~Test();
     void print();
     int run_all_tests();


}
