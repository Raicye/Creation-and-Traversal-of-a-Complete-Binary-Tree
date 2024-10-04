/*

问题描述：

现给出一个完全二叉树的节点个数以及它的后序遍历，请给出该树的层序遍历。

输入：
第一行为节点数，第二行为后序遍历序列。

输出：
在一行中输出该树的层序遍历，所有数字都以一个空格分割。


输入：
8
91 71 2 34 10 15 55 18

输出：
18 34 55 71 2 10 15 91

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, tree[N];//定义节点数n，创建用于存储二叉树的数组tree；

void build(int x) {//根据后序遍历创建二叉树。
	if (x > n) return;//如果x大于节点数n，则返回。
                      //若x>n则表明该节点x没有左/右子树，或没有叶子节点。

	build(x * 2);//创建左子树

	build(x * 2 + 1);//创建右子树

	cin >> tree[x];
}

/*
void build(int x) {//根据先序遍历创建二叉树。
	if (x > n) return;//如果x大于节点数n，则返回。
	//若x>n则表明该节点x没有左/右子树，或没有叶子节点。
	
	cin >> tree[x];
	
	build(x * 2);//创建左子树

	build(x * 2 + 1);//创建右子树

}
*/

/*
void build(int x) {//根据中序遍历创建二叉树。
	if (x > n) return;//如果x大于节点数n，则返回。
	//若x>n则表明该节点x没有左/右子树，或没有叶子节点。

	build(x * 2);//创建左子树

	cin >> tree[x];

	build(x * 2 + 1);//创建右子树

}
*/

void xianxu(int x) {//先序遍历输出。
	if (x > n) return;
	
	cout << tree[x] << " ";
	
	xianxu(x * 2);

	xianxu(x * 2 + 1);
}

void zhongxu(int x) {//中序遍历输出。
	if (x > n) return;

	zhongxu(x * 2);

	cout << tree[x] << " ";

	zhongxu(x * 2 + 1);
}

void houxu(int x) {//后序遍历输出。
	if (x > n) return;

	houxu(x * 2);
	
	houxu(x * 2 + 1);
	
	cout << tree[x] << " ";
}

int main() {
	cin >> n;
	build(1);

	for (int i = 1; i <= n; i++) {//层序遍历。
		cout << tree[i] << " ";
	}
	cout << endl;

	xianxu(1);//先序遍历
	cout << endl;

	zhongxu(1);//中序遍历
	cout << endl;

	houxu(1);//后序遍历
	cout << endl;

	return 0;
}
/*
注：
1.完全二叉树的节点数是确定的，同时，根据节点数，二叉树的形状也就确定了。
2.若已知一个结点存储在数组的下标x，则该结点的左孩子下标为2*x，右孩子下标为x*2+1
*/
