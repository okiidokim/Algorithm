function solution(A,B){
    var answer = 0;
    A.sort((a, b) => a-b);
    B.sort((a, b) => b-a);
    answer = A.reduce((acc, curr, i) => (acc + curr*B[i]), 0)
    return answer;
}