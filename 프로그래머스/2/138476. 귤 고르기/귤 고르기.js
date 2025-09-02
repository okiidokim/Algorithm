function solution(k, tangerine) {
    var answer = 0;
    let counts = [...Array(10000001).keys()];
    counts.fill(0);
    for (let t of tangerine) {
        counts[t]++;
    }
    counts.sort((a,b) => b-a);
    let sum = 0;
    while(sum < k) {
        sum += counts[answer];
        answer++;
    }
    return answer;
}