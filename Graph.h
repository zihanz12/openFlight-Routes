#pragma once
#include <vector>
#include <iostream>

#include <unordered_map>
#include "math_helper/lla_to_dis.h"
#include "Airports.h"
#include <map>
#include <functional>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
    public:
        Graph();
        ~Graph();
        std::vector<std::vector<int>> *adj_matrix;
        std::vector<bool> visited_;
        std::vector<int> bfs(Graph * graph ,int start_index);
        std::vector<int> bfsHelper(Graph * graph ,int start_index);
        std::vector<int> neighbors(int airport_index);
        void a_star_search (std::vector<std::vector<int>>& graph,
                            Airports& start,
                            Airports& goal,
                            std::stack<Airports>& cost_sofar,
                            std::map<int, Airports*>& airport_dict, 
                            std::map<int, Airports>& added);
        void printShortest(std::stack<Airports>& cost_sofar);

        int minKey_helper(Graph* graph, std::vector<int> key, std::vector<bool> mstSet);
        void printMST_helper(std::vector<int> parent, Graph * graph, int start_index);
        void primMST(Graph* graph, int start_index);
        
};

