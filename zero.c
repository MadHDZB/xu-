#define _CRT_SECURE_NO_WARNINGS

//线性表
//由n(n >= 0)个数据特性相同的元素构成的有限序列，称为线性表
//线性表中元素的个数n定义为线性表的长度，当n=0时称为空表
//对于非空的线性表或线性结构，特点是：
//存在唯一一个被称为“第一个”的数据元素（首节点）
//存在唯一一个被称为“最后一个”的数据元素（尾节点）
//除第一个元素外，结构中的每个数据元素均只有一个前驱
//除最后一个元素外，结构中的每个数据元素均只有一个后继



//顺序表
//用一组连续的内存单元依次存储线性表的各个元素，也就是说，逻辑上相邻的元素，实际的物理存储空间也是连续的


//顺序表演示

//#include<stdio.h>
//#include<stdlib.h>
//#define MAXSIZE 100
//typedef int ElemType;
////顺序表定义
//typedef struct {
//	ElemType* data;
//	int length;
//}SeqList;
////顺序表初始化
//SeqList* InitSeqList()
//{
//	SeqList* s = (SeqList*)malloc(sizeof(SeqList));
//	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//	s->length = 0;
//	return s;
//}
////尾部添加元素
//int appendElem(SeqList* s, ElemType e)
//{
//	if (s->length >= MAXSIZE) {
//		printf("顺序表已满\n");
//		return 0;
//	}
//	s->data[s->length] = e;
//	s->length++;
//	return 1;
//}
////遍历顺序表
//void ListElem(SeqList* s)
//{
//	for (int i = 0; i < s->length; i++) {
//		printf("%d ", s->data[i]);
//	}
//	printf("遍历结束\n");
//}
////插入元素
//int insertElem(SeqList* s, int pos, ElemType e)//pos代表第几个元素
//{
//	if (s->length >= MAXSIZE) {
//		printf("顺序表已经满了\n");
//		return 0;
//	}
//	if (pos < 1 || pos > s->length) {
//		printf("插入位置错误\n");
//		return 0;
//	}
//	for (int i = s->length - 1; i >= pos - 1; i--) {
//		s->data[i + 1] = s->data[i];
//	}
//	s->data[pos - 1] = e;
//	s->length++;
//	return 1;
//}
////删除元素
//ElemType deleteElem(SeqList* s, int pos)
//{
//	ElemType e = s->data[pos - 1];
//	if (pos < 1 || pos > s->length) {
//		printf("删除位置错误\n");
//		return 0;
//	}
//	for (int i = pos - 1; i < s->length - 1; i++) {
//		s->data[i] = s->data[i + 1];
//	}
//	s->length--;
//	return e;
//}
////查找元素
//int findElem(SeqList* s, ElemType e)
//{
//	if (s->length == 0) {
//		printf("顺序表为空");
//		return 0;
//	}
//	for (int i = 0; i < s->length; i++) {
//		if (s->data[i] == e) {
//			return i + 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	SeqList* s = InitSeqList();	//用指针的话结构体不会自动初始化？
//	printf("初始化成功，此时长度为：%d\n", s->length);
//	printf("目前占用内存%zu个字节\n", sizeof(ElemType) * MAXSIZE);	//注意：若打印sizeof(s->data)结果是4个字节，因为sizeof(s->data)是指针的大小，而不是它指向内存的大小
//	appendElem(s, 88);
//	appendElem(s, 77);
//	appendElem(s, 66);
//	ListElem(s);
//	int sign1 = insertElem(s, 2, 33);
//	if (sign1) {
//		printf("插入数据成功\n");
//	}
//	else {
//		printf("插入数据失败\n");
//	}
//	ListElem(s);
//	int sign2 = deleteElem(s, 2);
//	if (sign2) {
//		printf("删除成功，删除元素为：%d\n",sign2);
//	}
//	ListElem(s);
//	int sign3 = findElem(s, 66);
//	if (sign3) {
//		printf("你查找的是第%d个元素\n", sign3);
//	}
//	else {
//		printf("查找失败\n");
//	}
//	free(s->data);
//	free(s);
//	return 0;
//}



//链表
//线性表链式存储结构的特点是：用一组任意的存储单元存储线性表的数据元素（这组存储单元可以是连续的，也可以是不连续的）。
//为了表示每个数据元素a(i)与其直接后继数据元素 a(i+1)之间的逻辑关系，对数据元素ai来说，除了其本身的信息之外，还需要存储一个指示其直接后继的信息（直接后继的存储位置），
//这两部分信息组成数据元素a(i)的存储映像，称为“节点”（node）
//结点包括两个域：其中存储数据元素信息的称为“数据域”；存储直接后继存储位置有域称为“指针域”。指针域中存储的信息称作指针或链。
//（即一个节点存储着当前位置的数据以及指向下一个位置的指针）

////单链表演示

//#include<stdio.h>
//#include<stdlib.h>
//typedef int ElemType;
////单链表定义
//typedef struct node {
//	ElemType data;
//	struct node* next;
//}Node;
////初始化
//Node* initList()
//{
//	Node* head = (Node*)malloc(sizeof(Node));
//	head->data = 0;
//	head->next = NULL;
//	return head;
//}
////插入数据 - 头插法（每次把数据都插在头的后面）
//void insertElem(Node* L, ElemType e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = e;
//	p->next = L->next;
//	L->next = p;
//}
////获取尾部节点
//Node* get_tail(Node* L)
//{
//	Node* p = L;
//	while (p->next != NULL) {
//		p = p->next;
//	}
//	return p;
//}
////插入数据 - 尾插法（每次把数据都插在尾的后面）
//Node* insertTail(Node* tail, ElemType e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = e;
//	tail->next = p;
//	p->next = NULL;
//	return p;
//}
////在指定位置插入数据
//int insertNode(Node* L, int pos, ElemType e)
//{
//	//用来保存插入位置的前驱节点
//	Node* p = L;
//	int i = 0;
//	//遍历链表找到插入位置的前驱节点
//	while (i < pos - 1) {
//		p = p->next;
//		i++;
//		if (p == NULL) {
//			return 0;
//		}
//	}
//	//要插入的新节点
//	Node* q = (Node*)malloc(sizeof(Node));
//	q->data = e;
//	q->next = p->next;
//	p->next = q;
//	return 1;
//}
////遍历
//void ListNode(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
////删除节点
//int deleteNode(Node* L, int pos)
//{
//	Node* p = L;
//	int i = 0;
//	//找到要删除节点的前驱节点
//	while (i < pos - 1) {
//		p = p->next;
//		i++;
//		if (p == NULL || p->next == NULL) {
//			printf("要删除的位置错误\n");
//			return 0;
//		}
//	}
//	//找到要删除的节点并释放空间
//	Node* q = p->next;
//	p->next = q->next;
//	free(q);
//	return 1;
//}
////获取链表长度
//int ListLength(Node* L)
//{
//	Node* p = L;
//	int len = 0;
//	while (p != NULL) {
//		p = p->next;
//		len++;
//	}
//	return len;
//}
////释放链表（注意头节点的空间是不释放的）
//void freeList(Node* L)
//{
//	Node* p = L->next;
//	Node* q;
//	while (p != NULL) {
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	L->next = NULL;
//}
////利用双指针找到倒数第k个节点		可以画图辅助理解				双指针应用场景广泛，多思考
//void findNodeFS(Node* L, int k)
//{
//	Node* fast = L->next;
//	Node* slow = L->next;
//	for (int i = 0; i < k; i++) {
//		fast = fast->next;
//	}
//	while (fast != NULL) {
//		fast = fast->next;
//		slow = slow->next;
//	}
//	printf("倒数第%d个节点的值为：%d\n", k, slow->data);
//}
////反转链表
//Node* reverseList(Node* head)
//{
//	Node* first = NULL;
//	Node* second = head->next;
//	Node* third;
//	while (second != NULL) {
//		third = second->next;
//		second->next = first;					//指针的“=”可以直接看成前面的指针指向“=”后面的部分
//		first = second;
//		second = third;
//	}
//	Node* hd = initList();
//	hd->next = first;
//	return hd;
//}
////删除列表中间节点				依然快慢指针
//void delMiddleNode(Node* head)
//{
//	Node* fast = head->next;
//	Node* slow = head;
//	while (fast != NULL && fast->next != NULL) {   
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	Node* q = slow->next;
//	slow->next = q->next;
//	free(q);
//}
//int main()
//{
//	Node* list = initList();
//	insertElem(list, 10);
//	insertElem(list, 20);
//	insertElem(list, 30);
//	Node* tail = get_tail(list);
//	tail = insertTail(tail, 40);
//	tail = insertTail(tail, 50);
//	tail = insertTail(tail, 60);
//	ListNode(list);
//	//insertNode(list, 2, 15);
//	//ListNode(list);
//	//int sign = deleteNode(list, 99);
//	//if (sign) {
//	//	ListNode(list);
//	//}
//	//findNodeFS(list, 3);
//	delMiddleNode(list);
//	ListNode(list);
//	printf("%d\n", ListLength(list));
//	/*Node* reverse = reverselist(list);
//	listnode(reverse);
//	freelist(list);
//	printf("%d\n", listlength(list));*/
//	return 0;
//}




//求两串具有相同后缀的字符串（且相同后缀储存在同一个链表中），其相同后缀的起始位置

//#include<stdio.h>
//#include<stdlib.h>
//typedef char Elemtype;
////创建
//typedef struct node {
//	Elemtype data;
//	struct node* next;
//}Node;
////初始化
//Node* initList()
//{
//	Node* L = (Node*)malloc(sizeof(Node));
//	L->data = 0;
//	L->next = NULL;
//	return L;
//}
////添加数据--尾插法
//int insertNode(Node* L, Elemtype e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	while (L->next != NULL) {
//		L = L->next;
//	}
//	L->next = p;
//	p->data = e;
//	p->next = NULL;
//	return 1;
//}
////遍历
//void printList(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL) {
//		printf("%c ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
////获取链表长度
//int listLength(Node* L)
//{
//	Node* p = L->next;
//	int len = 0;
//	while (p != NULL) {
//		len++;
//		p = p->next;
//	}
//	return len;
//}
////获取相同后缀的起始位置
//Elemtype getPos(Node* L1, Node* L2, int len1, int len2)
//{
//	int t = 0;
//	Node* p = NULL, *p1 = NULL;
//	if (len1 > len2) {
//		t = len1 - len2;
//		p = L1->next;
//		p1 = L2->next;
//	}
//	else {
//		t = len2 - len1;
//		p = L2->next;
//		p1 = L1->next;
//	}
//	while (t > 0) {
//		p = p->next;
//		t--;
//	}
//	while (1) {
//		if (p->data == p1->data) {
//			return p->data;
//			break;
//		}
//		p = p->next;
//		p1 = p1->next;
//	}
//}
////释放链表（注意头节点的空间是不释放的）
//void freeList(Node* L)
//{
//	Node* p = L->next;
//	Node* q;
//	while (p != NULL) {
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	L->next = NULL;
//}
//int main()
//{
//	Node* L1 = initList();
//	Node* L2 = initList();
//	printf("初始化成功\n");
//	insertNode(L1, 'l');
//	insertNode(L1, 'o');
//	insertNode(L1, 'a');
//	insertNode(L1, 'd');
//	insertNode(L1, 'i');
//	insertNode(L1, 'n');
//	insertNode(L1, 'g');
//	insertNode(L2, 'b');
//	insertNode(L2, 'e');
//	insertNode(L2, 'i');
//	insertNode(L2, 'n');
//	insertNode(L2, 'g');
//	printList(L1);
//	printList(L2);
//	int len1 = listLength(L1);
//	int len2 = listLength(L2);
//	printf("%d\n", len1);
//	printf("%d\n", len2);
//	Elemtype e = getPos(L1, L2, len1, len2);
//	printf("相同后缀的字母为：%c\n", e);
//	freeList(L1);
//	freeList(L2);
//	return 0;
//}




////拿空间换时间！！！！！

////题目要求：用单链表保存n个整数，节点结构为[data][link],且|data|<=n（n为正整数）。现要求设计一个时间复杂度尽可能高的算法，对于链表中data的绝对
////值相等的节点，仅保留第一次出现的节点而删除其余绝对值相等的节点。
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
////创建
//typedef struct node {
//	int data;
//	struct node* next;
//}Node;
////初始化
//Node* initList()
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = 0;
//	p->next = NULL;
//	return p;
//}
////添加数据--尾插法
//int insertElem(Node* L, int e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	while (L->next != NULL) {
//		L = L->next;
//	}
//	L->next = p;
//	p->data = e;
//	p->next = NULL;
//	return 1;
//}
////遍历
//void printList(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
////删除绝对值相同的节点获取新链表
//void removeNode(Node* L, int n)
//{
//	Node* p = L;
//	int index;	//作为数组下标使用
//	int* arr = (int*)malloc(sizeof(int) * (n + 1));	//数组的下标恰好为data的绝对值，通过开辟空间来减少时间复杂度（即用空间换时间）
//	for (int i = 0; i < n + 1; i++) {
//		*(arr + i) = 0;
//	}
//	while (p->next != NULL) {
//		index = abs(p->next->data);
//		if (*(arr + index) == 0 ) {
//			*(arr + index) = 1;		//数组值为1代表m这个数已经存在，为0代表不存在
//			p = p->next;
//		}
//		else {
//			Node* temp = p->next;		//将该节点删除
//			p->next = temp->next;
//			free(temp);
//		}
//	}
//	free(arr);
//}
//int main()
//{
//	Node* L = initList();
//	printf("初始化成功\n");
//	insertElem(L, 11);
//	insertElem(L, -11);
//	insertElem(L, 22);
//	insertElem(L, -33);
//	insertElem(L, 33);
//	insertElem(L, 44);
//	printList(L);
//	removeNode(L, 44);
//	printList(L);
//	return 0;
//}




//由a1 a2 a3 ... an 类型链表变成 a1 an a2 an-1 a3 an-2 ... 类型的链表
//#include<stdio.h>
//#include<stdlib.h>
//typedef int Elemtype;
////创建
//typedef struct node {
//	Elemtype data;
//	struct node* next;
//}Node;
////初始化
//Node* initList()
//{
//	Node* L = (Node*)malloc(sizeof(Node));
//	L->data = 0;
//	L->next = NULL;
//	return L;
//}
////添加数据--尾插法
//void insertTail(Node* L, Elemtype e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	while (L->next != NULL) {
//		L = L->next;
//	}
//	L->next = p;
//	p->data = e;
//	p->next = NULL;
//}
////遍历
//void printList(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
////将链表分为两半
//Node* divList(Node* L)
//{
//	Node* fast = L;
//	Node* slow = L;
//	while (fast != NULL && fast->next != NULL) {
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}
////反转链表
//Node* reverseList(Node* L)
//{
//	Node* p = L->next;
//	Node* p1 = p->next;
//	Node* p2 = p1->next;
//	p->next = NULL;	//此时第一个节点变成最后一个节点
//	while (p2 != NULL) {
//		p1->next = p;
//		p = p1;
//		p1 = p2;
//		p2 = p2->next;
//	}
//	p1->next = p;
//	L->next = p1;
//	return L;
//}
////执行插入操作
//Node* newList(Node* L1, Node* L2)	//第一个参数为原链表，第二个参数为反转后的后半段链表
//{
//	Node* p = L1->next;
//	Node* q = L2->next;
//	Node* p1 = p->next;
//	Node* q1 = q->next;
//	while (q1 != NULL) {
//		p->next = q;
//		q->next = p1;
//		p = p1;
//		p1 = p1->next;
//		q = q1;
//		q1 = q1->next;
//	}
//	p->next = q;
//	if (p1 != q) {		//偶数个节点时，p1和q是相等的，奇数个节点时，p1和q是不相等的，需要另外处理
//		q->next = p1;
//		p1->next = NULL;
//	}
//	return L1;
//}
//int main()
//{
//	Node* L = initList();
//	printf("初始化成功\n");
//	insertTail(L, 11);
//	insertTail(L, 22);
//	insertTail(L, 33);
//	insertTail(L, 44);
//	insertTail(L, 55);
//	insertTail(L, 66);
//	insertTail(L, 77);
//	printList(L);
//	Node* half = divList(L);	//后半段链表
//	printList(half);
//	Node* half1 = reverseList(half);	//反转后的后半段链表
//	printList(half1);
//	Node* finalList = newList(L, half1);
//	printList(finalList);
//	return 0;
//}




//判断链表是否有环 -- 快慢指针

//#include<stdio.h>
//#include<stdlib.h>
//typedef int Elemtype;
//创建
//typedef struct node{
//	Elemtype data;
//	struct node* next;
//}Node;
//初始化
//Node* initList()
//{
//	Node* L = (Node*)malloc(sizeof(Node));
//	L->data = 0;
//	L->next = NULL;
//	return L;
//}
//插入数据 -- 尾插法
//void insertNode(Node* L, Elemtype e)
//{
//	while (L->next != NULL) {
//		L = L->next;
//	}
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = e;
//	p->next = NULL;
//	L->next = p;
//}
//遍历
//void printList(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//获取链表尾部
//Node* tailList(Node* L)
//{
//	while (L->next != NULL) {
//		L = L->next;
//	}
//	return L;
//}
//判断是否有环
//int isCycle(Node* L)
//{
//	Node* fast = L->next;
//	Node* slow = L->next;
//	while (fast != NULL && fast->next != NULL) {	//如果没环，那么fast或fast->next会指向NULL
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast) {		//相遇说明有环
//			return 1;
//		}
//	}
//	return 0;
//}
//查找环的起点
//Node* start(Node* L)
//{
//	先确定环有多少个节点
//	int cnt = 0;	//环的节点数
//	Node* fast = L;
//	Node* slow = L;
//	while (fast != NULL && fast->next != NULL) {
//		fast = fast->next->next;
//		slow = slow->next;
//		if (slow == fast) {
//			break;
//		}
//	}
//	while (1) {
//		fast = fast->next;
//		cnt++;
//		if (slow == fast) {
//			break;
//		}
//	}
//	再从头走起，fast先走cnt（环的节点数）步，然后slow和fast一起走，直到相遇就是环的起点
//	fast = L;
//	slow = L;
//	while (cnt != 0) {
//		fast = fast->next;
//		cnt--;
//	}
//	while (slow != fast) {
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return fast;
//}
//int main()
//{
//	Node* L = initList();
//	printf("初始化成功\n");
//	insertNode(L, 11);
//	insertNode(L, 22);
//	insertNode(L, 33);
//	Node* tail = tailList(L);
//	Node* three = tail;
//	insertNode(L, 44);
//	insertNode(L, 55);
//	insertNode(L, 66);
//	printList(L);
//	Node* L1 = L;
//	while (L1->next != NULL) {
//		L1 = L1->next;
//	}
//	L1->next = three;
//	if (isCycle(L)) {
//		printf("有环\n");
//		Node* p = start(L);
//		printf("环的起始节点为：%d\n", p->data);
//	}
//	else {
//		printf("没环\n");
//	}
//	return 0;
//}




//循环链表怎么释放空间？？




//双向链表
//包含三个指针域：prev：指向前驱节点；data：数据域；next：指向后继节点

//双向链表演示
//#include<stdio.h>
//#include<stdlib.h>
//typedef int Elemtype;
////创建
//typedef struct node {
//	struct node* prev;
//	Elemtype data;
//	struct node* next;
//}Node;
////初始化
//Node* initList()
//{
//	Node* L = (Node*)malloc(sizeof(Node));
//	L->prev = NULL;
//	L->data = 0;
//	L->next = NULL;
//	return L;
//}
////插入数据 -- 头插法
//void insertHead(Node* L, Elemtype e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = e;
//	p->next = L->next;
//	L->next = p;
//	p->prev = L;
//	if (p->next != NULL) {
//		p->next->prev = p;
//	}
//}
////插入数据 -- 尾插法
//void insertTail(Node* L, Elemtype e)
//{
//	while (L->next != NULL) {
//		L = L->next;
//	}
//	Node* p = (Node*)malloc(sizeof(Node));
//	L->next = p;
//	p->prev = L;
//	p->data = e;
//	p->next = NULL;
//}
////遍历
//void printList(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
////在指定位置插入数据
//void insertNode(Node* L, int pos, Elemtype e)
//{
//	Node* p = L;
//	while (pos != 0) {
//		p = p->next;		//p是要插入的节点的后继
//		pos--;
//		if (p == NULL) {
//			printf("非法插入\n");
//			return;
//		}
//	}
//	Node* p1 = (Node*)malloc(sizeof(Node));		//p1是要插入的节点
//	p1->data = e;
//	p1->prev = p->prev;
//	p->prev->next = p1;
//	p->prev = p1;
//	p1->next = p;
//}
////删除节点
//void deleNode(Node* L, int pos)
//{
//	Node* p = L;
//	while (pos != 0) {
//		p = p->next;		//p是要删除的节点
//		pos--;
//		if (p == NULL) {
//			printf("非法删除\n");
//			return;
//		}
//	}
//	p->prev->next = p->next;
//	p->next->prev = p->prev;
//	p->prev = NULL;
//	p->next = NULL;
//	free(p);
//}
//int main()
//{
//	Node* L = initList();
//	printf("初始化成功\n");
//	insertTail(L, 11);
//	insertTail(L, 22);
//	insertTail(L, 33);
//	insertTail(L, 44);
//	insertTail(L, 55);
//	insertTail(L, 66);
//	printList(L);
//	insertNode(L, 3, 666);
//	printList(L);
//	deleNode(L, 3);
//	printList(L);
//	return 0;
//}



//栈：后进先出，元素从栈顶入栈，从栈底出栈

//栈 -- 顺序结构版
//栈 -- 静态内存版

//#define MAXSIZE 100
//typedef int ElemType;
//#include<stdio.h>
//typedef struct {
//	ElemType data[MAXSIZE];
//	int top;//数组下标
//}Stack;
////初始化
//void initStack(Stack* s)
//{
//	s->top = -1;
//}
////判断栈是否为空
//int isEmpty(Stack* s)
//{
//	if (s->top == -1) {
//		printf("栈为空\n");
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
////入栈
//int push(Stack* s, ElemType e)
//{
//	if (s->top >= MAXSIZE - 1) {
//		printf("栈已满\n");
//		return 0;
//	}
//	s->top++;
//	s->data[s->top] = e;
//	return 1;
//}//出栈
//int pop(Stack* s, ElemType* e)
//{
//	if (s->top == -1) {
//		printf("栈为空\n");
//		return 0;
//	}
//	*e = s->data[s->top];
//	s->top--;
//	return 1;
//}
////获取栈顶元素
//int getTop(Stack* s, ElemType* e)
//{
//	if (s->top == -1) {
//		printf("栈为空\n");
//		return 0;
//	}
//	*e = s->data[s->top];
//	return 1;
//}
//int main()
//{
//	Stack s;
//	ElemType e;
//	initStack(&s);
//	push(&s, 10);
//	push(&s, 20);
//	push(&s, 30);
//	getTop(&s, &e);
//	printf("栈顶元素为：%d\n", e);
//	pop(&s, &e);
//	printf("出栈元素为：%d\n", e);
//	getTop(&s, &e);
//	printf("栈顶元素为：%d\n", e);
//	return 0;
//}
//小知识：定义Stack s;时，编译器会为结构体Stack分配内存，这时s可以正常引用。但是定义Stack* s;时，这时定义的是一个指针变量，且s指向随机内存地址（即未初始化），指向的内存可能不可访
//问或非法，直接使用该指针会导致未定义行为（如程序崩溃或报错）




//栈 -- 动态内存分配版

//#define MAXSIZE 100
//typedef int ElemType;
//#include<stdio.h>
//typedef struct {
//	ElemType* data;
//	int top;
//}Stack;
////初始化
//Stack* initStack()
//{
//	Stack* s = (Stack*)malloc(sizeof(Stack));
//	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//	s->top = -1;
//	return s;
//}
////判断栈是否为空
//int isEmpty(Stack* s)
//{
//	if (s->top == -1) {
//		printf("栈为空\n");
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
////入栈
//int push(Stack* s, ElemType e)
//{
//	if (s->top >= MAXSIZE - 1) {
//		printf("栈已满\n");
//		return 0;
//	}
//	s->top++;
//	s->data[s->top] = e;
//	return 1;
//}
////出栈
//int pop(Stack* s, ElemType* e)
//{
//	if (s->top == -1) {
//		printf("栈为空\n");
//		return 0;
//	}
//	*e = s->data[s->top];
//	s->top--;
//	return 1;
//}
////获取栈顶元素
//int getTop(Stack* s, ElemType* e)
//{
//	if (s->top == -1) {
//		printf("栈为空\n");
//		return 0;
//	}
//	*e = s->data[s->top];
//	return 1;
//}
//int main()
//{
//	Stack* s = initStack();
//	ElemType e;
//	initStack(&s);
//	push(s, 10);
//	push(s, 20);
//	push(s, 30);
//	getTop(s, &e);
//	printf("栈顶元素为：%d\n", e);
//	pop(s, &e);
//	printf("出栈元素为：%d\n", e);
//	getTop(s, &e);
//	printf("栈顶元素为：%d\n", e);
//	return 0;
//}




//栈 -- 链式结构版
//跟链表差不多，唯一需要注意的点是只能用头插法，记住头节点是栈顶，尾节点是栈底，元素是从栈顶入栈的（另一种记法：链表遍历是从头开始的，故首节点就是第一个读到的数据，也就是最后一个
//入栈的数据，所以插入数据用的是头插法）

//typedef int ElemType;
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Stack{
//	ElemType data;
//	struct Stack* next;
//}Stack;
////初始化
//Stack* initStack()
//{
//	Stack* s = (Stack*)malloc(sizeof(Stack));
//	s->data = 0;
//	s->next = NULL;
//	return s;
//}
////判断栈是否为空
//void isEmpty(Stack* s)
//{
//	if (s->next == NULL) {
//		printf("栈为空\n");
//	}
//	else {
//		printf("栈不为空\n");
//	}
//}
////入栈（只能是头插法）
//void push(Stack* s, ElemType e)
//{
//	Stack* p = (Stack*)malloc(sizeof(Stack));
//	p->data = e;
//	p->next = s->next;
//	s->next = p;
//}
////出栈
//void pop(Stack* s)
//{
//	if (s->next == NULL) {
//		printf("栈为空\n");
//		return;
//	}
//	Stack* p = s->next;
//	s->next = p->next;
//	free(p);
//}
////获取栈顶元素
//void getTop(Stack* s, ElemType* e)
//{
//	Stack* p = s->next;
//	if (p == NULL) {
//		printf("栈为空，无元素\n");
//		return;
//	}
//	*e = p->data;
//}
//int main()
//{
//	Stack* s = initStack();
//	ElemType e = 0;
//	isEmpty(s);
//	getTop(s, &e);
//	push(s, 10);
//	push(s, 20);
//	push(s, 30);
//	isEmpty(s);
//	getTop(s, &e);
//	printf("%d\n", e);
//	pop(s);
//	getTop(s, &e);
//	printf("%d\n", e);
//	return 0;
//}




//队列：先进先出，元素从队尾（rear）插入，从队头（front）删除

//队列 -- 顺序结构版

//#define MAXSIZE 3
//typedef int ElemType;
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct {
//	ElemType data[MAXSIZE];
//	int front;
//	int rear;
//}Queue;
////初始化
//void initQueue(Queue* q)
//{
//	q->front = 0;
//	q->rear = 0;
//}
////判断队列是否为空
//void isEmpty(Queue* q)
//{
//	if (q->front == q->rear) {
//		printf("队列为空\n");
//	}
//	else {
//		printf("队列不为空\n");
//	}
//}
////调整队列 -- 每一次内存不够就要做一次，时间复杂度太高了，所以要把队列弄成循环队列！！！
//int queueFull(Queue* q)
//{
//	if (q->front > 0) {
//		int step = q->front;
//		for (int i = q->front; i <= q->rear; i++) {
//			q->data[i - step] = q->data[i];
//		}
//		q->front = 0;
//		q->rear = q->rear - step;//此时rear指向最后一个元素的位置，而在前面的循环中，队列的每一个值都往前赋值了，故最后一个元素的值已经赋值给倒数第二个元素了，所以最后一个元素的位置刚好用来插入下一个元素
//		return 1;
//	}
//	else {
//		printf("队列真的满了\n");
//		return 0;
//	}
//}
////入队
//void insertQueue(Queue* q, ElemType e)
//{
//	if (q->rear >= MAXSIZE) {
//		if (!queueFull(q)) {
//			printf("入队失败\n");
//			return;
//		}
//	}
//	q->data[q->rear] = e;
//	q->rear++;
//}
////出队
//void deleQueue(Queue* q)
//{
//	if (q->front == q->rear) {
//		printf("队列为空\n");
//		return;
//	}
//	q->front++;
//}
////获取队头数据
//void getHead(Queue* q, ElemType* e)
//{
//	if (q->front == q->rear) {
//		printf("队列为空\n");
//		return;
//	}
//	*e = q->data[q->front];
//}
//int main()
//{
//	Queue q;
//	ElemType e;
//	initQueue(&q);
//	insertQueue(&q, 10);
//	insertQueue(&q, 20);
//	insertQueue(&q, 30);
//	deleQueue(&q);
//	insertQueue(&q, 40);
//	getHead(&q, &e);
//	printf("%d\n", e);
//	deleQueue(&q);
//	getHead(&q, &e);
//	printf("%d\n", e);
//	deleQueue(&q);
//	getHead(&q, &e);
//	printf("%d\n", e);
//	return 0;
//}




//循环队列

//#define MAXSIZE 3
//typedef int ElemType;
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct {
//	ElemType data[MAXSIZE];
//	int front;
//	int rear;
//}Queue;
////初始化
//void initQueue(Queue* q)
//{
//	q->front = 0;
//	q->rear = 0;
//}
////判断队列是否为空
//void isEmpty(Queue* q)
//{
//	if (q->front == q->rear) {
//		printf("队列为空\n");
//	}
//	else {
//		printf("队列不为空\n");
//	}
//}
////入队
////逻辑是先判断队列是否满再插入数据，而rear本来就是指向最后一个元素的下一个位置，故执行插入第MAXSIZE个元素的之前，rear已经指向最后一个位置了，就会显示队列满了
////由于循环队列的这种特性，所以队列中始终会有一个位置是废弃的，即最多存储MAXSIZE - 1个元素
//void insertQueue(Queue* q, ElemType e)
//{
//	if ((q->rear + 1) % MAXSIZE == q->front) {//不能修改为q->rear % MAXSIZE == q->front，因为队列为空时这个条件也成立，无法区分队列空的还是满的
//		printf("队列真的满了\n");
//		return;
//	}
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % MAXSIZE;
//}
////出队
//void deleQueue(Queue* q)
//{
//	if (q->front == q->rear) {
//		printf("队列为空\n");
//	}
//	q->front = (q->front + 1) % MAXSIZE;
//}
////获取队头数据
//void getHead(Queue* q, ElemType* e)
//{
//	if (q->front == q->rear) {
//		printf("队列为空\n");
//		return;
//	}
//	*e = q->data[q->front];
//}
//int main()
//{
//	Queue q;
//	ElemType e;
//	initQueue(&q);
//	insertQueue(&q, 10);
//	insertQueue(&q, 20);
//	insertQueue(&q, 30);//这里30无法进入队列，队列中最后一个位置为空
//	getHead(&q, &e);
//	printf("%d\n", e);
//	deleQueue(&q);//删除第一个元素10后，这个位置就变成废弃的位置，队列中先前那个废弃的位置就可以插入数据了
//
//	getHead(&q, &e);
//	printf("%d\n", e);
//
//	insertQueue(&q, 40);//40插入队列中最后一个位置，此时rear指向第一个位置（10的位置），队列满了
//	deleQueue(&q);
//	insertQueue(&q, 50);
//	insertQueue(&q, 60);
//	return 0;
//}




//队列 -- 链式结构版

//#include<stdio.h>
//#include<stdlib.h>
//typedef int ElemType;
//
//typedef struct QueueNode {
//	ElemType data;
//	struct QueueNode* next;
//}QueueNode;
//
//typedef struct {
//	QueueNode* front;
//	QueueNode* rear;
//}Queue;
////初始化
//Queue* initQueue()
//{
//	Queue* q = (Queue*)malloc(sizeof(Queue));
//	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
//	node->data = 0;
//	node->next = NULL;
//	q->front = node;
//	q->rear = node;
//	return q;
//}
////判断队列是否为空
//int isEmpty(Queue* q)
//{
//	if (q->front == q->rear) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
////入队（尾插法）
//void insertQueue(Queue* q, ElemType e)
//{
//	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
//	node->data = e;
//	node->next = NULL;
//	q->rear->next = node;
//	q->rear = node;
//}
////出队
//void deleQueue(Queue* q)
//{
//	if (isEmpty(q)) {
//		printf("队列为空\n");
//		return;
//	}
//	QueueNode* node = q->front->next;
//	q->front->next = node->next;
//	if (q->rear == node) {
//		q->rear = q->front;
//	}
//	free(node);
//}
////获取队头元素
//ElemType getFront(Queue* q)
//{
//	if (isEmpty(q)) {
//		printf("队列为空\n");
//		return 0;
//	}
//	return q->front->next->data;
//}
//int main()
//{
//	Queue* q = initQueue();
//	ElemType e;
//	insertQueue(q, 10);
//	insertQueue(q, 20);
//	insertQueue(q, 30);
//	e = getFront(q);
//	printf("%d\n", e);
//
//	deleQueue(q);
//	e = getFront(q);
//	printf("%d\n", e);
//
//	deleQueue(q);
//	e = getFront(q);
//	printf("%d\n", e);
//
//	deleQueue(q);
//	e = getFront(q);
//	printf("%d\n", e);
//	return 0;
//}




//后缀表达式计算的实现

//#define MAXSIZE 100
//#include<stdio.h>
//#include<stdlib.h>
//typedef int ElemType;
//
//typedef struct{
//	ElemType* data;
//	int top;
//}Stack;
////定义枚举类型表示每次读到的字符是什么类型
//typedef enum
//{
//	LEFT_PARE,RIGHT_PARE,//左括号和右括号
//	ADD,SUB,MUL,DIV,MOD,
//	EOS,NUM//EOS为'\0'
//}contentType;
//
//char expr[] = "82/2+56*-\0";//全局变量为后缀表达式
//
////初始化
//Stack* initStack()
//{
//	Stack* s = (Stack*)malloc(sizeof(Stack));
//	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//	s->top = -1;
//	return s;
//}
////入栈
//void push(Stack* s, ElemType e)
//{
//	if (s->top >= MAXSIZE - 1) {
//		printf("栈已满\n");
//		return;
//	}
//	s->data[++s->top] = e;
//}
////出栈
//void pop(Stack* s, ElemType* e)
//{
//	if (s->top == -1) {
//		printf("栈为空\n");
//		return;
//	}
//	*e = s->data[s->top];
//	s->top--;
//}
////获取字符类型
//contentType getToken(char* symbol, int* index)
//{
//	*symbol = expr[*index];
//	*index = *index + 1;
//	switch (*symbol)
//	{
//	case '(':
//		return LEFT_PARE;
//	case ')':
//		return RIGHT_PARE;
//	case '+':
//		return ADD;
//	case '-':
//		return SUB;
//	case '*':
//		return MUL;
//	case '/':
//		return DIV;
//	case '%':
//		return MOD;
//	case '\0':
//		return EOS;
//	default:
//		return NUM;
//	}
//}
////计算后缀表达式
//void eval(Stack* s)
//{
//	char symbol;
//	int op1, op2;
//	int index = 0;
//	contentType token;
//	token = getToken(&symbol, &index);
//	ElemType result;
//	while (token != EOS) {
//		if (token == NUM) {
//			push(s, symbol - '0');//用ASKII码相减得到对应数字
//		}
//		else {
//			pop(s, &op2);
//			pop(s, &op1);
//			switch (token)
//			{
//			case ADD:
//				push(s, op1 + op2);
//				break;
//			case SUB:
//				push(s, op1 - op2);
//				break;
//			case MUL:
//				push(s, op1 * op2);
//				break;
//			case DIV:
//				push(s, op1 / op2);
//				break;
//			case MOD:
//				push(s, op1 % op2);
//				break;
//			default:
//				break;
//			}
//		}
//		token = getToken(&symbol, &index);
//	}
//	pop(s, &result);
//	printf("%d\n", result);
//}
//int main()
//{
//	Stack* s = initStack();
//	eval(s);
//	return 0;
//}




//中缀表达式转化为后缀表达式
//网课有（表达式求值那个视频）




//树

//创建与遍历

//#include<stdio.h>
//#include<stdlib.h>
//
//typedef char ElemType;
//typedef struct TreeNode {
//	ElemType data;
//	struct TreeNode* lchild;
//	struct TreeNode* rchild;
//}TreeNode, *BiTree;
//
//char str[] = "ABDH#K###E##CFI###G#J##";
//int index = 0;
////创建树
//void creatTree(BiTree* T)
//{
//	ElemType ch;
//	ch = str[index++];
//	if (ch == '#') {
//		*T = NULL;
//	}
//	else {
//		*T = (BiTree)malloc(sizeof(TreeNode));
//		(*T)->data = ch;
//		creatTree(&(*T)->lchild);
//		creatTree(&(*T)->rchild);
//	}
//}
////前序遍历
//void preOrder(BiTree T)
//{
//	if (T == NULL) {
//		return;
//	}
//	printf("%c ", T->data);
//	preOrder(T->lchild);
//	preOrder(T->rchild);
//}
////中序遍历
//void inOrder(BiTree T)
//{
//	if (T == NULL) {
//		return;
//	}
//	inOrder(T->lchild);
//	printf("%c ", T->data);
//	inOrder(T->rchild);
//}
////后序遍历
//void postOrder(BiTree T)
//{
//	if (T == NULL) {
//		return;
//	}
//	postOrder(T->lchild);
//	postOrder(T->rchild);
//	printf("%c ", T->data);
//}
//int main()
//{
//	BiTree T;
//	creatTree(&T);
//	preOrder(T);
//	printf("\n");
//	inOrder(T);
//	printf("\n");
//	postOrder(T);
//	printf("\n");
//	return 0;
//}

//线索二叉树 -- 优点：无需递归，只用像遍历链表那样就可以遍历树了

//#include<stdio.h>
//#include<stdlib.h>
//typedef char ElemType;
//
//typedef struct ThreadNode {
//	ElemType data;
//	struct ThreadNode* lchild;
//	struct ThreadNode* rchild;
//	int ltag;//为0时lchild指向该节点的左子树，为1时指向该节点的前驱
//	int rtag;//为0时rchild指向该节点的右子树，为1时指向该节点的后继
//}ThreadNode, * ThreadTree;
//
//char str[] = "ABDH##I##EJ##CF##G##";
//int index = 0;
//
//ThreadTree prev;
//
////创建树
//void creatTree(ThreadTree* T)
//{
//	ElemType ch;
//	ch = str[index++];
//	if (ch == '\0') {
//		return;
//	}
//	if (ch == '#') {//节点为空时赋值NULL
//		*T = NULL;
//	}
//	else {
//		*T = (ThreadTree)malloc(sizeof(ThreadNode));
//		(*T)->data = ch;//给该节点赋值
//		creatTree(&(*T)->lchild);//用递归的方式从左节点开始继续创建树（前序遍历的方式）
//		if ((*T)->lchild != NULL) {
//			(*T)->ltag = 0;
//		}
//
//		creatTree(&(*T)->rchild);//左节点创建结束，创建右节点
//		if ((*T)->rchild != NULL) {
//			(*T)->rtag = 0;
//		}
//	}
//}
////具体线索化
//void threading(ThreadTree T)
//{
//	if (T != NULL)
//	{
//		printf("Current Node: %p, prev Node: %p\n", T, prev);
//		threading(T->lchild);
//		if (T->lchild == NULL) {//左子树为空
//			T->ltag = 1;//标记左子树为线索
//			T->lchild = prev;//左子树指向前驱
//		}
//		if (prev->rchild == NULL) {//前驱的右子树为空
//			prev->rtag = 1;//标记右子树为线索
//			prev->rchild = T;//右子树指向后继（当前节点）
//		}
//		prev = T;//将当前节点赋值为前驱，继续下一个节点的线索化
//		threading(T->rchild);
//	}
//}
////开始线索化
//void inOrderThreading(ThreadTree* head, ThreadTree T)
//{
//	//头节点
//	*head = (ThreadTree)malloc(sizeof(ThreadNode));
//	(*head)->ltag = 0;//规定头节点的左子树指向树的根
//	(*head)->rtag = 1;//规定头节点的右子树用于线索化，指向遍历的最后一个节点
//	(*head)->rchild = (*head);//暂时让右子树指向自己
//
//	if (T == NULL) {//树为空
//		(*head)->lchild = *head;
//	}
//	else {
//		(*head)->lchild = T;//头节点左子树指向树根
//		prev = (*head);//prev指向前驱，此时树根的前驱就是头节点
//		
//		threading(T);
//
//		//最后一个节点线索化
//		prev->rchild = *head;//在前面操作中，最后一个节点变成了prev
//		prev->rtag = 1;
//
//		//头节点右子树指向遍历的最后一个节点
//		(*head)->rchild = prev;
//	}
//}
////利用线索进行中序遍历
//void inOrder(ThreadTree T)
//{
//	ThreadTree curr;//current，当前节点
//	curr = T->lchild;//T是头节点，current从第一个节点开始
//
//	while (curr != T) {
//		while (curr->ltag == 0) {
//			curr = curr->lchild;
//		}
//		printf("%c ", curr->data);
//
//		while (curr->rtag == 1 && curr->rchild != T) {//前面线索化过程中设置了最后一个节点的rchild指向头节点，故第二个条件就是所有循环结束标志
//			curr = curr->rchild;
//			printf("%c ", curr->data);
//		}
//		curr = curr->rchild;
//	}
//	printf("\n");
//}
//
//int main()
//{
//	ThreadTree head;
//	ThreadTree T;
//	//创建
//	creatTree(&T);
//	//线索化
//	inOrderThreading(&head, T);
//	//基于线索遍历
//	inOrder(head);
//	return 0;
//}

//树的层序遍历 -- 求深度

//#include<stdio.h>
//#include<stdlib.h>
//#define MAXSIZE 100
//typedef char TreeType;
//
//typedef struct TreeNode {
//	TreeType data;
//	struct TreeNode* lchild;
//	struct TreeNode* rchild;
//}TreeNode, *ElemType, *BiTree;
//
//typedef struct {
//	ElemType* data;
//	int front;
//	int rear;
//}Queue;
//
//char str[] = "ABDH#K###E##CFI###G#J##";
//int index = 0;
////创建树
//void creatTree(BiTree* T)
//{
//	TreeType ch;
//	ch = str[index++];
//	if (ch == '#') {//节点为空时赋值NULL
//		*T = NULL;
//	}
//	else {
//		*T = (BiTree)malloc(sizeof(TreeNode));
//		(*T)->data = ch;//给该节点赋值
//		creatTree(&(*T)->lchild);
//		creatTree(&(*T)->rchild);
//	}
//}
////队列初始化
//Queue* initQueue()
//{
//	Queue* q = (Queue*)malloc(sizeof(Queue));
//	q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
//	q->front = 0;
//	q->rear = 0;
//	return q;
//}
////判断队列是否为空
//int isEmpty(Queue* Q)
//{
//	if (Q->front == Q->rear) {
//		printf("空的\n");
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
////入队
//void equeue(Queue* q, ElemType e)
//{
//	if ((q->rear + 1) % MAXSIZE == q->front) {
//		printf("队列真的满了\n");
//		return;
//	}
//	q->data[q->rear] = e;
//	q->rear = (q->rear + 1) % MAXSIZE;
//}
////出队
//void dequeue(Queue* q, ElemType* e)
//{
//	if (q->front == q->rear) {
//		printf("队列为空\n");
//	}
//	*e = q->data[q->front];
//	q->front = (q->front + 1) % MAXSIZE;
//}
////获取队列元素数量
//int queueSize(Queue* Q)
//{
//	if (!isEmpty(Q)) {
//		return Q->rear - Q->front;
//	}
//	else {
//		return 0;
//	}
//}
////求深度
//int maxDepth(BiTree root)
//{
//	if (root == NULL) {
//		return 0;
//	}
//	int depth = 0;
//	Queue* q = initQueue();
//	equeue(q, root);
//
//	while (!isEmpty(q)) {
//		int count = queueSize(q);
//		while (count > 0) {
//			BiTree curr;
//			dequeue(q, &curr);
//			if (curr->lchild != NULL) {
//				equeue(q, curr->lchild);
//			}
//			if (curr->rchild != NULL) {
//				equeue(q, curr->rchild);
//			}
//			count--;
//		}
//		depth++;
//	}
//	return depth;
//}
//
//int main()
//{
//	BiTree T;
//	creatTree(&T);
//	printf("%d\n", maxDepth(T));
//	return 0;
//}

