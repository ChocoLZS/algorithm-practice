import java.util.*;

class l119 {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new LinkedList<>();
        list.add(1);
        for (int i = 1; i <= rowIndex; i++) {
            list.add(0);
            for (int index = i; index > 0; index--) {
                list.set(index, list.get(index - 1) + list.get(index));
            }

        }
        return list;
    }
}