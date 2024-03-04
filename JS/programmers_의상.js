function solution(clothes) {
    const map = new Map();
    for (const cloth of clothes) {
        const [name, sort] = cloth;
        if(map.has(sort)) map.set(sort, map.get(sort) + 1);
        else map.set(sort, 1);
    }
    console.log(Array.from(map.values()))
    
    return Array.from(map.values()).reduce((acc, cur) => acc * (cur + 1), 1) - 1;
}