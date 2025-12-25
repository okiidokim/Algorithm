function solution(cipher, code) {
    var answer = '';
    for (let i = 0; i < cipher.length; i++) {
        const c = cipher[i];
        if (Number.isInteger((i+1)/code)) answer += c;
    }
    return answer;
}