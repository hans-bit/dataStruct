#include<stdio.h>
#include<stdlib.h>
/*
*   用int数组+栈顶 制作int栈，栈空间从数组下标为0的位置开始,栈底默认为-1。
*   全局都不判断异常
*/

struct Stack{
	int* arr;//栈空间
	int sp;//栈顶
};

//创建一个栈,指定栈的最大容量,并初始化栈顶指针指向栈底(-1). 
struct Stack* stack_init(unsigned n){
	struct Stack* stack;
	stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->arr=(int*)malloc(n * sizeof(int));
	stack->sp=-1;
	return stack;
}

//将一个值压入栈顶. 
void stack_push(struct Stack* stack,int value){
	stack->sp++; 
	stack->arr[stack->sp]=value;

} 
//将一个值从栈顶弹出.
int stack_pop(struct Stack* stack){
    int value=stack->arr[stack->sp];
    stack->sp--;
	return value;
}

//返回栈的元素个数. 
unsigned stack_count(struct Stack* stack){
	return (stack->sp)+1;
}

//从底向顶输出栈内元素的值. 
void stack_out(struct Stack* stack){
	for(int i=0; i < stack_count(stack) ; i++)
	{
		printf("%d:%d ",i,stack->arr[i]);
	}	
	printf("\n");
}

int main(){
	printf("创建--------------------------------------------\n");
	struct Stack* stack=stack_init(5);
	printf("计数--------------------------------------------\n");
	printf("%u\n",stack_count(stack)); 
	printf("压入栈--------------------------------------------\n");
	stack_push(stack,1);
	stack_push(stack,2);
    stack_push(stack,3);
	stack_push(stack,4);
	stack_push(stack,5);
	printf("输出--------------------------------------------\n");
	stack_out(stack);
	printf("弹出栈--------------------------------------------\n");
	printf("%d\n",stack_pop(stack));
	printf("%d\n",stack_pop(stack));
	printf("输出--------------------------------------------\n");
	stack_out(stack);
	printf("计数--------------------------------------------\n");
	printf("%u\n",stack_count(stack)); 
	
	system("pause"); 
	return 0;
}
