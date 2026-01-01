function solution(num_list, n) {
    var answer = [];
    let idx = 0;
    let sIdx = 0;
    for (const num of num_list) {
        if (idx !== sIdx) {
            idx++;
            continue;
        }
        answer.push(num);
        idx++;
        sIdx += n;
    }
    return answer;
}