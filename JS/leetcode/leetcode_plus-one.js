/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
  let pivot = digits.length - 1;
  digits[digits.length - 1] += 1;

  while (pivot >= 0) {
    if (digits[pivot] < 10) {
      break;
    }

    digits[pivot] = 0;
    if (pivot === 0) {
      digits.unshift(1);
      break;
    }
    pivot--;
    digits[pivot] += 1;
  }

  // for 문
  for (let i = digits.length - 1; i >= 0; i--) {
    if (digits[i] + 1 !== 10) {
      digits[i] += 1;
      break;
    }

    digits[i] = 0;
    if (i === 0) {
      digits.unshift(1);
      break;
    }
  }
  return digits;
};
