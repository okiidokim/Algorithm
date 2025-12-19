function solution(n, t) {
    let answer = n;
    while(t--) {
        answer *= 2;
    }
    return answer;
}