function solution(n, words) {
    var answer = [];

    let map = new Map();
    let who = 1;
    let turn = 1;
    for (let i = 0; i < words.length; i++) {
        if (words[i].length === 1) {
            answer.push(who);
            answer.push(turn);
            break;
        }
        if (i > 0 && words[i][0] !== words[i-1][words[i-1].length-1]) {
            console.log(words[i-1][words[i-1].length-1]);
            answer.push(who);
            answer.push(turn);
            break;
        }
        if (map.get(words[i])) {
            answer.push(who);
            answer.push(turn);
            break;
        }
        map.set(words[i], true);
        if (who === n) {
            who = 1;
            turn++;
        } else {
            who++;
        }
    }
    if (answer.length === 0) {
        answer.push(0);
        answer.push(0);
    }

    return answer;
}