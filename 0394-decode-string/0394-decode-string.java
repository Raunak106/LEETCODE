import java.util.*;

class Solution {

    public String decodeString(String s) {

        Stack<Integer> number = new Stack<>();
        Stack<StringBuilder> string = new Stack<>();

        StringBuilder current = new StringBuilder();
        int num = 0;

        for(int i = 0; i < s.length(); i++){

            char currentChar = s.charAt(i);

            if(Character.isDigit(currentChar)){
                num = num * 10 + (currentChar - '0');
            }

            else if(currentChar == '['){
                number.push(num);
                string.push(current);
                current = new StringBuilder();
                num = 0;
            }

            else if(currentChar == ']'){

                int times = number.pop();
                StringBuilder prev = string.pop();

                while(times-- > 0){
                    prev.append(current);
                }

                current = prev;
            }

            else{
                current.append(currentChar);
            }
        }

        return current.toString();
    }
}
