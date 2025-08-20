function solution(s) {
    var answer = "";
    
    const numbers = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];
    let numStr = "";
    
    for (let i = 0; i < s.length; i++) {
        numStr += s[i];
        if (numStr >= '0' && numStr <= '9') {
            answer += String(numStr);
            numStr = "";
            continue;
        }
        if (numbers.includes(numStr)) {
            const index = numbers.indexOf(numStr);
            answer += String(index);
            numStr = "";
        }
    }
    return Number(answer);
}