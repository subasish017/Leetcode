//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    queue<pair<int,pair<int,int>>> q;
	    vector<vector<bool>>vis(N, vector<bool>(N,false));
	    
	    int delrow[]={2,1,-1,-2,-2,-1,1,2};
        int delcol[]={-1,-2,-2,-1,1,2,2,1};
        
        int x = KnightPos[0];
        int y = KnightPos[1];
        
        q.push({0,{x-1,y-1}});
        while(!q.empty())
        {
        
            auto it=q.front();
            q.pop();
            
            int dist=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            int X = TargetPos[0];
            int Y = TargetPos[1];
            
            if(r==X-1 and c==Y-1)
             {return dist;}
                    
            for(int i=0;i<8;i++)
            {
                int nr = r + delrow[i];
                int nc = c + delcol[i]; 
                
                if(nr>=0 && nc>=0 && nr<N && nc<N && vis[nr][nc]==false)
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
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends