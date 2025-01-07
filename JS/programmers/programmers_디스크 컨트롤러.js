class MinHeap {
    constructor() {
        this.heap = [];
    }
    
    size() {
        return this.heap.length;
    }
    
    push(value) {
        this.heap.push(value);
        let curIndex = this.heap.length - 1;
        while(curIndex > 0 && this.heap[curIndex][1] < this.heap[Math.floor((curIndex - 1) / 2)][1]) {
            const tmp = this.heap[curIndex];
            this.heap[curIndex] = this.heap[Math.floor((curIndex - 1) / 2)];
            this.heap[Math.floor((curIndex - 1) / 2)] = tmp;
            curIndex = Math.floor((curIndex - 1) / 2);
        }
    }
    
    pop() {
        if (this.heap.length === 0) return null;
        if (this.heap.length === 1) return this.heap.pop();
        
        const minValue = this.heap[0];
        this.heap[0] = this.heap.pop();
        
        let curIndex = 0;
        let leftIndex = curIndex * 2 + 1;
        let rightIndex = curIndex * 2 + 2;
        
        while(this.heap[leftIndex] && this.heap[leftIndex][1] < this.heap[curIndex][1] ||
             this.heap[rightIndex] && this.heap[rightIndex][1] < this.heap[curIndex][1]) {
            let smallerIndex = leftIndex;
            if(this.heap[rightIndex] && this.heap[rightIndex][1] < this.heap[leftIndex][1]) {
                smallerIndex = rightIndex;
            }
            [this.heap[smallerIndex], this.heap[curIndex]] = [this.heap[curIndex], this.heap[smallerIndex]];
            curIndex = smallerIndex;
            leftIndex = curIndex * 2 + 1;
            rightIndex = curIndex * 2 + 2;
        }
        
        return minValue;
    }
    
    peek() {
        return this.heap[0];
    }
}

function solution(jobs) {
    var answer = 0;
    let time = 0;
    const n = jobs.length;
    const minHeap = new MinHeap();
    
    jobs.sort((a, b) => a[0] - b[0]);
    
    while (jobs.length || minHeap.size()) {
        while (jobs.length && jobs[0][0] <= time) {
            minHeap.push(jobs.shift());
        }
        
        // console.log(minHeap);
        if (minHeap.size()) {
            const [nextJobEnterTime, nextJobDuration] = minHeap.pop();
            if (nextJobEnterTime > time) time = nextJobEnterTime;
            answer = answer + (time - nextJobEnterTime) + nextJobDuration;
            time += nextJobDuration;  
        } else {
            time++;
        }
            
        // console.log(time);
        // console.log(answer);
    }
    answer = Math.floor(answer / n);
    return answer;
}