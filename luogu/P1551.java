import java.util.*;

public class Main {
    static int[] fa;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] strs = in.nextLine().split(" ");
        int n = Integer.parseInt(strs[0]);
        int m = Integer.parseInt(strs[1]);
        int p = Integer.parseInt(strs[2]);
        fa = new int[n+1];
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
        for (int i = 0; i < m; i++) {
            strs = in.nextLine().split(" ");
            merge(Integer.parseInt(strs[0]), Integer.parseInt(strs[1]));
        }
        for (int i = 0; i < p; i++) {
            strs = in.nextLine().split(" ");
            if (find(Integer.parseInt(strs[0])) == find(Integer.parseInt(strs[1]))) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
    
    static int find(int i) {
        if (i == fa[i]) {
            return i;
        } else {
            return find(fa[i]);
        }
    }

    static void merge(int i, int j) {
        fa[find(j)] = find(i);
    }
}