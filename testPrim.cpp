#include "reader.h"
#include <iostream>
#include <queue>
#include "math_helper/lla_to_dis.h"

using namespace std;

int main() {
    Reader* test = new Reader();
    test->ReadAirport("data/test_airports_prim.dat");
    test->ReadRoute("data/testRoutes.dat");
    cout<<"test one: start from vertex index 0"<<endl;
    test->graph_->primMST(test->graph_,0);
    cout<<"test two: start from vertex index 1"<<endl;
    test->graph_->primMST(test->graph_,1);
    delete test;
    return 0;
}