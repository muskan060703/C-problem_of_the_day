//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        if (arr.size() <= 1) {
            return 0;
        }
        if (arr[0] == 0) {
            return -1;
        }
        int maxReach = arr[0]; // The maximum index we can reach so far
        int steps = arr[0];    // Steps we can take before needing to jump
        int jumps = 1;         // Number of jumps made so far
        for (int i = 1; i < arr.size(); i++) {
            if (i == arr.size() - 1) {
                return jumps;
            }
            maxReach = max(maxReach, i + arr[i]); // Update the maxReach

            steps--; // Decrease the step count

            if (steps == 0) { // Need to make a jump
                jumps++;
                if (i >= maxReach) {
                    return -1; // If we cannot move forward
                }
                steps = maxReach - i; // Reset the steps to the number of steps we can now take
            }
        }

        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
