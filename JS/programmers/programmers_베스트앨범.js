function solution(genres, plays) {
    const answer = [];
    const playsPerGenre = new Map();
    // Map {
    // "classic" : [ 총횟수, [ 곡 리스트 [곡횟수, 곡인덱스] ]]
    // }
    for(let i=0; i<genres.length; i++) {
        const genre = genres[i];
        const play = plays[i];
        
        let info = playsPerGenre.get(genre);
        
        if(!info) info = [0, []];
        
        info[0] = info[0] + play;
        info[1].push([play, i]);
        
        playsPerGenre.set(genre, info);
    }
    const arr = Array.from(playsPerGenre);
    arr.sort((a,b) => b[1][0] - a[1][0]);
    for(let i=0; i<arr.length; i++) {
        let cnt = 0;
        arr[i][1][1].sort((a,b) => {
            if(a[0] === b[0]) return a[1] - b[1];
            else return b[0] - a[0];
        })
        for(const el of arr[i][1][1]) {
            if(cnt === 2) break;
            answer.push(el[1]);
            cnt++;
        }
    }
    return answer;
}