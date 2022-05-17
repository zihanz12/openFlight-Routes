#include "Airports.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include "Graph.h"
#include "math_helper/lla_to_dis.h"
using namespace std;

class Reader {
    public: 
        std::map<int, Airports*> airport_dict; 
        std::map<int, Airports*> index_airport;
        void ReadAirport(std::string filePath);
        void ReadRoute(std::string filePath);
        Reader();
        ~Reader();
        Graph* graph_;
};

