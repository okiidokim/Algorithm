function solution(array, n) {
    var answer = array.reduce((acc, curr) => curr===n ? acc += 1 : acc, 0);
    return answer;
}