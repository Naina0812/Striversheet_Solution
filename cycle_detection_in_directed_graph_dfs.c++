#include <bits/stdc++.h>
#include<iostream>
using namespace std;

bool checkcyclichelper(int n, vector<bool>&visited, vector<bool> &dfsvisited, vector<int> adj[]){
        visited[n]=true;
        dfsvisited[n]=true;
        
        for(auto neighbour: adj[n]){
            if(!visited[neighbour]){
                if(checkcyclichelper(neighbour,visited,dfsvisited,adj)==true){
                    return true;
                }
            }else if(dfsvisited[neighbour]){
                return true;
            }
        }
        dfsvisited[n]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V, false);
        vector<bool>dfsvisited(V, false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(checkcyclichelper(i,visited,dfsvisited,adj)==true){
                    return true;
                }
            }
        }
        return false;
    }
    int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	// Solution obj;
	//bool ans = obj.isCyclic(V, adj);
	bool ans = isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}