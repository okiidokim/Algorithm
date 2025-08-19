function solution(num) {
    var answer = 0;
    while (answer < 500) {
        if (num === 1) break;
        if (num % 2 === 0) {
            num /= 2;
        } else {
            num *= 3;
            num++;
        }
        answer++;
    }
    return answer === 500 ? -1 : answer;
}