function isValid(s: string): boolean {
    let stack = [];
    if (s.length == 1) return false;
    for (let i = 0; i < s.length; i++) {
        if (isLeft(s.charAt(i))) {
            stack.push(s.charAt(i));
        } else {
            if (stack.length == 0) return false;
            let left = stack.pop();
            if (!isMatch(left, s.charAt(i))) return false;
        }
    }
    return stack.length == 0;
};

function isMatch(left: string, right: string): boolean {
    let flag = true;
    switch (left) {
        case '(':
            flag = right == ')';
            break;
        case '{':
            flag = right == '}';
            break;
        case '[':
            flag = right == ']';
            break;
        default:
            flag = false;
    }
    return flag;
}

function isLeft(left: string): boolean {
    switch (left) {
        case '(':
        case '[':
        case '{':
            return true;
    }
    return false;
}