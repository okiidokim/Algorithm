function solution(my_string, n) {
    const sIdx = my_string.length -n;
    var answer = my_string.slice(sIdx);
    return answer;
}