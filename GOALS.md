# CS 225  PROPOSAL:


## Leading questions:

We plan to implement  A* search. We use A * search to find the shortest path from one airport to another airport . 
We also plan to implement prim’s algorithm to find the minimum spanning tree based on graph structure. We will also write proper test cases for each algorithm to assess full functionality of implementations.


## Graph structure:

We want to create a graph of the airports and the connecting flight routes, this graph will
allow us to assign weights for the edges based on the distance between airports.
The airport dataset has listed latitude and longitude for each airport. We plan to use this to determine the Euclidean distance of two airports.


## Dataset:

Openflights is the dataset our group chose to use. Link to the dataset. https://openflights.org/data.html

This dataset contains over 10,000 airports, 5888 airlines and 67663 routes between 3321 airports on 548 airlines spreading around the world.

Specifically, we need two datasets: Airport dataset and Route dataset.


## Algorithm implementation:

### 1.    BFS 	 	 							
We’ll use breadth-first search for a graphical representation of the flights. Our plan is to create a map of points for each valid airport. If there exists an edge between two nodes, that means there exists round trips between two airports. We need BFS to accomplish this because we will be iterating through every airport, so some sort of searching algorithm is needed.The Time.

Completed time complexity: O(V + E).
 
### 2.    Prim’s Algorithm
We will use the Prim's algorithm which is a greedy algorithm that finds a minimum spanning tree for a weighted graph. This means it finds a subset of the edges that forms a spanning tree , where the total weights of all the edges in the spanning tree is minimized. 

Algorithm’s input and output:
	Input: Graph, Start Airports index(from 0-7697)
Return: Minimum Spanning Tree(MST) of the input graph

Completed time complexity: O(V^2)

### 3.     A* Search 
We will use three functions to achieve this algorithm. The main A* search function followed by two helper functions: the construct path function and heuristics function. 

Main A* Function: 
	input : (start airport, destination airport)
	return: vector<> containing all airports in sequence that shortestest path pass.
	
Construct path function (helper function): 
	input : (stack<> of airports already pass)
	return: no return, but cout in the terminal containing airports already passed and destination airport. 
	
Heuristics function (helper function): O(1)
	input: (airport A, airport B)
	return: Euclidean Distance from A to B

Completed Running time: 
O(bd) where b is average routes of all airports have, d is number of airports that shortest path passed (length(stack<> return from A* search)). 



## Timeline:
###    11.16-11.24: 
Define header file, data structure, and how to compile(using g++)
Data cleaning and processing.
Parse dataset into project dataset and write corresponding test cases.
	
###    11.25-12.1:
Improving and debuging Reader.cpp which read data from dataset
Implementing BFS and Prim algorithm.
Improve functionality and debugiing, writing corresponding test cases.
	
###    12.2-12.13: 
Implementing A* algorithm, and priority queue
Working on improving functionality, debuging and written reports, as well as presentation vide which includes GOALS.md and DEVELOPMENT_LOG.md and RESULTS.md.
     




 

 

	







