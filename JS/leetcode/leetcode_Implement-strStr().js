/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
  let ret = -1;
  for (let i = 0; i < haystack.length - needle.length + 1; i++) {
    if (haystack[i] !== needle[0]) {
      continue;
    }

    let p1 = i;
    let p2 = 0;
    let count = 0;

    while (p2 < needle.length && haystack[p1] === needle[p2]) {
      p1++;
      p2++;
      count++;
    }

    if (count === needle.length) {
      ret = i;
      break;
    }
  }
  return ret;
};
