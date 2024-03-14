function bfs(graph, start) {
    const queue = [start];
    const visited = [];
    visited[start] = true;
    let connectedNodeCnt = 0;
    let pivot = 0;
    
    while(queue.length > pivot) {
        const node = queue[pivot++];
        const connected = graph[node] ?? [];
        for(let i=0; i<connected.length; i++) {
            if (!visited[connected[i]]) {
                visited[connected[i]] = true;
                queue.push(connected[i]);
                connectedNodeCnt += 1;
            }
        }
    }
    
    return connectedNodeCnt;
}

function solution(n, results) {
    var answer = 0;
    const winGraph = [];
    const loseGraph = [];
    
    for (let i=0; i<results.length; i++) {
        const win = results[i][0];
        const lose = results[i][1];
        
        if (winGraph[win]) winGraph[win].push(lose);
        else winGraph[win] = [lose];
        if (loseGraph[lose]) loseGraph[lose].push(win);
        else loseGraph[lose] = [win];
    }
    
    for(let i=1; i<=n; i++) {
        if(bfs(winGraph, i) + bfs(loseGraph, i) === n - 1) answer += 1;
    }
    
    return answer;
}