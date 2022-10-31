public class l784 {
    static final int INIT = 0;
    static final int MULTI = 1;
    static final int ZERO = 2;
    public boolean checkOnesSegment(String s) {
        int state = ZERO;
        int res = 0;
        for (int i = 0;i < s.length();i++) {
            char token = s.charAt(i);
            switch (state) {
                case INIT:
                    if (token == '1') {
                        state = MULTI;
                    }else {
                        state = ZERO;
                    }
                    break;
                case MULTI:
                    if (token == '0') {
                        state = ZERO;
                    }
                    break;
                case ZERO:
                    if (token == '1') {
                        res++;
                        state = INIT;
                    }
                    break;
            }
        }
        return res <=1;
    }
}
