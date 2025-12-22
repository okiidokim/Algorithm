function solution(num_list) {
    let odds = 0;
    let evens = 0;
    for (const num of num_list) {
        if (num%2 == 0) evens++;
        else odds++;
    }
    return [evens, odds];
}