#include "reader.h"
#include <iostream>
#include <vector>
#include <string>
#include "math_helper/lla_to_dis.h"

using namespace std;
int main() {
    Reader* test = new Reader();

    test->ReadAirport("test/test_airports.dat");
    test->ReadRoute("test_routes.dat");

    cout<<""<<endl;
    
    //test name.
    cout<<"Name:"<<endl;
    cout<<test->index_airport[0]->name_<<endl;
    string name0 = test->index_airport[0]->name_;
    string test0 = "Hangzhou Xiaoshan International Airport";
    if (name0 == test0) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[1]->name_<<endl;
    string name1 = test->index_airport[1]->name_;
    string test1 = "Shanghai Pudong International Airport";
    if (name1 == test1) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[2]->name_<<endl;
    string name2 = test->index_airport[2]->name_;
    string test2 = "Beijing Capital International Airport";
    if (name2 == test2) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[3]->name_<<endl;
    string name3 = test->index_airport[3]->name_;
    string test3 = "Chengdu Shuangliu International Airport";
    if (name3 == test3) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[4]->name_<<endl;
    string name4 = test->index_airport[4]->name_;
    string test4 = "San Pedro Airport";
    if (name4 == test4) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[5]->name_<<endl;
    string name5 = test->index_airport[5]->name_;
    string test5 = "Kotoka International Airport";
    if (name5 == test5) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[6]->name_<<endl;
    string name6 = test->index_airport[6]->name_;
    string test6 = "Tamale Airport";
    if (name6 == test6) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    //test IAIA.
    cout<<""<<endl;
    cout<<"IAIA:"<<endl;
    cout<<test->index_airport[7]->iaia_<<endl;
    string name7 = test->index_airport[7]->iaia_;
    string test7 = "NYI";
    if (name7 == test7) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[8]->iaia_<<endl;
    string name8 = test->index_airport[8]->iaia_;
    string test8 = "DJE";
    if (name8 == test8) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }
    
    cout<<"---------------"<<endl;
    cout<<test->index_airport[9]->iaia_<<endl;
    string name9 = test->index_airport[9]->iaia_;
    string test9 = "EBM";
    if (name9 == test9) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[10]->iaia_<<endl;
    string name10 = test->index_airport[10]->iaia_;
    string test10 = "SFA";
    if (name10 == test10) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    //test latitude.
    cout<<""<<endl;
    cout<<"Latitude:"<<endl;
    cout<<test->index_airport[0]->lat_<<endl;
    double name11 = test->index_airport[0]->lat_;
    double test11 = 30.22949982;
    if (name11 == test11) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[1]->lat_<<endl;
    double name12 = test->index_airport[1]->lat_;
    double test12 = 31.14340019;
    if (name12 == test12) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[2]->lat_<<endl;
    double name13 = test->index_airport[2]->lat_;
    double test13 = 40.08010101;
    if (name13 == test13) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    //test longitude.
    cout<<""<<endl;
    cout<<"Longitude:"<<endl;
    cout<<test->index_airport[3]->lon_<<endl;
    double name14 = test->index_airport[3]->lon_;
    double test14 = 103.9469986;
    if (name14 == test14) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[4]->lon_<<endl;
    double name15 = test->index_airport[4]->lon_;
    double test15 = -6.660820007;
    if (name15 == test15) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->index_airport[10]->lon_<<endl;
    double name16 = test->index_airport[10]->lon_;
    double test16 = 10.69099998;
    if (name16 == test16) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<""<<endl;

    delete test;

    test = new Reader();

    cout<<"Routes:"<<endl;

    test->ReadAirport("data/airports_original.dat");
    test->ReadRoute("data/routes.dat");

    cout<<""<<endl;

    //test routes which have edges.
    cout<<"Routes which have edges:"<<endl;
    cout<<test->graph_->adj_matrix->at(3630).at(3832)<<endl;
    int testGraph0 = test->graph_->adj_matrix->at(3630).at(3832);
    if (testGraph0 != 0) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->graph_->adj_matrix->at(619).at(1197)<<endl;
    int testGraph1 = test->graph_->adj_matrix->at(619).at(1197);
    if (testGraph1 != 0) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->graph_->adj_matrix->at(218).at(1346)<<endl;
    int testGraph2 = test->graph_->adj_matrix->at(218).at(1346);
    if (testGraph2 != 0) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    //test routes which have no edges.
    cout<<""<<endl;
    cout<<"Routes which have no edges:"<<endl;
    cout<<test->graph_->adj_matrix->at(218).at(1345)<<endl;
    int testGraph3 = test->graph_->adj_matrix->at(218).at(1345);
    if (testGraph3 == 0) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->graph_->adj_matrix->at(619).at(1196)<<endl;
    int testGraph4 = test->graph_->adj_matrix->at(619).at(1196);
    if (testGraph4 == 0) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }

    cout<<"---------------"<<endl;
    cout<<test->graph_->adj_matrix->at(2025).at(6466)<<endl;
    int testGraph5 = test->graph_->adj_matrix->at(2025).at(6466);
    if (testGraph5 == 0) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }
    
    return 0;
}