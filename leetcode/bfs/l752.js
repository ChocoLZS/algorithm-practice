/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
var openLock = function (deadends, target) {
    let deadend = new Set();
    for (let i = 0; i < deadends.length; i++) {
        deadend.add(deadends[i]);
    }
    let queue = [];
    let base = "0000";
    let step = 0;
    if (base == target) return step;
    queue.push(base);
    while (queue.length !== 0) {
        let queueLen = queue.length
        for (let i = 0; i < queueLen; i++) {
            let curPass = queue.shift();
            if (deadend.has(curPass)) continue;
            if (curPass == target) return step;
            deadend.add(curPass);
            for (let i = 0; i < 4; i++) {
                let _pass = minusOne(curPass, i);
                if (!deadend.has(_pass)) {
                    queue.push(_pass);
                }
            }
            for (let i = 0; i < 4; i++) {
                let _pass = plusOne(curPass, i);
                if (!deadend.has(_pass)) {
                    queue.push(_pass);
                }
            }
        }
        step++;
    }
    return -1;
};

function minusOne(str, index) {
    let ch = str.charAt(index);
    if (ch == '0')
        ch = '9';
    else {
        ch = ch - 1;
    }
    return str.substring(0, index) + ch + str.substring(index + 1, 4);
}
function plusOne(str, index) {
    let ch = str.charAt(index);
    if (ch == '9')
        ch = '0';
    else {
        ch = (parseInt(ch) + 1).toString();
    }
    return str.substring(0, index) + ch + str.substring(index + 1, 4);
}
