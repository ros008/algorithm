function getCombination(lookup, selectNum) {
  if (selectNum === 1) return lookup.map((el) => [el]);
  const results = [];
  lookup.forEach((fixed, index, origin) => {
    const rest = [...origin.slice(0, index), ...origin.slice(index + 1)];
    const combinations = getCombination(rest, selectNum - 1);
    const attached = combinations.map((el) => [fixed, ...el]);
    results.push(...attached);
  });
  return results;
}

function matches(user_id, banned_id) {
  const pattern = banned_id.replace(/\*/g, ".");
  const reg = new RegExp(`\^${pattern}\$`);
  return reg.test(user_id);
}

function listMatches(user_ids, banned_ids) {
  for (let k = 0; k < user_ids.length; k++) {
    if (!matches(user_ids[k], banned_ids[k])) {
      return false;
    }
  }
  return true;
}

function solution(user_id, banned_id) {
  let answer = 0;
  const set = new Set();

  const combination = getCombination(user_id, banned_id.length);

  for (let i = 0; i < combination.length; i++) {
    if (listMatches(combination[i], banned_id)) {
      const ordered = combination[i].sort().join("");
      set.add(ordered);
    }
  }

  return set.size;
}

// function solution(user_id, banned_id) {
//   const selected = Array(user_id.length).fill(false);
//   const regex = banned_id.map(id => new RegExp(`^${id.replaceAll('*', '.')}$`));
//   const set = new Set();

//   const dfs = (index = 0, arr = []) => {
//       if (index === banned_id.length) {
//           set.add(arr.sort().join(','));
//       } else {
//           for (let i = 0; i < user_id.length; i++) {
//               if (selected[i]) {
//                   continue;
//               }

//               if (user_id[i].match(regex[index])) {
//                   selected[i] = true;
//                   dfs(index + 1, [...arr, user_id[i]]);
//                   selected[i] = false;
//               }
//           }
//       }
//   };

//   dfs();

//   return set.size;
// }
