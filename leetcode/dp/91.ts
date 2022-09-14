function numDecodings(s: string): number {
    let res = 0;
    if (s.length == 1) {
        let ch = charMapping(s);
        if (ch == "#") return res;
        return res + 1;
    }
    if (s.length == 2) {

    }
};

function charMapping(ch: string): string {
    let fail = "#";
    if (ch.length == 1) {
        if (ch.charAt(0) == "0") return fail;
        return String.fromCharCode('A'.charCodeAt(0) + (Number.parseInt(ch) - 1));
    }
    if (ch.length == 2) {
        if (ch.charAt(0) > "2" || ch.charAt(0) < "1") {
            return fail;
        }
        if (ch.charAt(0) == "2" && ch.charAt(1) > "6") {
            return fail;
        }
        return String.fromCharCode('A'.charCodeAt(0) + (Number.parseInt(ch) - 1));
    }
    return fail;
}