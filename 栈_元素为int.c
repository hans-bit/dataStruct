#include<stdio.h>
#include<stdlib.h>
/*
*   ��int����+ջ�� ����intջ��ջ�ռ�������±�Ϊ0��λ�ÿ�ʼ,ջ��Ĭ��Ϊ-1��
*   ȫ�ֶ����ж��쳣
*/

struct Stack{
	int* arr;//ջ�ռ�
	int sp;//ջ��
};

//����һ��ջ,ָ��ջ���������,����ʼ��ջ��ָ��ָ��ջ��(-1). 
struct Stack* stack_init(unsigned n){
	struct Stack* stack;
	stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->arr=(int*)malloc(n * sizeof(int));
	stack->sp=-1;
	return stack;
}

//��һ��ֵѹ��ջ��. 
void stack_push(struct Stack* stack,int value){
	stack->sp++; 
	stack->arr[stack->sp]=value;

} 
//��һ��ֵ��ջ������.
int stack_pop(struct Stack* stack){
    int value=stack->arr[stack->sp];
    stack->sp--;
	return value;
}

//����ջ��Ԫ�ظ���. 
unsigned stack_count(struct Stack* stack){
	return (stack->sp)+1;
}

//�ӵ������ջ��Ԫ�ص�ֵ. 
void stack_out(struct Stack* stack){
	for(int i=0; i < stack_count(stack) ; i++)
	{
		printf("%d:%d ",i,stack->arr[i]);
	}	
	printf("\n");
}

int main(){
	printf("����--------------------------------------------\n");
	struct Stack* stack=stack_init(5);
	printf("����--------------------------------------------\n");
	printf("%u\n",stack_count(stack)); 
	printf("ѹ��ջ--------------------------------------------\n");
	stack_push(stack,1);
	stack_push(stack,2);
    stack_push(stack,3);
	stack_push(stack,4);
	stack_push(stack,5);
	printf("���--------------------------------------------\n");
	stack_out(stack);
	printf("����ջ--------------------------------------------\n");
	printf("%d\n",stack_pop(stack));
	printf("%d\n",stack_pop(stack));
	printf("���--------------------------------------------\n");
	stack_out(stack);
	printf("����--------------------------------------------\n");
	printf("%u\n",stack_count(stack)); 
	
	system("pause"); 
	return 0;
}
