function solution(n) {
    var answer = 0;
    const modNum = 1234567;
    let f = [];
    f[0] = 0;
    f[1] = 1;
    for (let i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
        f[i] = f[i] % modNum;
    }
    answer = f[n];
    return answer;
}