import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import java.util.*;

public class test {
    public static void main(String[] args) {
        int[] item = { 1, 1, 1, 1, 0, 0 };
        List<Integer> list = new LinkedList<>();
        for (int i = 0; i < 10; i++) {
            list.add(1);
        }
        list.add(5);
        list.remove(5);
        System.out.println(list.toString());
    }
}
