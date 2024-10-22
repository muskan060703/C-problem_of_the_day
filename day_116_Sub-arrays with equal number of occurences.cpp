//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        int result = 0;
       int n = arr.size();
        // Check for each subarray for the required condition
        for (int i = 0; i <= n - 1; i++) {
            int ctX = 0,  ctY = 0;
            for (int j = i; j <= n - 1; j++) {
                if (arr[j] == x) 
                    ctX += 1;
                else if (arr[j] == y) 
                    ctY += 1;
                if (ctX == ctY) 
                    result += 1;            
            }
        }
     
        return (result);
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends
