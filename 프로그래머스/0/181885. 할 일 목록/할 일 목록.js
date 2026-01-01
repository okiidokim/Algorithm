function solution(todo_list, finished) {
    var answer = [];
    for (let i = 0; i < finished.length; i++) {
        const todo = todo_list[i];
        const f = finished[i];
        if (f === false) {
            answer.push(todo);
        }
    }
    return answer;
}