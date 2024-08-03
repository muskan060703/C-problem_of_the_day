//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int ans = -1;
        int n = mat.size();
        int j = 0;
        for(int i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                
                if(mat[i][j] == 1) break;
            }
            if(j == n) {
                for( j = 0; j < n; j++) {
                    if( j != i and mat[j][i] == 0) break;
                }
                if( j == n ) return i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends