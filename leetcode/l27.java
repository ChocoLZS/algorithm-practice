package leetcode;

public class l27 {
    public int removeElement(int[] nums, int val) {
        int slot = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[slot] = nums[i];
                slot++;
            }
        }
        return slot;
    }
}
