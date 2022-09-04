function isValidSerialization(preorder: string): boolean {
    if (preorder == '#') return true;
    let strs = preorder.split(',');
    let index = 0;
    if (strs.length == 1 && strs[0] == '#') return true;
    const dfs = (str: string, parent: string): boolean => {
        if (index >= strs.length) return true;
        if (parent === '#' && str !== undefined || str === undefined) return false;
        if (str === '#') return true;
        return dfs(strs[++index], str) && dfs(strs[++index], str) && true;
    }
    return dfs(strs[index], strs[index]) && (index === strs.length);
};