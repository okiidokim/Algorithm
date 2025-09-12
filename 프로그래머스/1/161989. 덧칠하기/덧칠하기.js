function solution(n, m, section) {
    var answer = 0;
    while(section.length > 0) {
        answer++;
        let curr = section[0];
        while (section[0] < curr + m) {
            section.shift();
        }
    }
    return answer;
}