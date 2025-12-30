function solution(arr, n) {
    var answer = [];
    for (let i = 0; i < arr.length; i++) {
        const num = arr[i];
        if (arr.length % 2 === 1) {
            if (i % 2 === 0) answer.push(num + n);
            else answer.push(num);
        }
        else {
            if (i % 2 === 1) answer.push(num + n);
            else answer.push(num);
        }
    }
    return answer;
}