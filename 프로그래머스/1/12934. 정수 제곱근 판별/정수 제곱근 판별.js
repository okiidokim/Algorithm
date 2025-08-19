function solution(n) {
    var answer = 0;
    let x = 1;
    while (x*x < n) {
        x++
    }
    if (x*x === n) return (x+1)*(x+1);
    else return -1;
}