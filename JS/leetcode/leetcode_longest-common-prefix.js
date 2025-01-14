/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  let minLen = 200;
  let ret = "";

  for (let str of strs) minLen = Math.min(minLen, str.length);

  for (let i = 0; i < minLen; i++) {
    let isSame = true;
    let cur = strs[0][i];
    for (let j = 1; j < strs.length; j++) {
      if (strs[j][i] !== cur) {
        isSame = false;
        break;
      }
    }
    if (isSame) ret += cur;
    else break;
  }

  return ret;
};

/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  let ret = "";

  strs.sort();

  let first = strs[0];
  let last = strs[strs.length - 1];

  for (let i = 0; i < first.length; i++) {
    if (first[i] === last[i]) ret += first[i];
    else break;
  }

  return ret;
};
