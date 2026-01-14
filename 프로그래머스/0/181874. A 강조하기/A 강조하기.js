function solution(myString) {
    var answer = '';
    for (const c of myString) {
        if (c === 'a' || c === 'A') answer += 'A';
        else {
            answer += c.toLowerCase();
        }
    }
    return answer;
}