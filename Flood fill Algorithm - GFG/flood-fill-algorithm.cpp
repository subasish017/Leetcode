//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
        void dfs(int sr,int sc,vector<vector<int>>&res,vector<vector<int>>&image,int newColor,int n,int m,int ic,int delrow[],int delcol[])
        {
            res[sr][sc]=newColor;
            for(int i=0;i<4;i++)
            {
                int newrow=sr+delrow[i];
                int newcol=sc+delcol[i];
                if(newrow>=0 and newrow<n and newcol>=0 and newcol<m and image[newrow][newcol]==ic and res[newrow][newcol]!=newColor)
                {
                    dfs(newrow,newcol,res,image,newColor,n,m,ic,delrow,delcol);
                }
            }
        }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>>res=image;
        int ic=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,res,image,newColor,n,m,ic,delrow,delcol);
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends