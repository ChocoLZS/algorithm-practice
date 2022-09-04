function longestPalindrome(s: string): string {
    let res = '';
    for (let i = 0; i < s.length; i++) {
        let str = helper(s, i);
        res = res.length > str.length ? res : str;
    }
    return res;
};

function helper(s: string, startIndex: number): string {
    let left, right;
    left = startIndex - 1;
    right = startIndex + 1;
    let res = s.charAt(startIndex);
    while (left >= 0 && s.charAt(left) == s.charAt(startIndex)) {
        res = res.concat(s.charAt(left));
        left--;
    }
    while (right < s.length && s.charAt(right) == s.charAt(startIndex)) {
        res = res.concat(s.charAt(right));
        right++;
    }
    while (left >= 0 && right < s.length) {
        if (s.charAt(left) != s.charAt(right)) {
            break;
        }
        res = s.charAt(left) + res + s.charAt(right);
        left--;
        right++;
    }
    return s.substring(left + 1, right);
}