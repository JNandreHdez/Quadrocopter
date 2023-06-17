#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <locale>
#include <cassert>

#include "QuadroCopter.h"
#include "WayPoint.h"
#include "WayPointContainer.h"

int waypoint_class_test() {
  std::cout << "[TEST] WayPoint class test" << std::endl;
  // Test default constructor
  WayPoint wp_01;
  assert(wp_01.name() == "<Empty>");
  assert(wp_01.latitude() == 0.0);
  assert(wp_01.longitude() == 0.0);
  std::cout << "[RESULT] default constructor test passed" << std::endl;

  // Test constructor with parameters
  WayPoint wp_02("Stadt Stuttgart, Schnellzentrum Schlossplatz", 48.778555879487776, 9.180653355900166);
  assert(wp_02.name() == "Stadt Stuttgart, Schnellzentrum Schlossplatz");
  assert(wp_02.latitude() == 48.778555879487776);
  assert(wp_02.longitude() == 9.180653355900166);
  std::cout << "[RESULT] constructor with parameters test passed" << std::endl;

  // Test copy constructor
  WayPoint wp_03(wp_02);
  assert(wp_03.name() == "Stadt Stuttgart, Schnellzentrum Schlossplatz");
  assert(wp_03.latitude() == 48.778555879487776);
  assert(wp_03.longitude() == 9.180653355900166);
  std::cout << "[RESULT] copy constructor test passed" << std::endl;

  // Test assignment operator
  WayPoint wp_04;
  wp_04 = wp_02;
  assert(wp_04.name() == "Stadt Stuttgart, Schnellzentrum Schlossplatz");
  assert(wp_04.latitude() == 48.778555879487776);
  assert(wp_04.longitude() == 9.180653355900166);
  std::cout << "[RESULT] assignment operator test passed" << std::endl;

  // Test all getters
  assert(wp_04.name() == "Stadt Stuttgart, Schnellzentrum Schlossplatz");
  assert(wp_04.latitude() == 48.778555879487776);
  assert(wp_04.longitude() == 9.180653355900166);
  std::cout << "[RESULT] all getters test passed" << std::endl;

  // Test all setters
  wp_04.name("Schwanenapotheke");
  wp_04.latitude(48.77468354911471);
  wp_04.longitude(9.179642427064902);
  assert(wp_04.name() == "Schwanenapotheke");
  assert(wp_04.latitude() == 48.77468354911471);
  assert(wp_04.longitude() == 9.179642427064902);
  std::cout << "[RESULT] all setters test passed" << std::endl;

  // Test all other methods
  assert(wp_04.distance(wp_02) == 0.004);
  std::cout << "[RESULT] all other methods test passed" << std::endl;

  return 0;
}

int waypoint_container_class_test() {

  // Test all constructors
  
  // Test all getters
  
  // Test all setters
  
  // Test all other methods

  return 0;
}

int quadrocopter_class_test() {

  // Test all constructors
  
  // Test all getters
  
  // Test all setters
  
  // Test all other methods

  return 0;
}

 

int long_route_test() {

	std::map<int, WayPoint> deliveries_ext;

	WayPoint home("Home", 47.803368608966835, 9.222155055900785);
	//emplace all waypoints into deliveries_ext until wp_41
	WayPoint wp_01("Stadt Stuttgart, Schnellzentrum Schlossplatz", 48.778555879487776, 9.180653355900166);
	WayPoint wp_02("Schwanenapotheke", 48.77468354911471, 9.179642427064902);
	WayPoint wp_03("Stadt Stuttgart, Schnelltestzentrum Hohe Strasse", 48.777323361696816, 9.169995484735308);
	WayPoint wp_04("Charlotten-Apotheke", 48.77433969698046, 9.186067454053777);
	WayPoint wp_05("Coronastation Koenigsbau-Passagen", 48.77956211190766, 9.177957371240943);
	WayPoint wp_06("Europa Apotheke", 48.773757129065956, 9.175048796383347);
	WayPoint wp_07("Internationale Apotheke", 48.77432626184128, 9.174144911724058);
	WayPoint wp_08("NK Medical Services GmbH - Testzentrum Schillerplatz/Schlossplatz", 48.77763755204808, 9.178668069394567);
	WayPoint wp_09("Schnelltestzentrum Olgaeck des Emma64 Mobiler Pflege-und Sozialdienst", 48.774082550637985, 9.187092284735183);
	WayPoint wp_10("Zahnarztpraxis Dr. Hendrik Putze", 48.771013827025186, 9.1754785405592);
	WayPoint wp_11("15minutentest.de (Testzentrum Dorotheenquartier)", 48.77561408760594, 9.17996766939451);
	WayPoint wp_12("Airbrushtanning", 48.77292572437396, 9.187508198229622);
	WayPoint wp_13("Gesundhaus Apotheke im Milaneo", 48.7910940757532, 9.184606142406075);
	WayPoint wp_14("Privomed GmbH - Corona Buergertestzentrum", 48.77366210521173, 9.184395313570374);
	WayPoint wp_15("Medicare Schnelltestzentrum Stuttgart-Mitte", 48.775954086648234, 9.17710222706492);
	WayPoint wp_16("Zahnarztpraxis Dr. Michael Huss", 48.782050647561476, 9.181806584735433);
	WayPoint wp_17("Teststelle Kronenstrasse", 48.78422960176436, 9.175452813570661);
	WayPoint wp_18("Teststelle Bohnenviertel", 48.7738778098216, 9.18210560007598);
	WayPoint wp_19("Stadt Nizza", 43.710173, 7.261953);
	WayPoint wp_20("Stadt Nantes", 47.218371, -1.553621);
	WayPoint wp_21("Stadt Strasbourg", 48.573405, 7.752111);
	WayPoint wp_22("Stadt Montpellier", 43.610769, 3.876716);
	WayPoint wp_23("Stadt Bordeaux", 44.837789, -0.579180);
	WayPoint wp_24("Stadt Lille", 50.629250, 3.057256);
	WayPoint wp_25("Stadt Rennes", 48.117266, -1.677792);
	WayPoint wp_26("Stadt Reims", 49.258329, 4.031696);
	WayPoint wp_27("Stadt Le Havre", 49.494370, 0.107929);
	WayPoint wp_28("Stadt Saint-Etienne", 45.439695, 4.387177);
	WayPoint wp_29("Stadt Toulon", 43.124228, 5.928000);
	WayPoint wp_30("Stadt Grenoble", 45.188529, 5.724524);
	WayPoint wp_31("Stadt Dijon", 47.322047, 5.041480);
	WayPoint wp_32("Stadt Angers", 47.478419, -0.563166);
	WayPoint wp_33("Stadt Nimes", 43.836699, 4.360054);
	WayPoint wp_34("Stadt Aix-en-Provence", 43.529742, 5.447427);
	WayPoint wp_35("Stadt Rom", 41.902783, 12.496366);
	WayPoint wp_36("Stadt Mailand", 45.465422, 9.185924);
	WayPoint wp_37("Stadt Neapel", 40.851775, 14.268124);
	WayPoint wp_38("Stadt Turin", 45.070312, 7.686856);
	WayPoint wp_39("Stadt Palermo", 38.115688, 13.361267);
	WayPoint wp_40("Stadt Genua", 44.405650, 8.946256);
	WayPoint wp_41("Stadt Bologna", 44.494887, 11.342616);

	deliveries_ext.emplace(1, wp_01);
	deliveries_ext.emplace(2, wp_02);
	deliveries_ext.emplace(3, wp_03);
	deliveries_ext.emplace(4, wp_04);
	deliveries_ext.emplace(5, wp_05);
	deliveries_ext.emplace(6, wp_06);
	deliveries_ext.emplace(7, wp_07);
	deliveries_ext.emplace(8, wp_08);
	deliveries_ext.emplace(9, wp_09);
	deliveries_ext.emplace(10, wp_10);
	deliveries_ext.emplace(11, wp_11);
	deliveries_ext.emplace(12, wp_12);
	deliveries_ext.emplace(13, wp_13);
	deliveries_ext.emplace(14, wp_14);
	deliveries_ext.emplace(15, wp_15);
	deliveries_ext.emplace(16, wp_16);
	deliveries_ext.emplace(17, wp_17);
	deliveries_ext.emplace(18, wp_18);
	deliveries_ext.emplace(19, wp_19);
	deliveries_ext.emplace(20, wp_20);
	deliveries_ext.emplace(21, wp_21);
	deliveries_ext.emplace(22, wp_22);
	deliveries_ext.emplace(23, wp_23);
	deliveries_ext.emplace(24, wp_24);
	deliveries_ext.emplace(25, wp_25);
	deliveries_ext.emplace(26, wp_26);
	deliveries_ext.emplace(27, wp_27);
	deliveries_ext.emplace(28, wp_28);
	deliveries_ext.emplace(29, wp_29);
	deliveries_ext.emplace(30, wp_30);
	deliveries_ext.emplace(31, wp_31);
	deliveries_ext.emplace(32, wp_32);
	deliveries_ext.emplace(33, wp_33);
	deliveries_ext.emplace(34, wp_34);
	deliveries_ext.emplace(35, wp_35);
	deliveries_ext.emplace(36, wp_36);
	deliveries_ext.emplace(37, wp_37);
	deliveries_ext.emplace(38, wp_38);
	deliveries_ext.emplace(39, wp_39);
	deliveries_ext.emplace(40, wp_40);
	deliveries_ext.emplace(41, wp_41);

	// add all waypoints to a container

	QuadroCopter copter_07("QuadroCopter 07", home, "Ultra Long Range Copter", 500);
	for (auto& elem : deliveries_ext)
		copter_07.add(elem.second);

	copter_07.print();

	return 0;
}

int main()
{
	
	// Satz an Wegpunkte für Tests festlegen

	WayPoint wp_01("Stadt Stuttgart, Schnellzentrum Schlossplatz", 48.778555879487776, 9.180653355900166);
	WayPoint wp_02("Schwanenapotheke", 48.77468354911471, 9.179642427064902);
	WayPoint wp_03("Stadt Stuttgart, Schnelltestzentrum Hohe Strasse", 48.777323361696816, 9.169995484735308);
	WayPoint wp_04("Charlotten-Apotheke", 48.77433969698046, 9.186067454053777);
	WayPoint wp_05("Coronastation Koenigsbau-Passagen", 48.77956211190766, 9.177957371240943);
	WayPoint wp_06("Europa Apotheke", 48.773757129065956, 9.175048796383347);
	WayPoint wp_07("Internationale Apotheke", 48.77432626184128, 9.174144911724058);
	WayPoint wp_08("NK Medical Services GmbH - Testzentrum Schillerplatz/Schlossplatz", 48.77763755204808, 9.178668069394567);
	WayPoint wp_09("Schnelltestzentrum Olgaeck des Emma64 Mobiler Pflege-und Sozialdienst", 48.774082550637985, 9.187092284735183);
	WayPoint wp_10("Zahnarztpraxis Dr. Hendrik Putze", 48.771013827025186, 9.1754785405592);
	WayPoint wp_11("15minutentest.de (Testzentrum Dorotheenquartier)", 48.77561408760594, 9.17996766939451);
	WayPoint wp_12("Airbrushtanning", 48.77292572437396, 9.187508198229622);
	WayPoint wp_13("Gesundhaus Apotheke im Milaneo", 48.7910940757532, 9.184606142406075);
	WayPoint wp_14("Privomed GmbH - Corona Buergertestzentrum", 48.77366210521173, 9.184395313570374);
	WayPoint wp_15("Medicare Schnelltestzentrum Stuttgart-Mitte", 48.775954086648234, 9.17710222706492);
	WayPoint wp_16("Zahnarztpraxis Dr. Michael Huss", 48.782050647561476, 9.181806584735433);
	WayPoint wp_17("Teststelle Kronenstrasse", 48.78422960176436, 9.175452813570661);
	WayPoint wp_18("Teststelle Bohnenviertel", 48.7738778098216, 9.18210560007598);

	std::map<int, WayPoint> deliveries;

	deliveries.emplace(std::make_pair(1, wp_01));
	deliveries.emplace(std::make_pair(2, wp_02));
	deliveries.emplace(std::make_pair(3, wp_03));
	deliveries.emplace(std::make_pair(4, wp_04));
	deliveries.emplace(std::make_pair(5, wp_05));
	deliveries.emplace(std::make_pair(6, wp_06));
	deliveries.emplace(std::make_pair(7, wp_07));
	deliveries.emplace(std::make_pair(8, wp_08));
	deliveries.emplace(std::make_pair(9, wp_09));
	deliveries.emplace(std::make_pair(10, wp_10));
	deliveries.emplace(std::make_pair(11, wp_11));
	deliveries.emplace(std::make_pair(12, wp_12));
	deliveries.emplace(std::make_pair(13, wp_13));
	deliveries.emplace(std::make_pair(14, wp_14));
	deliveries.emplace(std::make_pair(15, wp_15));
	deliveries.emplace(std::make_pair(16, wp_16));
	deliveries.emplace(std::make_pair(17, wp_17));
	deliveries.emplace(std::make_pair(18, wp_18));

	WayPoint hq("Head Quarter", 48.803368608966835, 9.222155055900785);

	QuadroCopter copter_01("QuadroCopter 01", hq, "Low Range Copter", 20);
	QuadroCopter copter_02("QuadroCopter 02", hq, "Wide Range Copter", 50);

	for (auto& elem : deliveries)
	{
		copter_01.add(elem.second);
		copter_02.add(elem.second);
	}
	
	copter_01.print();
	
	copter_02.print();
	// Test der Methode print() mit contentFlag = false
	copter_02.print(false);

	// Test für einzelnen Wegpunkt
	QuadroCopter copter_03("QuadroCopter 03", hq, "Mid Range Copter", 35);
	copter_03.add(deliveries[1]);
	copter_03.print();

	// Test für zwei Wegpunkte
	QuadroCopter copter_04("QuadroCopter 04", hq, "Mid Range Copter", 35);
	copter_04.add(deliveries[1]);
	copter_04.add(deliveries[2]);
	copter_04.print();

	// Test auf doppelten Wegpunkt
	QuadroCopter copter_05("QuadroCopter 05", hq, "Mid Range Copter", 35);
	copter_05.add(deliveries[1]);
	copter_05.add(deliveries[1]);

	// Testing if exception is thrown when adding duplicate waypoint consecutively
	copter_05.print();
	
	// Test auf doppelten Wegpunkt
	QuadroCopter copter_06("QuadroCopter 06", hq, "Mid Range Copter", 35);
	copter_06.add(deliveries[1]);
	copter_06.add(deliveries[2]);
	copter_06.add(deliveries[2]);

	const WayPoint wp_1;
	const WayPoint wp_2("Punkt 1", 1.0, 2.0);

	std::cout << wp_1 << std::endl;
	std::cout << wp_2 << std::endl;

	auto* pContainer_1 = new WayPointContainer();
	pContainer_1->add(wp_1);
	pContainer_1->add(wp_2);

	// Testen des parametrierten Waypoint Konstruktors
	assert((*pContainer_1)[1].name() == "Punkt 1");
	assert((*pContainer_1)[1].latitude() == 1.0);
	assert((*pContainer_1)[1].longitude() == 2.0);

	// Testing copy constructor
	auto* pContainer_2 = new WayPointContainer(*pContainer_1);

	// Testing default constructor
	auto* pContainer_3 = new WayPointContainer();
	*pContainer_3 = *pContainer_1;

	// �nderung am ersten Container (Original)
	(*pContainer_1)[0].name("Klaus");
	// Testen der setter und getter
	assert((*pContainer_1)[0].name() == "Klaus");

	// Testing if copy constructor and other test instances are independent from original
	pContainer_1->print();
	pContainer_2->print();
	pContainer_3->print();

	delete pContainer_1;
	delete pContainer_2;
	delete pContainer_3;

	// Testing if Waypoint can be instantiated and passed as home to Copter constructor
	QuadroCopter* pCopter_1 = new QuadroCopter("Flight_01", WayPoint("Nauheimer 83", 48.804034706808196, 9.223216927065636), "Fast Model", 20);

	pCopter_1->print();
	// Teste mit großer Route und überschrittener Reichweite
	long_route_test();

  waypoint_class_test();

	return 0;
}
