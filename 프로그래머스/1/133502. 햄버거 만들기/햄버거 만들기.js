// 21:38~22:06 (30분)
function solution(ingredient) {
    var answer = 0;
    let arr = [];
    let breadCnt = 0;
    for (const ing of ingredient) {
        if (ing !== 1) {
            arr.push(ing);
            continue;
        }
        if (ing === 1 && breadCnt === 0) {
            arr.push(ing);
            breadCnt++;
            continue;
        }
        
        //두 번째 빵, 이전 값들 확인하기
        let tmp = [];
        const size = arr.length;
        let canMake = true;
        for (let i = 1; i <= 3; i++) {
            if (size-i < 0) {
                canMake = false;
                break;
            }
            if (arr[size-i] !== 4-i) {
                canMake = false;
                break;
            }
            tmp.push(4-i);
            arr.pop();
        }
        if (canMake) {
            answer++;
            breadCnt--;
        } else {
            for (let i = tmp.length-1; i >=0; i--) {
                arr.push(tmp[i]);
            }
            arr.push(ing);
            breadCnt++;
        }
    }
    return answer;
}