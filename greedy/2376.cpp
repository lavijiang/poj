/*
*greedy
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 25000 + 2;

struct shift{
	int l, r;
}lr[N];

bool cmp(shift a, shift b){
	return a.l < b.l;
}

int main() {
	int t, n, res = 1;
	cin >> n >> t;
	for (int i = 0; i < n; i++){
		cin >> lr[i].l >> lr[i].r;
	}

	sort(lr, lr + n, cmp);
	if (lr[0].l > 1){
		cout << "-1" << endl;
		return 0;
	}
	int st = 1, end = 1;
	for (int i = 0; i < n; i++){
		if (lr[i].l <= st){
			end = max(end, lr[i].r);
		}
		else{
			res++;
			st = end + 1;
			if (lr[i].l > st){
				cout << "-1";
				return 0;
			}
			else{
				end = max(end, lr[i].r);
			}
		}
		if (end >= t){
			break;
		}

	}
	if (end < t)
		cout << "-1";
	else
		cout << res;
	return 0;
}