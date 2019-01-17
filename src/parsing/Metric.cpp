#include "Metric.h"
#include <math.h>

#define earthRadiusKm 6371.0

Metric::Metric(string& type){
    this->type = type;
}


// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * M_PI / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / M_PI);
}

float Metric::get_distance(Node& node1, Node& node2){
    float result = 0;
    if (this->type.compare("EUC_2D") == 0) {
        float xd = node1.getX() - node2.getX();
        float yd = node1.getY() - node2.getY();
        result = sqrt( xd*xd + yd*yd);
    }else if (this->type.compare("GEO") == 0){
        double lat1r, lon1r, lat2r, lon2r, u, v;
        lat1r = deg2rad(node1.getX());
        lon1r = deg2rad(node1.getY());
        lat2r = deg2rad(node2.getX());
        lon2r = deg2rad(node2.getY());
        u = sin((lat2r - lat1r)/2);
        v = sin((lon2r - lon1r)/2);
        result = 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
    }
    return result;
}
