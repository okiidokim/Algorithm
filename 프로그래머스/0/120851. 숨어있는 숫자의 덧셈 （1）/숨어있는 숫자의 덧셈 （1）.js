function solution(my_string) {
    var answer = 0;
    for (const c of my_string) {
        if (c >= '0' && c <= '9') {
            answer += (c.charCodeAt(0) - '0'.charCodeAt(0));
        }
    }
    return answer;
}