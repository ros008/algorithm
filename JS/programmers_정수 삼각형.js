function solution(triangle) {
    var answer = 0;
    const len = triangle.length;
    
    for (let i=1; i<len; i++) {
        triangle[i][0] = triangle[i-1][0] + triangle[i][0];
        triangle[i][i] = triangle[i-1][i-1] + triangle[i][i];
        for (let j=1; j<i; j++) {
            triangle[i][j] = Math.max(triangle[i-1][j-1], triangle[i-1][j]) + triangle[i][j];
        }
    }
    
    
    return Math.max(...triangle[len-1]);
}