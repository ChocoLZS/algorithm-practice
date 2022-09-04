function smallestStringWithSwaps(s: string, pairs: number[][]): string {

};
function calcBestPath(pairs: number[][]) {
    for (let item of pairs) {
        item.sort();
    }
    pairs.sort();
    let startIndexMap = new Map<number, number>();
    for (let [idx, item] of pairs.entries()) {
        if (!startIndexMap.has(item[0])) {
            startIndexMap.set(item[0], idx);
        }
    }
    for (let item of startIndexMap) {
        let nextIdx = item[1];
    }


}