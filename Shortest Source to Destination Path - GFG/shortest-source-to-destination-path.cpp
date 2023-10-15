//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if(A[0][0]==0 || A[X][Y]==0) return -1;
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>>vis(N, vector<bool>(M,false));
        int delrow[]={0, -1, 0,1};
        int delcol[]={-1, 0, 1,0};
      
        q.push({0,{0,0}}); // dist, {row, col}
        vis[0][0]=true;
        
        while(!q.empty())
        {
        
            auto it=q.front();
            q.pop();
            int dist=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==X and c==Y)
             {return dist;}
                    
            for(int i=0;i<4;i++)
            {
                int nr = r + delrow[i];
                int nc = c + delcol[i]; 
                if(nr>=0 && nc>=0 && nr<N && nc<M && A[nr][nc]==1 && vis[nr][nc]==false)
                {
                    q.push({dist+1, {nr, nc}});
                    vis[nr][nc] = true;
                }
            }
           
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends