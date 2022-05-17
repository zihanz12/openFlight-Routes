#include "reader.h"
#include <iostream>
#include <queue>
#include "math_helper/lla_to_dis.h"

using namespace std;

int main() {
    Reader* test = new Reader();
    test->ReadAirport("data/test_airports_bfs.dat");
    test->ReadRoute("data/testRoutes.dat");
    cout <<test->graph_->adj_matrix->size()<<"---here is matrix size"<<endl;  

    std::vector<int> test_bfs = test->graph_->bfs(test->graph_,10);

    cout<<"--------------------below is bfs size--------------"<<endl;
    cout<<test_bfs.size() <<endl;
   
    for (int i = 0; i < test_bfs.size(); i++)
    {
        cout<< test_bfs[i];
        cout<< " ";
    } 
    cout<<"-------------------------"<<endl; 
    
    
    delete test;
    return 0;

}