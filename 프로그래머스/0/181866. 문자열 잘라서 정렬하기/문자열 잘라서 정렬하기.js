function solution(myString) {
    var answer = myString.split("x").filter((c) => c !== "").sort();
    return answer;
}