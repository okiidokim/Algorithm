function solution(my_string) {
    var answer = [];
    for (const c of my_string) {
        if (c >= '0' && c <= '9') {
            const num = c.charCodeAt(0) - '0'.charCodeAt(0);
            answer.push(num);
        }
    }
    answer = answer.sort((a, b) => a-b);
    return answer;
}