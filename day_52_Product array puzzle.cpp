//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

    
        // code here
        vector<long long int> mul;
        int n = nums.size();
        long long int ans = 1;
        bool zero = false;
        int cnt = 0;
        for( int i = 0; i < n; i++) 
        {
          if(nums[i] == 0) 
          {
              zero = true;
              cnt++;
              continue;
          }
          ans = ans * nums[i];
        }
        
        for(int i = 0; i < n ; i++)
        {
            if( zero == true and cnt > 1) mul.push_back(0);
            else if(zero == true and nums[i] != 0 ) mul.push_back(0);
            else if( nums[i] == 0 ) mul.push_back(ans);
            else 
            {
                long long int temp = ans / nums[i];
                mul.push_back(temp);
            }
        }
        return mul;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends