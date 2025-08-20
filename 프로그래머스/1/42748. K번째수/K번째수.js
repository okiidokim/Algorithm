function solution(array, commands) {
    var answer = [];
    for (let i = 0; i < commands.length; i++) {
        const a = commands[i][0];
        const b = commands[i][1];
        const c = commands[i][2];
        const newArr = array.slice(a-1, b);
        newArr.sort((a,b) => a-b);
        const num = newArr[c-1];
        answer.push(num);
    }
    return answer;
}