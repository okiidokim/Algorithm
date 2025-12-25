function solution(numbers) {
    var answer = -100000000;
    for (let i = 0; i < numbers.length; i++) {
        for (let j = i+1; j < numbers.length; j++) {
            if (i === j) continue;
            if (answer < numbers[i] * numbers[j]) {
                answer = numbers[i] * numbers[j];
            }
        }
    }
    return answer;
}