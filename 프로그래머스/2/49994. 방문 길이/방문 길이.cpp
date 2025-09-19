#include <string>
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int dx[4] = {-1, 1, 0, 0}; //L R U D
    int dy[4] = {0, 0, -1, 1};
    unordered_map<char,int> cmd{{'L',0},{'R',1},{'U',2},{'D',3}};
    
    int x = 5, y = 5;
    vector<vector<string>> board(11, vector<string>(11, ""));
    
    for (char c : dirs) {
        int idx = cmd[c];
        int nx = x + dx[idx], ny = y + dy[idx];
        char oppC;
        
        if (c == 'U') oppC = 'D';
        else if (c == 'D') oppC = 'U';
        else if (c == 'L') oppC = 'R';
        else oppC = 'L';
        
        if (nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;
        if (board[x][y].find(c) != string::npos) {}
        else if (board[nx][ny].find(oppC) != string::npos) {}
        else {
            answer++;
            board[x][y] += c;
        }
        x = nx; y = ny;
    }
    
    return answer;
}