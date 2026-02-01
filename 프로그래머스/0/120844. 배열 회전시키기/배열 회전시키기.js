function solution(numbers, direction) {
    if (direction === "right") {
        const tmp = numbers[numbers.length-1];
        numbers.pop();
        numbers.unshift(tmp);
    } else {
        const tmp = numbers[0];
        numbers.shift();
        numbers.push(tmp);
    }
    return numbers;
}