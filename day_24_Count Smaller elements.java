//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int arr[] = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                arr[i] = Integer.parseInt(s[i]);
            }

            int[] ans = new Solution().constructLowerArray(arr);
            for (int i = 0; i < arr.length; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends




// User function Template for Java

class Solution {
   static class TreeNode {
        int val;
        int count;
        TreeNode left, right;
        
        public TreeNode(int val){
            this.val = val;
            this.count = 1;
        }
    }
    
    int[] constructLowerArray(int[] arr) {
        // code here
        int[] ans = new int[arr.length];
        TreeNode root = null;
        
        for (int i = arr.length - 1; i >= 0; i--){
            root = insertAndCount(root, arr[i], ans, i);
        }
        return ans;
    }
    
    TreeNode insertAndCount(TreeNode root, int val, int[] ans, int index){
        if (root == null){
            root = new TreeNode(val);
        } else if (val <= root.val){
            root.count++;
            root.left = insertAndCount(root.left, val, ans, index);
        } else {
            ans[index] += root.count;
            root.right = insertAndCount(root.right, val, ans, index);
        }
        return root;
    }
}