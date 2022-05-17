#include "reader.h"

Reader::Reader() {
    graph_ = new Graph(); //delete?
}

Reader::~Reader() {
    delete graph_;
}

void Reader::ReadAirport(std::string filePath) {
    std::ifstream infile(filePath);
    string line;
    int count = 0;
    // data format: unique id, name, IATA, lat, long
    if (infile.is_open()) {
        while (getline(infile, line)) {
            std::vector<string> vec;
            string str = "";
            bool isquote = false;
            // read comma seperated file line bt line;
            for (auto& c : line) {
                switch (c) {
                    case '\"':
                        isquote = !isquote;
                        break;   //
                    case ',':
                        if (!isquote) {
                            vec.push_back(str);
                            str = "";
                        }
                        break;
                    default:
                        str += c;
                }
            }
            vec.push_back(str);
            airport_dict[std::stoi(vec[0])] = new Airports(vec[1], vec[2], std::stod(vec[3]), std::stod(vec[4]), count); 
            index_airport[count] = new Airports(vec[1], vec[2], std::stod(vec[3]), std::stod(vec[4]), count);
            // map key: aiport id;
            
            /*if (count == 292) {
                std::cout<<line<<std::endl;
                std::cout<< vec[0]<<" ID"<<std::endl;
                std::cout<< vec[1]<<std::endl;
                std::cout<< vec[2]<<std::endl;
                std::cout<< vec[3]<<std::endl;    
                std::cout<<"-----------"<<std::endl;
            } */
            count++;
        }
        graph_->adj_matrix->resize(airport_dict.size(), std::vector<int>(airport_dict.size()));  //here we resize by zihan
        //std::vector<bool> visited_(graph_->adj_matrix->size(), false);  // here we resize;  .. 20211207/3:07
        graph_->visited_= vector<bool>(airport_dict.size());
        std::cout<<count<<"----Aiports number"<<std::endl; 
    }
}


void Reader::ReadRoute(std::string filePath) {
    std::ifstream infile(filePath);
    string line;
    int count = 0;
    // departure id, destination id
    if (infile.is_open()) {
        while (getline(infile, line)) {
            count++;
            std::vector<string> vec;
            string str = "";
            for (auto& c : line) {
                switch (c) {
                    case ',':
                        vec.push_back(str);
                        str = "";
                        break;
                    default:
                        str += c;
                }
            }
            vec.push_back(str);
            // if airport ID is not found in dictionary, romove this route
            if (!airport_dict.count(std::stoi(vec[0])) || !airport_dict.count(std::stoi(vec[1]))) continue;
            // update adjacency matrix
            int index1 = airport_dict.at(std::stoi(vec[0]))->index_;
            int index2 = airport_dict.at(std::stoi(vec[1]))->index_;
            
            // if (count == 20037) {
            //     cout<<"find it!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            //     cout<<line<<endl;
            //     cout<<index1<<"index1"<<endl;
            //     cout<<index2<<"index2"<<endl;
            // }
            
            // if (graph_->adj_matrix->at(index1).at(index2) != 0) continue;
            double lat1, long1, lat2, long2;
            lat1 = airport_dict.at(std::stoi(vec[0]))->lat_;
            long1 = airport_dict.at(std::stoi(vec[0]))->lon_;
            lat2 = airport_dict.at(std::stoi(vec[1]))->lat_;
            long2 = airport_dict.at(std::stoi(vec[1]))->lon_;
            int weight = calculateDistance(lat2, long2, lat1, long1);
            graph_->adj_matrix->at(index1).at(index2) = weight;
            
            graph_->adj_matrix->at(index2).at(index1) = weight;   // matrix need to be symmetric

            /*if (count == 0) {
                std::cout<< std::stoi(vec[0])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[0]))->name_<<std::endl;
                std::cout<< std::stoi(vec[1])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[1]))->name_<<std::endl;
                std::cout<<"index1: ";
                std::cout<<index1<<std::endl;
                std::cout<<"index2: ";
                std::cout<<index2<<std::endl;
                std::cout<<"weight: ";
                std::cout<<weight<<std::endl;
                std::cout<<"--------------"<<std::endl;
                //std::cout<<graph_->adj_matrix->at(210).at(204)<<std::endl;
                //count++;           
            }
            if (count == 1) {
                std::cout<< std::stoi(vec[0])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[0]))->name_<<std::endl;
                std::cout<< std::stoi(vec[1])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[1]))->name_<<std::endl;
                std::cout<<"index1: ";
                std::cout<<index1<<std::endl;
                std::cout<<"index2: ";
                std::cout<<index2<<std::endl;
                std::cout<<"weight: ";
                std::cout<<weight<<std::endl;
                std::cout<<"--------------"<<std::endl;        
            }
            if (count == 2) {
                std::cout<< std::stoi(vec[0])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[0]))->name_<<std::endl;
                std::cout<< std::stoi(vec[1])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[1]))->name_<<std::endl;
                std::cout<<"index1: ";
                std::cout<<index1<<std::endl;
                std::cout<<"index2: ";
                std::cout<<index2<<std::endl;
                std::cout<<"weight: ";
                std::cout<<weight<<std::endl;
                std::cout<<"--------------"<<std::endl;        
            }
            if (count == 3) {
                std::cout<< std::stoi(vec[0])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[0]))->name_<<std::endl;
                std::cout<< std::stoi(vec[1])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[1]))->name_<<std::endl;
                std::cout<<"index1: ";
                std::cout<<index1<<std::endl;
                std::cout<<"index2: ";
                std::cout<<index2<<std::endl;
                std::cout<<"weight: ";
                std::cout<<weight<<std::endl;
                std::cout<<"--------------"<<std::endl;        
            }
            if (count == 4) {
                std::cout<< std::stoi(vec[0])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[0]))->name_<<std::endl;
                std::cout<< std::stoi(vec[1])<<std::endl;
                std::cout<< airport_dict.at(std::stoi(vec[1]))->name_<<std::endl;
                std::cout<<"index1: ";
                std::cout<<index1<<std::endl;
                std::cout<<"index2: ";
                std::cout<<index2<<std::endl;
                std::cout<<"weight: ";
                std::cout<<weight<<std::endl;
                std::cout<<"--------------"<<std::endl;        
            } */
        }
    }
    std::cout<<count<<"----routes number"<<std::endl; 
}