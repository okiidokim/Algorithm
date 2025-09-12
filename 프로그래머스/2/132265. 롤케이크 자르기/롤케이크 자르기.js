function solution(topping) {
    var answer = 0;
    let map = new Map();
    for (let t of topping) map.set(t, (map.get(t) || 0) +1);
    let set = new Set();
    for (let t of topping) {
        map.set(t, map.get(t) - 1);
        if (map.get(t) === 0) map.delete(t);
        set.add(t);
        if (set.size === map.size) answer++;
    }
    return answer;
}