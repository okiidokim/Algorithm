function solution(n) {
    var answer = 0;

    function combi(a, b) {
        const MOD_BIG = 1234567n;

        let up = [];
        let down = [...Array(b + 1).keys()];
        down = down.slice(1, down.length);

        for (let i = a; i > a - b; i--) {
            up.push(i);
        }

        const top = up.length > 0
          ? up.reduce((acc, curr) => acc * BigInt(curr), 1n)
          : 1n;

        const bottom = down.length > 0
          ? down.reduce((acc, curr) => acc * BigInt(curr), 1n)
          : 1n;

        return Number((top / bottom) % MOD_BIG);
    }

    let k = 0;
    while (n >= k) {
        answer += combi(n, k);
        n--;
        k++;
    }
    return answer % 1234567;
}
