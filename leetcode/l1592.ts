function reorderSpaces(text: string): string {
    const readSpace = 0;
    const readChar = 1;
    let record = [] as Array<string>;
    let str = '';
    let count = 0;
    let i = 0;
    let status = text.charAt(0) == ' ' ? readSpace : readChar;
    while (i < text.length) {
        switch (status) {
            case readSpace:
                if (text.charAt(i) == ' ') {
                    count++;
                } else {
                    str += text.charAt(i);
                    status = readChar;
                }
                break;
            case readChar:
                if (text.charAt(i) == ' ') {
                    record.push(str);
                    str = '';
                    status = readSpace;
                    count++;
                } else {
                    str += text.charAt(i);
                }
                break;
        }
        i++;
    }
    if (str !== '') record.push(str);
    let padding = '';
    let res;
    let paddingSpace = record.length != 1 ? Math.floor(count / (record.length - 1)) : count;
    for (i = 0; i < paddingSpace; i++) {
        padding += ' ';
    }
    if (record.length == 1) {
        res = record[0];
    } else {
        res = record.join(padding);
        padding = ''
        for (i = 0; i < count % (record.length - 1); i++) {
            padding += ' ';
        }
    }
    res = res.concat(padding);
    return res
};

console.log(reorderSpaces("  hello"))