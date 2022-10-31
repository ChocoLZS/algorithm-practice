package leetcode;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

class l1700 {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] breads = new int[2];
        for (int stu : students)
            breads[stu]++;
        for (int i = 0; i < sandwiches.length; i++) {
            breads[sandwiches[i]]--;
            if (breads[sandwiches[i]] == -1)
                return sandwiches.length - i;
        }
        return 0;
    }
}