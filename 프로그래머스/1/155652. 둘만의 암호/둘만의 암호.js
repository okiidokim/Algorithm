// 17:30 ~ 
function getIndex(c) {
    return c.charCodeAt(0)-'a'.charCodeAt(0);
}

function getAlpha(idx) {
    return String.fromCharCode('a'.charCodeAt(0) + idx);
}

function solution(s, skip, index) {
    var answer = '';
    let skipArr = new Array(26).fill(false);
    for (const c of skip) {
        const idx = getIndex(c);
        skipArr[idx] = true;
    }
    for (const c of s) {
        let counts = index;
        let idx = getIndex(c);
        while (counts--) {
            idx++;
            idx %= 26;
            if (skipArr[idx] === true) counts++;
        }
        idx %= 26;
        answer += getAlpha(idx);
    }
    //1~26 : index - 0~25 -> %26
    return answer;
}