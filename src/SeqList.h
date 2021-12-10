/*
 * SeqList.h
 *
 *  Created on: 2021年8月21日
 *      Author: cuijiangkun
 * 
 * 
 *  既然结构体是一种数据类型，那么就可以用它来定义变量。例如：

	struct stu stu1, stu2;

	定义了两个变量 stu1 和 stu2，它们都是 stu 类型，都由 5 个成员组成。注意关键字struct不能少。

	stu 就像一个“模板”，定义出来的变量都具有相同的性质。也可以将结构体比作“图纸”，将结构体变量比作“零件”，根据同一张图纸生产出来的零件的特性都是一样的。

	你也可以在定义结构体的同时定义结构体变量：

		struct stu{
			char *name;  //姓名
			int num;  //学号
			int age;  //年龄
			char group;  //所在学习小组
			float score;  //成绩
		} stu1, stu2;

	将变量放在结构体定义的最后即可。

	visualization
	https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
 */

const int Maxsize = 100;
typedef struct {
	int age;
} DataType;
//顺序表的结构
typedef struct
{
	DataType data[Maxsize];
	int length;
} SeqList;

//单链表的结构
typedef struct node
{
	DataType data;
	struct node *next;
} Node, *LinkList;

//双向循环链表
typedef struct DBNode
{
	DataType type;
	struct DBNode *pre, *next;
} * dbpointer, DBLinkList;

typedef struct
{
	DataType datatype[Maxsize];
	int top;
} SeqStack;

typedef struct linkStackNode
{
	struct linkStackNode *next;
	DataType data;
} LinkStack;

//循环队列
typedef struct cycleQ
{
	DataType datas[Maxsize];
	int front, rear;
} CycleQueue;

//链式队列
typedef struct lkQueueNode{
	DataType data;
	struct lkQueueNode * next;
} LkQNode;

typedef struct {
	LkQNode * front, * rear;
}LinkQueue;
