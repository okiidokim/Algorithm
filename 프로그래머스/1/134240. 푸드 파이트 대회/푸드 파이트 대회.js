function solution(food) {
    var answer = '0';
    for (let i = food.length-1; i >= 0; i--) {
        const cnt = Math.trunc(food[i]/2);
        const str = String(i).repeat(cnt);
        answer = str + answer + str;
    }
    
    return answer;
}