#include <stdio.h>
#include <malloc.h>

typedef int SElemTYpe;/*Ԫ�����ͣ���ʱ�����int*/

#define MAXSIZE 256
/**************************
 *ջ���ݽṹ
 ***************************/
typedef struct{
	SElemTYpe data[MAXSIZE];
	int top;
}SqStack;
/*******************************
*��ջ
����ڲ�����ջָ�룬��ջԪ��
*******************************/
int Push(SqStack *S,SElemTYpe e)
{
	if(S->top == MAXSIZE-1)
		return -1;
	S->top++;
	S->data[S->top]=e;

	return 0;
}

/*******************************
 *��ջ
 *��ڲ�����ջָ�룬��ջԪ��ָ��
 ******************************/
int Pop(SqStack *S,SElemTYpe *e)
{
	if(S->top == -1)
		return -1;
	*e=S->data[S->top];
	S->top--;

	return 0;
}

/************************
 *��ʼ��ջ
 *��ڲ�����ջָ��
 ************************/
int InitStack(SqStack *S)
{
	S->top = 0;
	return 0;
}

int main(void)
{
	SElemTYpe a[5]={1,2,3,4,5};
	SqStack *S;
	
	S = (SqStack *)malloc(sizeof(SqStack));
	if(NULL == S){
		printf("malloc error!\n");
		return -1;
	}

	int reval;
	InitStack(S);
	reval = Push(S,a[4]);
	if(reval<0){
		printf("PUSH error!\n");
		return -1;
	}
	printf("push data:%d\n",S->data[S->top]);

	int b=1;
	reval = Pop(S,&b);
	if(reval<0){
		printf("Pop error \n");
		return -1;
	}
	printf("POP data:%d\n",b);

	free(S);
	return 0;
}
