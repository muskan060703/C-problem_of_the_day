//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &vec) {
        // Your code here
        vector<int> arr = vec;
        int n = arr.size();
        int sz = n/2;
        int k = 1;
        while(sz--){
            int p = arr.size();
            int val = arr[p-1];
            arr.erase(arr.end()-1);
            arr.insert(arr.begin(), val);
            arr.erase(arr.begin()+(p-k));
            k++;
        }
        return arr[0];
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
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
