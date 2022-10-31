package leetcode.string;

import java.util.*;

public class l811 {
    public List<String> subdomainVisits(String[] cpdomains) {
        ArrayList<String> res = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();
        for (String domain : cpdomains) {
            String[] splits = domain.split(" ");
            int count = Integer.parseInt(splits[0]);
            String[] subdomains = splits[1].split("\\.");
            String curDom = "";
            for (int i = subdomains.length - 1; i >= 0; i--) {
                if (i == subdomains.length - 1) {
                    curDom =  subdomains[i];
                } else {
                    curDom =  subdomains[i] + "." + curDom;
                }
                if (map.get(curDom) == null) {
                    map.put(curDom, count);
                } else {
                    Integer curCount = map.get(curDom);
                    map.put(curDom, curCount.intValue() + count);
                }
            }
        }
        map.forEach((domain, count) -> {
            res.add(count.toString() + " " + domain);
        });
        return res;
    }
}
