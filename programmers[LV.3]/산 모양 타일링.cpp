//
// Created by hong jun chung on 1/14/25.
// 산 모양 타일링 / LV.3
//
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> tops) {
    int cnt = 0;
    // vector<int> points;
    queue<int> points;

    for(int i = 0 ; i < tops.size() ; i++) {
        if(tops[i] == 1) {
            // points.push_back(2*i + 4 + cnt);
            points.push(2*i + 4 + cnt);
            cnt++;
        }
    }

    int num = 2 * n + 1 + cnt;

    int arr[num + 4];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(int j = 3 ; j < num + 1 ; j++) {
        // if((find(points.begin(), points.end(), j))==points.end()) {
        if(j!=points.front()) {
            arr[j] = (arr[j-1] + arr[j-2]) % 10007;
            // points.pop();
        }
        else {
            arr[j] = (arr[j-1] + arr[j-3]) % 10007;
            points.pop();
        }
    }
    return arr[num];
}