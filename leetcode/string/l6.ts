//(i-1)*n;
//node counts i + (i-1)*2 * n;
function convert(s: string, numRows: number): string {
    if (numRows == 1) return s;
    let straightBars = getStraightBars(s, numRows);
    let xBars = getXBars(s, numRows);
    console.log(straightBars, xBars);
    let res = '';
    for (let bias = 0; bias < numRows; bias++) {
        for (let [index, item] of straightBars.entries()) {
            res = res + item.charAt(bias);
            if (bias != 0 && bias != numRows - 1) {
                if (xBars[index])
                    res = res + xBars[index].charAt(numRows - 2 - bias);
            }
        }
    }
    return res;
};

function getStraightBars(s: string, numRows: number): Array<string> {
    let index = 0;
    let arr = [];
    while ((index + numRows) <= s.length) {
        arr.push(s.substring(index, index + numRows));
        index += 2 * numRows - 2;
    }
    if (index < s.length) {
        arr.push(s.substring(index, s.length));
    }
    return arr;
}
function getXBars(s: string, numRows: number): Array<string> {
    let index = numRows;
    let arr = [];
    if (numRows <= 2) return arr;
    while ((index + numRows - 2) <= s.length) {
        arr.push(s.substring(index, index + numRows - 2));
        index += 2 * numRows - 2;
    }
    if (index < s.length) {
        arr.push(s.substring(index, s.length));
    }
    return arr;
}

convert("PAYPALISHIRING", 4);

