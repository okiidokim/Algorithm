function solution(order) {
    const stringNum = order.toString();
    const cnt = stringNum.split('').reduce((acc, curr) => curr === '3' || curr === '6' || curr === '9' ? acc += 1 : acc, 0);
    return cnt;
} 