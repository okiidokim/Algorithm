function solution(a, d, included) {
    var answer = 0;
    let changingNum = a;
    for (let i = 0; i < included.length; i++) {
        if (included[i]) answer += changingNum;
        changingNum += d;
    }
    return answer;
}