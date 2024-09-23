//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long SN=(n*1ll*(n+1))/2;
        
        long long S2N=(n*1ll*(n+1)*1ll*(2*n+1))/6;
        long long S=0,S2=0;
        
        for(int i=0;i<n;i++)
        {
            S+=arr[i];
            S2=S2+((long long)arr[i]*(long long)arr[i]);
        }
        
        long long val1=S-SN; //x-y
        long long val2=S2-S2N;
        
        val2=val2/val1;  //x+y
        
        long long x= (val1+val2)/2;
        
        long long y=(x-val1);
        
        return {(int)x,(int)y};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
