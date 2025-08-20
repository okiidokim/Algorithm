function solution(s) {
    var answer = [];
    const alpha = Array.from({length : 26}, () => -1);
    for (let i = 0; i < s.length; i++) {
        const index = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
        if (alpha[index] === -1) {
            answer.push(-1);
            alpha[index] = i;
        }
        else {
            answer.push(i - alpha[index]);
            alpha[index] = i;
        }
    }
    return answer;
}