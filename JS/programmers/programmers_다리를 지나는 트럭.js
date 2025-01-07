function solution(bridge_length, weight, truck_weights) {
    let answer = 0;
    let cur_weight = 0;
    const bridge = [];
    
    while (truck_weights.length) {
        if (bridge.length === bridge_length) {
            cur_weight -= bridge.shift();
        }
        
        if (cur_weight + truck_weights[0] <= weight) {
            cur_weight += truck_weights[0];
            bridge.push(truck_weights.shift())
        } else {
            bridge.push(0);
        }
        
        answer++;
    }
    
    return answer + bridge_length;
}