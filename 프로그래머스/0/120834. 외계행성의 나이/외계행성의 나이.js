function solution(age) {
    var answer = '';
    while (age > 0) {
        const n = age % 10;
        const asciiNum = 'a'.charCodeAt(0) + n;
        const ascii = String.fromCharCode(asciiNum);
        answer += ascii;
        age = Math.floor(age/10);
    }
    return answer.split('').reverse().join('');
}