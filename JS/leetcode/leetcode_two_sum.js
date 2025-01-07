/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const map = new Map();
  for (let i = 0; i < nums.length; i++) {
    const sub = target - nums[i];
    if (map.has(sub)) {
      return [map.get(sub), i];
    }
    map.set(nums[i], i);
  }
  return [];
};
