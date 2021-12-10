/*
 ============================================================================
 Name        : practice.c
 Author      : JK
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// #include "SeqList.h"
//#include "SortAlgorithms.h"
#include "SortAlgorithms.c"
#include "Tree.c"


//二叉树层次遍历
// void levelorder(BTreeList bt)
// {
//     LinkList Q;
//     Q = InitialLinkList();
//     if (bt != NULL)
//     {
//         EnQueue(&Q, bt);
//         while (!EmptyQueue(Q))
//         {
//             p = Gethead(&Q);
//             outQueue(&Q);
//             visit(p);
//             if (p->lchild !NULL)
//                 EnQueue(&Q, p->lchild);
//             if (p->rchild !NULL)
//                 EnQueue(&Q, p->rchild);
//         }
//     }
// }



// 递归函数
// 例 求整数n的阶乘函数 1 当n=0时
// n! = 1   当n=0时
// n*(n-1)! 当n>0时
// 程序实现：
// int f (int n){
// 	if(n==0) return(1);
// 	else return n*f (n-1);
// }
//---------------------------循环队列的实现 START---------------------------//
//下溢条件即队列空： CQ.front==CQ.rear
// 上溢条件即队列满： 尾指针从后面追上头指针
// 即：(CQ.rear+1)%maxsize==CQ.front （尾赶头）
// （浪费一个空间，队满时实际队容量=maxsize-1）
void InitCycleQueue(CycleQueue* cq){
	cq->front=0;
	cq->rear=0;
}
int IsEmptyQueue(CycleQueue * cq){
	if(cq->rear == cq->front){
		return 1;
	}
	return 0;
}
void enqueue(CycleQueue * cq, DataType d){
	//取模如果小于max则值为分子，如果等于则为0，回到循环队列0点
	if((cq->rear + 1) % Maxsize == cq->front){
		printf("queue full");
		return;
	}
	cq->rear = (cq->rear + 1) % Maxsize;
	cq->datas[cq->rear] = d;
}

void dequeue(CycleQueue * cq){
	if(IsEmptyQueue(cq)){
		printf("queue is empty");
		return;
	}
	cq->front = (cq->front + 1) % Maxsize;
}
DataType * getTopCq(CycleQueue * cq){
	if(IsEmptyQueue(cq)){
		printf("queue is empty");
		return NULL;
	}
	return &(cq->datas[(cq->front + 1) % Maxsize]);
}
//---------------------------循环队列的实现 END---------------------------//


//---------------------------链式队列的实现 START---------------------------//
void InitLinkQueue(LinkQueue * lq){
	LkQNode* tmp =(LkQNode *) malloc(sizeof(LkQNode));
	lq->front=tmp;
	lq->rear = tmp;
	(lq->front)->next = NULL;
}
//链队列下溢条件：
// LQ.front->next==NULL 或 LQ. front==LQ. rear；
int EmptyQueue(LinkQueue LQ) {
	if (LQ.rear==LQ.front) return 1;
	else return 0;
}
void EnQueue(LinkQueue *LQ,DataType x) {
	LkQNode *temp;
	temp=(LkQNode *)malloc(sizeof(LkQNode));
	temp->data=x;
	temp->next=NULL;
	(LQ->rear)->next=temp;
	LQ->rear=temp;
}
/*
不下溢，则①取队头结点temp；②送队头元素至x；③从
链式队中删除队头结点；④若链式队中原只有一个元素，则删
除后队列为空，应修改队尾指针；⑤结点temp回归系统。
*/
int OutQueue(LinkQueue *LQ){
	LkQNode *temp;
	if (EmptyQueue(*LQ)){
		printf("empty");
		return 0;
	} else {
		//取出第一个
		temp = (LQ->front)->next;
		//将首节点指向第二个数据
		(LQ->front)->next = temp->next;
		if (temp->next == NULL)
			//如果为空了
			LQ->rear = LQ->front;
		free(temp);
		return 1;
	}
}

DataType GetHead(LinkQueue LQ)
{
	LkQNode *temp;
	if (EmptyQueue(LQ))
		// return NULL
		return *(DataType*)malloc(sizeof(DataType));
	else {
		temp = LQ.front->next;
		return temp->data;
	}
}
//---------------------------链式队列的实现 END---------------------------//



//---------------------------链栈的实现 START---------------------------//
LinkStack * InitLinkStack(LinkStack *ls){
	ls=(LinkStack *)malloc(sizeof(LinkStack));
	ls->next = NULL;
	return ls;
}

//链栈不会有上溢情况发生
void PushLinkStack(LinkStack *ls, DataType x){
	LinkStack * tmp;
	tmp = (LinkStack *) malloc(sizeof(LinkStack));
	tmp->data = x;
	tmp->next = ls->next;
	ls->next = tmp;
}
int PopLinkStack(LinkStack *ls){
	// if(!EmptyLinkStack(ls)){
	// 	return 0;
	// }
	LinkStack * tmp;
	tmp = ls->next;
	ls->next = tmp->next;
	free(tmp);
	return 1;
}
int GetTopLinkStack(LinkStack *ls){
	// if(!EmptyLinkStack(ls)){
	// 	return NULL;
	// }
	return ls->next->data.age;
}
int EmptyLinkStack(LinkStack *ls){
	if(ls->next == NULL){
		return 1;
	}
	return 0;
}
//---------------------------链栈的实现 END---------------------------//

//---------------------------顺序栈的实现 START---------------------------//
int InitSeqStack(SeqStack *seqStk){
	if(seqStk != NULL){
		seqStk->top=0;
		return 1;
	}
}
int EmptySeqStack(SeqStack *seqStk){
	if(seqStk != NULL){
		return seqStk->top!=0;
	}
}
//栈的第0个是空
int PushSeqStack(SeqStack * seqStk, DataType dt){
	if(seqStk->top == Maxsize - 1){
		exit("stack full");
		return 0;
	}
	seqStk->top++ ;
	seqStk->datatype[seqStk->top] = dt;
	return 1;
}
int PopSeqStack(SeqStack * seqStk){
	if(!EmptySeqStack(seqStk)){
		exit("empty stack");
	}
	DataType data = seqStk->datatype[seqStk->top];
	seqStk->top--;
	return data.age;
}
//---------------------------顺序栈的实现 END---------------------------//


//---------------------------单链表的实现 START---------------------------//
LinkList InitialLinkList(){
	LinkList lk;
	//malloc定义出的是指针类型
	lk = malloc(sizeof(Node));
	lk->next = NULL;
	return lk;
}

Node *GetNodeFromLinkList(LinkList l, int i){
	Node *p;
	p = l->next;
	int c = 1;
	while (c != i && p != NULL){
		c++;
		p = p->next;
	}
	if (c == i){
		return p;
	}
	else{
		return NULL;
	}
}

Node InsertLinkList(LinkList head, DataType data, int i){
	Node *q, *p;
	if (i == 1){
		q = head;
	}
	else{
		q = GetNodeFromLinkList(head, i - 1);
	}
	if (q == NULL){
		exit("pre is null");
	}
	p = malloc(sizeof(Node));
	p->data = data;
	p->next = q->next;
	q->next = p;
}

int GetLinkListLength(LinkList head){
	Node *p = head;
	int i = 0;
	while (p->next != NULL){
		p = p->next;
		i++;
	}
	return i;
}

//注意链表中的i代表的就是第i个，不同于数组中是从0开始
void DeleteFromLinkList(LinkList l, int i){
	Node * q;
	if(i == 1){
		q = l;
	} else {
		q=GetNodeFromLinkList(l, i-1);
	}
	if(q != NULL && q->next != NULL){
		Node *p = q->next;
		q->next = p->next;
		free(p);
	} else {
		exit("err");
	}
}
//---------------------------单链表的实现 END---------------------------//

//---------------------------顺序表的实现 START---------------------------//
/**
 	添加节点，到第i个位置，从length-1开始整体向后移动1一位
 	在长度为n的顺序表的第i(1≤i≤n+1)个位置上插入一
	个元素，元素的移动次数为(n-i+1)
 **/
void insertSeqlist(SeqList *l, DataType x, int i){
	if (l->length > Maxsize){
		exit("list full");
	}
	if (i < 1 || i > Maxsize - 1){
		exit("length over flow");
	}
	for (int j = l->length; j >= i; j--){
		l->data[j] = l->data[j - 1];
	}
	l->data[i - 1] = x;
	printf("i=%d \n", i);
	printf("x=%d \n", l->data[i - 1].age);
	l->length++;
}

int LocateSeqlist(SeqList *L, DataType x){
	int i = 0;
	while ((i < L->length) && ((L->data[i].age) != x.age)){
		i++;
	} //在顺序表中查找值为 x 的结点
	if (i < L->length)
		return i + 1; //若找到值为x的元素，返回元素的序号
	else
		return -1; //未查找到值为x的元素，返回0
}
/**删除顺序表中的第i节点**/
int DeleteSeqList(SeqList *L, int i){
	if (i < 1 || i > L->length){
		exit("error");
	}
	//从第i个开始向前移动
	for (int j = i; j < L->length; j++){
		L->data[i - 1] = L->data[i];
	}
	L->length--;
}
//---------------------------顺序表的实现 END---------------------------//
int main(){
	//Test 顺序表Start
	SeqList *l = (SeqList *)malloc(sizeof(SeqList));
	l->length = 0;
	DataType x;
	x.age = 232;
	DataType x1;
	x1.age = 233;
	DataType x2;
	x2.age = 234;

	insertSeqlist(l, x, 1);
	insertSeqlist(l, x1, 2);
	insertSeqlist(l, x2, 3);
	int i = 0;
	while (i <= l->length - 1){
		int tmpAge = l->data[i].age;
		printf("tmpAge=%d \n", tmpAge);
		i++;
	}
	int loc = LocateSeqlist(l, x1);
	printf("loc=%d \n", loc);
	//Test 顺序表End
//---------------------------------------------------------------------//
	//Test单链表Start
	LinkList lk = InitialLinkList();
	
	InsertLinkList(lk,x,1);
	InsertLinkList(lk,x1,2);
	InsertLinkList(lk,x2,3);
	Node* n = GetNodeFromLinkList(lk, 2);
	int lkLen = GetLinkListLength(lk);
	printf("n=%d \n", n->data.age);
	printf("lkLen=%d \n", lkLen);
	DeleteFromLinkList(lk, 1);
	lkLen = GetLinkListLength(lk);
	printf("lkLen=%d \n", lkLen);
	//Test单链表END

	//Test顺序栈START
	// SeqStack* stk;
	// InitSeqStack(stk);
	// PushSeqStack(stk, x);
	// PushSeqStack(stk, x1);
	// PushSeqStack(stk, x2);
	// int isEmp = EmptySeqStack(stk);
	// int topAge = PopSeqStack(stk);
	// printf("isEmpStk=%d", isEmp);
	// printf("topAge=%d", topAge);

	//TEST链栈的实现
	LinkStack * lstk = malloc(sizeof(LinkStack));
	lstk->next = NULL;
		DataType x3;
	x3.age = 232;
	//InitLinkStack(lstk);
	PushLinkStack(lstk, x3);
	// PushLinkStack(lstk, x1);
	// PushLinkStack(lstk, x2);
	int topD = GetTopLinkStack(lstk);
	printf("topd=%d \n", topD);

	//TEST循环链表
	CycleQueue cq;
	InitCycleQueue(&cq);
	enqueue(&cq, x);
	enqueue(&cq, x1);
	enqueue(&cq, x2);
	printf("cq.rear=%d \n", cq.rear);
	dequeue(&cq);
	printf("cq.front=%d \n", cq.front);
	DataType *firstCq = getTopCq(&cq);
	printf("firstCq=%d \n", firstCq->age);

	//TEST链式队列
	// LinkQueue * lkQueue;
	// InitLinkQueue(lkQueue);


	//TEST 直接插入排序
	List list;
	for(int r = 1; r <= N; r++){
		Record re;
		//Record *tmp = (Record *)malloc(sizeof(Record));
		re.key = rand() % 100;
		// List[r] = re;
		list[r] = re;
		printf("re=%d", re.key);
	}
	//直接插入排序
	//StraightInsertSort(list, N);
	//冒泡排序
	// BubbleSort(list, N);

	//快速排序
	//quickSort(list, 0, N-1);

	//直接选择排序
	//selectSort(list, N);
	//堆排序
	HeapSort(list, N);
	// for(int r = 0; r < N+1; r++){
	// 	printf("sorted re=%d \n", list[r].key);
	// }
	return EXIT_SUCCESS;
}
