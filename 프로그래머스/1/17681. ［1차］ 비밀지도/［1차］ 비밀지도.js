function solution(n, arr1, arr2) {
    var answer = [];
    
    let biNumArr1 = [];
    let biNumArr2 = [];
    
    for (let num of arr1) {
        let tmp = "";
        while (num > 0) {
            const rem = num % 2;
            tmp += String(rem);
            num = Math.trunc(num/2);
        }
        while (tmp.length < n) {
            tmp += "0";
        }
        tmp = tmp.split("").reverse().join("");
        biNumArr1.push(tmp);
    }
    for (let num of arr2) {
        let tmp = "";
        while (num > 0) {
            const rem = num % 2;
            tmp += String(rem);
            num = Math.trunc(num/2);
        }
        while (tmp.length < n) {
            tmp += "0";
        }
        tmp = tmp.split("").reverse().join("");
        biNumArr2.push(tmp);
    }
    
    for (let i = 0; i < n; i++) {
        let str = "";
        for (let j = 0; j < n; j++) {
            if (biNumArr1[i][j] === "0" && biNumArr2[i][j] === "0") str += " ";
            else str += "#";
        }
        answer.push(str);
    }
    return answer;
}