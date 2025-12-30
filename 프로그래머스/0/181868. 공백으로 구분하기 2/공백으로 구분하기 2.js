function solution(my_string) {
    var stringArr = my_string.split(" ");
    let answer = [];
    for (const str of stringArr) {
        if (str === "") continue;
        answer.push(str);
    }
    return answer;
}