package leetcode;

import java.util.ArrayList;
import java.util.List;

public class l1441 {
    public List<String> buildArray(int[] target, int n) {
        List<String> res = new ArrayList<>();
        int ele = 1;
        for (int num : target) {
            while (ele < num) {
                res.add("Push");
                res.add("Pop");
                ele++;
            }
            res.add("Push");
            ele++;
        }
        return res;   
    }
}
