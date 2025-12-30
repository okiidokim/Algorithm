function solution(myString) {
    var answer = [];
    let cnt = 0;
    for (const c of myString) {
        if (c !== 'x') cnt++;
        else {
            answer.push(cnt);
            cnt = 0;
        }
    }
    answer.push(cnt);
    return answer;
}