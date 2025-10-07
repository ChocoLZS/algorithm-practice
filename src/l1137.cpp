#include "leetcode.hpp"

#define indexOf(n) (n + 3) % 3

int main() {
    int n = 25;
    uint32_t t[3] = {0, 1, 1};
    if (n <= 2) {
        return t[n];
    }

    for (int i = 3; i <= n; i++) {
        t[indexOf(i)] = t[indexOf(i-1)] + t[indexOf(i-2)] + t[indexOf(i-3)];
    }
    
    printf("%d", t[indexOf(n)]);

    return 0;
}


// #define indexOf(n) (n + 3) % 3

// class Solution {
// public:
//     int tribonacci(int n) {
//         uint32_t t[3] = {0, 1, 1};
//         if (n <= 2) {
//             return t[n];
//         }

//         for (int i = 3; i <= n; i++) {
//             t[indexOf(i)] =
//                 t[indexOf(i - 1)] + t[indexOf(i - 2)] + t[indexOf(i - 3)];
//         }

//         return t[indexOf(n)];
//     }
// };