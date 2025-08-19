function solution(numbers) {
    var answer = 0;
    const arr = [...Array(10).keys()];
    for (let num of arr) {
        if (numbers.find(n => n === num)) continue;
        answer+=num;
    }
    return answer;
}