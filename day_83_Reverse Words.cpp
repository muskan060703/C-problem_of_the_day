//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        int start=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='.')
            {
                int low=start;
                int high=i-1;
                while(low<=high)
                {
                    swap(S[low],S[high]);
                    low++;
                    high--;
                }
                start=i+1;
            }
        }
                int low=start;
                int high=S.length()-1;
                while(low<=high)
                {
                    swap(S[low],S[high]);
                    low++;
                    high--;
                }
                low=0;
                high=S.length()-1;
                 while(low<=high)
                {
                    swap(S[low],S[high]);
                    low++;
                    high--;
                }
        
        return S;
        // code here 
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends
