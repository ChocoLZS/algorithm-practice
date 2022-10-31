package leetcode;

import java.util.*;

public class l927 {
    
    public int[] threeEqualParts(int[] arr) {
        int[] res = { -1, -1 };
        ArrayList<Integer> index_1 = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 1) {
                index_1.add(i);
            }
        }
        int size = index_1.size();
        if (size % 3 == 0 && size != 0) {
            int start_1 = 0;
            int end_1 = index_1.get((size / 3) - 1);
            int start_2 = index_1.get((size / 3));
            int end_2 = index_1.get((size / 3) * 2 - 1);
            int start_3 = index_1.get((size / 3) * 2);
            int end_3 = arr.length - 1;

            String firstpart = calcBina(arr, start_1, end_1);
            String secondpart = calcBina(arr, start_2, end_2);
            String thirdpart = calcBina(arr, start_3, end_3);
            while (end_1 < start_2 && end_2 < start_3) {
                if (s) {
                    res[0] = end_1;
                    res[1] = end_2 + 1;
                    break;
                }
                if (firstpart.compareTo(thirdpart) < 0) {
                    end_1++;
                    firstpart += Integer.toString(arr[end_1]);
                    continue;
                } else if (firstpart.compareTo(thirdpart) > 0) {
                    break;
                }
                //firstpart == thridpart
                if (secondpart.compareTo(thirdpart) < 0) {
                    end_2++;
                    secondpart += Integer.toString(arr[end_2]);
                    continue;
                } else if (secondpart.compareTo(thirdpart) > 0) {
                    break;
                }
            }
        }
        if (size == 0) {
            res[0] = 0;
            res[1] = arr.length - 1;
        }
        return res;
    }

    String calcBina(int[] arr, int start, int end) {
        String res = "";
        for (int i = start; i <= end; i++) {
            if (res.length() == 0 && arr[i] == 0)
                continue;
            res += Integer.toString(arr[i]);
        }
        return res;
    }
}
