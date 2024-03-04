def solution(clothes):
    answer = 1
    dic = {}
    for cloth in clothes:
        name, sort = cloth
        if sort in dic:
            dic[sort] = dic[sort] + 1
        else:
            dic[sort] = 1
    print(dic)
    for key, value in dic.items():
        answer = answer * (value + 1)
        
    return answer - 1