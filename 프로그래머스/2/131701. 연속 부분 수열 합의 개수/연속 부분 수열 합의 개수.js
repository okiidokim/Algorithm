function solution(elements) {
    let set = new Set();
    for (let i = 1; i < elements.length + 1; i++) {
        for (let j = 0; j < elements.length; j++) {
            let sum = 0;
            for (let k = 0; k < i; k++) {
                const index = (j+k) % elements.length;
                sum += elements[index];
            }
            set.add(sum);
        }
    }
    return set.size;
}