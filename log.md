#2021/11/18 Ruoqi Zuo<br/>
Clean Airports dataset and Routes dataset<br/>

#2021/11/18 Ruoqi Zuo<br/>
Clean Airports dataset and Routes dataset<br/>
Add Airports class, which store the node of graph<br/>
Construct Airports class including Constructor and Copy Constructor<br/>

#2021/11/19 Qirun Tang<br/>
Add math_helper folder with calculateDistance() function which convert 2 LLA to distance<br/>
Add Reader class, which read data from airports.data, and store into a map<int, Airports*><br/>
Test ReadAirport() in reader.cpp<br/>
Compile and run program should use: <br/>
g++ reader.cpp Airports.cpp testReader.cpp -o testReader.out -std=c++11 <br/>
./testReader.out<br/>

#2021/12/3 Qirun Tang<br/>
Construct Graph class contains adjacent matrix(2d vector) to build graph<br/>
Adjacent matrix was innitialized with size 7698 * 7698 because the airports dataset contains 7698 airports, each of them is a vertex of graph <br/>
Implement ReadRoute which read data from route.data and update adjacent matrix<br/>

#2021/12/3 Zihan Zhou<br/>
Construct Graph class and optimize code structure, commite changes in resizing matrix.<br/>
Debug minor bugs in readAirports fuction and readroute function. Set matrix to be symmetric.</br>

#2021/12/5 Zihan Zhou</br>
Implement breadth-first search using adjacent matrix. Along the way, used two vectors and output solution as a vector containing nodes(airports).</br>
Writing testcase for bfs function.</br>

#2021/12/7 Zihan Zhou</br>
Dectecting that our graph construction would output disconnected graph with different componets. Based on that, revise bfs implementation, add bfsHelper function, and make bfs function to return all noeds(7698 nodes) in the output as a vector. In this way, the output solution contains different components and for each component, we traverse the graph in bfs order.</br>
Updating testcases using test-graph with several components. Test without errors.</br>

#2021/12/9 Zihan Zhou</br>
Implementing prim algorithm using adjacent matrix, output Minimum spanning tree as 3 columns. The first column is the parent node (setting the parent node of root node to be -1), the second column is the child node, the third column is the weight of the edge connecting parent node and child node. Through those 3 columns, we can easily construct Minimum Spanning Tree.</br>
Writing testcase for Prim algorithm.

#2021/12/9 Qirun Tang<br/>
Figuring out how to use std::priority_queue to suite our dataset<br/>

#2021/12/9 Ruoqi Zuo<br/>
Writing helper function neighbor() for A* search<br/>

#2021/12/9 Jiateng Wang<br/>
Constructing Airports class comparator which is used in std::priority_queue<br/>

#2021/12/12 Qirun Tang<br/>
Figuring out need to add a map in reader class which search Airports using index<br/>
Successfully utilized std::priority_queue in A* search algorithm<br/>
Implemented A* Algorithm<br/>
Writing printShortest() function to help A* track back and print shortest path in terminal<br/>
Writing test cases to test the correctness of A* search algorithm<br/>

#2021/12/12 Jiateng Wang<br/>
Helping build A* algorithm, checking doc of std libarary online<br/>
Debug A* algorithm on tracking visited airports<br/>

#2021/12/12 Jiateng Wang<br/>
Construct test cases for Reader.cpp<br/>
Write test cases testing whether names are correctly read out<br/>
Write test cases testing whether IAIAs are correctly read out<br/>
Write test cases testing whether latitudes are correctly read out<br/>
Write test cases testing whether longitudes are correctly read out<br/>
Write test cases testing whether routes which have edges are correctly been validated<br/>
Write test cases testing whether routes which have no edges are correctly been validated<br/>

#2021/12/13 Qirun Tang<br/>
Writing README.md<br/>
Writing GOALS.md<br/>
Writing RESULTS.md<br/>