function solution(array) {
    const idx = Math.floor(array.length/2);
    array = array.sort((a,b)=>a-b);
    const answer = array[idx];
    return answer;
}