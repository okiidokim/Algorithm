function solution(s) {
    var answer = [];
    let step = 0;
    let zeros = 0;
    
    while (s !== "1") {
        step++;
        
        //1번
        let cnt = 0;
        for (let c of s) {
            if (c === "1") cnt++;
        }
        let noZero = "";
        for (let i = 0; i < cnt; i++) noZero += '1';
        zeros += s.length - cnt;
    
        //2번
        let len = noZero.length;
        s = "";
        while (len > 0) {
            s += String(len%2);
            len = Math.trunc(len/2);
        }
        s = s.split("").reverse().join("");
    }
    
    answer.push(step);
    answer.push(zeros);
    return answer;
}