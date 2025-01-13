/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
  const arr = s
    .toLowerCase()
    .split("")
    .filter((x) => x.match(/[A-Za-z0-9]/));
  for (let i = 0; i < arr.length / 2; i++) {
    if (arr[i] !== arr[arr.length - 1 - i]) return false;
  }
  return true;
};
