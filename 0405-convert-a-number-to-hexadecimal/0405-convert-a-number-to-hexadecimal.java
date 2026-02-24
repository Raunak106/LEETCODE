class Solution {
    public String toHex(int num) {
        if (num == 0) return "0";
        
        char[] hex = "0123456789abcdef".toCharArray();
        StringBuilder sb = new StringBuilder();
        
        while (num != 0) {
            sb.append(hex[num & 15]);   // 15 = 0xF (last 4 bits)
            num >>>= 4;                 // unsigned right shift by 4 bits
        }
        
        return sb.reverse().toString();
    }
}
