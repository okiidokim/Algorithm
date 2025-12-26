function solution(str_list, ex) {
    var answer = '';
    for (const str of str_list) {
        if (str.includes(ex)) continue;
        answer += str;
    }
    return answer;
}