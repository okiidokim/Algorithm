function solution(my_string, n) {
    var answer = '';
    for (const c of my_string) {
        for (let i = 0; i < n; i++) answer += c;
    }
    return answer;
}