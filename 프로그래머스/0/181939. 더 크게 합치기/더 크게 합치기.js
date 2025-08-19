function solution(a, b) {
    const order = String(a) + String(b);
    const reverse = String(b) + String(a);
    if (Number(reverse) > Number(order)) return Number(reverse);
    else return Number(order);
}