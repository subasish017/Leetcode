//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        // Create a count array to store the frequency of each element
          int count[n] = {0};
          for (int i = 0; i < n; i++) {
            count[arr[i]]++;
          }
        
          // Initialize a list to store the duplicates
          vector<int> res;
        
          // Iterate through the count array and add elements with frequency > 1 to the list
          for (int i = 0; i < n; i++) {
            if (count[i] > 1) {
              res.push_back(i);
            }
          }
        
          // If no duplicates are found, return an empty list
          if (res.empty()) {
            res.push_back(-1);
          }
        
          // Sort the list in ascending order
          sort(res.begin(), res.end());
        
          return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends