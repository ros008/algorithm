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
        while(curIndex > 0 && this.heap[curIndex] < this.heap[Math.floor((curIndex - 1) / 2)]) {
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
        
        while(this.heap[leftIndex] && this.heap[leftIndex] < this.heap[curIndex] ||
             this.heap[rightIndex] && this.heap[rightIndex] < this.heap[curIndex]) {
            let smallerIndex = leftIndex;
            if(this.heap[rightIndex] && this.heap[rightIndex] < this.heap[leftIndex]) {
                smallerIndex= rightIndex;
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

function solution(scoville, K) {
    let answer = 0;
    let minHeap = new MinHeap();
    
    for(let i=0; i<scoville.length; i++) {
        minHeap.push(scoville[i]);
    }
    
    while (minHeap.size() > 0 && minHeap.peek() < K) {
        if(minHeap.size() < 2) return -1;
        let first = minHeap.pop();
        let second = minHeap.pop();
        minHeap.push(first + second * 2);
        answer++;
    }
    
    
    return answer;
}