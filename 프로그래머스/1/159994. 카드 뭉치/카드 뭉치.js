function solution(cards1, cards2, goal) {
    var answer = "Yes";
    let index1 = 0, index2 = 0;
    for (let i = 0; i < goal.length; i++) {
        if (cards1[index1] === goal[i]) {
            index1++;
            continue;
        } else if (cards2[index2] === goal[i]) {
            index2++;
            continue;
        } 
        return "No";
    }

    return answer;
}