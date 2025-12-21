function solution(s1, s2) {
    let sames = 0;
    for (const str of s1) {
        if (s2.includes(str)) sames++;
    }
    return sames;
}