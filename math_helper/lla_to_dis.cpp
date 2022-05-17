#include "lla_to_dis.h"
#include <cmath>
#define pi 3.14159265358979323846
using namespace std;

double calculateDistance(double lat1, double long1, double lat2, double long2) {
    double dist;
    dist = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2);
    dist = acos(dist);
    dist = (6371 * pi * dist) / 180;
    return dist;
}