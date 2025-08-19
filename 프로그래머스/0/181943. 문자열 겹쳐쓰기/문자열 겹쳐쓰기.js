function solution(my_string, overwrite_string, s) {
    var answer = '';
    answer += my_string.slice(0, s);
    answer += overwrite_string;
    const restartIndex = s + overwrite_string.length;
    const backStr = my_string.slice(restartIndex, my_string.length);
    answer += backStr;
    return answer;
}