// 18:54 ~

function solution(array, height) {
    var answer = array.reduce((acc, curr) => curr>height ? acc += 1 : acc, 0);
    return answer;
}