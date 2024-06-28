#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform Breadth First Search on a graph
// represented using adjacency list
```
vector<int> BFS(vector<vector<int>>& adj_list, int start)  
{  
    int n = adj_list.size();  
    vector<bool> visited(n, false);  // a boolean array to track visited vertices  
    vector<int> order;  // a vector to store the BFS traversal order  
  
    queue<int> q;  // a queue to hold the vertices to be visited  
    q.push(start);  // add the starting vertex to the queue  
    visited[start] = true;  // mark the starting vertex as visited  
    while (!q.empty())  
    {  
        int u = q.front();  // get the next vertex in the queue  
        q.pop();  // remove the vertex from the queue  
  
        order.push_back(u);  // add the vertex to the traversal order  
  
        // add all the unvisited neighbors of u to the queue  
        for (int v : adj_list[u])  
        {  
            if (!visited[v])  
            {  
                q.push(v);  
                visited[v] = true;  
            }  
        }  
    }  
    return order;  
}  

// Function to add an edge to the graph
void addEdge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}

int main()
{
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph
    vector<vector<int> > adjList(vertices);

    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    // Mark all the vertices as not visited
    //vector<bool> visited(vertices, false);

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth First Traversal starting from vertex "
            "0: ";
    BFS(adjList, 0);

    return 0;
}