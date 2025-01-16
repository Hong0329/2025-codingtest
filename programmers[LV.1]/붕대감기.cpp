//
// Created by hong jun chung on 1/16/25.
//
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int num = attacks[attacks.size()-1][0];
    int arr[num+1];
    int t = 0;
    int cnt = 0;

    for(int i = 1 ; i < num + 1 ; i++) {
        if(i==attacks[cnt][0]) {
            answer -= attacks[cnt][1];
            cout << answer << " ";
            if(answer <= 0) {
                return -1;
                break;
            }
            cnt++;
            t = 0;
        }
        else {
            answer += bandage[1];
            if(answer > health) answer = health;
            t += 1;
            if(t==bandage[0]) {
                answer += bandage[2];
                if(answer > health) answer = health;
                t = 0;
            }
            cout << answer << " ";
        }
    }
    return answer;
}