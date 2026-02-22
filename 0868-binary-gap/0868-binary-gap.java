class Solution {
    public int binaryGap(int n) {
        int last=-1;
        int curr=0;
        int max=0;

        while(n>0){
            if((n & 1)== 1){
                if(last != -1){
                    max= Math.max(max,curr - last);

                }
                last=curr;
            }
            curr++;
            n=n>>1;

        }

        return max;
    }
}