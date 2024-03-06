def solution(bridge_length, weight, truck_weights):
    answer = 0
    cur_weight = 0
    bridge = []
    
    while len(truck_weights) > 0:
        if len(bridge) == bridge_length:
            cur_weight -= bridge.pop(0)
            
        if cur_weight + truck_weights[0] > weight:
            bridge.append(0)
        else:
            cur = truck_weights.pop(0)
            bridge.append(cur)
            cur_weight += cur
        answer += 1
        
    return answer + bridge_length