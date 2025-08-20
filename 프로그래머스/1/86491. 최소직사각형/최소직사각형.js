function solution(sizes) {
    var answer = 0;
    let width = 0;
    let height = 0;
    for (let i = 0; i < sizes.length; i++) {
        const big = sizes[i][0] > sizes[i][1] ? sizes[i][0] : sizes[i][1];
        const small = sizes[i][0] > sizes[i][1] ? sizes[i][1] : sizes[i][0];
        width = big > width ? big : width;
        height = small > height ? small : height;
    }
    answer = width * height;
    return answer;
}