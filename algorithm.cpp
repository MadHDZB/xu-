#define _CRT_SECURE_NO_WARNINGS

//二分查找 -- 切记要排序！

//例题：数的范围

//给定一个按照升序排列的长度为n的整数数组，以及q个查询。对于每个查询，返回一个元素k的起始位置和终止位置（位置从0开始计数）。
//如果数组中不存在该元素，则返回 - 1 - 1。
//输入格式：
//第一行包含整数n和q，表示数组长度和询问个数,
//第二行包含n个整数（均在1～10000范围内），表示完整数组,
//接下来q行，每行包含一个整数k，表示一个询问元素。
//输出格式：
//共q行，每行包含两个整数，表示所求元素的起始位置和终止位置。
//如果数组中不存在该元素，则返回 - 1 ,- 1

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 10010;
//
//int n, q, k;
//int arr[N];
//
////查找第一次出现的位置
//int binary_search1(int x)
//{
//	int l = -1, r = n;
//	while (l + 1 < r) {
//		int mid = (l + r) / 2;
//		if (arr[mid] < x) {
//			l = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	if (arr[r] == x) {
//		return r;
//	}
//	return -1;
//}
////查找最后一次出现的位置
//int binary_search2(int x)
//{
//	int l = -1, r = n;
//	while (l + 1 < r) {
//		int mid = (l + r) / 2;
//		if (arr[mid] <= x) {
//			l = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	if (arr[l] == x) {
//		return l;
//	}
//	return -1;
//}
//
//int main()
//{
//	scanf("%d%d", &n, &q);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	while (q--) {
//		scanf("%d", &k);
//		int res1 = binary_search1(k);
//		int res2 = binary_search2(k);
//
//		printf("%d\n", res1);
//		printf("%d\n", res2);
//	}
//	return 0;
//}

//浮点数的二分

//给定一个浮点数 n，求它的三次方根。
//输入格式
//共一行，包含一个浮点数n。
//输出格式
//共一行，包含一个浮点数，表示问题的解。
//注意，结果保留6位小数。
//数据范围：-10000≤n≤10000
//输入样例：1000.00
//输出样例：10.000000

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//double n;
//
//bool check(double x)
//{
//	if (x * x * x <= n) {
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	scanf("%lf", &n);
//
//	double l = -100, r = 100;
//	while (r - l > 1e-8) {
//		double mid = (l + r) / 2;
//		if (check(mid)) {
//			l = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	printf("%lf\n", l);
//	//printf("%lf\n", r);//结果一样的，因为l和r都精确到了1e-8，题目只要求1e-6
//	return 0;
//}

//P2249 查找（比例题还简单）

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 1000000;
//
//int n, m, x;
//int arr[N];
//
//int binary_search(int x)
//{
//	int l = 0, r = n + 1;
//	while (l + 1 < r) {
//		int mid = (l + r) / 2;
//		if (arr[mid] < x) {
//			l = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	if (arr[r] == x) {
//		return r;
//	}
//	return -1;
//}
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	while (m--) {
//		scanf("%d", &x);
//		int res = binary_search(x);
//		printf("%d ", res);
//	}
//	return 0;
//}

//P1102 A-B数对

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 200010;
//
//int n, c;
//int arr[N];
//long long res = 0;//数据太大，会爆int，int最大为2^31-1，最小-2^31
//
//void binary_search(int x)
//{
//	int l = -1, r = n, l1 = -1, r1 = n;
//	while (l + 1 < r) {
//		int mid = (l + r) / 2;
//		if (arr[mid] < x) {
//			l = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	if (arr[r] != x) return;
//
//	while (l1 + 1 < r1) {
//		int mid = (l1 + r1) / 2;
//		if (arr[mid] <= x) {
//			l1 = mid;
//		}
//		else {
//			r1 = mid;
//		}
//	}
//
//	res += (l1 - r + 1);
//}
//
//int main()
//{
//	scanf("%d%d", &n, &c);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < n; i++) {
//		int a = arr[i] + c;
//		binary_search(a);
//	}
//	printf("%lld\n", res);
//	return 0;
//}

//P1873 砍树 

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 1000010;
//
//int n, m;
//int arr[N];
//
//bool check(int x)
//{
//	int sum = 0;//记录此时的木材总长度
//	for (int i = 0; i < n; i++) {
//		sum += max(0, arr[i] - x);
//		if (sum >= m) return true;
//	}
//	return false;
//}
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	int highest = 0;//记录树的最大高度
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//		highest = max(highest, arr[i]);
//	}
//
//	int l = 0, r = highest;//二分锯子的高度（二分答案）
//	while (l + 1 < r) {
//		int mid = (l + r) / 2;
//		if (check(mid)) {
//			l = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	
//	if (check(r)) {//check的目的是检查所有情况不满足的情况，这时候二分的结果是L始终指向0，而R最终指向1，若不满足这种极端情况就可以输出L（输出R的意义是什么??），而这道题条件所有树的高度总和 > M，自动排除了极端情况，故这道保险没起作用
//		printf("%d\n", r);
//	}
//	else {
//		printf("%d\n", l);
//	}
//	return 0;
//}

//总结：二分答案型的有：最小值中最大 模型，最大值中最小 模型

//P2440 木材加工

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 100010;
//
//int n, k;
//int arr[N];
//
//bool check(int x)
//{
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += arr[i] / x;
//		if (sum >= k) return true;
//	}
//	return false;
//}
//
//int main()
//{
//	scanf("%d%d", &n, &k);
//
//	int longest = 0;
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//		longest = max(longest, arr[i]);
//	}
//
//	int l = 0, r = longest;
//	while (l + 1 < r) {
//		int mid = (l + r) / 2;
//		if (check(mid)) {
//			l = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	if (check(r)) {//不满足所有情况时，L指向0，刚好输出0。满足某种情况时，L指向最终结果，还是输出L（依然没搞懂输出R的情况是什么）
//		printf("%d", r);
//	}
//	else {
//		printf("%d\n", l);
//	}
//
//	return 0;
//}




//DFS -- Depth-First-Search：深度优先搜索

//题目1：从1到n这n个整数中随机任意选取多个，输出所有可能的选择方案

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 20;
//
//int n;
//int st[N];//state，记录每个数的状态，0表示还没考虑，1表示选这个数，2表示不选这个数
//
//void dfs(int x)
//{
//	if (x > n) {
//		for (int i = 1; i <= n; i++) {
//			if (st[i] == 1) {
//				printf("%d ", i);
//			}
//		}
//		printf("\n");
//		return;
//	}
//	//选
//	st[x] = 1;
//	dfs(x + 1);
//	st[x] = 0;//恢复到待选状态
//	//不选
//	st[x] = 2;
//	dfs(x + 1);
//	st[x] = 0;//恢复到待选状态
//}
//
//int main()
//{
//	scanf("%d", &n);
//	dfs(1);
//	return 0;
//}

//题目2：求n的全排列

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 10;
//
//int n;
//bool st[N];//true表示已经选过这个数，false表示还没选这个数
//int arr[N];//存的是答案
//
//void dfs(int x)
//{
//	if (x > n) {
//		for (int i = 1; i <= n; i++) {
//			printf("%d ", arr[i]);
//		}
//		printf("\n");
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!st[i]) {
//			st[i] = true;
//			arr[x] = i;
//			dfs(x + 1);
//			st[i] = false;//恢复现场
//			arr[x] = 0;//恢复现场
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//	dfs(1);
//	return 0;
//}

//题目3：求n的r组合数，即C（n, r）

//作者写法 -- 更妙！
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 21;
//
//int arr[N];//记录选了哪些数
//int n, r;
//
//void dfs(int x, int start)//x记录当前枚举到哪个位置，start记录当前位置从几开始枚举
//{
//  if(x + n - start < r) return;//剪枝（作用是提前退出，程序效率能够提高1倍）        其实应该是(x - 1) + (n - start + 1); x-1表示前面填了几个数，n-start+1表示还有几个数可供选择
// 
//	if (x > r) {
//		for (int i = 1; i <= r; i++) {
//			printf("%d ", arr[i]);
//		}
//		printf("\n");
//		return;
//	}
//	for (int i = start; i <= n; i++) {
//		arr[x] = i;
//		dfs(x + 1, i + 1);
//		arr[x] = 0;//恢复现场
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &n, &r);
//	dfs(1, 1);
//	return 0;
//} 

//自己的写法 -- 比较冗杂
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 21;
//
//int arr[N];//存储答案
//bool st[N];//表示这个数有没有被选
//int n, r;
//
//void dfs(int x)
//{
//	if (x > r) {
//		for (int i = 1; i <= r; i++) {
//			if (arr[i] != 0) {
//				printf("%d ", arr[i]);
//			}
//		}
//		printf("\n");
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!st[i] && i > arr[x - 1]) {//第二个条件是：保证后面选的数都比前面选的数更大，这样自然而然就避免重复了
//			arr[x] = i;
//			st[i] = true;
//			dfs(x + 1);
//			arr[x] = 0;
//			st[i] = false;
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &n, &r);
//	dfs(1);
//	return 0;
//}

//题目4：选数

//题目描述：
//已知n个整数x1，x2, …，xn，以及1个整数k（k < n）。从n个整数中任选k个整数相加，可分别得到一系列的和。
//例如当n = 4，k = 3，4个整数分别为3, 7，12，19时，可得全部的组合与它们的和为 :
//3 + 7 + 12 = 22
//3 + 7 + 19 = 29
//7 + 12 + 19 = 38
//3 + 12 + 19 = 34
//现在，要求你计算出和为素数共有多少种。
//例如上例，只有一种的和为素数：3 + 7 + 19＝ 29。
//输入格式：
//第一行两个空格隔开的整数m, k(1 <= n <= 20, k < n).
//第二行n个整数，分别为x1, x2, ... ,xn(1 <= xi <= 5 * 1e6 ）。
//输出格式：
//输出一个整数，表示种类数。

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 21;
//
//int arr[N];//记录选了哪几个数
//int num[N];//存数字
//int n, k;
//int count = 0;
//
//bool is_prime(int x)//prime素数
//{
//	int cnt = 0;
//	for (int i = 2; i * i <= x; i++) {//判断素数的优化算法！！！：i * i <= x即可！！！（原时间复杂度为O(n)，优化后变为O(根号n)）
//		if (x % i == 0) {
//			cnt++;
//		}
//	}
//	if (!cnt) {
//		return true;
//	}
//	return false;
//}
//
//void dfs(int x, int start)//x记录当前枚举到哪个位置，start记录当前位置从几开始枚举
//{
//	if (x > k) {
//		int sum = 0;
//		for (int i = 1; i <= k; i++) {
//			sum += num[arr[i]];
//		}
//		if (is_prime(sum)) {
//			::count++;//因为在using namespace std中有std::count算法，所以这里使用"::"明确指示该变量为全局变量
//		}
//		return;
//	}
//	for (int i = start; i <= n; i++) {
//		arr[x] = i;
//		dfs(x + 1, i + 1);
//		arr[x] = 0;//恢复现场
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &n, &k);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &num[i]);
//	}
//	dfs(1, 1);
//	printf("%d\n", ::count);
//	return 0;
//} 

//P2089 烤鸡

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 30;
//int res = 0;
//int arr[N];
//int n;
//
//void dfs1(int x, int sum)
//{
//    if (x > 10) {
//        if (sum == n) {
//            res++;
//        }
//        return;
//    }
//    for (int i = 1; i <= 3; i++) {
//        arr[x] = i;
//        dfs1(x + 1, sum + i);
//        arr[x] = 0;
//    }
//}
//
//void dfs2(int x, int sum)
//{
//    if (x > 10) {
//        if (sum == n) {
//            res++;
//            for (int i = 1; i <= 10; i++) {
//                printf("%d ", arr[i]);
//            }
//            printf("\n");
//        }
//        return;
//    }
//    for (int i = 1; i <= 3; i++) {
//        arr[x] = i;
//        dfs2(x + 1, sum + i);
//        arr[x] = 0;
//    }
//}
//
//int main()
//{
//    scanf("%d", &n);
//    dfs1(1, 0);
//    printf("%d\n", res);
//    dfs2(1, 0);
//    return 0;
//}

//P1088 火星人

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 10001;
//
//int arr[N];//记录方案
//bool st[N];//记录每个数选没选过
//int mars[N];//记录火星人的初始排列
//int n, m;
//int res = 0;
//
//void dfs(int x)
//{
//	if (x > n) {
//		res++;
//		if (res == m + 1) {//这里不是res == m，因为第一次遇到火星人给的数字时res也会加1
//			for (int i = 1; i <= n; i++) {
//				printf("%d ", arr[i]);
//			}
//			exit(0);//输出正确结果后退出程序，或者在前面加个判断条件res > m + 1就return
//		}
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (!res) {//妙！！！省去了大量没必要的遍历
//			i = mars[x];
//		}
//		if (!st[i]) {
//			arr[x] = i;
//			st[i] = true;
//			dfs(x + 1);
//			arr[x] = 0;
//			st[i] = false;
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &mars[i]);
//	}
//	dfs(1);
//	return 0;
//}

//P1149 火柴棒等式

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 1001;
//
//int n;
//int arr[N];
//int res = 0;
//int nums[1001] = { 6,2,5,5,4,5,6,3,7,6 };//存火柴棍
//
//void dfs(int x, int sum)
//{
//	if (sum > n) return;//剪枝
//	
//	if (x > 3) {
//		if (arr[1] + arr[2] == arr[3] && sum == n) {
//			res++;
//		}
//		return;
//	}
//	for (int i = 0; i <= 1000; i++) {
//		arr[x] = i;
//		dfs(x + 1, sum + nums[i]);
//		arr[x] = -1;//恢复现场
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//	n -= 4;
//	//记忆化搜索！！！：递推出后10 - 1000需要用到的火柴棍（时间复杂度更小了）
//	for (int i = 10; i <= 1000; i++) {
//		nums[i] = nums[i % 10] + nums[i / 10];
//	}
//	dfs(1, 0);
//	printf("%d\n", res);
//	return 0;
//}

//P2036 PERKET

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 20;
//
//int sour[N], bitter[N];
//int n;
//int st[N];
//int res = 1e9;
//
//void dfs(int x)
//{
//	if (x > n) {
//		int sum1 = 1;
//		int sum2 = 0;
//		bool has_tl = false;
//		for (int i = 1; i <= n; i++) {
//			if (st[i] == 1) {
//				has_tl = true;
//				sum1 *= sour[i];
//				sum2 += bitter[i];
//			}
//			if (has_tl) {
//				res = min(res, abs(sum1 - sum2));	//cpp库函数：min(x, y)，比较两个数大小并返回较小的那个数
//			}
//		}
//		return;
//	}
//	st[x] = 1;
//	dfs(x + 1);
//
//	st[x] = 2;
//	dfs(x + 1);
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d%d", &sour[i], &bitter[i]);
//	}
//	dfs(1);
//	printf("%d\n", res);
//	return 0;
//}

//P1683 入门 -- 代码实际上有问题的，如果必须走过同一瓷砖的话，st状态数组就得回溯，但是题目的样例显然不包含这种情况，所以这道题没有回溯

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 30;
//
//int w, h;
//char arr[N][N];//记录地图
//int dx[] = { -1,0,1,0 };//方向数组
//int dy[] = { 0,1,0,-1 };//方向数组
//bool st[N][N];//记录瓷砖是否走过了
//int res = 0;//记录瓷砖数
//
//void dfs(int x, int y)
//{
//	for (int i = 0; i < 4; i++) {
//		int a = x + dx[i], b = y + dy[i];
//
//		if (a < 0 || a >= h || b < 0 || b >= w) continue;
//		if (arr[a][b] == '#') continue;
//		if (st[a][b]) continue;
//
//		st[a][b] = true;
//		res++;
//		dfs(a, b);
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &w, &h);
//	for (int i = 0; i < h; i++) {
//		scanf("%s", arr[i]);
//	}
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (arr[i][j] == '@') {
//				st[i][j] = true;
//				dfs(i, j);
//			}
//		}
//	}
//	res++;//起点瓷砖也算入
//	printf("%d\n", res);
//	return 0;
//}

//P1596  Lake Counting S

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//const int N = 101;
//
//int n, m;
//char arr[N][N];
//bool st[N][N];
//int dx[] = { 1,1,1,0,0,-1,-1,-1 };//八联通的方向数组
//int dy[] = { -1,0,1,1,-1,1,0,-1 };//八联通的方向数组
//int res = 0;
//
//void dfs(int x, int y)
//{
//	for (int i = 0; i < 8; i++) {
//		int a = x + dx[i], b = y + dy[i];
//
//		if (a < 0 || a >= n || b < 0 || b >= m) continue;
//		if (arr[a][b] != 'W') continue;
//		if (st[a][b]) continue;
//
//		st[a][b] = true;
//		dfs(a, b);
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++) {
//		scanf("%s", arr[i]);
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (arr[i][j] == 'W' && !st[i][j]) {
//				st[i][j] = true;
//				dfs(i, j);
//				res++;
//			}
//		}
//	}
//	printf("%d\n", res);
//	return 0;
//}

//AcWing -- 1114 棋盘问题

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//const int N = 8;
//
//char arr[N][N];
//bool st[N];
//int n, k;
//int res = 0;
//
//void dfs(int x, int cnt)//x表示枚举到哪一行,cnt记录摆放的棋子数
//{
//	if (cnt == k) {
//		res++;
//		return;
//	}
//	if (x == n) return;
//	for (int i = 0; i < n; i++) {//枚举第几列
//		if (arr[x][i] == '#' && !st[i]) {
//			st[i] = true;
//			dfs(x + 1, cnt + 1);
//			st[i] = false;
//		}
//	}
//	dfs(x + 1, cnt);//跳过当前行
//}
//
//int main()
//{
//	while (scanf("%d%d", &n, &k)) {
//		if (n == -1) break;
//		for (int i = 0; i < n; i++) {
//			scanf("%s", arr[i]);
//		}
//		res = 0;
//		dfs(0, 0);
//		printf("%d\n", res);
//	}
//	return 0;
//}

//P1025 数的划分

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//
//const int N = 6;
//
//int n, k;
//int res = 0;
//
//void dfs(int x, int start, int sum)
//{
//	if (sum > n) return;
//	if (x > k) {
//		if (sum == n) {
//			res++;
//		}
//		return;
//	}
//	for (int i = start; sum + (k - x + 1) * i <= n; i++) {//妙啊妙啊！剪枝！循环条件是优化的结果，k-x+1表示后面还有几个数要填，而i就是能填的最小数，如果最小的结果都大于n，则不需要进入后面的循环了
//		dfs(x + 1, i, sum + i);
//	}
//}
//
//int main()
//{
//	scanf("%d%d", &n, &k);
//	dfs(1, 1, 0);
//	printf("%d\n", res);
//	return 0;
//}



//BFS -- Breadth-First-Search：广度优先搜索

//P1746 离开中山路

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//typedef pair<int, int> PII;//存坐标		pair<int, int>是STL提供的模板类，用于存储两个整数的有序对（可类比数学中的二维坐标点），PII是给它起的别名
//
//const int N = 1010;
//
//int n;
//int a1, b1, a2, b2;
//char arr[N][N];//存地图
//int dist[N][N];//存每个点到起点的距离 -- distance 
//queue<PII> q;//表示创建一个存储PII的队列
//
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//
//int bfs(int x, int y)
//{
//	memset(dist, -1, sizeof dist);//距离都初始化为-1
//	q.push({ x,y });
//	dist[x][y] = 0;
//
//	while (!q.empty()) {//队列不为空，继续循环
//		PII t = q.front();//取出队头
//		q.pop();//弹出
//
//		for (int i = 0; i < 4; i++) {
//			int a = t.first + dx[i], b = t.second + dy[i];    //first指t的第一个参数，即坐标x，同理，second指坐标y
//
//			if (a < 1 || a > n || b < 1 || b > n) continue;
//			if (arr[a][b] != '0') continue;
//			if (dist[a][b] >= 0) continue;
//
//			q.push({ a,b });
//			dist[a][b] = dist[t.first][t.second] + 1;
//
//			if (dist[a2][b2] > 0) return dist[a2][b2];
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%s", arr[i] + 1);//切记+1（数组名指向首元素地址，+1使数组指向第二个元素地址，即数组下标为1的地址）
//	}
//	scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
//	int res = bfs(a1, b1);
//	printf("%d\n", res);
//	return 0;
//}

//P1443 马的遍历

//做法1：常规队列
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//typedef pair<int, int> PII;
//
//const int N = 410;
//
//int n, m;
//int x, y;
//int dist[N][N];
//queue<PII> q;
//
//int dx[] = { 1,1,-1,-1,2,2,-2,-2 }, dy[] = { 2,-2,2,-2,1,-1,1,-1 };//马走日，所以坐标要特殊处理
//
//void bfs(int x, int y)
//{
//	memset(dist, -1, sizeof dist);
//	q.push({ x, y });
//	dist[x][y] = 0;
//
//	while (!q.empty()) {
//		auto t = q.front();
//		q.pop();
//
//		for (int i = 0; i < 8; i++) {
//			int a = t.first + dx[i], b = t.second + dy[i];
//
//			if (a < 1 || a > n || b < 1 || b > m) continue;
//			if (dist[a][b] >= 0) continue;
//
//			dist[a][b] = dist[t.first][t.second] + 1;
//			q.push({ a,b });
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d%d%d%d", &n, &m, &x, &y);
//	bfs(x, y);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			printf("%d ", dist[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//做法二：队列数组 -- 优点：比调用底层库函数速度更快
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//
//using namespace std;
//typedef pair<int, int> PII;
//
//const int N = 410;
//
//int n, m, x, y;
//int dist[N][N];
//PII q[N * N];
//int dx[] = { -2,-1,1,2,2,1,-1,-2 }, dy[] = { 1,2,2,1,-1,-2,-2,-1 };
//int h = 0, t = 0;//h队头，t队尾
//
//void bfs(int x, int y)
//{
//	memset(dist, -1, sizeof dist);
//	dist[x][y] = 0;
//	q[t++] = { x,y };
// 
//	while (h != t) {
//		PII temp = q[h++];
//
//		for (int i = 0; i < 8; i++) {
//			int a = temp.first + dx[i], b = temp.second + dy[i];
//
//			if (a < 1 || a > n || b < 1 || b > m) continue;
//			if (dist[a][b] >= 0) continue;
//
//			dist[a][b] = dist[temp.first][temp.second] + 1;
//			q[t++] = { a,b };
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d%d%d%d", &n, &m, &x, &y);
//	bfs(x, y);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			printf("%d ", dist[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//P1332 血色先锋队 -- 多源BFS

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//typedef pair<int, int> PII;
//
//const int N = 510;
//
//queue<PII> q;
//int n, m, a, b;
//int dist[N][N];
//
//int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
//
//void bfs()
//{
//	while (!q.empty()) {
//		auto t = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int p1 = t.first + dx[i], p2 = t.second + dy[i];
//
//			if (p1 < 1 || p1 > n || p2 < 1 || p2 > m) continue;
//			if (dist[p1][p2] >= 0) continue;
//
//			q.push({ p1,p2 });
//			dist[p1][p2] = dist[t.first][t.second] + 1;
//		}
//	}
//}
//
//int main()
//{
//	int x, y;
//	scanf("%d%d%d%d", &n, &m, &a, &b);
//	memset(dist, -1, sizeof dist);
//	while (a--) {
//		scanf("%d%d", &x, &y);
//		dist[x][y] = 0;
//		q.push({ x,y });
//	}
//	bfs();
//	while (b--) {
//		scanf("%d%d", &x, &y);
//		printf("%d\n", dist[x][y]);
//	}
//	return 0;
//}

//AcWing -- 173 矩阵距离        习题

//P1162 填涂颜色 -- 染色问题

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//typedef pair<int, int> PII;
//
//const int N = 35;
//
//queue<PII> q;
//int n;
//int arr[N][N];
//bool st[N][N];
//int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
//
//void bfs(int x, int y)
//{
//	q.push({ x,y });
//	st[x][y] = true;
//
//	while (!q.empty()) {
//		auto t = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int a = t.first + dx[i], b = t.second + dy[i];
//
//			if (a < 0 || a > n + 1 || b < 0 || b > n + 1) continue;
//			if (st[a][b]) continue;
//			if (arr[a][b] == 1) continue;
//
//			q.push({ a,b });
//			st[a][b] = true;
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	bfs(0, 0);//妙！！将方阵往外扩一圈，这样就保证边界一定是0了，再往边界倒一桶水，这样的话没有被灌溉的0就是被1围起来的0了
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (arr[i][j] == 0 && !st[i][j]) {
//				arr[i][j] = 2;
//			}
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//P2895 天降陨石 -- 有外界干扰的迷宫问题

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//
//using namespace std;
//typedef pair<int, int> PII;
//
//const int N = 310;
//
//queue<PII> q;
//int m, x, y, t;
//int fire[N][N];
//int dist[N][N];
//
//int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
//
//int bfs()
//{
//	memset(dist, -1, sizeof dist);
//	q.push({ 0,0 });
//	dist[0][0] = 0;
//
//	while (!q.empty()) {
//
//		auto t = q.front();
//		q.pop();
//		
//		for (int i = 0; i < 4; i++) {
//			int a = t.first + dx[i], b = t.second + dy[i];
//
//			if (a < 0 || b < 0) continue;//贝西可以越界
//			if (dist[a][b] >= 0) continue;
//
//			dist[a][b] = dist[t.first][t.second] + 1;
//			if (dist[a][b] >= fire[a][b]) continue;
//			q.push({ a,b });
//
//			if (fire[a][b] == 0X3f3f3f3f) return dist[a][b];
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	scanf("%d", &m);
//	memset(fire, 0X3f, sizeof fire);
//	while (m--) {
//		scanf("%d%d%d", &x, &y, &t);
//		fire[x][y] = min(t, fire[x][y]);
//		for (int i = 0; i < 4; i++) {
//			int a = x + dx[i], b = y + dy[i];
//			if (a < 0 || a > 301 || b < 0 || b > 301) continue;
//			fire[a][b] = min(t, fire[a][b]);//取最早落在（x, y）的那个流星的时间
//		}
//	}
//	int res = bfs();
//	printf("%d\n", res);
//	return 0;
//}

//P2658 汽车拉力比赛

//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<queue>
//
//using namespace std;
//typedef pair<int, int> PII;
//
//const int N = 510;
//
//int m, n;
//int arr[N][N];//地图
//int flag[N][N];//记录路标
//bool st[N][N];//记录走过的山
//int sign_cnt = 0;//记录路标数
//int x, y;//记录查找到的第一个路标位置
//queue<PII> q;
//
//int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
//
//bool check(int x1)
//{
//	int cnt = 1;//记录已经走过的路标数
//	q.push({ x,y });
//	st[x][y] = true;
//
//	while (!q.empty()) {
//		auto t = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int a = t.first + dx[i], b = t.second + dy[i];
//
//			if (a < 0 || a >= m || b < 0 || b >= n) continue;
//			if (st[a][b]) continue;
//			if (abs(arr[a][b] - arr[t.first][t.second]) > x1) continue;
//
//			st[a][b] = true;
//			q.push({ a,b });
//			if (flag[a][b] == 1) {
//				cnt++;
//				if (cnt == sign_cnt) {
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	scanf("%d%d", &m, &n);
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &flag[i][j]);
//			if (flag[i][j] == 1) {
//				x = i, y = j;
//				sign_cnt++;
//			}
//		}
//	}
//
//	int l = -1, r = 1e9 + 10;
//	while(l + 1 < r) {
//		int mid = (l + r) / 2;
//		while (!q.empty()) {//每次都要清空队列
//			q.pop();
//		}
//		memset(st, false, sizeof st);//清空状态数组
//		if (check(mid)) {
//			r = mid;
//		}
//		else {
//			l = mid;
//		}
//	}
//	printf("%d\n", r);
//	return 0;
//}

