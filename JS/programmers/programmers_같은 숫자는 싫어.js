function solution(arr)
{
    let answer = [];
    arr.forEach(el => {
        if(answer.length === 0 || answer[answer.length - 1] !== el) answer.push(el)
    })
    return answer;
}