function solution(s)
{
    var answer = -1;
    let arr = [];
    for (let i = 0; i < s.length; i++) {
        if (arr.length === 0) arr.push(s[i]);
        else {
            if (arr[arr.length-1] === s[i]) arr.pop();
            else arr.push(s[i]);
        }
    }
    if (arr.length === 0) answer = 1;
    else answer = 0;
    return answer;
}