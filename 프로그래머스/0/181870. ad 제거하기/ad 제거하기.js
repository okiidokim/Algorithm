function solution(strArr) {
    var answer = [];
    for (const str of strArr) {
        if (str.includes("ad")) continue;
        answer.push(str);
    }
    return answer;
}