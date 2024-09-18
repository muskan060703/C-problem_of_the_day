//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool matching(char &a,char&b)
    {
        return ((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'));
    }
    //Function to check if brackets are balanced or not.
    bool ispar(string &str)
    {
        stack<char>s;
        for(char x: str)
        {
            if(x =='(' || x =='[' || x =='{')
            s.push(x);
            else
            {
                if(s.empty()==true)
                return false;
                if(matching(s.top(),x)==false)
                return false;
                else
                s.pop();
            }
        }
        return (s.empty()==true);
        
    }

};


//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
