# include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;

    vector<string> unheard(n);
    vector<string> unseen(m);
    vector<string> duplicate;

    for(int i=0; i<n; i++){
        cin >> unheard[i];
    }
    for(int i=0; i<m; i++){
        cin >> unseen[i];
    }

    sort(unheard.begin(), unheard.end());
    sort(unseen.begin(), unseen.end());

    int i=0, j=0;
    while (i<n && j<m){
        if(unheard[i] == unseen[j]){
            duplicate.push_back(unheard[i]);
            i++; j++;
        }
        else if(unheard[i] < unseen[j]){
            i++;
        }
        else{
            j++;
        }
    }

    cout << duplicate.size()<<"\n";
    for(const string& name: duplicate){
        cout << name << "\n";
    }

    return 0;
}
