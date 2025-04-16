#define _CRT_SECURE_NO_WARNINGS

//数据结构

//实验1

//实验1：合并顺序表
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct {
//	int* data;
//	int len;
//}List;
//List* initList()
//{
//	List* l = (List*)malloc(sizeof(List));
//	l->data = (int*)malloc(sizeof(int) * 100);
//	l->len = 0;
//	return l;
//}
//void appendElem(List* l, int e)
//{
//	if (l->len >= 100) {
//		l->data = (int*)realloc(l->data, sizeof(int) * 100);
//	}
//	l->data[l->len] = e;
//	l->len++;
//}
//List* insert(List* l1, List* l2)
//{
//	List* l = initList();
//	if (l1->len + l2->len > 100) {
//		int len = l1->len + l2->len - 100;
//		l->data = (int*)realloc(l->data, sizeof(int) * len);
//	}
//	for (int i = 0; i < l1->len; i++) {
//		appendElem(l, l1->data[i]);
//	}
//	for (int i = 0; i < l2->len; i++) {
//		appendElem(l, l2->data[i]);
//	}
//	return l;
//}
//void sort(List* l)
//{
//	for (int i = 0; i < l->len - 1; i++) {
//		for (int j = 0; j < l->len - i - 1; j++) {
//			if (l->data[j] > l->data[j + 1]) {
//				int t = l->data[j];
//				l->data[j] = l->data[j + 1];
//				l->data[j + 1] = t;
//			}
//		}
//	}
//}
//void print(List* l)
//{
//	for (int i = 0; i < l->len; i++) {
//		printf("%d ", l->data[i]);
//	}
//}
//int main()
//{
//	List* l1 = initList();
//	List* l2 = initList();
//	int n, x;
//	scanf("%d", &n);
//	while (n != 0) {
//		scanf("%d", &x);
//		n--;
//		appendElem(l1, x);
//	}
//	scanf("%d", &n);
//	while (n != 0) {
//		scanf("%d", &x);
//		n--;
//		appendElem(l2, x);
//	}
//	List* l = insert(l1, l2);
//	sort(l);
//	printf("List A:");
//	print(l1);
//	printf("\nList B:");
//	print(l2);
//	printf("\nList C:");
//	print(l);
//	return 0;
//}

////实验1：链式线性表的基本操作
//#include<stdio.h>
//#include<malloc.h>
//#define ERROR 0
//#define OK 1 
//#define ElemType int
//
//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//}LNode, * LinkList;//cpp写法，LNode表示结构体本身，LinkList表示指向节点的指针
//
//int CreateLink_L(LinkList& L, int n) {
//	//创建含有n个元素的单链表
//	LinkList p, q;
//	int i;
//	ElemType e;
//	L = new LNode;//cpp写法，new相当于malloc，分配在堆上的内存
//	L->next = NULL;            //先建立一个带头结点的单链表
//	q = L;
//	for (i = 0; i < n; i++) {
//		scanf("%d", &e);
//		p = new LNode;  // 生成新结点
//		// 请补全代码
//		q->next = p;
//		p->data = e;
//		p->next = NULL;
//		q = p;
//	}
//	return OK;
//}
//
//int LoadLink_L(LinkList& L) {
//	// 单链表遍历
//	LinkList p = L->next;
//	if (p == NULL)printf("The List is empty!"); // 请填空
//	else
//	{
//		printf("The LinkList is:");
//		while (p != NULL)    // 请填空
//		{
//			printf("%d ", p->data);
//			p = p->next;    // 请填空
//		}
//	}
//	printf("\n");
//	return OK;
//}
//
//int LinkInsert_L(LinkList& L, int i, ElemType e) {
//	// 算法2.9
//	// 在带头结点的单链线性表L中第i个位置之前插入元素e
//	// 请补全代码
//	int len = 0;
//	LinkList p = L, q = L->next;
//	while (p != NULL) {
//		len++;
//		p = p->next;
//	}
//	p = L;
//	if (i < 1 || i > len + 1) {
//		return ERROR;
//	}
//
//	for (i; i > 1; i--) {
//		p = p->next;
//		q = q->next;
//	}
//	if (p == NULL) {
//		return ERROR;
//	}
//	LinkList p1 = new LNode;
//	p->next = p1;
//	p1->data = e;
//	p1->next = q;
//	return OK;
//}
//
//int LinkDelete_L(LinkList& L, int i, ElemType& e) {
//	// 算法2.10
//	// 在带头结点的单链线性表L中，删除第i个元素，并用e返回其值
//	// 请补全代码
//	int len = 0;
//	LinkList p = L, q = NULL, p1 = NULL;
//	while (p != NULL) {
//		len++;
//		p = p->next;
//	}
//	p = L;
//	if (i < 1 || i > len + 1) {
//		return ERROR;
//	}
//	for (i; i > 1; i--) {
//		p = p->next;
//	}
//	p1 = p->next;
//	q = p1->next;
//	p->next = q;
//	e = p1->data;
//	free(p1);
//	return OK;
//}
//
//int main()
//{
//	LinkList T;
//	int a, n, i;
//	ElemType x, e;
//	printf("Please input the init size of the linklist:\n");
//	scanf("%d", &n);
//	printf("Please input the %d element of the linklist:\n", n);
//	if (CreateLink_L(T, n))     // 判断链表是否创建成功，请填空
//	{
//		printf("A Link List Has Created.\n");
//		LoadLink_L(T);
//	}
//	while (1)
//	{
//		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
//		scanf("%d", &a);
//		switch (a)
//		{
//		case 1: scanf("%d%d", &i, &x);
//			if (!LinkInsert_L(T, i, x)) printf("Insert Error!\n"); // 判断i值是否合法，请填空
//			else printf("The Element %d is Successfully Inserted!\n", x);
//			break;
//		case 2: scanf("%d", &i);
//			if (!LinkDelete_L(T,i,e)) printf("Delete Error!\n"); // 判断i值是否合法，请填空
//			else printf("The Element %d is Successfully Deleted!\n", e);
//			break;
//		case 3: LoadLink_L(T);
//			break;
//		case 0: return 1;
//		}
//	}
//}

//拓展习题1

////字符串去重  大错特错！
//#include<stdio.h>
//#include<stdlib.h>
//#define MAXSIZE 100000
//typedef struct {
//	char* data;
//	int top;
//}Node;
//
//Node* initList()
//{
//	Node* L = (Node*)malloc(sizeof(Node));
//	L->data = (char*)malloc(sizeof(char) * MAXSIZE);
//	L->top = -1;
//	return L;
//}
////判断是否重复
//int jud(Node* L, char e)
//{
//	for (int i = 0; i < L->top + 1; i++) {
//		if (L->data[i] == e) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int push(Node* L, int n)
//{
//	if (L->top >= MAXSIZE - 1) {
//		printf("已满\n");
//		return 0;
//	}
//	char e;
//	while (n > 0) {
//		scanf(" %c", &e);
//		if (jud(L, e)) {
//			L->top++;
//			L->data[L->top] = e;
//		}
//		n--;
//	}
//	return 1;
//}
//
//void sort(Node* L)
//{
//	for (int i = 0; i < 25; i++) {
//		for (int j = 0; j < 25 - i; j++) {
//			if (L->data[i] > L->data[i + 1]) {
//				char t = L->data[i];
//				L->data[i] = L->data[i + 1];
//				L->data[i + 1] = t;
//			}
//		}
//	}
//}
//
//int main()
//{
//	Node* L = initList();
//	int n;
//	scanf("%d", &n);
//	push(L, n);
//	sort(L);
//	int i = 0;
//	while (L->data[i]) {
//		printf("%c", L->data[i]);
//		i++;
//	}
//	return 0;
//}

//实验2

//顺序栈的基本操作
//#include<malloc.h> 
//#include<stdio.h> 
//#define OK 1
//#define ERROR 0
//#define STACK_INIT_SIZE 100 // 存储空间初始分配量
//#define STACKINCREMENT 10 // 存储空间分配增量
//
//typedef int SElemType; // 定义栈元素类型
//typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
//
//struct SqStack
//{
//	SElemType* base; // 在栈构造之前和销毁之后，base的值为NULL
//	SElemType* top; // 栈顶指针
//	int stacksize; // 当前已分配的存储空间，以元素为单位
//}; // 顺序栈
//
//Status InitStack(SqStack& S)
//{
//	// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
//	// 请补全代码
//	S.base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;
//	return OK;
//}
//
//Status Push(SqStack& S, SElemType e)
//{
//	// 在栈S中插入元素e为新的栈顶元素
//	// 请补全代码
//	if (S.top - S.base >= STACK_INIT_SIZE) {
//		SElemType* newBase = new SElemType[S.stacksize + STACKINCREMENT];//重新分配内存空间
//		for (int i = 0; i < S.stacksize; i++) {
//			newBase[i] = S.base[i];//将数据复制到新的内存空间中
//		}
//		delete[]S.base;//释放旧内存
//		S.base = newBase;//更新指针
//		S.top = S.base + S.stacksize;//更新指针
//		S.stacksize += STACKINCREMENT;//更新容量
//	}
//	*S.top = e;
//	S.top++;
//	return OK;
//}
//
//Status Pop(SqStack& S, SElemType& e)
//{
//	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
//	// 请补全代码
//	if (S.top == S.base) {
//		return ERROR;
//	}
//	S.top--;
//	e = *S.top;
//	return OK;
//}
//
//Status GetTop(SqStack S, SElemType& e)
//{
//	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
//	// 请补全代码
//	if (S.top == S.base) {
//		return ERROR;
//	}
//	e = *(S.top - 1);
//	return OK;
//}
//
//int StackLength(SqStack S)
//{
//	// 返回栈S的元素个数
//	// 请补全代码
//	int n = 0;
//	SElemType* p = S.top;
//	while (p != S.base) {
//		p--;
//		n++;
//	}
//	return n;
//}
//
//Status StackTraverse(SqStack S)
//{
//	// 从栈顶到栈底依次输出栈中的每个元素
//	SElemType* p = S.top;        //请填空
//		if (p == S.base)printf("The Stack is Empty!"); //请填空
//		else
//		{
//			printf("The Stack is: ");
//			while (p != S.base)            //请填空
//			{
//				p--;               //请填空
//				printf("%d ", *p);
//
//			}
//		}
//	printf("\n");
//	return OK;
//}
//
//int main()
//{
//	int a;
//	SqStack S;
//	SElemType x, e;
//	if (InitStack(S))    // 判断顺序表是否创建成功，请填空
//	{
//		printf("A Stack Has Created.\n");
//	}
//	while (1)
//	{
//		printf("1:Push \n2:Pop \n3:Get the Top \n4:Return the Length of the Stack\n5:Load the Stack\n0:Exit\nPlease choose:\n");
//		scanf("%d", &a);
//		switch (a)
//		{
//		case 1: scanf("%d", &x);
//			if (!Push(S,x)) printf("Push Error!\n"); // 判断Push是否合法，请填空
//			else printf("The Element %d is Successfully Pushed!\n", x);
//			break;
//		case 2: if (!Pop(S, e)) printf("Pop Error!\n"); // 判断Pop是否合法，请填空
//			  else printf("The Element %d is Successfully Poped!\n", e);
//			break;
//		case 3: if (!GetTop(S, e))printf("Get Top Error!\n"); // 判断Get Top是否合法，请填空
//			  else printf("The Top Element is %d!\n", e);
//			break;
//		case 4: printf("The Length of the Stack is %d!\n", StackLength(S)); //请填空
//			break;
//		case 5: StackTraverse(S);  //请填空
//			break;
//		case 0: return 1;
//		}
//	}
//}

//顺序队列的基本操作（非循环队列） ----  太垃圾了，空间复杂度太高
//#include<malloc.h> 
//#include<stdio.h> 
//#define OK 1
//#define ERROR 0
//typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
//typedef int QElemType;
//#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)
//
//typedef struct
//{
//	QElemType* base; // 初始化的动态分配存储空间
//	int front; // 头指针,若队列不空,指向队列头元素
//	int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
//}SqQueue;
//
//Status InitQueue(SqQueue& Q)
//{
//	// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
//	// 请补全代码
//	Q.base = (QElemType*)malloc(sizeof(QElemType) * MAXQSIZE);
//	Q.front = 0;
//	Q.rear = 0;
//	return OK;
//}
//
//Status EnQueue(SqQueue& Q, QElemType e)
//{
//	// 插入元素e为Q的新的队尾元素
//	// 请补全代码
//	if (Q.rear >= MAXQSIZE) {
//		QElemType* newBase = new QElemType[MAXQSIZE * 2];
//		for (int i = 0; i < Q.rear; i++) {
//			newBase[i] = Q.base[i];
//		}
//		Q.base = newBase;
//		delete[]Q.base;
//	}
//	Q.base[Q.rear] = e;
//	Q.rear++;
//	return OK;
//}
//
//Status DeQueue(SqQueue& Q, QElemType& e)
//{
//	// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
//	// 请补全代码
//	if (Q.front == Q.rear) {
//		return ERROR;
//	}
//	e = Q.base[Q.front];//可以操作内存地址？
//	Q.front++;
//	return OK;
//}
//
//Status GetHead(SqQueue Q, QElemType& e)
//{
//	// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
//	// 请补全代码
//	if (Q.front == Q.rear) {
//		return ERROR;
//	}
//	e = Q.base[Q.front];
//	return OK;
//}
//
//int QueueLength(SqQueue Q)
//{
//	// 返回Q的元素个数
//	// 请补全代码
//	return Q.rear - Q.front;
//}
//
//Status QueueTraverse(SqQueue Q)
//{
//	// 若队列不空，则从队头到队尾依次输出各个队列元素，并返回OK；否则返回ERROR.
//	int i;
//	i = Q.front;
//	if (Q.rear == Q.front)printf("The Queue is Empty!");  //请填空
//	else {
//		printf("The Queue is: ");
//		while (i != Q.rear)     //请填空
//		{
//			printf("%d ", Q.base[i]);   //请填空
//			i = i + 1;   //请填空
//		}
//	}
//	printf("\n");
//	return OK;
//}
//
//int main()
//{
//	int a;
//	SqQueue S;
//	QElemType x, e;
//	if (InitQueue(S))    // 判断顺序表是否创建成功，请填空
//	{
//		printf("A Queue Has Created.\n");
//	}
//	while (1)
//	{
//		printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
//		scanf("%d", &a);
//		switch (a)
//		{
//		case 1: scanf("%d", &x);
//			if (!EnQueue(S, x)) printf("Enter Error!\n"); // 判断入队是否合法，请填空
//			else printf("The Element %d is Successfully Entered!\n", x);
//			break;
//		case 2: if (!DeQueue(S, e)) printf("Delete Error!\n"); // 判断出队是否合法，请填空
//			  else printf("The Element %d is Successfully Deleted!\n", e);
//			break;
//		case 3: if (!GetHead(S, e))printf("Get Head Error!\n"); // 判断Get Head是否合法，请填空
//			  else printf("The Head of the Queue is %d!\n", e);
//			break;
//		case 4: printf("The Length of the Queue is %d!\n", QueueLength(S));  //请填空
//			break;
//		case 5: QueueTraverse(S); //请填空
//			break;
//		case 0: return 1;
//		}
//	}
//}

//栈的应用 -- 十进制转换成八进制
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#define MAXSIZE 100
//
//typedef struct Stack {
//	int* data;
//	int base;
//	int top;
//}Stack;
//
//void initStack(Stack& s)
//{
//	s.data = (int*)malloc(sizeof(int) * MAXSIZE);
//	s.top = 0;
//	s.base = 0;
//}
//
//void push(Stack& s, int e)
//{
//	if (s.top >= MAXSIZE) {
//		int* newData = new int[MAXSIZE * 2];
//		for (int i = 0; i < MAXSIZE; i++) {
//			newData[i] = s.data[i];
//		}
//		delete[]s.data;
//		s.data = newData;
//	}
//	s.data[s.top] = e;
//	s.top++;
//}
//
//void print(Stack& s)
//{
//	for (int i = s.top - 1; i >= s.base; i--) {
//		printf("%d", s.data[i]);
//	}
//}
//
//int main()
//{
//	Stack s;
//	initStack(s);
//	int x, n = 0, sum = 0;
//	scanf("%d", &x);
//	while (x / 8 != 0) {
//		n = x / 8;
//		x %= 8;
//	}
//	push(s, x);
//	push(s, n);
//	print(s);
//	return 0;
//}

//括号匹配检验
//typedef char SElemType;
//#include"malloc.h" 
//#include"stdio.h"
//#include"math.h"
//#include"stdlib.h" // exit()
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
//#define STACK_INIT_SIZE 10 // 存储空间初始分配量
//#define STACKINCREMENT 2 // 存储空间分配增量
//struct SqStack
//{
//    SElemType* base; // 在栈构造之前和销毁之后，base的值为NULL
//    SElemType* top; // 栈顶指针
//    int stacksize; // 当前已分配的存储空间，以元素为单位
//}; // 顺序栈
//Status InitStack(SqStack& S)
//{
//    S.base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
//    S.top = S.base;
//    S.stacksize = STACK_INIT_SIZE;
//    return OK;
//}
//
//Status StackEmpty(SqStack S)
//{
//    if (S.base == S.top) {
//        return OK;
//    }
//    return ERROR;
//}
//Status Push(SqStack& S, SElemType e)
//{
//    if (S.top - S.base >= STACK_INIT_SIZE) {
//        SElemType* newBase = new SElemType[STACK_INIT_SIZE + STACKINCREMENT];
//        for (int i = 0; i < STACK_INIT_SIZE; i++) {
//            newBase[i] = S.base[i];
//        }
//        delete[]S.base;
//        S.base = newBase;
//        S.top = S.base + STACK_INIT_SIZE;
//        S.stacksize += STACKINCREMENT;
//    }
//    *S.top = e;
//    S.top++;
//    return OK;
//}
//Status Pop(SqStack& S, SElemType& e)
//{
//    if (S.base == S.top) {
//        return ERROR;
//    }
//    S.top--;
//    e = *S.top;
//    return OK;
//}
//void check()
//{ // 对于输入的任意一个字符串，检验括号是否配对
//    SqStack s;
//    SElemType ch[80], * p, e;
//    if (InitStack(s)) // 初始化栈成功
//    {
//        //printf("请输入表达式\n");
//        scanf("%s", ch);
//        p = ch;
//        while (*p) // 没到串尾
//            switch (*p)
//            {
//            case '(':
//            case '[':
//                Push(s, *p);
//                p++;
//                break; // 左括号入栈，且p++
//            case ')':
//            case ']':
//                if (!StackEmpty(s)) // 栈不空
//                {
//                    Pop(s, e); // 弹出栈顶元素
//                    if (*p == ')' && e != '(' || *p == ']' && e != '[')
//                        // 弹出的栈顶元素与*p不配对
//                    {
//                        printf("isn't matched pairs\n");
//                        exit(ERROR);
//                    }
//                    else
//                    {
//                        p++;
//                        break; // 跳出switch语句
//                    }
//                }
//                else // 栈空
//                {
//                    printf("lack of left parenthesis\n");
//                    exit(ERROR);
//                }
//            default: p++; // 其它字符不处理，指针向后移
//            }
//        if (StackEmpty(s)) // 字符串结束时栈空
//            printf("matching\n");
//        else
//            printf("lack of right parenthesis\n");
//    }
//}
//int main()
//{
//    check();
//}

//行编辑程序
//typedef char SElemType;
//#include"malloc.h" 
//#include"stdio.h"
//#include"math.h"
//#include"stdlib.h" // exit()
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
//#define STACK_INIT_SIZE 10 // 存储空间初始分配量
//#define STACKINCREMENT 2 // 存储空间分配增量
//struct SqStack
//{
//    SElemType* base; // 在栈构造之前和销毁之后，base的值为NULL
//    SElemType* top; // 栈顶指针
//    int stacksize; // 当前已分配的存储空间，以元素为单位
//}; // 顺序栈
//
//Status InitStack(SqStack& S)
//{ // 构造一个空栈S
//    S.base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
//    S.top = S.base;
//    S.stacksize = STACK_INIT_SIZE;
//    return OK;
//}
//Status StackEmpty(SqStack S)
//{ // 若栈S为空栈，则返回TRUE，否则返回FALSE
//    if (S.base == S.top) {
//        return TRUE;
//    }
//    return FALSE;
//}
//Status ClearStack(SqStack& S)
//{ // 把S置为空栈
//    S.top = S.base;
//    return OK;
//}
//Status DestroyStack(SqStack& S)
//{ // 销毁栈S，S不再存在
//    free(S.base);
//    S.base = NULL;
//    S.top = NULL;
//    S.stacksize = 0;
//    return OK;
//}
//Status Push(SqStack& S, SElemType e)
//{ // 插入元素e为新的栈顶元素
//    if (S.top - S.base >= S.stacksize) {
//        SElemType* newBase = new SElemType[S.stacksize + STACKINCREMENT];
//        for (int i = 0; i < S.stacksize; i++) {
//            newBase[i] = S.base[i];
//        }
//        delete[]S.base;
//        S.base = newBase;
//        S.top = S.base + S.stacksize;
//        S.stacksize += STACKINCREMENT;
//    }
//    *S.top = e;
//    S.top++;
//    return OK;
//}
//Status Pop(SqStack& S, SElemType& e)
//{ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
//    if (S.base == S.top) {
//        return ERROR;
//    }
//    S.top--;
//    e = *S.top;
//    return OK;
//}
//Status StackTraverse(SqStack S, Status(*visit)(SElemType))//第二个参数是函数指针，visit是指向函数的指针变量，(SElemType)表示指针visit所指向的函数有一个参数，参数类型是SElemType,Status表示函数返回值是Status，当调用StackTraverse函数时，这个visit参数的位置直接用要调用函数的函数名就行了
//{ // 从栈底到栈顶依次对栈中每个元素调用函数visit()。-- 这里只是恰好visit参数名和下面的函数名重名了，实际上真正调用的函数名是任意的
//  // 一旦visit()失败，则操作失败
//    while (S.top > S.base)
//        visit(*S.base++);
//    printf("\n");
//    return OK;
//}
//Status visit(SElemType c)
//{
//    printf("%c", c);
//    return OK;
//}
//void LineEdit()
//{ // 利用字符栈s，从终端接收一行并送至调用过程的数据区。算法3.2
//    SqStack s;
//    char ch, c;
//    int n, i;
//    InitStack(s);
//    scanf("%d", &n);
//    ch = getchar();//getchar()是读取输入缓冲区中残留的字符，当scanf输入整数后，会用回车键'\n'表示结束，这时n接受了整数值，输入缓冲区中会残留'\n'，这时候getchar()就读取到'\n'
//    for (i = 1; i <= n; i++)
//    {
//        ch = (c = getchar());
//        while (ch != '\n')
//        {
//            switch (c)
//            {
//            case '#':Pop(s, c);
//                break; // 仅当栈非空时退栈
//            case '@':ClearStack(s);
//                break; // 重置s为空栈
//            default:Push(s, c); // 有效字符进栈
//            }
//            ch = (c = getchar()); // 从终端接收下一个字符
//        }
//        StackTraverse(s, visit); // 将从栈底到栈顶的栈内字符输出
//        ClearStack(s); // 重置s为空栈
//    }
//    DestroyStack(s);
//}
//void main()
//{
//    LineEdit();
//}

//表达式求值 -- 可以计算两位数和负数，负数用（0 - x)表示，太复杂可能会出错
//#include<malloc.h> 
//#include<stdio.h> 
//#include<math.h>
//#define OK 1
//#define ERROR 0
//#define STACK_INIT_SIZE 100 // 存储空间初始分配量
//#define STACKINCREMENT 10 // 存储空间分配增量
//
//typedef double SElemType; // 定义栈元素类型
//typedef char CElemType;
//typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
//
//struct SqStack
//{
//	SElemType* base; // 在栈构造之前和销毁之后，base的值为NULL
//	SElemType* top; // 栈顶指针
//	int stacksize; // 当前已分配的存储空间，以元素为单位
//}; // 顺序栈
//
//Status InitStack(SqStack& S)
//{
//	// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
//	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
//	if (!S.base) return ERROR;
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;
//	return OK;
//}
//
//Status Push(SqStack& S, SElemType e)
//{
//	// 在栈S中插入元素e为新的栈顶元素
//	if (S.top - S.base >= S.stacksize)
//	{
//		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
//		if (!S.base) return ERROR;
//		S.top = S.base + S.stacksize;
//		S.stacksize += STACKINCREMENT;
//	}
//	*S.top++ = e;
//	return OK;
//}
//
//Status Pop(SqStack& S, SElemType& e)
//{
//	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
//	if (S.top == S.base) return ERROR;
//	e = *--S.top;
//	return OK;
//}
//
//Status GetTop(SqStack S, SElemType& e)
//{
//	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
//	if (S.top == S.base) return ERROR;
//	e = *(S.top - 1);
//	return OK;
//}
//
//Status GetTop2(SqStack S, SElemType& e)
//{
//	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
//	if (S.top == S.base) return ERROR;
//	e = *(S.top - 2);
//	return OK;
//}
//
//Status StackTraverse(SqStack S)
//{
//	// 从栈顶到栈底依次输出栈中的每个元素
//	SElemType* p = (SElemType*)malloc(sizeof(SElemType));
//	p = S.top;
//	if (S.top == S.base)printf("The Stack is Empty!");
//	else
//	{
//		p--;
//		while (p >= S.base)
//		{
//			printf("%.0f ", *p);
//			p--;
//		}
//	}
//	printf("\n");
//	return OK;
//}
//
//struct CqStack
//{
//	CElemType* base; // 在栈构造之前和销毁之后，base的值为NULL
//	CElemType* top; // 栈顶指针
//	int stacksize; // 当前已分配的存储空间，以元素为单位
//}; // 顺序栈
//
//Status InitCStack(CqStack& S)
//{
//	// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
//	S.base = (CElemType*)malloc(STACK_INIT_SIZE * sizeof(CElemType));
//	if (!S.base) return ERROR;
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;
//	return OK;
//}
//
//Status PushToken(CqStack& S, CElemType e)
//{
//	// 在栈S中插入元素e为新的栈顶元素
//	if (S.top - S.base >= S.stacksize)
//	{
//		S.base = (CElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(CElemType));
//		if (!S.base) return ERROR;
//		S.top = S.base + S.stacksize;
//		S.stacksize += STACKINCREMENT;
//	}
//	*S.top++ = e;
//	return OK;
//}
//
//Status PopToken(CqStack& S, CElemType& e)
//{
//	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
//	if (S.top == S.base) return ERROR;
//	e = *--S.top;
//	return OK;
//}
//
//Status GetTokenTop(CqStack S, CElemType& e)
//{
//	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
//	if (S.top == S.base) return ERROR;
//	e = *(S.top - 1);
//	return OK;
//}
//
////比较优先级
//int prior(char a, char b)//a表示要入栈的符号，b表示栈顶符号
//{
//	if ((a == '*' && b == '*') || (a == '*' && b == '/') || (a == '/' && b == '*') || (a == '/' && b == '/') || (a == '+' && b == '*') || (a == '+' && b == '/') || (a == '-' && b == '*') || (a == '-' && b == '/') || (a == '+' && b == '+') || (a == '+' && b == '-') || (a == '-' && b == '+') || (a == '-' && b == '-')) {
//		return 0;//栈顶符号出栈
//	}
//	else {
//		return 1;//入栈
//	}
//}
//
//double calculate(double op1, double op2, char symbol)
//{
//	switch(symbol) {
//	case '+':
//		return op1 + op2;
//	case '-':
//		return op1 - op2;
//	case '*':
//		return op1 * op2;
//	case '/':
//		return op1 / op2;
//	}
//	return 0;
//}
//
//void operate(SqStack& s1, CqStack& s2, double* op1, double* op2, double* result)//简单计算式的计算
//{
//	char c;
//	double e;
//	double e2;
//	double arr[10000] = { 0 };
//	int n = 0;//计数器
//	PopToken(s2, c);
//	GetTop(s1, e);
//	GetTop2(s1, e2);
//	if (e != 32 && e2 == 32) {//空格
//		Pop(s1, e);
//		arr[n] = e;
//		n++;
//		Pop(s1, e);//弹出空格
//		do {
//			Pop(s1, e);
//			arr[n] = e;
//			n++;
//			if (GetTop(s1, e) && e == 32) {
//				Pop(s1, e);//弹出空格
//			}
//			else {//栈顶没有元素或者有元素但不是空格
//				break;
//			}
//		} while (1);
//		while (n >= 0) {
//			*op2 += arr[n] * pow(10, n);
//			n--;
//		}
//		n++;//使n回到0
//	}
//	else {
//		Pop(s1, *op2);
//	}
//	GetTop(s1, e);
//	GetTop2(s1, e2);
//	if (e != 32 && e2 == 32) {//空格
//		Pop(s1, e);
//		arr[n] = e;
//		n++;
//		Pop(s1, e);//弹出空格
//		do {
//			Pop(s1, e);
//			arr[n] = e;
//			n++;
//			if (GetTop(s1, e) && e == 32) {
//				Pop(s1, e);//弹出空格
//			}
//			else {//栈顶没有元素或者有元素但不是空格
//				break;
//			}
//		} while (1);
//		while (n >= 0) {
//			*op1 += arr[n] * pow(10, n);
//			n--;
//		}
//		n++;//使n回到0
//	}
//	else {
//		Pop(s1, *op1);
//	}
//	*result = calculate(*op1, *op2, c);
//	Push(s1, *result);
//}
//
//int main()
//{
//	SqStack s1;//存储数字
//	CqStack s2;//存储符号
//	InitStack(s1);
//	InitCStack(s2);
//	char data[100];
//	scanf("%s", data);
//	double e = 0;//存储数字
//	char c = '\0';//存储符号
//	double result, op1 = 0, op2 = 0;
//	for (int i = 0; data[i] != '\0'; i++) {
//		char x = data[i];
//		switch (x) {
//		case '(':
//			PushToken(s2, x);
//			break;
//		case ')':
//			do {
//				operate(s1, s2, &op1, &op2, &result);
//				GetTokenTop(s2, c);
//			} while (c != '(');
//			PopToken(s2, c);//把'('弹出栈
//			break;
//		case '+':
//		case '-':
//		case '*':
//		case '/':
//			if (GetTokenTop(s2, c) && c != '(') {
//				if (prior(x, c)) {
//					PushToken(s2, x);
//				}
//				else {
//					operate(s1, s2, &op1, &op2, &result);
//					PushToken(s2, x);
//				}
//			}
//			else {
//				PushToken(s2, x);
//			}
//			break;
//		case '='://处理栈中剩余的运算
//			while (GetTokenTop(s2, c)) {
//				operate(s1, s2, &op1, &op2, &result);
//			}
//			break;
//		default:
//			Push(s1, x - '0');
//			if (data[i + 1] >= '0' && data[i + 1] <= '9') {
//				Push(s1, ' ');
//			}
//			break;
//		}
//	}
//	StackTraverse(s1);
//	return 0;
//}

//汉诺塔问题 -- 递归思想						注意OJ上这道题把第二根杆子视为目标杆，而这里的代码将第三根杆子视为目标杆
//#include<stdio.h>
//void print(char x, int n, char y)
//{
//	printf("%c->%d->%c\n", x, n, y);
//}
//
//void hanoi(int n, char start, char temp, char end)//汉诺塔问题有三个杆子，命名为起始杆，中转杆和目标杆，目的是将起始杆上的盘子全部移到目标杆上
//{
//	if (n == 1) {
//		print(start, n, end);//n=1时只剩一个盘子，直接打印出最后一个盘子的移动轨迹
//	}
//	else {
//		hanoi(n - 1, start, end, temp);//先把n-1个盘子移到中转杆上，此时目标杆视为中转杆，中转杆视为目标杆
//		print(start, n, end);//n-1个盘子移动完毕后，打印出第n-1个盘子的移动轨迹
//		hanoi(n - 1, temp, start, end);//然后再把中转杆上n-1个盘子移到目标杆上，此时中转杆视为起始杆
//	}
//}
//
//int main()
//{
//	int n;
//	char a, b, c;
//	scanf("%d", &n);
//	while (getchar() != ' ');//清除输入缓冲区知道空格（否则下面的%c会读取到空格）
//	scanf("%c", &a);
//	while (getchar() != ' ');
//	scanf("%c", &b);
//	while (getchar() != ' ');
//	scanf("%c", &c);
//	hanoi(n, a, b, c);
//	return 0;
//}

//队列的应用 -- 银行客户平均等待时间
//#include<malloc.h>
//#include<stdio.h>
//#include<stdlib.h>
//#define OK 1
//#define ERROR 0
//typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
//typedef double QElemType;
//#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)
//
//typedef struct
//{
//	QElemType* base; // 初始化的动态分配存储空间
//	int front; // 头指针,若队列不空,指向队列头元素
//	int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
//}SqQueue;
//
//Status InitQueue(SqQueue& Q)
//{
//	// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
//	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
//	if (!Q.base) exit(1);
//	Q.rear = Q.front = 0;
//	return OK;
//}
//
//Status EnQueue(SqQueue& Q, QElemType e)
//{
//	// 插入元素e为Q的新的队尾元素
//	if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;
//	Q.base[Q.rear] = e;
//	Q.rear = (Q.rear + 1) % MAXQSIZE;
//	return OK;
//}
//
//Status DeQueue(SqQueue& Q, QElemType& e)
//{
//	// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
//	if (Q.front == Q.rear) return ERROR;
//	e = Q.base[Q.front];
//	Q.front = (Q.front + 1) % MAXQSIZE;
//	return OK;
//}
//
//Status GetHead(SqQueue Q, QElemType& e)
//{
//	// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
//	if (Q.front == Q.rear) return ERROR;
//	e = Q.base[Q.front];
//	return OK;
//}
//
//int QueueLength(SqQueue Q)
//{
//	// 返回Q的元素个数
//	return Q.rear % MAXQSIZE - Q.front % MAXQSIZE;
//}
//
//int main()
//{
//	SqQueue q;
//	InitQueue(q);
//	int n, m = 1;
//	scanf("%d", &n);
//	double t0, t, avg = 0, e;//t0为时刻，t为用时，avg为平均用时
//	double arr[100] = { 0 };
//	scanf("%lf", &t0);
//	scanf("%lf", &t);
//	arr[0] = t0;
//	arr[1] = t;
//	while (m != n) {
//		double 	sum = 0;;//sum为个人等待时间
//		scanf("%lf", &t0);
//		scanf("%lf", &t);
//		arr[m + 1] = t;
//		for (int i = 0; i <= m; i++) {
//			sum += arr[i];
//		}
//		sum -= t0;
//		if (sum <= 0) {//说明这一位客户不需要等待了，跟第一位客户一样
//			for (int i = 0; i <= m + 1; i++) {//清空数组
//				arr[i] = 0;
//			}
//			arr[0] = t0;
//			arr[1] = t;
//		}
//		else {
//			EnQueue(q, sum);
//		}
//		m++;
//	}
//	while (GetHead(q, e)) {
//		DeQueue(q, e);
//		avg += e;
//	}
//	avg /= n;
//	printf("%.2f\n", avg);
//	return 0;
//}

//阿克曼函数
//#include<stdio.h>
//int akm(int m, int n)
//{
//	if (m == 0) {
//		return n + 1;
//	}
//	else if (m > 0 && n == 0) {
//		return akm(m - 1, 1);
//	}
//	else if (m > 0 && n > 0) {
//		return akm(m - 1, akm(m, n - 1));
//	}
//}
//int main()
//{
//	int m, n;
//	scanf("%d", &m);
//	scanf("%d", &n);
//	int res = akm(m, n);
//	printf("%d", res);
//	return 0;
//}

//计算next值
//#include "stdio.h"
//#include "stdlib.h"
//#define  MAXSTRLEN  255                   // 用户可在255以内定义最大串长
//typedef unsigned char SString[MAXSTRLEN + 1];	// 0号单元存放串的长度
//
//void get_next(SString T, int next[]) {
//	// 算法4.7
//	// 求模式串T的next函数值并存入数组next
//	// 请补全代码
//	next[1] = 0;
//	int i = 1, j = 0;
//	while (i < T[0]) {//T[0]是字符串的长度
//		if (j == 0 || T[i] == T[j]) {
//          i++;
//          j++;
//			next[i] = j;
//		}
//		else {
//			j = next[j];
//		}
//	}
//
//}
//int main() {
//	int next[MAXSTRLEN];
//	SString S;
//	int n, i, j;
//	char ch;
//	scanf("%d", &n);    // 指定要验证NEXT值的字符串个数
//	ch = getchar();
//	for (i = 1; i <= n; i++)
//	{
//		ch = getchar();
//		for (j = 1; j <= MAXSTRLEN && (ch != '\n'); j++)    // 录入字符串
//		{
//			S[j] = ch;
//			ch = getchar();
//		}
//		S[0] = j - 1;    // S[0]用于存储字符串中字符个数
//		get_next(S, next);
//		printf("NEXT J is:");
//		for (j = 1; j <= S[0]; j++)
//			printf("%d", next[j]);
//		printf("\n");
//	}
//	return 0;
//}

//KMP算法
//#include "stdio.h"
//#include "stdlib.h"
//#define TRUE  1
//#define FALSE  0
//#define OK  1
//#define ERROR  0
//#define INFEASLBLE  -1
//#define OVERFLOW  -2
//#define MAXSTRLEN  255 	//用户可在255以内定义最大串长
//typedef unsigned char SString[MAXSTRLEN + 1];	//0号单元存放串的长度
//
//void get_next(SString T, int next[]) {
//    // 算法4.7
//    // 求模式串T的next函数值并存入数组next
//    // 请补全代码
//    next[1] = 0;
//    int j = 0, i = 1;
//    while (i < T[0]) {
//        if (j == 0 || T[i] == T[j]) {
//            i++;
//            j++;
//            next[i] = j;
//        }
//        else {
//            j = next[j];
//        }
//    }
//}
//
//int Index_KMP(SString S, SString T) {
//    // 算法4.6
//    // 利用模式串T的next函数求T在主串S中第pos个字符之后的位置
//    // KMP算法。请补全代码
//    int next[MAXSTRLEN + 1] = { 0 };
//    get_next(T, next);
//    int i = 1, j = 1;
//    while (i <= S[0] && j <= T[0]) {
//        if (j == 0 || S[i] == T[j]) {//字符相同时，读取下一个字符
//            i++;
//            j++;
//        }
//        else {//字符不同，j回到next位置（子串中有对称划分出的每一个块，该操作就是使该字符从这一个块回到上一个对称块的相同字符处）
//            j = next[j];
//        }
//    }
//    if (j > T[0]) {//主串中有子串，返回主串起始字符位置
//        return i - T[0];
//    }
//    else {//主串中无子串，返回0
//        return 0;
//    }
//}
//
//int main()
//{
//    SString T, S;
//    int i, j, n;
//    char ch;
//    int pos = 0;
//    scanf("%d", &n);    // 指定n对需进行模式匹配的字符串
//    ch = getchar();
//    for (j = 1; j <= n; j++)
//    {
//        ch = getchar();
//        for (i = 1; i <= MAXSTRLEN && (ch != '\n'); i++)    // 录入主串
//        {
//            S[i] = ch;
//            ch = getchar();
//        }
//        S[0] = i - 1;    // S[0]用于存储主串中字符个数
//        ch = getchar();
//        for (i = 1; i <= MAXSTRLEN && (ch != '\n'); i++)    // 录入模式串
//        {
//            T[i] = ch;
//            ch = getchar();
//        }
//        T[0] = i - 1;    // T[0]用于存储模式串中字符个数
//        pos = Index_KMP(S, T);    // 请填空
//        printf("%d\n", pos);
//    }
//    return 0;
//}

//不完整排序
//#include<stdio.h>
//void sort(int arr[])
//{
//	int len;
//	scanf("%d", &len);
//	for (int i = 0; i < len; i++) {
//		scanf("%d", &arr[i]);
//	}
//	int i = 0, j = len - 1;
//	while (i <= j) {
//		if (arr[i] > 0 && arr[j] < 0) {
//			int t = arr[i];
//			arr[i] = arr[j];
//			arr[j] = t;
//			i++;
//			j--;
//		}
//		if (arr[i] < 0) {
//			i++;
//		}
//		if (arr[j] > 0) {
//			j--;
//		}
//	}
//	for (int i = 0; i < len; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[100000] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	while (n > 0) {
//		sort(arr);
//		n--;
//	}
//	return 0;
//}

//实验3

//二叉树的构建及遍历操作
//#include "stdio.h"
//#include "malloc.h"
//#define TRUE 1
//#define FALSE 0
//#define OK  1
//#define ERROR  0
//#define INFEASIBLE -1
//#define OVERFLOW -2
//typedef int  Status;
//
//typedef char  ElemType;
//typedef struct BiTNode {
//    ElemType data;
//    struct BiTNode* lchild, * rchild;//左右孩子指针
//} BiTNode, * BiTree;
//
//Status CreateBiTree(BiTree& T) {  // 算法6.4
//  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
//  // 构造二叉链表表示的二叉树T。
//    char ch;
//    scanf("%c", &ch);
//    if (ch == '#') T = NULL;
//    else {
//        if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) return ERROR;
//        (*T).data = ch;// 生成根结点
//        CreateBiTree((*T).lchild);   // 构造左子树
//        CreateBiTree((*T).rchild); // 构造右子树
//    }
//    return OK;
//} // CreateBiTree
//
//Status PreOrderTraverse(BiTree T) {
//    // 前序遍历二叉树T的递归算法
//    //补全代码,可用多个语句
//    if (T == NULL) {
//        return OK;
//    }
//    printf("%c", T->data);
//    PreOrderTraverse(T->lchild);
//    PreOrderTraverse(T->rchild);
//} // PreOrderTraverse
//
//Status InOrderTraverse(BiTree T) {
//    // 中序遍历二叉树T的递归算法
//   //补全代码,可用多个语句
//    if (T == NULL) {
//        return OK;
//    }
//    InOrderTraverse(T->lchild);
//    printf("%c", T->data);
//    InOrderTraverse(T->rchild);
//} // InOrderTraverse
//
//Status PostOrderTraverse(BiTree T) {
//    // 后序遍历二叉树T的递归算法
//    //补全代码,可用多个语句
//    if (T == NULL) {
//        return OK;
//    }
//    PostOrderTraverse(T->lchild);
//    PostOrderTraverse(T->rchild);
//    printf("%c", T->data);
//} // PostOrderTraverse
//
//int main()   //主函数
//{
//    //补充代码
//    BiTree T;
//    CreateBiTree(T);
//    PreOrderTraverse(T);
//    printf("\n");
//    InOrderTraverse(T);
//    printf("\n");
//    PostOrderTraverse(T);
//    printf("\n");
//}

//笔记：在cpp中，函数传递参数时，如果函数体的参数声明带有&，说明函数体中使用的是该变量的地址（注意：在main函数中传递的参数仍然是变量名，不需要额外使用"&"进行取地址操作），此时该变量
//      视为指针变量，可以用"*"进行解引用，但是对于结构体的操作，仍然使用"."而不是"->"

//求二叉树各种节点数
//#include "stdio.h"
//#include "malloc.h"
//#define TRUE 1
//#define FALSE 0
//#define OK  1
//#define ERROR  0
//#define INFEASIBLE -1
//#define OVERFLOW -2
//typedef int  Status;
//
//typedef char  ElemType;
//typedef struct BiTNode {
//    ElemType data;
//    struct BiTNode* lchild, * rchild;//左右孩子指针
//} BiTNode, * BiTree;
//
//Status CreateBiTree(BiTree& T) {  // 算法6.4
//  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
//  // 构造二叉链表表示的二叉树T。
//    char ch;
//    scanf("%c", &ch);
//    if (ch == '#') T = NULL;
//    else {
//        if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) return ERROR;
//        T->data = ch; // 生成根结点
//        CreateBiTree(T->lchild);   // 构造左子树
//        CreateBiTree(T->rchild);   // 构造右子树
//    }
//    return OK;
//} // CreateBiTree
////度为2
//int Num1(BiTree T)
//{
//    if (T == NULL) {
//        return 0;
//    }
//    if (T->lchild != NULL && T->rchild != NULL) {
//        return 1 + Num1(T->lchild) + Num1(T->rchild);
//    }
//    if (T->lchild != NULL && T->rchild == NULL) {
//        return Num1(T->lchild);
//    }
//    if (T->lchild == NULL && T->rchild != NULL) {
//        return Num1(T->rchild);
//    }
//    return 0;
//}
////度为1
//int Num2(BiTree T)
//{
//    if (T == NULL) {
//        return 0;
//    }
//    if (T->lchild != NULL && T->rchild != NULL) {
//        return Num2(T->lchild) + Num2(T->rchild);
//    }
//    if (T->lchild != NULL && T->rchild == NULL) {
//        return 1 + Num2(T->lchild);
//    }
//    if (T->lchild == NULL && T->rchild != NULL) {
//        return 1 + Num2(T->rchild);
//    }
//    return 0;
//}
////度为0
//int Num3(BiTree T)
//{
//    if (T->lchild == NULL && T->rchild == NULL) {
//        return 1;
//    }
//    if (T->lchild != NULL && T->rchild != NULL) {
//        return Num3(T->lchild) + Num3(T->rchild);
//    }
//    if (T->lchild != NULL && T->rchild == NULL) {
//        return Num3(T->lchild);
//    }
//    if (T->lchild == NULL && T->rchild != NULL) {
//        return Num3(T->rchild);
//    }
//    return 0;
//}
//int main()
//{
//    BiTree T = NULL;
//    CreateBiTree(T);
//    printf("%d\n", Num1(T));
//    printf("%d\n", Num2(T));
//    printf("%d\n", Num3(T));
//    return 0;
//}

//二叉树的宽度 --- 错的
//#include<stdio.h>
//#include<stdlib.h>
//#define MAXSIZE 100
//typedef int TreeType;
////树的结构体
//typedef struct TreeNode {
//	TreeType data;
//	struct TreeNode* lchild;
//	struct TreeNode* rchild;
//}TreeNode, * ElemType, * BiTree;
////队列的结构体
//typedef struct {
//	ElemType* data;
//	int front;
//	int rear;
//}Queue;
//
//int arr[105] = { 0 };
//
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
////创建树
//BiTree creatNode(TreeType value)
//{
//	BiTree node = (BiTree)malloc(sizeof(TreeNode));
//	node->data = value;
//	node->lchild = node->rchild = NULL;
//	return node;
//}
////查找父节点的指针
//BiTree findNode(BiTree root, int value)
//{
//	if (root == NULL) return NULL;
//	if (root->data == value) return root;
//	//查找该节点的左孩子
//	BiTree leftResult = findNode(root->lchild, value);
//	if (leftResult) return leftResult;
//	//左节点没有，则说明在右节点
//	return findNode(root->rchild, value);
//}
////输入父子关系
//void insertNode(BiTree root, int parent, int child)
//{
//	BiTree parentNode = findNode(root, parent);
//	if (parentNode->lchild == NULL) {
//		parentNode->lchild = creatNode(child);
//	}
//	else {
//		parentNode->rchild = creatNode(child);
//	}
//}
////求宽度
//void Width(BiTree root)
//{
//	if (root == NULL) {
//		return;
//	}
//	Queue* q = initQueue();
//	equeue(q, root);
//
//	int i = 0;
//	while (!isEmpty(q)) {
//		int count = queueSize(q);
//		arr[i++] = count;
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
//	}
//}
////前序遍历
//void preOrder(BiTree T)
//{
//	if (T == NULL) {
//		return;
//	}
//	printf("%d ", T->data);
//	preOrder(T->lchild);
//	preOrder(T->rchild);
//}
//int main()
//{
//	BiTree root = NULL;
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n - 1; i++) {//一共n个节点，第一次会创建出两个节点，故循环n - 1次
//		int parent, child;
//		scanf("%d%d", &parent, &child);
//		if (root == NULL) {
//			root = creatNode(parent);
//		}
//		insertNode(root, parent, child);
//	}
//	preOrder(root);
//	Width(root);
//	int max = arr[0];
//	for (int i = 0; i < 32; i++) {
//		if (arr[i] > max) {
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}





























//程序设计与算法竞赛

//第1题

//#include<stdio.h>
//
//long long a, b;
//
//long long cal(long long a, long long b)
//{
//	long long sum = a * b;
//	while (b != 0) {
//		a %= b;
//		long long t = a;
//		a = b;
//		b = t;
//	}
//	return sum / a;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n > 0) {
//		scanf("%lld%lld", &a, &b);
//		printf("%lld\n", cal(a, b));
//		n--;
//	}
//	printf("group 1 done\n");
//	while (scanf("%lld%lld", &a, &b)) {
//		if (a == 0 && b == 0) {
//			break;
//		}
//		printf("%lld\n", cal(a, b));
//	}
//	printf("group 2 done\n");
//	while (scanf("%lld%lld", &a, &b) > 0) {
//		printf("%lld\n", cal(a, b));
//	}
//	printf("group 3 done\n");
//	return 0;
//}

//笔记：scanf表示输入结束，在Windows环境下可以按下ctrl+Z键（会看到^Z）再按下回车键，就表示输入结束（可能需要重复多次）

//第2题
