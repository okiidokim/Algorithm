function solution(progresses, speeds) {
    var answer = [];
    while (progresses.length > 0) {
        let curr = progresses[0]; progresses.shift();
        let speed = speeds[0]; speeds.shift();
        let days = 0;
        while (curr < 100) {
            curr += speed;
            days++;
        }
        let next = progresses[0];
        let nextSpeed = speeds[0];
        let tmp = next + nextSpeed*days;
        let cnt = 1;
        while (tmp >= 100) {
            console.log(curr, tmp);
            progresses.shift();
            speeds.shift();
            next = progresses[0];
            nextSpeed = speeds[0];
            tmp = next + nextSpeed*days;
            cnt++;
        }
        answer.push(cnt);
    }
    return answer;
}