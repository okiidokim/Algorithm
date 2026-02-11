function solution(arr, queries) {
    for (const q of queries) {
        for (let i = q[0]; i <= q[1]; i++) {
            arr[i]++;
        }
    }
    return arr;
}