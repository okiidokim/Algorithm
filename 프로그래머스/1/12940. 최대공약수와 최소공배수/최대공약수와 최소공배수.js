function solution(n, m) {
    var answer = [];
    let div = 1;
    const size = n > m ? m : n;
    for (let i = 2; i <= size; i++) {
        if (n%i === 0 && m%i === 0) div = i;
    }
    const mul = div * (n/div) * (m/div);
    answer.push(div);
    answer.push(mul);
    return answer;
}