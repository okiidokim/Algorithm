function solution(hp) {
    var answer = 0;
    const goon = Math.floor(hp/5);
    let left = hp - goon*5;
    const byung = Math.floor(left/3);
    left = left - byung*3;
    return goon + byung + left;
}