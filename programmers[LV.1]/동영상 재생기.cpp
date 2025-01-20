//
// Created by hong jun chung on 1/20/25.
//
#include <bits/stdc++.h>

using namespace std;

int convert(string str) {
    int a1 = (str[0] - '0') * 10 * 60;
    int a2 = (str[1] - '0') * 60;
    int a3 = (str[3] - '0') * 10;
    int a4 = (str[4] - '0');
    return a1 + a2 + a3 + a4;
}

int prev(int posnum, int startnum, int endnum) {
    posnum -= 10;
    if(posnum < 0) {
        posnum = 0;
    }
    if(startnum <= posnum && posnum < endnum) {
        posnum = endnum;
    }
    return posnum;
}

int next(int posnum, int lennum, int startnum, int endnum) {
    posnum += 10;
    if(lennum < posnum) {
        posnum = lennum;
    }
    if(startnum <= posnum && posnum < endnum) {
        posnum = endnum;
    }
    return posnum;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int lennum = convert(video_len);
    int posnum = convert(pos);
    int startnum = convert(op_start);
    int endnum = convert(op_end);

    if(startnum <= posnum && posnum < endnum) {
        posnum = endnum;
    }

    for(int i = 0 ; i < commands.size() ; i++) {
        if(commands[i] == "prev"){
            posnum = prev(posnum, startnum, endnum);
        }
        else {
            posnum = next(posnum, lennum, startnum, endnum);
        }
    }
    answer += to_string(posnum / 600);
    answer += to_string((posnum % 600) / 60);
    answer += ":";
    answer += to_string((posnum % 60) / 10);
    answer += to_string(posnum % 10);
    return answer;
}