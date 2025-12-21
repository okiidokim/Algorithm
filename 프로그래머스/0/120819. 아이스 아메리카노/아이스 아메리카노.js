function solution(money) {
    const coffee = 5500;
    const cnt = Math.floor(money/coffee);
    const left = money - cnt*coffee;
    return [cnt, left];
}