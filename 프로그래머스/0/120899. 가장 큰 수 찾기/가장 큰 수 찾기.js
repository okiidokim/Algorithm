function solution(array) {
    let num = 0;
    let idx = 0;
    for (const n of array) {
        if (n > num) {
            num = n;
            idx = array.indexOf(n);
        }
    }
    return [num, idx];
}