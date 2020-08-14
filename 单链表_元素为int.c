#include<stdio.h>
#include<stdlib.h>
/*先有实现,才有后续优化,不判断异常*/
struct group{
	int value;
	struct group* next;
};
//初始化一个链表 
struct group* list_init(unsigned int n/*指定链表初始长度*/){
	struct group *head,*tmp,*current;
	head=NULL;
	printf("输入初始化的%u个值:",n);
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

//在链表末尾添加元素. 
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

//在链表指定索引(从0开始,在索引元素后面插入)处的后面插入某元素 
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

//删除链表指定索引(索引元素从0开始)处的值. 
void rm(struct group* list_head,unsigned int index){
	//x-1 x x+1 x代指要删除的索引. x-1是前一个元素索引 x+1是后一个元素索引. 
	if(index==0)//删除第一个元素. (将第二个元素赋给第一个元素.如果只有一个元素,则直接free释放)
	{
		if(list_head->next != NULL)//元素大于等于两个 
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
		current=current->next;//指向x-1. 
	}
	//删除x处的元素,并将 x-1处的next指向本来的x+1(跳过了x索引处的元素) 
	struct group* tmp=current->next;//tmp指向x  将要即将释放的内存空间地址备份. 
	if(current->next->next!=NULL)//符合则删除的不是最后一个元素.不符合则表明删除最后一个元素,就不用再连接两个分开的元素. 
	{
		current->next=current->next->next;//current->next是x的索引,current->next->next是x+1的索引 
	}
	else
	{
		current->next=NULL;
	} 
	free(tmp); //释放此处链表的空间(删除x处的元素). 
}

//打印链表中的值. 
void outList(struct group* list_head/*指定输出链表的头指针*/){
	struct group* current=list_head;
	int i=0;
	printf("{");
	while(current->next != NULL)//打印一次 
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
	printf("创建----------------------------------\n");
	struct group* test=list_init(10);
	
	printf("输出----------------------------------\n");
	outList(test);
	
	printf("插入----------------------------------\n");
	insert(test,0,117);
	outList(test);
	insert(test,10,117);
	outList(test);
	insert(test,5,117);
	outList(test);
	
	printf("末尾添加----------------------------------\n");
	append(test,16);
	outList(test);
	
	printf("删除----------------------------------\n");
	rm(test,0);
	outList(test);
	rm(test,12); 
	outList(test);
	rm(test,1); 
	outList(test);
	
	printf("计数----------------------------------\n");
	printf("%u\n",count(test));
	
	system("pause");
	return 0;
} 
