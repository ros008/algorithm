function solution(skill, skill_trees) {
  var answer = 0;
  let skill_arr = skill.split("");
  for (let i = 0; i < skill_trees.length; i++) {
    const skill_tree = skill_trees[i]
      .split("")
      .filter((w) => skill_arr.includes(w))
      .join("");
    if (skill_tree === skill.slice(0, skill_tree.length)) answer++;
  }

  return answer;
}
