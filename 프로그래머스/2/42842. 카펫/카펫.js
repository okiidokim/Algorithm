function solution(brown, yellow) {
    var answer = [];
    let x = 1, y = yellow / x;
    while (x <= y) {
        const cal = x * 2 + y * 2 + 4;
        if (brown === cal) {
            answer.push(y+2);
            answer.push(x+2);
            break;
        }
        x++;
        y = yellow/x;
    }
    return answer;
}