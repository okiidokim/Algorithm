function solution(name, yearning, photo) {
    var answer = [];
    for (let i = 0; i < photo.length; i++) {
        let score = 0;
        for (let n of photo[i]) {
            if (name.includes(n)) {
                const index = name.indexOf(n);
                score += yearning[index];
            }
        }
        answer.push(score);
    }
    return answer;
}