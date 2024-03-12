const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

function makeLandGroup(land, height) {
    const N = land.length;
    const landGroup = new Array(N).fill(-1).map(() => new Array(N).fill(-1));
    let num = 0;
    
    for (let i=0; i<N; i++) {
        for (let j=0; j<N; j++) {
            if(landGroup[i][j] === -1) {
                num += 1;
                landGroup[i][j] = num;
                const queue = [[i, j]];
                let pivot = 0;
                
                while(queue.length > pivot) {
                    const [x, y] = queue[pivot++];
                    
                    for(let i=0; i<4; i++) {
                        const nx = x + dx[i];
                        const ny = y + dy[i];

                        if(nx >=0 && nx < N && ny >= 0 && ny < N && landGroup[nx][ny] === -1) {
                            if (Math.abs(land[x][y] - land[nx][ny]) <= height) {
                                landGroup[nx][ny] = num;
                                queue.push([nx, ny]);   
                            }
                        }
                    }    
                }   
            }
        }
    } 
    
    return [landGroup, num];
}

function makeEdges(land, landGroup) {
    const N = land.length;
    const edges = [];
    
    const visited = Array.from({ length: N }, () => new Array(N).fill(false));
    
    visited[0][0] = true;
    
    const queue = [[0, 0]];
    let pivot = 0;
    
    while (queue.length > pivot) {
        const [x, y] = queue[pivot++];
        for (let i=0; i<4; i++) {
            const nx = x + dx[i];
            const ny = y + dy[i];
            
            if(nx >= 0 && nx < N && ny >=0 && ny < N) {
                const curLandGroup = landGroup[x][y];
                const nextLandGroup = landGroup[nx][ny];
                const diff = Math.abs(land[x][y] - land[nx][ny]);
                if(curLandGroup !== nextLandGroup) {
                    edges.push([curLandGroup, nextLandGroup, diff]);
                }
                if(!visited[nx][ny]) {
                    queue.push([nx, ny]);
                    visited[nx][ny] = true;
                }
            }
        }
    }
    
    return edges;
}

class UnionFind {
    
    constructor(n) {
        this.parents = Array.from({length: n}, (_, i) => i);
    }
    
    getParentList() {
        return this.parents;
    }
    
    getParent(n) {
        if (this.parents[n] === n) return n;
        return this.parents[n] = this.getParent(this.parents[n]);
    }
    
    unionParent(a, b) {
        const aParent = this.getParent(a);
        const bParent = this.getParent(b);
        if(aParent < bParent) this.parents[bParent] = aParent;
        else this.parents[aParent] = bParent;
    }
    
    findParent(a, b) {
        const aParent = this.getParent(a);
        const bParent = this.getParent(b);
        return aParent === bParent;
    }
}

function solution(land, height) {
    var answer = 0;
    
    const [landGroup, landNum] = makeLandGroup(land, height);
    const edges = makeEdges(land, landGroup);
    
    edges.sort((a, b) => a[2] - b[2]);
    
    const unionFind = new UnionFind(landNum + 1);
    
    let cnt = 1;
    for(let i=0; i<edges.length; i++) {
        const [from, to, dist] = edges[i];
        if(!unionFind.findParent(from, to)) {
            answer += dist;
            unionFind.unionParent(from, to);
            cnt += 1;
        }
        if (cnt === landNum) break;
    }
    
    return answer;
}