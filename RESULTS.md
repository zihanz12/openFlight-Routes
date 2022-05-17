# Results

## Dataset<br/>
We cleaned and utilized two dataset on Openflight. <br/>
### Airports Dataset (/root/ruoqiz3-zihanz12-qirunt2-jiateng3/data/airports_original.dat)<br/>
Original: <br/>
`1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,"U","Pacific/Port_Moresby","airport","OurAirports"`<br/>
Cleaned: <br/>
`1,Goroka Airport,GKA,-6.081689835,145.3919983`<br/>
Airport ID, Airport Name, IAIA, Latitude, Longitude<br/>
### Routes Dataset (/root/ruoqiz3-zihanz12-qirunt2-jiateng3/data/routes.dat)<br/>
Original: <br/>
`2B,410,AER,2965,KZN,2990,,0,CR2`<br/>
Cleaned: <br/>
`2965,2990`<br/>
Source airport ID, Destination airport ID<br/>

## Reader class (reader.h and reader.cpp)

### Class Fields
- `std::map<int, Airports*> airport_dict`: a map from Airports ID to Airports object.<br/>
- `std::map<int, Airports*> index_airport`: a map from Airports Index to Airports object.<br/>
- `Graph* graph_`: a graph object pointer.<br/>
### Function
- Constructor:`Reader()` and Deconstructor`~Reader()`
- `void ReadAirport(std::string filePath)`: function read airports dataset to the two map in class cields.<br/>
- `void ReadRoute(std::string filePath)`: function read routes dataset, and construct graph by using adjacent matrix, the adjacent matrix is located at `graph->adj_matrix` where `graph_` is class field.<br/>
For example, if there is an routes between airports with index 1 and 2, the adj_matrix[1][2] and the adj_matrix[2][1] will have same non-zero value, and this value is the distance between those two airports calculated by Euclidian distance using two airports' lon and lat.<br/>
**Test Case Result**<br/>
Using comman in terminal: <br/>
`g++ reader.cpp Airports.cpp Graph.cpp test_reader.cpp math_helper/lla_to_dis.cpp -o testReader.out -std=c++11` and `./testReader.out`<br/>
It will prints the result in terminal, it is really long so I only put few lines here<br/>
```
Name:
Hangzhou Xiaoshan International Airport
True
---------------
IAIA:
NYI
True
---------------
```
That the first line is which field is checking, the second line is which value we expect, the third line is whether it is correct. <br/>


## Airports class (Airports.h and Airports.cpp)

### Class Fields
- `std::string name_; std::string iaia_; double lat_; double lon_; int index_; double cur_cost; int from_;` each variable stands for its variable name.<br/>
### Function
- Constructor `Airports(std::string setName, std::string setIAIA, double setLat, double setLon, int setIndex);`<br/>
- Copy Constructor `Airports(const Airports& other);`<br/>
- `bool operator==(const Airports& other);` true if the 5 fields in the constructor are the same.<br/>
- `bool operator>(const Airports& other) const;` used in A* to implement priority queue.<br/>

## Graph class (Graph.h and Graph.cpp)

### Class Fields
- `std::vector<std::vector<int>> *adj_matrix;` the adjacent matrix for our Graph.<br/>
- `std::vector<bool> visited_;` used in bfs() to record traversed Airports index.<br/>
### Function
- Constructor`Graph();` Deconstructor `~Graph();`
- `std::vector<int> bfs(Graph * graph ,int start_index);` BFS algorithm with Time Complexity O(V+E), V is number of airports in dataset, E is number of valid routes in dataset.<br/>
using helper function `std::vector<int> bfsHelper(Graph * graph ,int start_index);`<br/>
**Test Case Result**<br/>
Using command in terminal: <br/>
`g++ reader.cpp Airports.cpp Graph.cpp testBfs.cpp math_helper/lla_to_dis.cpp -o testBfs.out -std=c++11` and `./testBfs.out`<br/>
```
11----Aiports number
13----routes number
11---here is matrix size
here we go in bfs
first componet's size is 3
11--is matrix size
component is 3
--------------------below is bfs size--------------
11
10 9 8 0 1 2 3 4 6 7 5 -------------------------
```
This test case use two dataset `data/test_airports_bfs.dat` and `data/testRoutes.dat` and we have manually construct graph based on dataset on papaer and calculated the result in the terminal it is correct.<br/>
- `void primMST(Graph* graph, int start_index)` Prim Algorithm to find Minimum spanning tree<br/>
Which utilizes two helper function`int minKey_helper(Graph* graph, std::vector<int> key, std::vector<bool> mstSet);`and`void printMST_helper(std::vector<int> parent, Graph * graph, int start_index);`<br/>
Time Complexity is O(V^2) where V is number of airports in dataset.<br/>
The output is printed in terminal, which represnets Minimum spanning tree as 3 columns. The first column is the parent node (setting the parent node of root node to be -1), the second column is the child node, the third column is the weight of the edge connecting parent node and child node. Through those 3 columns, we can easily construct Minimum Spanning Tree.<br/>

**Test Case Result**<br/>
Using command in terminal: <br/>
`g++ reader.cpp Airports.cpp Graph.cpp testPrim.cpp math_helper/lla_to_dis.cpp -o testPrim.out -std=c++11` and `./testPrim.out` <br/>
```
4----Aiports number
13----routes number
test one: start from vertex index 0
parent -- child -- Weight
-1 -- 0 -- No weight between -1 and root node
0 -- 1 -- 138
0 -- 2 -- 224
1 -- 3 -- 109
test two: start from vertex index 1
parent -- child -- Weight
1 -- 0 -- 138
-1 -- 1 -- No weight between -1 and root node
0 -- 2 -- 224
1 -- 3 -- 109
```
This test case use two dataset `data/test_airports_prim.dat` and `data/testRoutes.dat`and we have manually construct graph on papaer based on dataset and calculated result in the terminal it is correct.<br/>

- `void a_star_search (std::vector<std::vector<int>>& graph,Airports& start,Airports& goal std::stack<Airports>& cost_sofar, std::map<int, Airports*>& airport_dict, std::map<int, Airports>& added)`<br/>
A* algorithm, which prints the shortest path of `Airports& start`and`Airports& goal` in terminal line.<br/>
The input of the funtion: the adjacent matrix of the graph, the start airports, the end airports, a empty stack<Airports>, a map works as dictionary of adjacent matrix that can transfer index of 
Airports to sepecific Airports class object at that index, an empty map check whitch airports has been visited. <br/>
Using helper function `void printShortest(std::stack<Airports>& cost_sofar)` to trace back shortest path and `double heuristic(Airports& a, Airports& b)` to calculate Heuristic value (the Euclidian distance between two airports).<br/>
Has the Time Complexity of O(bd) where b is average routes of all airports have, d is number of airports that shortest path passed (length(stack<> return from A* search)). <br/>
**Test Case Result**<br/>
Using comman in terminal line: <br/>
`g++ reader.cpp Airports.cpp Graph.cpp test_Astar.cpp math_helper/lla_to_dis.cpp -o testAstar.out -std=c++11` and - `./testAstar.out` <br/>
```
end----Beijing Capital International Airport----Chengdu Shuangliu International Airport----start
---------

end----Chengdu Shuangliu International Airport----Guangzhou Baiyun International Airport----Charles de Gaulle International Airport----Chicago O'Hare International Airport----University of Illinois Willard Airport----start
```
This test case use two dataset `data/airports_original.dat` and `data/routes.dat`.<br/>
The first end----start is using A* to find the shortest path between Chengdu Airports and Beijing Airports, and there is direct route between those two airports so the shortest path only contain those two Airports.<br/>
The second end----start is using A* to find the shortest path between UIUC airports and Chengdu Airports, we manually construct graph based on the result's adjacent Airports, and calculated the shortest path between those two Airports is excatly the same one as shown in terminal.<br/>