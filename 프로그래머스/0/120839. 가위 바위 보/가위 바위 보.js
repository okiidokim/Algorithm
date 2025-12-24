function solution(rsp) {
    var answer = '';
    for (const c of rsp) {
        if (c === '2') answer += '0';
        if (c === '0') answer += '5';
        if (c === '5') answer += '2';
    }
    return answer;
}