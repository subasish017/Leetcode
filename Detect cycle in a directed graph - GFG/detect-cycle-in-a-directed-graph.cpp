//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs( int src, int vis[], vector<int> adj[], int pv[])
    {
        vis[src]=1;
        pv[src]=1;
        for(auto it: adj[src])
        {
            if(!vis[it])
            {
                if(dfs(it, vis, adj, pv)==true)
                return true;
            }
            else if(pv[it]){
            return true;
            }
        }
        pv[src]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pv[V]={0};
            for(int i=0; i<V; i++)
            {
                if(!vis[i])
                {
                    if(dfs(i, vis, adj, pv)== true)
                    return true;
                }
            }
            return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends