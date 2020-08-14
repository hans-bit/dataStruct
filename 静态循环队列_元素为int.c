#include<stdio.h>
#include<stdlib.h>
/*
*
*    队列的英文是queue
*    队列有先进先出,从前面删除,从后面插入的属性. 
*    数据类型为int
*    循环静态队列,内部实现为数组. 
*    判断队满的情况用省略最后一个元素,使front和rear紧挨着的方法.
*    不添加len参数(即使我认为判断队列空,非空,满 的情况下,有len会更方便一点.) 
*     
*/


typedef struct qs{//queue struct
    unsigned int front;
    unsigned int rear;
    unsigned int maxCount; 
    int* data;
}Queue;


//队列初始化 返回0失败,1成功 
int queueInit(Queue* queue,unsigned int maxCount){
    queue->data=(int*)malloc( maxCount * sizeof(int) );
    queue->maxCount=maxCount;
    queue->front=0;
    queue->rear=0;
    return 1;
}

//判断队列是否为空,返回0为非空,1为空 
int getQueueIsEmpty(Queue* queue){
//满足front==rear 则队列为空
    if(queue->front==queue->rear)
        return 1;
    else
        return 0; 
}

//判断队列是否为满,0为没有满,1为已满 
int getQueueIsFull(Queue* queue){
//front紧挨着rear,且rear在front后面(此时数组是一个标量,并没有前后的方向数据,但是可以用数学表达式来表示)
//满足(rear+1)%maxCount==front,则队列已满,也就是最大队列元素个数为 MaxCount-1 
    if( (( (queue->rear) +1) % queue->maxCount) == queue->front)
        return 1;
    else
        return 0;
}


//队列 入队,返回0失败,1成功,参数一为目标队列,参数二为入队参数 
int queuePush(Queue* queue,int num){
    if(!getQueueIsFull(queue)){//队列不满则可以进行入队操作 
        //入队则rear加1(循环式的+1哦)
        //由于rear永远指向最后一个元素的下一个位置,所以直接把这个位置填充元素,再使rear+1指向下一元素. 
        queue->data[queue->rear]=num;
        queue->rear=( (queue->rear) +1) % queue->maxCount;
        return 1;
    }
    return 0;
}

//队列 出队,返回0失败,1成功,参数一为目标队列,参数二为出队参数存储位置 
int queuePop(Queue* queue,int* num){
    if(!getQueueIsEmpty(queue)){//队列非空才可以进行出队操作. 
        //出队则front加1(循环式的+1哦)
        *num=queue->data[queue->front];
        queue->front=( (queue->front) + 1) % queue->maxCount;
        return 1;
    }
    return 0;
}

//获取队列已保存的元素个数. 
unsigned int getQueueCount(Queue* queue){
    //难的推导了.上公式:（rear-front+maxcount )mod maxcount
    return (queue->rear - queue->front + queue->maxCount) % queue->maxCount;
}

//以数组的方式返回队列中所有的元素.若队列为空则返回NULL 
int* queueToArray(Queue* queue){
    //一个int最多占10字符(2147483647)
    if(getQueueIsEmpty(queue))
        return NULL;
    int frontTmp=queue->front;  //从这一段到结尾都必须是原子操作. 
    int count=getQueueCount(queue);
    int* num=(int*)malloc(sizeof(int)*count);
    for(int i=0;i<count;i++){
        queuePop(queue,&num[i]);
    }
    queue->front=frontTmp;
    return num; 
}

int main(void){
    Queue queue;
    queueInit(&queue,6);//最大可保存元素为maxcount-1个. 
    printf("%d\n",getQueueIsEmpty(&queue));//预测结果:1 
    
    queuePush(&queue,10);
    queuePush(&queue,11);
    queuePush(&queue,12);
    queuePush(&queue,13);
    queuePush(&queue,14);
    printf("%d\n",getQueueCount(&queue));//5
    
    printf("%d\n",getQueueIsFull(&queue));//1
    
    int tmp;
    queuePop(&queue,&tmp);
    queuePop(&queue,&tmp);
    printf("%d\n",tmp);//11
    printf("%d\n",getQueueCount(&queue));//2
    printf("%d\n",getQueueIsFull(&queue));//0
    
    queuePush(&queue,100);
    int* num=queueToArray(&queue);
    int count=getQueueCount(&queue);
    for(int i=0;i<count;i++){
        printf("%d ",num[i]);
    }
    
    return 0;
}
