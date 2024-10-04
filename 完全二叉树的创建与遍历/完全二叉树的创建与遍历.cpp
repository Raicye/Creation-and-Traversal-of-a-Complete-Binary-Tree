/*

问题描述：



*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, tree[N];//定义节点数n，创建用于存储二叉树的数组tree；

void build(int x) {
	if (x > n) return;

	build(x * 2);

	build(x * 2 + 1);

	cin >> tree[x];
}

int main() {
	cin >> n;
	build(1);
	for (int i = 1; i <= n; i++) {
		cout << tree[i] << " ";
	}
	return 0;
}