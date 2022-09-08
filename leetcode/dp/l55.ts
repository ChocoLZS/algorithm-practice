function canJump(nums: number[]): boolean {
    let step = 0
    for (let i = 0; i < nums.length; i++) {
        if (i > step) return false;
        step = Math.max(step, i + nums[i])
    }
    return true;
};

canJump([3, 2, 1, 0, 4])