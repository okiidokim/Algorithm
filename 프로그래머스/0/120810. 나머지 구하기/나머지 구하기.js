function solution(num1, num2) {
    const mok = Math.floor(num1/num2);
    const answer = num1 - mok*num2;
    return answer;
}