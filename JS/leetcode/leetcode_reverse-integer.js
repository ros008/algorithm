/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
  let res = 0;
  if (x < 0) {
    res = parseInt(x.toString().split("").slice(1).reverse().join("")) * -1;
  } else {
    res = parseInt(x.toString().split("").reverse().join(""));
  }

  if (res > Math.pow(2, 31) - 1 || res < -Math.pow(2, 31)) return 0;

  return res;
};
