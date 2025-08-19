function solution(n) {
    let str = String(n);
    
    let arr = [];
    for (let i = 0; i < str.length; i++)
        arr.push(Number(str[i]));
    
    arr.sort((a,b) => b-a);
    
    let answer = "";
    for (let c of arr)
        answer += c;
    
    return Number(answer);
}