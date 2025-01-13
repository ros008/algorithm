/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function (s) {
  s = s.trim();

  let sign = 1;
  let num = 0;
  let i = 0;
  const INT_MAX = Math.pow(2, 31) - 1;
  const INT_MIN = -Math.pow(2, 31);

  if (i < s.length && (s[i] === "+" || s[i] === "-")) {
    sign = s[i] === "-" ? -1 : 1;
    i++;
  }

  while (i < s.length && /^\d$/.test(s[i])) {
    num = num * 10 + parseInt(s[i]);
    i++;
  }
  num *= sign;
  num = Math.max(Math.min(num, Math.pow(2, 31) - 1), -Math.pow(2, 31));
  return num;
};
