/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let ans = 0;
  let min = prices[0];

  for (let i = 1; i < prices.length; i++) {
    min = Math.min(min, prices[i]);
    ans = Math.max(ans, prices[i] - min);
  }

  return ans;
};
