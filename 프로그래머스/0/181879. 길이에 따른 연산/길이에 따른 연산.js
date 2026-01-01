function solution(num_list) {
    const sum = num_list.reduce((acc, curr) => acc += curr, 0);
    const muls = num_list.reduce((acc, curr) => acc *= curr, 1);
    if (num_list.length >= 11) return sum;
    return muls;
}