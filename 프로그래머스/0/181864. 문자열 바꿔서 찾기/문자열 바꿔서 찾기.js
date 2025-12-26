function solution(myString, pat) {
    let newString = "";
    for (const c of myString) {
        if (c === 'A') newString += 'B';
        else newString += 'A';
    }
    if (newString.includes(pat)) return 1;
    return 0;
}