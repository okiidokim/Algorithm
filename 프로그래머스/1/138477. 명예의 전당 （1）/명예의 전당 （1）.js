function solution(k, score) {
    var answer = [];
    let glory = [];
    for (let i = 0; i < score.length; i++) {
        if (i < k) {
            glory.push(score[i]);
        }
        else {
            if (score[i] > glory[0]) {
                glory.shift();
                glory.push(score[i]);
            }
        }
        glory.sort((a, b)=> a-b);
        answer.push(glory[0]);
    }
    return answer;
}