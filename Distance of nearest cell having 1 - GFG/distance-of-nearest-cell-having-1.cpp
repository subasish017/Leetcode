//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    queue<pair<int,pair<int, int>>> q;
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<m; j++)
	        {
	            if(grid[i][j]==1)
	            {
	                vis[i][j]=1;
	                grid[i][j]=0;
	                q.push({0,{i,j}});
	            }
	        }
	    }
	    
	    int dx[] = {-1,0,1,0};
	    int dy[] = {0,1,0,-1};
	    
	    while(!q.empty())
	    {
	        auto it = q.front();
	        int dist = it.first;
	        int x = it.second.first;
	        int y= it.second.second;
	        q.pop();
	        grid[x][y]= dist;
	        
	        for(int i=0; i<4; i++)
	        {
	            int dnx = dx[i] + x;
	            int dny = dy[i] + y;
	            if( dnx>=0 && dny>=0 && dnx<n && dny<m && vis[dnx][dny]==0)
	            {
	                vis[dnx][dny]=1;
	                q.push({dist+1,{dnx,dny}});
	            }
	        }
	    }
	    return grid;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends