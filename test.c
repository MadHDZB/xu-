//#define _CRT_SECURE_NO_WARNINGS

//顺序表

//#include<stdio.h>
//#include<stdlib.h>
//#define MAX 100
//typedef int Elemtype;
////创建
//typedef struct {
//	Elemtype* data;
//	int length;
//}SeqList;
////初始化
//SeqList* InitList()
//{
//	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
//	L->data = (Elemtype*)malloc(sizeof(Elemtype) * MAX);
//	L->length = 0;
//	return L;
//}
////添加数据
//int appendElem(SeqList* L, Elemtype e)
//{
//	if (L->length >= MAX) {
//		printf("顺序表已满，添加失败\n");
//		return 0;
//	}
//	L->data[L->length] = e;
//	L->length++;
//	return 1;
//}
////遍历
//void printList(SeqList* L)
//{
//	for (int i = 0; i < L->length; i++) {
//		printf("%d ", L->data[i]);
//	}
//	printf("\n");
//}
////插入表项
//int insertElem(SeqList* L, int pos, Elemtype e)
//{
//	if (L->length >= MAX) {
//		printf("顺序表已满，插入失败\n");
//		return 0;
//	}
//	if (pos<1 || pos>L->length) {
//		printf("非法插入\n");
//		return 0;
//	}
//	for (int i = L->length - 1; i >= pos - 1; i--) {
//		L->data[i + 1] = L->data[i];
//	}
//	L->data[pos - 1] = e;
//	L->length++;
//	return 1;
//}
////删除表项
//int deleElem(SeqList* L, int pos)
//{
//	if (pos<1 || pos>L->length) {
//		printf("非法删除\n");
//		return 0;
//	}
//	for (int i = pos; i <= L->length - 1; i++) {
//		L->data[i - 1] = L->data[i];
//	}
//	L->length--;
//	return 1;
//}
////查找元素
//Elemtype findElem(SeqList* L, Elemtype e)
//{
//	int flag = 0;
//	int i = 0;
//	for (i = 0; i < L->length; i++) {
//		if (L->data[i] == e) {
//			flag = 1;
//			break;
//		}
//	}
//	if (flag) {
//		return i + 1;
//	}
//	else {
//		printf("要查找的元素不存在\n");
//		return 0;
//	}
//}
//int main()
//{
//	SeqList* L = InitList();
//	printf("初始化成功\n");
//	appendElem(L, 11);
//	appendElem(L, 22);
//	appendElem(L, 33);
//	appendElem(L, 44);
//	printList(L);
//	insertElem(L, 3, 666);
//	printList(L);
//	int temp = findElem(L, 777);
//	if (temp) {
//		printf("该元素是第%d个元素\n", temp);
//	}
//	deleElem(L, 3);
//	printList(L);
//	free(L->data);
//	free(L);
//	return 0;
//}
//



//链表
//#include<stdio.h>
//#include<stdlib.h>
//typedef int Elemtype;
////创建
//typedef struct node{
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
////添加数据--头插法
//int insertHead(Node* L, Elemtype e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = e;
//	p->next = L->next;
//	L->next = p;
//	return 1;
//}
////添加数据--尾插法
//int insertTail(Node* L, Elemtype e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = e;
//	p->next = NULL;
//	while (L->next != NULL) {
//		L = L->next;
//	}
//	L->next = p;
//	return 1;
//}
////删除节点
//int deleNode(Node* L, Elemtype e)
//{
//	Node* p = L;
//	int flag = 0;
//	while (p != NULL && p->next != NULL) {
//		if (p->next->data == e) {
//			Node* p1 = p->next;
//			p->next = p1->next;
//			free(p1);
//			flag = 1;
//			break;
//		}
//		p = p->next;
//	}
//	if (flag) {
//		return 1;
//	}
//	else {
//		printf("非法删除\n");
//		return 0;
//	}
//}
////遍历
//void printNode(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
////获取链表长度
//int ListLength(Node* L)
//{
//	Node* p = L->next;
//	int len = 0;
//	while (p != NULL) {
//		len++;
//		p = p->next;
//	}
//	return len;
//}
////释放链表空间
//void freeList(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL) {
//		Node* p1 = p;
//		p = p->next;
//		free(p1);
//	}
//	L->next = NULL;
//}
////找倒数第k个节点的值（快慢指针）
//int findNodeFS(Node* L, int k)
//{
//	Node* p = L->next;
//	Node* p1 = L->next;
//	while (k > 0) {
//		p1 = p1->next;
//		k--;
//	}
//	while (p1 != NULL) {
//		p = p->next;
//		p1 = p1->next;
//	}
//	return p->data;
//}
////反转链表
//Node* reverseList(Node* L)
//{
//	Node* p = L->next;
//	Node* p1 = L->next;
//	while (p1 != NULL) {
//		if (p == L->next) {
//			p1 = p->next;
//			p->next = NULL;
//		}
//		Node* p2 = p1->next;
//		p1->next = p;
//		p = p1;
//		p1 = p2;
//	}
//	L->next = p;
//	return L;
//}
////删除链表中间节点
//void delMiddleNode(Node* L)
//{
//	Node* p = L->next;
//	Node* p1 = L->next;
//	Node* p2 = L;
//	if (p == NULL) {
//		printf("表空，无法删除节点\n");
//		return;
//	}
//	while (p1->next != NULL) {
//		p = p->next;
//		p1 = p1->next->next;
//		p2 = p2->next;
//	}
//	p2->next = p->next;
//	free(p);
//}
//int main()
//{
//	Node* L = initList();
//	printf("初始化成功\n");
//	insertHead(L, 11);
//	insertHead(L, 22);
//	insertHead(L, 33);
//	insertHead(L, 44);
//	printNode(L);
//	insertTail(L, 666);
//	printNode(L);
//	int temp = deleNode(L, 99);
//	if (temp) {
//		printNode(L);
//	}
//	int len = ListLength(L);
//	printf("链表长度为：%d\n", len);
//	int value = findNodeFS(L, 2);
//	printf("%d\n", value);
//	L = reverseList(L);
//	printNode(L);
//	delMiddleNode(L);
//	printNode(L);
//	freeList(L);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 11;
//	printf("%p", a);
//	return 0;
//}

//笔记：
//fscanf返回值是成功赋值的输入项数量，若部分输入项匹配失败，则返回已成功赋值的项数，若全部输入项匹配失败，则返回0，若遇到文件末尾或错误，则返回-1
//fscanf读值时是自动跳过空格和换行符的，如：abc\nqqq，此时fscanf(file,"%s%s",a1,a2)读到的是a1为abc和a2为qqq，也就是说两个值中间是空格或者换行符都不影响fscanf读值
//但如果是fscanf(file,"mamamammam\n"),此时不用接收任何值，这相当于移动fscanf在文件中的指针位置，这时候\n或者空格和\t都会作为被读的对象一个个读过去，且此时fscanf返回值为0。但注意：这里的\n对于fscanf
//来说是跟空格和制表符（\t）是等效的，不能精确匹配\n，若要精确匹配\n，需要写成：fscanf(file, "aaaaa%*1[n]")，1表示匹配一个换行符，也可换成任意数量
//fscanf(file, "aaa ")和fscanf(file, "aaa-")和fscanf(file, "aaa\t")等效，此时fscanf会匹配aaa后接任意数量（包括0个）的空白字符（"\n", " ", "\t"）


//fseek函数：
//int fseek(FILE* stream, long int offset, int whence)
//作用：移动文件指针到指定位置，为后续读写操作设定起始点
//stream：通过fopen成功打开的有效文件对象
//offset：相对基准点（whence）的偏移字节数，可正可负，正值表示向文件末尾方向移动指针，负值表示向文件开头方向移动指针
//whence：设定偏移的基准位置，可选择以下常量：
//1.SEEK_SET：从文件开头开始计算偏移
//2.SEEK_CUR：从当前指针位置开始计算偏移
//3.SEEK_END：从文件末尾开始计算偏移
//返回值：成功返回0，失败（例如文件未打开，不可寻址或偏移超出范围）返回非零值
//eg:
//				fseek(file, 0, SEEK_END);  long size=ftell(file)			此时返回文件总字节数


//ftell函数：
//long int ftell(FILE* stream)
//作用：返回当前文件指针相对于文件开头的字节偏移量（即从文件起始位置到当前指针位置的字节数），常与fseek函数配合使用
//eg:
//				fseek(file, 0, SEEK_END);//将指针移到文件末尾
//				long size=ftell(file);//此时返回值即为文件总字节数
//				rewind(file);//恢复指针到文件开头




//第1638行snprintf解释：
//