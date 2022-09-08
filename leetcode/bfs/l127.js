/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
//BFS
var ladderLength = function (beginWord, endWord, wordList) {
    if (!wordList.includes(endWord)) return 0;
    let step = 1;
    let wordSet = new Set(wordList);
    let wordTable = [];
    for (let i = 0; i < endWord.length; i++) {
        wordTable.push(new Set());
    }
    for (let i = 0; i < endWord.length; i++) {
        wordSet.forEach((v) => {
            wordTable[i].add(v.charAt(i))
        })
    }
    let visited = new Set();
    let queue = [];
    queue.push(beginWord);
    while (queue.length !== 0) {
        let queueLen = queue.length;
        for (let i = 0; i < queueLen; i++) {
            let cur = queue.shift();
            if (visited.has(cur)) continue;
            if (cur == endWord) return step;
            visited.add(cur);
            for (let j = 0; j < wordTable.length; j++) {
                for (let ch of wordTable[j]) {
                    let nextStr = changeChar(cur, ch, j);
                    if (!visited.has(nextStr) && wordSet.has(nextStr)) {
                        queue.push(nextStr);
                    }
                }
            }
        }
        step++;
    }
    return 0;
};

function changeChar(str, ch, index) {
    return str.substring(0, index) + ch + str.substring(index + 1, str.length);
}