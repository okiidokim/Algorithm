//21:10~
function solution(s) {
    var answer = 0;
    let x = s[0];
    let sames = 0;
    let diffs = 0;
    for (let i = 0; i < s.length; i++) {
        if (x == s[i]) sames++;
        else diffs++;
        
        if (sames == diffs) {
            x = s[i+1];
            sames = 0;
            diffs = 0;
            answer++;
        }
    }
    if (sames !== 0 || diffs !== 0) answer++;
    return answer;
}