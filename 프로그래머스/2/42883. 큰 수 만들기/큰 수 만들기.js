// 16:27 ~
function solution(number, k) {    
    let stack = [];
    for (const ch of number) {
        while (k > 0 && stack.length > 0 && stack[stack.length-1] < ch) {
            stack.pop();
            k--;
        }
        stack.push(ch);
    }
    if (k > 0) {
        stack.splice(stack.length-k, k);
    }
    return stack.join('');
}