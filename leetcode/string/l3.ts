
//map
// function _lengthOfLongestSubstring(s: string): number {
//     let ans = 0;
//     let start, end;
//     start = end = 0;
//     let map = new Map<string, number>();
//     while (end < s.length) {
//         let ch = s.charAt(end);
//         if (map.has(ch)) {
//             let curIndex = map.get(ch);
//             for (; start <= curIndex; start++) {
//                 map.delete(ch);
//             }
//         }
//         map.set(ch, end);
//         ans = Math.max(ans, end - start + 1);
//         end += 1;
//     }
//     return ans;
// };

//set
function lengthOfLongestSubstring(s: string): number {
    let ans = 0;
    let start = 0, end = 0;
    let set = new Set<string>();
    while (end < s.length) {
        let ch = s.charAt(end);
        if (set.has(ch)) {
            while (start < end && ch != s.charAt(start)) {
                set.delete(ch);
                start++;
            }
            if (start < end && ch == s.charAt(start)) {
                start++;
            }
        }
        set.add(ch);
        ans = Math.max(ans, end - start + 1);
        end++;
    }
    return ans;
}
