//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n = nums.size();
        vector<int>ans ;
        int el1, el2 ;
        int cnt1 = 0, cnt2 = 0 ;

        for( int i = 0 ; i < n ; i ++ ) {
            if( cnt1 == 0 and el2 != nums[i] ) {
                cnt1 = 1 ;
                el1 = nums[i] ;
            }
            else if( cnt2 == 0 and el1 != nums[i] ) {
                cnt2 = 1 ;
                el2 = nums[i] ;
            }
            else if ( el1 == nums[i] ) cnt1++ ;
            else if ( el2 == nums[i] ) cnt2++ ;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0 ;

        for(int i = 0 ; i < n ; i ++ ) {
            if( el1 == nums[i] ) cnt1++ ;
            if( el2 == nums[i] ) cnt2++ ;
        }

        if( cnt1 > ( n/3 ) and el1 != el2 ) ans.push_back(el1);
        if( cnt2 > ( n/3 ) ) ans.push_back(el2);
        
        if ( ans.empty() ) ans.push_back(-1);

        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
