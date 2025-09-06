function solution(citations) {
    var answer = 0;
    citations.sort((a,b) => b-a); //내림차순
    for (let i = 0; i < citations.length; i++) {
        if (i+1 === citations[i]) {
            answer = citations[i];
        } else if (i+1 > citations[i]) {
            let curr = citations[i];
            while (curr < citations[i-1]) {
                if (i === curr) {
                    answer = curr;
                    break;
                }
                curr++;
            }
        }
        if (answer > 0) break;
    }
    if (answer === 0 && citations[citations.length-1] >= citations.length) answer = citations.length;
    return answer;
}