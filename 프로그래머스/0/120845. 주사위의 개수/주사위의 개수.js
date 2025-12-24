function solution(box, n) {
    
    const xCnt = Math.floor(box[0]/n);
    const yCnt = Math.floor(box[1]/n);
    const zCnt = Math.floor(box[2]/n);
    
    return xCnt * yCnt * zCnt;
}