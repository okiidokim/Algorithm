function solution(binomial) {
    let [n1, op, n2] = binomial.split(" ");
    n1 = parseInt(n1);
    n2 = parseInt(n2);
    if (op === '+') return n1 + n2;
    if (op === '-') return n1 - n2;
    return n1 * n2;
}