function solution(participant, completion) {
    var answer = '';
    const map = new Map();
    participant.forEach(person => {
        if (!map.has(person)) 
            map.set(person, 1);
        else
            map.set(person, map.get(person) + 1);
    })
    for(const person of completion) {
        if (map.get(person) === 1) {a
            map.delete(person)
        } else {
            map.set(person, map.get(person) - 1);
        }
    }
    console.log(map)
    for (const key of map.keys()) {
        return key;
    }
    
}