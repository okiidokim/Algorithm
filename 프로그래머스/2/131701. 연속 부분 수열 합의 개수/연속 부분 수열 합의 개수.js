function solution(elements) {
    const size = elements.length;
    const ele = elements.concat(elements);
    const newArr = new Array(2*size+1).fill(0);
    for (let i = 0; i < ele.length; i++) {
        newArr[i+1] = ele[i] + newArr[i];
    }
    let set = new Set();
    for (let i = 1; i <= size; i++) {
        for (let j = 0; j < size; j++) {
            const sum = newArr[j + i] - newArr[i];
            set.add(sum);
        }
    }
    return set.size;
}