/**
 * @param {number} n
 * @param {number} presses
 * @return {number}
 */
var flipLights = function (n, presses) {
    let arr = new Array(n).fill(0);
    let res = new Set();
    for (let method1 = 0; method1 <= presses; method1++) {
        for (let method2 = 0; method2 + method1 <= presses; method2++) {
            for (let method3 = 0; method3 + method2 + method1 <= presses; method3++) {
                let method4 = presses - (method3 + method2 + method1)
                arr = new Array(n).fill(0);
                for (let index = 0; index < n; index++) {
                    if (flip(index, method1, method2, method3, method4)) {
                        arr[index] = arr[index] ^ 1;
                    }
                }
                res.add(arr.join(''));

            }
        }
    }
    return res.size;
};

flipLights(3, 1)

function flip(index, method1, method2, method3, method4) {
    let flipCount = 0;
    flipCount += method1;
    if ((index + 1) % 2 == 0) {
        flipCount += method2;
    } else {
        flipCount += method3;
        if (index % 3 == 0) {
            flipCount += method4;
        }
    }
    console.log(flipCount)
    return flipCount % 2 !== 0;
}
