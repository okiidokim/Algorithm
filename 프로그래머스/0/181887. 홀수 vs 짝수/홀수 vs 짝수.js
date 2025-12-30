function solution(num_list) {
    var answer = 0;
    let odds = 0;
    let evens = 0;
    for (let i = 1; i < num_list.length + 1; i++) {
        if (i%2 === 0) evens += num_list[i-1];
        else odds += num_list[i-1];
    }
    return odds > evens ? odds : evens;
}