function solution(n) {
    var answer = 0;
    
    let cnt = 0;
    while (Math.pow(3, cnt) <= n) cnt++;
    cnt--;
    
    let threeStr = "";
    while (cnt >= 0) {
        const share = Math.trunc(n/Math.pow(3,cnt));
        const left = n - share * Math.pow(3,cnt);
        threeStr += share;
        n = left;
        cnt--;
    }
    
    threeStr = threeStr.split("").reverse().join("");
    cnt = threeStr.length;
    while (cnt > 0) {
        answer += Number(threeStr[threeStr.length-cnt]) * Math.pow(3, cnt-1);
        cnt--;
    }
    
    return answer;
}