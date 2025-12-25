function solution(my_string) {
    let answer = my_string.toLowerCase();
    answer = answer.split("").sort().join("");
    return answer;
}