#include <iostream>
#include <string>
class Test
 {
   private:
     QuadroCopterTest qctest;
     WaypointTest wptst;
     WaypointContainerTest wpctst;
      
   public:
     Test();
     ~Test();
     void print();
     int run_all_tests();


}
