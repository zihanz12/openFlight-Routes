#include "Airports.h"
#include <iostream>

Airports::Airports() {
    name_ = "";
    iaia_ = "";
    lat_ = 0;
    lon_ = 0;
    index_ = -1;
    cur_cost = 0;
    from_ = -1;
}
Airports::Airports(std::string setName, std::string setIAIA, double setLat, double setLon, int setIndex) {
    name_ = setName;
    iaia_ = setIAIA;
    lat_ = setLat;
    lon_ = setLon;
    index_ = setIndex;
    cur_cost = 0;
    from_ = -1;
}

Airports::~Airports() {
    name_ = "";
    iaia_ = "";
    lat_ = 0;
    lon_ = 0;
    index_ = -1;
    cur_cost = 0;
}

Airports::Airports(const Airports& other) {
    name_ = other.name_;
    iaia_ = other.iaia_;
    lon_ = other.lon_;
    lat_ = other.lat_;
    index_ = other.index_;
    cur_cost = other.cur_cost;
    from_ = other.from_;
}

std::string Airports::getName() {
    return name_;
}
std::string Airports::getIAIA() {
    return iaia_;
}
double Airports::getLat() {
    return lat_;
}
double Airports::getLon() {
    return lon_;
}
int Airports::getIndex() {
    return index_;
}

bool Airports::operator==(const Airports& other) {
    if (name_ != other.name_ || iaia_ != other.iaia_ || lat_ != other.lat_ || lon_ != other.lon_ || index_ != other.index_) {
        return false;
    }
    return true;
}

bool Airports::operator>(const Airports& other) const {
    return cur_cost > other.cur_cost;
}