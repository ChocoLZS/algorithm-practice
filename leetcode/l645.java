package leetcode;

import java.util.*;

public class l645 {
    public int[] findErrorNums(int[] nums) {
        List<Integer> list = new ArrayList<>();
        int pre, cur;
        pre = cur = 0;
        for (cur = 1; cur < nums.length; cur++, pre++) {
            if (nums[pre] == nums[cur]) {
                list.add(nums[cur]);
            } else {
                int gap = nums[cur] - nums[pre];
                if (gap >= 2) {
                    for (int i = 1; i < gap; i++) {
                        list.add(nums[pre] + i);
                    }
                }
            }
        }
        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            res[i] = list.get(i);
        }
        return res;
    }
}
