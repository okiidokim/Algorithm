function solution(s) {
    var answer = '';
    
    let arr = [];
    for (let c of s)
        arr.push(c);
    
    arr.sort();
    arr.reverse();
    
    for (let c of arr)
        answer += c;
    
    return answer;
}