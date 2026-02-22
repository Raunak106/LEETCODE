class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] ans=new int[2*n];
        int a=0, b=n;
        for(int i=0 ; i<2*n ; i++){
            if(i%2 == 1){
                ans[i]=nums[b++];
            }
            if(i%2 ==0 ){
                ans[i]=nums[a++];
            }
        }
        return ans;
        
    }
}