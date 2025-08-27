function solution(n) {
    var answer = 0;
    
    let biStr = "";
    let met1 = false, met0 = false;
    while (n > 0) {
        biStr += String(n%2);
        if (n%2 === 1) met1 = true;
        else met0 = true;
        n = Math.trunc(n/2);
    }
    biStr = biStr.split("").reverse().join("");  
    
    if (!met1 || !met0)
        biStr = biStr.slice(0, 1) + '0' + biStr.slice(1);
    else {
        biStr = '0' + biStr;
        const i = biStr.lastIndexOf('01');
    
        const left = biStr.slice(0, i);
        const right = biStr.slice(i + 2);
        const ones = (right.match(/1/g) || []).length;
        const zeros = right.length - ones;

        biStr = left + '10' + '0'.repeat(zeros) + '1'.repeat(ones);
        if (biStr[0] === '0') biStr = biStr.slice(1);
    }
    
    for (let i = 0; i < biStr.length; i++) {
        answer += Math.pow(2, biStr.length-i-1) * biStr[i];
    }
    
    return answer;
}