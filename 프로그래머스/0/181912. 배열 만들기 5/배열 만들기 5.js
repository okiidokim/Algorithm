function solution(intStrs, k, s, l) {
    var answer = [];
    for (const str of intStrs) {
        const numStr = str.slice(s, s + l);
        const num = parseInt(numStr);
        if (num > k) answer.push(num);
    }
    return answer;
}