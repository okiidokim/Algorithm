function solution(priorities, location) {
    var answer = 0;
    let arr = [...Array(priorities.length).keys()];
    let maxPri = Math.max(...priorities);
    let step = 1;
    while (arr.length > 0) {
        let curr = arr[0];
        while (priorities[curr] !== maxPri) {
            arr.shift();
            arr.push(curr);
            curr = arr[0];
        }
        console.log(arr);
        if (curr === location) {
            return step;
        }
        priorities[curr] = 0;
        arr.shift();
        maxPri = Math.max(...priorities);
        step++;
    }
    return answer;
}