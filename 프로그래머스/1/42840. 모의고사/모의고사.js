function solution(answers) {
    var answer = [];
    let cnts = new Array(3);
    cnts.fill(0);
    const stu3 = {
        0 : 3,
        1 : 3,
        2 : 1,
        3 : 1,
        4 : 2,
        5 : 2,
        6 : 4,
        7 : 4,
        8 : 5,
        9 : 5,
    }
    const stu2 = {
        1 : 1,
        3 : 3,
        5 : 4,
        7 : 5,
    }
    for (let i = 0; i < answers.length; i++) {
        const stu1Ans = i%5 + 1;
        if (stu1Ans === answers[i]) cnts[0]++;
        const stu2Ans = i % 2 === 0 ? 2 : stu2[i % 8];
        if (stu2Ans === answers[i]) cnts[1]++;
        const stu3Ans = stu3[i % 10];
        if (stu3Ans === answers[i]) cnts[2]++;
    }
    const max = Math.max(...cnts);
    answer = cnts.reduce((acc, curr, i) => (curr === max ? (acc.push(i+1), acc) : acc), []);
    return answer;
}