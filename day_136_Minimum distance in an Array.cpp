//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minDist(vector<int>& a, int x, int y) {
        // code here
           int x_index=-1;
       int y_index=-1;
       int n = a.size();
       int result=INT_MAX;
       for(int i=0; i<n; i++){
           if(a[i]==x){
              x_index=i;
           }
           if(a[i]==y){
               y_index=i;
           }
           if(x_index!=-1&&y_index!=-1){
               result=min(result,abs(x_index-y_index));
           }
       }
       if(result==INT_MAX){
               return -1;
           }
       return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x, y;
        cin >> x >> y;
        cin.ignore();
        Solution obj;
        cout << obj.minDist(arr, x, y) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
