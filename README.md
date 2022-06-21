
## Constributors <br/>
**Qirun Tang** (NetID: qirunt2)<br/>
**Zihan Zhou** (NetID: zihanz12)<br/>

## Main Code location: <br/>
- Located in main folder with path /root/ruoqiz3-zihanz12-qirunt2-jiateng3<br/>

## Main Function files location: <br/>
- Airports.h Airports.cpp (Airports class)<br/>
- reader.h reader.cpp (Read Airports function, Read Routes function)<br/>
- Graph.h Graph.cpp (BFS, Prim, A star)<br/>

## Dataset location: <br/>
- data folder with path /root/ruoqiz3-zihanz12-qirunt2-jiateng3/data<br/>
- airports_original.dat is main airports dataset we used.<br/>
- routes.data is the main routes dataset we used.<br/>

Thereare still other data set located in data and test folder, which is work for test case<br/>

## Result files location: <br/>
- GOALS.md is GOALS <br/>
- log.md is DEVELOPMENT<br/>
- RESULT.md is RESULT<br/>

## How to build and run code: <br/>
- First, create a new Reader object from example "Reader* test = new Reader()";<br/>
- Call function of Reader object in sequence: <br/>
    `test->ReadAirport("location of airports dataset")`<br/>
    `test->ReadRoute("location of routes dataset")`;<br/>
### Call function of graph class: <br/>
### BFS: <br/>
- bfs(Graph * graph ,int start_index)<br/>
- input: pointer of the graph, starting bfs Airports index<br/>
- return: vector of index of airports traversed<br/>

### Prim: <br/>
- primMST(Graph* graph, int start_index)<br/>
- input: pointer of the graph, starting Airports index<br/>
- return: print in terminal with 3 columns. The first column is the parent node (setting the parent node of root node to be -1), the second column is the child node, the third column is the weight of the edge connecting parent node and child node. Using those 3 columns to construct Minimum Spanning Tree.</br>

### A* algorithm: <br/>
- a_star_search(std::vector<std::vector<int>>& graph, Airports& start, Airports& goal, std::stack<Airports>& cost_sofar, std::map<int, Airports*>& index_airport, std::map<int, Airports>& added) <br/>
- intput: the adjacent matrix of the graph, the start airports, the end airports, a empty stack<Airports>, a map works as dictionary of adjacent matrix that can transfer index of 
Airports to sepecific Airports class object at that index, an empty map check whitch airports has been visited. <br/>
- return: no return, cout in the terminal of the shortes path from the end to start<br/>

## Test Suite<br/>
### Test Reader Class<br/>
- `g++ reader.cpp Airports.cpp Graph.cpp test_reader.cpp math_helper/lla_to_dis.cpp -o testReader.out -std=c++11`
- `./testReader.out`
### Test BFS <br/>
- `g++ reader.cpp Airports.cpp Graph.cpp testBfs.cpp math_helper/lla_to_dis.cpp -o testBfs.out -std=c++11`
- `./testBfs.out`
### Test Prim <br/>
- `g++ reader.cpp Airports.cpp Graph.cpp testPrim.cpp math_helper/lla_to_dis.cpp -o testPrim.out -std=c++11`
- `./testPrim.out`
### Test A* <br/>
- `g++ reader.cpp Airports.cpp Graph.cpp test_Astar.cpp math_helper/lla_to_dis.cpp -o testAstar.out -std=c++11`
- `./testAstar.out`
