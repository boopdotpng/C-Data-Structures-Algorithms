/*
You are given a directed graph of an airline network represented as an adjacency list.
For the test graph below, the entry {"CLT", {"JFK", "ORD"}} means there is a non-stop flight between CLT (Charlotte), and JFK (NYC), as well as between CLT and ORD (Chicago).  However, to fly from CLT to MIA (Miami) on this airline network, you would have to fly from CLT to ORD, and from ORD to DFW (Dalls), and DFW to MIA. That would be 2 stops.  Alterately, you could fly from ORD to LAX (LA), and LAX to MIA. There could be multiple such flight paths with varying number of intermediate stops.

Problem: Given a graph representing an airline network, find the minimum number of stops to fly from starting city to destination city. A direct connection would be zero stops.

Do NOT modify the test. Note that your code should for any arbirtrary directed airline network, not just the one given in the test.
Include any additional STL libraries that you may need
Note: For full credit your code should be O(n + m) where n is the number of vertices, and m is the number of edges in the graph.
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int minStops(std::unordered_map<std::string, std::vector<std::string>> &aList, std::string v1, std::string v2)
{
	queue<std::string> q;
	unordered_map<std::string, bool> visited;
	unordered_map<std::string, int> distances; // create maps to keep track of visited airports and distances

	for (auto element : aList)
	{
		visited[element.first] = false;
		distances[element.first] = 0;
	} // set initial default values for each map

	q.push(v1);
	visited[v1] = true; // visit first node

	string airport; // current airport that we're visiting

	while (!q.empty()) // until there are no more airports left
	{
		airport = q.front();
		q.pop(); // start with topmost airport in queue

		for (auto element : aList[airport]) // go through each adjacent airport until we find a path
		{
			if (!visited[element]) // makes sure we dont go through an airport we've already gone through
			{
				visited[element] = true;
				q.push(element); // add airports in adjacent list to search through
				distances[element] = distances[airport] + 1; // since we're directly adjacent to the airport, we add 1 to distance
			}
		}
	}
	return distances[v2] - distances[v1] - 1; // return the distance between the two airports
}

// Test
int main()
{
	std::unordered_map<std::string, std::vector<std::string>> adjList{{"CLT", {"JFK", "ORD"}},
																	  {"JFK", {"CLT", "LHR", "MUC"}},
																	  {"LHR", {"CDG", "ORD", "MUC"}},
																	  {"MUC", {"BCN", "LHR", "JFK"}},
																	  {"ORD", {"LHR", "LAX", "DFW"}},
																	  {"DFW", {"SLC", "MIA"}},
																	  {"LAX", {"ORD", "MIA"}},
																	  {"MIA", {"LAX"}},
																	  {"SLC", {"DFW"}}};
	std::cout << "Number of stops between CLT and LAX is " << minStops(adjList, "CLT", "LAX") << std::endl; // Should 1

	std::cout << "Number of stops between MIA and BCN " << minStops(adjList, "MIA", "BCN") << std::endl; // Should be 4

	return 0;
}
