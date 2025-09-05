function solution(want, number, discount) {
    var answer = 0;
    const wantMap = new Map();
    for (let i = 0; i < want.length; i++) {
        wantMap.set(want[i], number[i]);
    }
    
    let newMap = new Map();
        
    for (let i = 0; i < 10; i++) {
        const cnt = newMap.get(discount[i]);
        if (!cnt) newMap.set(discount[i], 1);
        else newMap.set(discount[i], cnt+1);
    }

    let flag = true;
    for (let [item, cnt] of wantMap) {
        if (!newMap.get(item) || newMap.get(item) < cnt) {
            flag = false;
            break;
        }
    }
    if (flag) answer++;
    
    for (let i = 10; i < discount.length; i++) {
        const cnt = newMap.get(discount[i]);
        if (!cnt) newMap.set(discount[i], 1);
        else newMap.set(discount[i], cnt+1);
        const removeCnt = newMap.get(discount[i-10]);
        if (removeCnt > 1) newMap.set(discount[i-10], removeCnt-1);
        else newMap.delete(discount[i-10]);
        flag = true;
        for (let [item, cnt] of wantMap) {
            if (!newMap.get(item) || newMap.get(item) < cnt) {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
    
    
    return answer;
}