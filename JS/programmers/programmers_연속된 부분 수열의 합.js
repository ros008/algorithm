function solution(sequence, k) {
    let answer = [];
    let left = 0;
    let right = 0;
    let sum = sequence[0];
    
    while(right<sequence.length) {
        if(sum < k) {
            sum += sequence[++right];
        } else if(sum > k) {
            sum -= sequence[left++];
        } else {
            answer.push([left, right]);
            sum += sequence[++right];
        }
    }
    answer.sort((a,b) => {
        const len = Math.abs(a[0] - a[1]) - Math.abs(b[0] - b[1]);
        if(len !== 0) return len;
        return a[0] - b[0];
    })
    return answer[0];
}