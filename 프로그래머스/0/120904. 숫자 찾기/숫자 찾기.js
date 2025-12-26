function solution(num, k) {
    const str = num.toString();
    const finder = k.toString();
    return str.indexOf(finder) === -1 ? -1 : str.indexOf(finder) + 1;
}