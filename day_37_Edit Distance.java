//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String s1 = br.readLine();
            String[] S = s1.split(" ");
            String s = S[0];
            String t = S[1];
            Solution ob = new Solution();
            int ans = ob.editDistance(s, t);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


class Solution {
     int mem[][];
    public int editDistance(String s, String t) {
        // Code here
        return tab(s,t);
    }
    public int tab(String s, String t){
        int [][] dp = new int[s.length()+1][t.length()+1];
        for(int i =0;i<=s.length();i++){
            dp[i][0] = i;
        }
        for(int i =0;i<=t.length();i++) dp[0][i] = i;
        
        for(int i =1;i<=s.length();i++){
            for(int j =1;j<=t.length();j++){
                if(s.charAt(i-1) == t.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+ Math.min(dp[i-1][j-1],Math.min(dp[i-1][j],dp[i][j-1]));
                }
            }
            
        }
        return dp[s.length()][t.length()];
    }
    public int helper(String s, String t , int i, int j){
        if(i == s.length() || j == t.length()){
            return s.length() - i+t.length() - j;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        if(s.charAt(i) == t.charAt(j)){
            return mem[i][j] = helper(s,t,i+1,j+1);
        }
        int min =  1+helper(s,t,i+1,j);//delete
        min = Math.min(min,1+ helper(s,t,i,j+1));//add
        min = Math.min(min,1+helper(s,t,i+1,j+1));//replace
        return mem[i][j] =  min;
    }
}