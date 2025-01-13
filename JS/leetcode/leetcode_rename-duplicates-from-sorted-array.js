/**
 * @param {number[]} nums
 * @return {number}
 */

// 증가하는 순서로 주어짐.
var removeDuplicates = function (nums) {
  let prev = 0;

  for (let i = 1; i < nums.length; i++) {
    if (nums[i] !== nums[prev]) {
      nums[++prev] = nums[i];
    }
  }

  return prev + 1;
};
