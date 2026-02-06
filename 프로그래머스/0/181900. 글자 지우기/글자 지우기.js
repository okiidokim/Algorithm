function solution(my_string, indices) {
    let answer = '';
    indices.sort((a, b) => a-b);
    let idx = 0;
    for (let i = 0; i < my_string.length; i++) {
        if (i === indices[idx]) {
            idx++;
            continue;
        }
        answer += my_string[i];
    }
    return answer;
}