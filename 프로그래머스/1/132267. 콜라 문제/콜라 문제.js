function solution(a, b, n) {
    var answer = 0;
    let emptyCoke = n;
    let newCoke = 0;
    while (emptyCoke > a-1) {
        let remain = emptyCoke % a;
        newCoke = Math.trunc(emptyCoke/a) * b;
        answer += newCoke;
        emptyCoke = remain + newCoke;
    }
    return answer;
}