#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int total;
    cin >> total;
    unordered_map<int, pair<int, int>>un_map;
    int tick=0;
    for (int i = 0; i < total; ++i) {
        ++tick;
        int num;
        cin >> num;
        if (un_map.find(num) != un_map.end()) {
            un_map[num].first++;
        }
        else {
            if (un_map.size() < N) {
                un_map.insert({ num, { 1,tick } });
            }
            else {
                int min = INT_MAX;
                for (unordered_map<int, pair<int, int>>::iterator iter = un_map.begin(); iter != un_map.end(); ++iter) {
                    if (iter->second.first < min) {
                        min = iter->second.first;
                    }
                }
                int min_tick=INT_MAX;
                for (unordered_map<int, pair<int, int>>::iterator iter = un_map.begin(); iter != un_map.end(); ++iter) {
                    if (iter->second.first==min&& (iter->second.second<min_tick)) {
                        min_tick = iter->second.second;
                    }
                }
                for (unordered_map<int, pair<int, int>>::iterator iter = un_map.begin(); iter != un_map.end();) {
                    if (iter->second.first == min && iter->second.second == min_tick) {
                        iter = un_map.erase(iter);
                    }
                    else {
                        ++iter;
                    }
                }
                un_map.insert({ num, { 1,tick } });
            }
        }
    }
    vector<int>res;
    for (unordered_map<int, pair<int, int>>::iterator iter = un_map.begin(); iter != un_map.end(); ++iter) {
        res.push_back(iter->first);
    }
    sort(res.begin(), res.end(), less<int>());
    for (int i : res) {
        cout << i << ' ';
    }
    return 0;
}