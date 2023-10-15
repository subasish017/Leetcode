//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        //bfs traversal
        queue<pair<int, int>> q;
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1){
                q.push({i,j});
                vis[i][j]=1;
                }
                else
                vis[i][j]=0;
            }
        }
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();
            
            
            
            for(int i=0; i<4; i++)
            {
                int dnx = x + dx[i];
                int dny = y + dy[i];
                
                if(dnx>=0 && dny>=0 && dnx<n && dny<m && grid[dnx][dny]==2 && vis[dnx][dny]==0)
                {
                    return true;
                    break;
                }
            
                if(dnx>=0 && dny>=0 && dnx<n && dny<m && grid[dnx][dny]==3 && vis[dnx][dny]==0)
                {
                    q.push({dnx, dny});
                    vis[dnx][dny]=1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends