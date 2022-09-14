package leetcode;

public class l26 {
    public int removeDuplicates(int[] nums) {
        int placeIndex = 0;
        for (int item : nums) {
            if (item != nums[placeIndex]) {
                nums[++placeIndex] = item;
            }
        }
        return placeIndex + 1;
    }
}
