//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int n = arr.size();
        int cnt = 0;
        
        for(int i = 0; i < n; i++) 
            if(arr[i] != i+1)
            cnt++;
            
            if(cnt > 4) return false;
            if(cnt == 0 || cnt == 2) return true;
            for(int i = 0; i < n ; i++ ) 
            if(arr[i] != i+1)
            if(arr[arr[i]-1] == i+1)
            return true;
        
        return false;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends
