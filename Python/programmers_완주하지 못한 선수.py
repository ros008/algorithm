def solution(participant, completion):
    answer = ''
    dic = {}
    for person in participant:
        if person in dic:
            dic[person] = dic[person] + 1
        else:
            dic[person] = 1
    
    for person in completion:
        if person in dic:
            if dic[person] == 1:
                del dic[person]
            else:
                dic[person] = dic[person] - 1
    
    for key in dic:
        answer = key
    
    return answer