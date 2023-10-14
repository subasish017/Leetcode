//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) 
    {
        // Code here
        queue<pair<string, int>> q;
        unordered_set<string> map(wordList.begin(), wordList.end());
        q.push({startWord,1} );
        map.erase(startWord);
        while(!q.empty())
        {
            string word = q.front().first;
            int len = q.front().second;
            q.pop();
            if(word == targetWord )
            {
                return len;
            }
            for(int i =0; i<word.length(); i++)
            {
                char orig = word[i];
                for(char j ='a'; j<= 'z' ;j++)
                {
                    word[i] = j;
                    if(map.find(word)!= map.end())
                    {
                        q.push({word, len+1});
                        map.erase(word);
                    }
                }
            word[i] = orig;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends