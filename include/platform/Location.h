#ifndef LOCATION_H
#define LOCATION_H

#include <cmath>

class Location {
private:
    double latitude;
    double longitude;

public:
    Location(double latitude = 0.0, double longitude = 0.0) 
        : latitude(latitude), longitude(longitude) {}

    double calculateDistance(const Location& other) const {
        // Exemple simplifié de calcul de distance
        return std::sqrt(std::pow(latitude - other.latitude, 2) + 
                         std::pow(longitude - other.longitude, 2));
    }

    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

    void setLatitude(double latitude) { this->latitude = latitude; }
    void setLongitude(double longitude) { this->longitude = longitude; }
};

#endif // LOCATION_H
