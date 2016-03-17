//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

vector<int> res;
int knap(int i, int sum, int sumlim, int lim, vector<pair<int, int>> v) {
	if (sum > lim)
		return -1e9;
	if (i == (int) v.size())
		return sumlim;
	return max(knap(i + 1, sum + v[i].second, sumlim + v[i].first, lim, v),
			knap(i + 1, sum, sumlim, lim, v));
}
void knapv(int i, int sum, vector<int> temp, vector<pair<int, int>> v,
		int sumlim) {
	if (sum == sumlim) {
		res = temp;
		return;
	}
	if (i == (int) v.size() || sum > sumlim)
		return;
	temp.push_back(v[i].second);
	knapv(i + 1, sum + v[i].first, temp, v, sumlim);
	if (!temp.empty())
		temp.pop_back();
	knapv(i + 1, sum, temp, v, sumlim);
}

//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// knapsack
	vector<pair<int, int>> v;
	vector<int> temp;
	int n, x, y, wi;
	cin >> wi >> n;
	while (n--) {
		cin >> x >> y;
		v.push_back( { x, y });
	}
	knapv(0, 0, temp, v, knap(0, 0, 0, wi, v));
	for (auto i : res)
		cout << i << endl;
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
