function solution(s) {
    var answer = '';
    let wordArr = s.split(" ");
    console.log(wordArr);
    for (let i = 0; i < wordArr.length; i++) {
        let word = "";
        for (let j = 0; j < wordArr[i].length; j++) {
            if (j%2 === 0) word += wordArr[i][j].toUpperCase();
            else word += wordArr[i][j].toLowerCase();
        }
        answer += word;
        if (i !== wordArr.length-1) answer += " ";
    }
    return answer;
}