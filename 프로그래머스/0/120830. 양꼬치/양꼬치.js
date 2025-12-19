function solution(n, k) {
    const services = Math.floor(n/10);
    const price = n*12000 + (k-services)*2000;
    return price;
}