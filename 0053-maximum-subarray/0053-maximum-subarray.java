class Solution {
    public int maxSubArray(int[] nums) {
        int max = nums[0], sum = 0;

        for(int x : nums){
            sum = Math.max(x, sum + x);
            max = Math.max(max, sum);
        }
        return max;
    }
}
