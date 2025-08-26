function solution(s) {
    var answer = '';
    let arr = s.split(' ');
    const max = Math.max(...arr);
    const min = Math.min(...arr);
    answer += String(min);
    answer += " ";
    answer += String(max);
    return answer;
}