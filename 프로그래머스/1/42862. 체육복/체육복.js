// 15:40 ~
function solution(n, lost, reserve) {    
    lost.sort((a, b) => a-b);
    reserve.sort((a, b) => a-b);
    
    let newLost = [];
    for (const l of lost) {
        const idx = reserve.indexOf(l);
        if (idx === -1) {
            newLost.push(l);
        } else {
            reserve.splice(idx, 1);
        }
    }
    
    let answer = n - newLost.length;
    let reserveIdx = 0;
    for (const l of newLost) {
        let gap = reserve[reserveIdx] - l;
        while (reserveIdx < reserve.length && gap < -1) {
            reserveIdx++;
            gap = reserve[reserveIdx] - l;
        }
        if (reserveIdx >= reserve.length) break;        
        
        if (gap === -1 || gap === 1) {
            reserveIdx++;
            answer++;
        }
    }
    return answer;
}