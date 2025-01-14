/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function (s) {
  let sign = 1;
  let idx = 0;
  let ret = 0;

  const INT_MAX = Math.pow(2, 31) - 1;
  const INT_MIN = -Math.pow(2, 31);

  s = s.trim();

  if (s[idx] === "-") {
    sign = -1;
    idx++;
  } else if (s[idx] === "+") {
    idx++;
  }

  while (idx < s.length && /^\d/.test(s[idx])) {
    ret = ret * 10 + parseInt(s[idx]);
    idx++;
  }

  ret *= sign;
  if (ret > INT_MAX) return INT_MAX;
  else if (ret < INT_MIN) return INT_MIN;
  return ret;
};
