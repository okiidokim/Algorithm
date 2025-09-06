function solution(arr1, arr2) {
    var answer = [];
    const col = arr1.length;
    const row = arr2[0].length;
    for (let i = 0; i < col; i++) {
        let arr = [];
        for (let j = 0; j < row; j++) {
            let sum = 0;
            for (let k = 0; k < arr1[0].length; k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            arr.push(sum);
        }
        answer.push(arr);
    }
    return answer;
}