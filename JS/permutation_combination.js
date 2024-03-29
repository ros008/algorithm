// 순열(permutation)은 서로 다른 n개의 원소를 가지는 어떤 집합에서 중복 없이 순서에 상관있게 r개의 원소를 선택하거나 혹은 나열하는 것이며, 이는 조합과 마찬가지로 n개의 원소로 이루어진 집합에서 r개의 원소로 이루어진 부분집합을 만드는 것과 같다.

// 조합(combination)은 서로 다른 n개의 원소를 가지는 어떤 집합에서 중복 없이 순서에 상관없게 r개의 원소를 선택하는 것이며, 이는 n개의 원소로 이루어진 집합에서 r개의 원소로 이루어진 부분집합을 만드는 것과 같다.

// 반복문으로 순열과 조합을 만들어낼 수는 있다. 하지만 개수가 늘어나면 반복문의 수도 늘어나며 뽑아야 되는 개수가 n개처럼 변수로 들어왔을 때 대응이 어렵다.
// 그렇기에 순열과 조합은 재귀를 사용하여 풀이하는 경우가 많다.

/**
 * getCombination - 조합 재귀
 * @param {Array} lookup 아직 선택되지 않은 후보군 리스트
 * @param {number} selectNumber 선택해야할 개수
 * @returns 조합 가능한 Array
 */
const getCombination = (lookup, selectNumber) => {
  const results = [];
  if (selectNumber === 1) return lookup.map((el) => [el]);
  lookup.forEach((fixed, index, origin) => {
    const rest = origin.slice(index + 1);
    const combinations = getCombination(rest, selectNumber - 1);
    const attached = combinations.map((el) => [fixed, ...el]);
    results.push(...attached);
  });
  return results;
};

/**
 * getPermutation - 순열 재귀
 * @param {Array} lookup 아직 선택되지 않은 후보군 리스트
 * @param {number} selectNumber 선택해야할 개수
 * @returns 조합 가능한 Array
 */
// 순열 재귀
const getPermutation = (lookup, selectNumber) => {
  const results = [];
  if (selectNumber === 1) return lookup.map((el) => [el]);
  lookup.forEach((fixed, index, origin) => {
    const rest = [...origin.slice(0, index), ...origin.slice(index + 1)];
    const permutations = getPermutation(rest, selectNumber - 1);
    const attached = permutations.map((el) => [fixed, ...el]);
    results.push(...attached);
  });
  return results;
};
// Input: [1,2,3,4]
// 1(fixed) -> permutation([2,3,4]) -> 2(fixed) -> permutation(3,4) -> ...
// 2(fixed) -> permutation([1,3,4]) -> 1(fixed) -> permutation(3,4) -> ...
// 3(fixed) -> permutation([1,2,4]) -> ...
// 4(fixed) -> permutation([1,2,3]) -> ...

const resCombination = getCombination([1, 2, 3, 4, 5], 5);
console.log(resCombination, resCombination.length);

const resPermutation = getPermutation([1, 2, 3, 4, 5], 5);
console.log(resPermutation, resPermutation.length);
