function solution(arr) {
    var answer = arr;
    
    const minValue = Math.min(...arr);
    const index = arr.indexOf(minValue)
    arr.splice(index,1);
    
    if (arr.length === 0) answer.push(-1);
    return answer;
}