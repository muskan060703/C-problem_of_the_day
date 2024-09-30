// User function Template for Java

class Solution {
    int[] mem;
    public int minimizeCost(int k, int arr[]) {
        // code here
        mem = new int[arr.length+1];
        Arrays.fill(mem,-1);
        return helper(arr,0,k);
    }
    public int helper(int[] arr,int i, int k){
        if(i == arr.length-1){
            return 0;
        }
        if(mem[i] !=-1){
            return mem[i];
        }
        int cost = Integer.MAX_VALUE;
        for(int next = i+1;next <=i+k && next<arr.length ;next++){
            cost = Math.min(cost,Math.abs(arr[next] - arr[i]) + helper(arr,next,k));
        }
        return mem[i] = cost;
    }
}
