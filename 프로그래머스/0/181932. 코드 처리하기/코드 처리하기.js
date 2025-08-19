function solution(code) {
    let mode = 0;
    let ret = "";
    for (let i = 0; i < code.length; i++) {
        if (mode === 0) {
            if (code[i] !== "1" && i%2 === 0) ret += code[i];
            else if (code[i] === "1") mode = 1;
        } else {
            if (code[i] !== "1" && i%2 === 1) ret += code[i];
            else if (code[i] === "1") mode = 0;
        }
    }
    if (ret === "") return "EMPTY";
    return ret;
}