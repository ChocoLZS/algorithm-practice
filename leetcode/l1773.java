package leetcode;

import java.util.*;

public class l1773 {
    Map<String,Integer> map = new HashMap<>(){{
        put("type",0);
        put("color",1);
        put("name",2);
    }};

    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int res = 0;
        for (List<String> list : items) {
            if (list.get(map.get(ruleKey)).equals(ruleValue))
                res++;
        }
        return res;
    }
}
