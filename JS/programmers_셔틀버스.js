function solution(n, t, m, timetable) {
  let answer = "";

  function getTime(time) {
    const [hour, minute] = time.split(":").map(Number);
    return hour * 60 + minute;
  }

  let times = timetable.map((t) => getTime(t));
  let curBusTime = 9 * 60;

  times.sort((a, b) => a - b);

  for (let i = 0; i < n; i++) {
    let curTimeCrewNum = times.filter((time) => time <= curBusTime).length;
    if (i === n - 1) {
      if (curTimeCrewNum >= m) curBusTime = times[m - 1] - 1;
    } else {
      if (curTimeCrewNum <= m) {
        times.splice(0, curTimeCrewNum);
      } else {
        times.splice(0, m);
      }
      curBusTime += t;
    }
  }
  const hour = Math.floor(curBusTime / 60);
  const min = curBusTime % 60;
  answer =
    String(hour < 10 ? "0" + hour : hour) +
    ":" +
    String(min < 10 ? "0" + min : min);
  return answer;
}
