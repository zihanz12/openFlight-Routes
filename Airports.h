#pragma once
#include <string>

class Airports {
    public:
        Airports();
        Airports(std::string setName, std::string setIAIA, double setLat, double setLon, int setIndex);
        ~Airports();
        Airports(const Airports& other);
        std::string getName();
        std::string getIAIA();
        double getLat();
        double getLon();
        int getIndex();
        bool operator==(const Airports& other);
        bool operator>(const Airports& other) const;

        std::string name_;
        std::string iaia_;
        double lat_;
        double lon_;
        int index_;
        double cur_cost;
        int from_;
};

