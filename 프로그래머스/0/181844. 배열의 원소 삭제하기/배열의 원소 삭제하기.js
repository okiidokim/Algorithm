function solution(arr, delete_list) {
    var answer = [];
    for (const num of arr) {
        if (delete_list.includes(num)) continue;
        answer.push(num);
    }
    return answer;
}