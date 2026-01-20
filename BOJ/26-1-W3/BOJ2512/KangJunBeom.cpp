#include <bits/stdc++.h>
using namespace std;

int money[10001];
int n, target;
int low = 1, high;
long long ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i<n; ++i){
		cin >> money[i];
		if(high<money[i]) high = money[i];
	}
	cin >> target;

	while(low<=high){
		int sum = 0;
		int mid = (low+high)/2;
		for(int i = 0; i<n; ++i){
			if(money[i]>=mid) sum+=mid;
			else sum += money[i];
		}
		if(sum<=target){
			low = mid+1;
			ans = mid;
		}
		else{
			high = mid-1;
		}
	}

	cout << ans;
}