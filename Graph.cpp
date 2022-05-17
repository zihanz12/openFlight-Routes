#include "Graph.h"
#include <climits> 
using namespace std;


Graph::Graph() {
    adj_matrix = new std::vector<std::vector<int>>;
	//visited_= vector<bool>(6);   // resize in airports.cpp
	//std::vector<bool> visited_(adj_matrix->size(), false);
    //adj_matrix->resize(5, std::vector<int>(5));   // resize in here?
    
}

Graph::~Graph() {
    delete adj_matrix;
}


// Function to perform BFS on the graph

std::vector<int> Graph::bfs(Graph * graph ,int start_index)
{
	int count_componet = 1;
	std::vector<int> solution;
	cout<<"here we go in bfs"<<endl;
	//delete//std::vector<bool> visited_(5, false);  //
	solution = bfsHelper(graph,start_index);
	
    cout<<"first componet's size is "<<solution.size()<<endl;
	cout<<graph->adj_matrix->size()<<"--is matrix size"<<endl;

	for (int u =0; u<graph->adj_matrix->size(); u++) {
		//cout<<u<<"+here can we gointo loops?------"; //----
		//cout<<"visited_[u] is"<<visited_[u]<<"printed--"<<endl;
       if (!visited_[u]) {
            std::vector<int> solution_ = bfsHelper(graph,u);
			//cout<<solution_.size()<<"--solution size"<<endl;
			solution.insert(solution.end(),solution_.begin(),solution_.end()); //
            count_componet++;  //COUNT_COMPONET; 
			if (solution.size()==3900) {
                break;
			}
	   }
	}
	/*cout<<solution[3236]<<endl;
	cout<<solution[3237]<<endl;
	cout<<solution[3238]<<endl;
	cout<<solution[3239]<<endl;
	cout<<solution[3240]<<endl;
	cout<<solution[3250]<<endl; */
	cout <<"component is "<<count_componet<<endl;
    return solution;
} 

std::vector<int> Graph::bfsHelper(Graph * graph, int start_index) {

	// Visited vector to so that
	// a vertex is not visited more than once
	// Initializing the vector to false as no
	// vertex is visited at the beginning
   
	std::vector<int> solution;
	//std::vector<bool> visited(graph ->adj_matrix->size(), false); //=====
	//std::vector<bool> visited_(5, false); 
	    //visited=visited_;  //=======
	    //cout<<visited_[0]<<" --is good now?"<<endl;
	std::vector<int> q;

	q.push_back(start_index);

	// Set source as visited
	visited_[start_index] = true;

	int vis;
	while (!q.empty()) {
		vis = q[0];

		// Print the current node
		//cout<<vis<<"-";

        solution.push_back(vis);
		q.erase(q.begin());

		// For every adjacent vertex to the current vertex
		for (int i = 0; i < graph ->adj_matrix->at(vis).size(); i++) {
			if (graph ->adj_matrix->at(vis).at(i) != 0 && (!visited_[i])) {

				// Push the adjacent node to the queue 
				q.push_back(i);

				// Set
				visited_[i] = true;
				/*cout<<"i is"<<i<<", visitied[i] is "<<visited_[i]<<"--";
				cout<<"why here?jump?"<<endl;*/
			}
		}
		//visited_= visited;
	}
	//visited_= visited;
	return solution;
}


// Here we perform Prim on the graph

// Find the unvisited vertex with minimum key value.
int Graph::minKey_helper(Graph* graph, vector<int> key, vector<bool> mstSet)
{
	int min = INT_MAX, min_index;
    int V = graph ->adj_matrix->size();
	for (int v = 0; v < V; v++) {
		if (mstSet[v] == false && key[v] < min) {
			min = key[v], min_index = v;
		}
	}
	return min_index;
}

// Helper function to print the constructed MST stored in parent.
void Graph::printMST_helper(vector<int> parent, Graph * graph, int start_index)
{
	cout<<"parent"<<" -- "<<"child"<<" -- "<<"Weight"<<endl;
	int V = graph ->adj_matrix->size();
	for (int i = 0; i < V; i++) {
		if (i == start_index) {
			cout<<"-1"<<" -- "<<i<<" -- No weight between -1 and root node"<<endl;
			continue;
		}
		cout<<parent[i]<<" -- "<<i<<" -- "<<graph ->adj_matrix->at(i).at(parent[i])<<endl; 
	}
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void Graph::primMST(Graph* graph, int start_index)
{
	int V = graph ->adj_matrix->size();
	// vector to store constructed MST

	std::vector<int> parent(V);

	// Using key<> to pick minimum weight edge in cut
	std::vector<int> key(V);
	
    // vector mstSet would show if visited.
	std::vector<bool> mstSet(V);

	// Initialize key values as infinite large
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	//Initiallize the input index as the root of minimum spanning tree. 
	//Initialize its key value to be 0, so it will get picked at first.
	key[start_index] = 0;

	// Set the parent of root (first picked node) to be  -1 .
	parent[start_index] = -1; 

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey_helper(graph, key, mstSet);

		// mark as visited.
		mstSet[u] = true;

		for (int v = 0; v < V; v++) {
			if (graph ->adj_matrix->at(u).at(v) && mstSet[v] == false && graph ->adj_matrix->at(u).at(v) < key[v]) {
				parent[v] = u, key[v] = graph ->adj_matrix->at(u).at(v); 
			}
		}
	}

	// print Minimum spanning tree.
	printMST_helper(parent, graph, start_index);
}



// heuristic function for A* algorithm
double heuristic(Airports& a, Airports& b) {
	return calculateDistance(a.lat_, a.lon_, b.lat_, b.lon_);
}

void Graph::a_star_search(std::vector<std::vector<int>>& graph,
						Airports& start,
						Airports& goal,
						std::stack<Airports>& cost_sofar,
						std::map<int, Airports*>& index_airport,
						std::map<int, Airports>& added)
{
	std::priority_queue<Airports, std::vector<Airports>, std::greater<Airports>> frontier;
	frontier.push(start);

	int count = 0;
	while (!frontier.empty()) {
		// current shortest path
		Airports current = frontier.top();

		// cout<<"current"<<count<<":"<<current.name_<<"--cost:"<<current.cur_cost<<endl;
		// cout<<"goal: "<<goal.name_<<endl;

		// find destination
		if (current == goal) {
			// cout<<"here"<<endl;
			cost_sofar.push(current);
			break;
		}
		// find vector of airports that connect with current airports
		vector<int> adj = neighbors(current.index_);
		for (int elem : adj) {
			Airports* next = index_airport[elem];
			double cur_cost = current.cur_cost + graph.at(current.index_).at(elem) + heuristic(*next, goal);
			// cout<<count<<"next"<<next->name_<<"--cost:"<<cur_cost<<endl;

			// if one vertext has included in priority queue
			if (added.count(next->index_) != 0) {
				// update information in priority queue only if the new cost is smaller
				if (added.at(next->index_).cur_cost > cur_cost) {
					next->cur_cost = cur_cost;
					next->from_ = current.index_;
					frontier.push(*next);
					added[next->index_] = *next;
				} else {
					// didn't update priority queue when the cost doens't change or larger
					continue;
				}
			}
			// update priority queue when it is firt time met airpot
			next->cur_cost = cur_cost;
			next->from_ = current.index_;
			frontier.push(*next);
			added[next->index_] = *next;
		}
		// record the airport that visited, and pop the top of priority queue
		cost_sofar.push(current);
		frontier.pop();
		count++;
  	}
	printShortest(cost_sofar);
}

void Graph::printShortest(std::stack<Airports>& path) {
	Airports* current1 = &path.top();
	cout<<"end----"<<current1->name_<<"----";
	path.pop();
	while (!path.empty())
    {
		Airports* current2 = &path.top();
		if (current1->from_ == current2->index_) {
			cout<<current2->name_<<"----";
			current1 = current2;
		} else if (current2->from_ == -1) {
			cout<<current2->name_<<"----";
		}
		path.pop();
    }
	cout<<"start"<<endl;
}

std::vector<int> Graph::neighbors(int airport_index) {
	vector<int> solution;
	if (airport_index >= 0 && airport_index < adj_matrix->size()) {
		for (int i = 0; i < adj_matrix->size(); i++) {
			if (adj_matrix->at(airport_index).at(i)) {
				solution.push_back(i);
			}
		}
	}
	return solution;
}