function solution(arr, flag) {
    var answer = [];
    for (let i = 0; i < arr.length; i++) {
        if (flag[i]) {
            for (let j = 0; j < arr[i] * 2; j++) {
                answer.push(arr[i]);
            }
        } else {
            for (let j = 0; j < arr[i]; j++) {
                if (answer.length === 0) break;
                answer.pop();
            }
        }
    }
    return answer;
}