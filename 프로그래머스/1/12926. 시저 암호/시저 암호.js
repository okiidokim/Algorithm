function solution(s, n) {
    var answer = '';
    for (let c of s) {
        let ascii = c.charCodeAt(0);
        if (ascii >= 'a'.charCodeAt(0) && ascii <= 'z'.charCodeAt(0)) {
            ascii += n;
            if (ascii > 'z'.charCodeAt(0)) ascii -= 26;
            answer += String.fromCharCode(ascii);
        } else if (ascii >= 'A'.charCodeAt(0) && ascii <= 'Z'.charCodeAt(0)) {
            ascii += n;
            if (ascii > 'Z'.charCodeAt(0)) ascii -= 26;
            answer += String.fromCharCode(ascii);
        } else {
            answer += c;
        }
    }
    return answer;
}