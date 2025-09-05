function solution(s) {
    var answer = 0;
    let size = s.length;
    while(size--) {
        let arr = [];
        let flag = true;
        for (let i = 0; i < s.length; i++) {
            if (s[i] === '(' || s[i] === '{' || s[i] === '[') {
                arr.push(s[i]);
                continue;
            } else {
                if (arr.length === 0) {
                    flag = false;
                    break;
                }
                if (arr[arr.length-1] === '(' && s[i] === ')') arr.pop();
                else if (arr[arr.length-1] === '{' && s[i] === '}') arr.pop();
                else if (arr[arr.length-1] === '[' && s[i] === ']') arr.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (arr.length > 0) flag = false;
        if (flag) answer++;
        
        const firstChar = s[0];
        s = s.slice(1, s.length);
        s += firstChar;
    }
    return answer;
}