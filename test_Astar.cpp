#include "reader.h"
#include <iostream>
#include <queue>
#include "math_helper/lla_to_dis.h"

using namespace std;

int main() {
    Reader* test = new Reader();

    test->ReadAirport("data/airports_original.dat");
    test->ReadRoute("data/routes.dat");

    std::priority_queue<Airports, std::vector<Airports>, std::greater<Airports>>* frontier = new std::priority_queue<Airports, std::vector<Airports>, std::greater<Airports>>;

    Airports* air1 = test->airport_dict[3395];
    Airports* air2 = test->airport_dict[3364];
    stack<Airports> answer1;
    std::map<int, Airports> added1;
    test->graph_->a_star_search(*test->graph_->adj_matrix, *air1, *air2, answer1, test->index_airport, added1);
    // test->graph_->printShortest(answer1);

    cout<<"---------"<<endl;

    Airports* air3 = test->airport_dict[4049];
    Airports* air4 = test->airport_dict[3395];
    stack<Airports> answer2;
    std::map<int, Airports> added2;
    test->graph_->a_star_search(*test->graph_->adj_matrix, *air3, *air4, answer2, test->index_airport, added2);
    // test->graph_->printShortest(answer2);
    

    // cout<<test->graph_->adj_matrix->at(3630).at(3832)<<endl;
    
    delete test;

    return 0;
}