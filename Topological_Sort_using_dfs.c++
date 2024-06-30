#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
void findTopoSort(int node,vector<bool>&vis,stack<int>&st, vector<int> adj[]){
	    vis[node]=true;
	    
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            findTopoSort(it, vis, st, adj);
	        }
	    }
	    st.push(node);
	}
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    //make one visited array
	    vector<bool>vis(V,false);
	    stack<int>st;
	    
	    for(int i=0;i<V;i++){
	        findTopoSort(i,vis, st, adj);
	    }
	
	vector<int>topo;
	while(!st.empty()){
	    topo.push_back(st.top());
	    st.pop();
	}
	return  topo;
	}

int main() {

  int N = 6;

  vector < int > adj[5 + 1];

  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

//   Solution obj;
//   vector < int > res = obj.topoSort(6, adj);
  vector < int > res = topoSort(6, adj);

  cout << "Toposort of the given graph is:" <<" ";
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
} 