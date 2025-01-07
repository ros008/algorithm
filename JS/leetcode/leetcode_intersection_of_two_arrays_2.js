/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
// 정렬
// var intersect = function(nums1, nums2) {
//     nums1.sort((a, b) => a - b);
//     nums2.sort((a, b) => a - b);
//     let i = 0, j = 0;
//     const ans = [];
//     while(i<nums1.length && j<nums2.length) {
//         if(nums1[i] === nums2[j]) {
//             ans.push(nums1[i]);
//             i++;
//             j++;
//         } else if(nums1[i] < nums2[j]) {
//             i++;
//         } else {
//             j++;
//         }
//     }
//     return ans;
// };

// Map 사용
var intersect = function (nums1, nums2) {
  const ans = [];
  const map = new Map();
  for (let i = 0; i < nums1.length; i++) {
    map.set(nums1[i], (map.get(nums1[i]) || 0) + 1);
  }
  for (let j = 0; j < nums2.length; j++) {
    if (map.has(nums2[j]) && map.get(nums2[j]) > 0) {
      map.set(nums2[j], map.get(nums2[j]) - 1);
      ans.push(nums2[j]);
    }
  }
  return ans;
};
