function solution(number) {
    const sum = number.split('').reduce((acc, curr) => acc += parseInt(curr), 0);
    var answer = sum % 9;
    return answer;
}