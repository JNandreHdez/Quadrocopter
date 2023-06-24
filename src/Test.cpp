#include "Test.h"

Test::Test() {
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
        WayPoint wp_41("Stadt Bologna", 44.494887, 11.342616);i
        // emplace all waypoints into  
}

Test::run_all_test() {
  wp.test();
  wpc.test();
  qc.test();
  cout << "Tests passed!"
}
