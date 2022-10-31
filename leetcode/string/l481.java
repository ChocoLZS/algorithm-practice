package leetcode.string;

public class l481 {
    public int magicalString(int n) {
        StringBuilder sb = new StringBuilder();
        sb.append("122");
        int strPtr = 2;
        int elePtr = 3;
        int count = 1;
        String newStr = "";
        int left = 0;
        while (elePtr < n) {
            if (left == 0) {
                if(sb.charAt(strPtr) == '1'){
                    left = 1;
                } else {
                    left = 2;
                }
                if (sb.charAt(elePtr - 1) == '1') {
                    newStr = "2";
                } else {
                    newStr = "1";
                }
                strPtr++;
            } else {
                if (newStr == "1") {
                    count++;
                }
                sb.append(newStr);
                elePtr++;
                left--;
            }
        }
        return count;
    }
}
