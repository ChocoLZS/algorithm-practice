package leetcode;

import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class l807 {
    class Pairs {
        int val;
        int flag;
        boolean visited;

        Pairs(int val, int flag) {
            this.val = val;
            this.flag = flag;
            this.visited = false;
        }
    }

    public int[] advantageCount(int[] nums1, int[] nums2) {
        int len = nums1.length;
        int[] res = new int[len];
        List<Integer> nums1_list = Arrays.stream(nums1).boxed().collect(Collectors.toList());
        List<Pairs> nums2_list = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            nums2_list.add(new Pairs(nums2[i], i));
        }
        //逆序
        Collections.sort(nums1_list,(a,b)->b-a);
        //逆序
        Collections.sort(nums2_list, (a, b) -> b.val - a.val);
        int i = 0, p = 0;
        for (; i < len && p < len;) {
            Pairs pairs = nums2_list.get(p);
            Integer integer = nums1_list.get(i);
            if (pairs.val < integer.intValue()) {
                res[pairs.flag] = integer.intValue();
                pairs.visited = true;
                i++;
            }
            p++;
        }
        for (p = 0; p < len; p++,i++) {
            Pairs pairs = nums2_list.get(p);
            if (!pairs.visited) {
                res[pairs.flag] = nums1_list.get(i).intValue();
                i++;
            }
                
        }
        return res;
    }
}
