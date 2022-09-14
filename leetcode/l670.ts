function maximumSwap(num: number): number {
    const list = [] as Array<number>;
    while (num != 0) {
        list.push(num % 10);
        num = Math.floor(num / 10);
    }
    let n = list.length, ans = 0;
    const idx = [] as Array<number>;
    for (let i = 0, j = 0; i < n; i++) {
        if (list[i] > list[j]) j = i;
        idx.push(j);
    }
    console.log(list, idx);
    // for (let i = n - 1; i >= 0; i--) {
    //     if (list[idx[i]] != list[i]) {
    //         const temp = list[idx[i]];
    //         list[idx[i]] = list[i]
    //         list[i] = temp;
    //         break;
    //     }
    // }
    for (let i = n - 1; i >= 0; i--) ans = ans * 10 + list[i];

    return ans;
};
