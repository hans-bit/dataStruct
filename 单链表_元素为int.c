#include<stdio.h>
#include<stdlib.h>
/*����ʵ��,���к����Ż�,���ж��쳣*/
struct group{
	int value;
	struct group* next;
};
//��ʼ��һ������ 
struct group* list_init(unsigned int n/*ָ�������ʼ����*/){
	struct group *head,*tmp,*current;
	head=NULL;
	printf("�����ʼ����%u��ֵ:",n);
	for(unsigned int i=0;i<n;i++)
	{
		tmp=(struct group*)malloc(sizeof(struct group));
		scanf("%d",&(tmp->value));
		tmp->next=NULL;
		if(head==NULL)
		{
			head=tmp;
		}
		else
		{
			current->next=tmp;
		}
		current=tmp;
	}
	return head;
}

//������ĩβ���Ԫ��. 
void append(struct group* list_head,int value){
	while(list_head->next!=NULL)
	{
		list_head=list_head->next;	
	}
	struct group* tmp=(struct group*)malloc(sizeof(struct group));
	tmp->value=value;
	tmp->next=NULL;
	list_head->next=tmp;
}

//������ָ������(��0��ʼ,������Ԫ�غ������)���ĺ������ĳԪ�� 
void insert(struct group* list_head,unsigned index,int value){
	struct group* current=list_head;
	for(unsigned int i=0;i<index;i++)
	{
		current=current->next;
	}
	struct group* tmp=(struct group*)malloc(sizeof(struct group));
	tmp->value=value;
	tmp->next=current->next;
	current->next=tmp;
}

//ɾ������ָ������(����Ԫ�ش�0��ʼ)����ֵ. 
void rm(struct group* list_head,unsigned int index){
	//x-1 x x+1 x��ָҪɾ��������. x-1��ǰһ��Ԫ������ x+1�Ǻ�һ��Ԫ������. 
	if(index==0)//ɾ����һ��Ԫ��. (���ڶ���Ԫ�ظ�����һ��Ԫ��.���ֻ��һ��Ԫ��,��ֱ��free�ͷ�)
	{
		if(list_head->next != NULL)//Ԫ�ش��ڵ������� 
		{
			list_head->value = list_head->next->value;
			list_head->next = list_head->next->next;
		}
		else
		{
			free(list_head);
		}
		return;
	}
	struct group* current=list_head;
	for(unsigned int i=0;i < index-1;i++)
	{
		current=current->next;//ָ��x-1. 
	}
	//ɾ��x����Ԫ��,���� x-1����nextָ������x+1(������x��������Ԫ��) 
	struct group* tmp=current->next;//tmpָ��x  ��Ҫ�����ͷŵ��ڴ�ռ��ַ����. 
	if(current->next->next!=NULL)//������ɾ���Ĳ������һ��Ԫ��.�����������ɾ�����һ��Ԫ��,�Ͳ��������������ֿ���Ԫ��. 
	{
		current->next=current->next->next;//current->next��x������,current->next->next��x+1������ 
	}
	else
	{
		current->next=NULL;
	} 
	free(tmp); //�ͷŴ˴�����Ŀռ�(ɾ��x����Ԫ��). 
}

//��ӡ�����е�ֵ. 
void outList(struct group* list_head/*ָ����������ͷָ��*/){
	struct group* current=list_head;
	int i=0;
	printf("{");
	while(current->next != NULL)//��ӡһ�� 
	{
		printf("%d : %d ,",i,current->value);
		current=current->next;
		i++;
	}
	printf(" %d : %d",i,current->value);
	printf("}\n");
}

unsigned count(struct group* list_head){
	struct group* current=list_head;
	unsigned int len=1;
	if(current==NULL)
	{
		return 0;
	}

	while(current->next != NULL)
	{
		len++;
		current=current->next;
	}
	return len;
}

int main(void){
	printf("����----------------------------------\n");
	struct group* test=list_init(10);
	
	printf("���----------------------------------\n");
	outList(test);
	
	printf("����----------------------------------\n");
	insert(test,0,117);
	outList(test);
	insert(test,10,117);
	outList(test);
	insert(test,5,117);
	outList(test);
	
	printf("ĩβ���----------------------------------\n");
	append(test,16);
	outList(test);
	
	printf("ɾ��----------------------------------\n");
	rm(test,0);
	outList(test);
	rm(test,12); 
	outList(test);
	rm(test,1); 
	outList(test);
	
	printf("����----------------------------------\n");
	printf("%u\n",count(test));
	
	system("pause");
	return 0;
} 
