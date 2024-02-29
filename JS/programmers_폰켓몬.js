// https://school.programmers.co.kr/learn/courses/30/lessons/1845

function solution(nums) {
    let answer = 0;
    const map =  new Map();
    nums.forEach(num => {
        if(map.has(num)){
            map.set(num, map.get(num) + 1);
        } else {
            map.set(num, 1);
        }
    });
    
    
    return Math.min(Math.floor(nums.length / 2), map.size)
}