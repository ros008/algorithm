/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }

  const map = new Map();
  for (let c of s) {
    map.set(c, (map.get(c) || 0) + 1);
  }

  for (let c of t) {
    if (!map.has(c) || map.get(c) === 0) return false;
    map.set(c, map.get(c) - 1);
  }

  return true;
};
