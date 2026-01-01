function solution(arr, intervals) {
    var answer = [];
    let idx = 0;
    for (const n of arr) {
        if (idx < intervals[0][0]) {
            idx++;
            continue;
        }
        if (idx > intervals[0][1]) break;
        answer.push(n);
        idx++;
    }
    idx = 0;
    for (const n of arr) {
        if (idx < intervals[1][0]) {
            idx++;
            continue;
        }
        if (idx > intervals[1][1]) break;
        answer.push(n);
        idx++;
    }
    return answer;
}