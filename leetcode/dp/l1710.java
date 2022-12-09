import java.util.*;

public class l1710 {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        int res = 0;
        Arrays.sort(boxTypes,(a,b)->{
            return b[1] - a[1];
        });
        for (int[] boxType : boxTypes) {
            if (truckSize > boxType[0]) {
                truckSize -= boxType[0];
                res += boxType[0] * boxType[1];
            } else {
                res += truckSize * boxType[1];
                break;
            }
        }
        return res;
    }
}
