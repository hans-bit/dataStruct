#include<stdio.h>
#include<stdlib.h>
/*
*
*    ���е�Ӣ����queue
*    �������Ƚ��ȳ�,��ǰ��ɾ��,�Ӻ�����������. 
*    ��������Ϊint
*    ѭ����̬����,�ڲ�ʵ��Ϊ����. 
*    �ж϶����������ʡ�����һ��Ԫ��,ʹfront��rear�����ŵķ���.
*    �����len����(��ʹ����Ϊ�ж϶��п�,�ǿ�,�� �������,��len�������һ��.) 
*     
*/


typedef struct qs{//queue struct
    unsigned int front;
    unsigned int rear;
    unsigned int maxCount; 
    int* data;
}Queue;


//���г�ʼ�� ����0ʧ��,1�ɹ� 
int queueInit(Queue* queue,unsigned int maxCount){
    queue->data=(int*)malloc( maxCount * sizeof(int) );
    queue->maxCount=maxCount;
    queue->front=0;
    queue->rear=0;
    return 1;
}

//�ж϶����Ƿ�Ϊ��,����0Ϊ�ǿ�,1Ϊ�� 
int getQueueIsEmpty(Queue* queue){
//����front==rear �����Ϊ��
    if(queue->front==queue->rear)
        return 1;
    else
        return 0; 
}

//�ж϶����Ƿ�Ϊ��,0Ϊû����,1Ϊ���� 
int getQueueIsFull(Queue* queue){
//front������rear,��rear��front����(��ʱ������һ������,��û��ǰ��ķ�������,���ǿ�������ѧ���ʽ����ʾ)
//����(rear+1)%maxCount==front,���������,Ҳ����������Ԫ�ظ���Ϊ MaxCount-1 
    if( (( (queue->rear) +1) % queue->maxCount) == queue->front)
        return 1;
    else
        return 0;
}


//���� ���,����0ʧ��,1�ɹ�,����һΪĿ�����,������Ϊ��Ӳ��� 
int queuePush(Queue* queue,int num){
    if(!getQueueIsFull(queue)){//���в�������Խ�����Ӳ��� 
        //�����rear��1(ѭ��ʽ��+1Ŷ)
        //����rear��Զָ�����һ��Ԫ�ص���һ��λ��,����ֱ�Ӱ����λ�����Ԫ��,��ʹrear+1ָ����һԪ��. 
        queue->data[queue->rear]=num;
        queue->rear=( (queue->rear) +1) % queue->maxCount;
        return 1;
    }
    return 0;
}

//���� ����,����0ʧ��,1�ɹ�,����һΪĿ�����,������Ϊ���Ӳ����洢λ�� 
int queuePop(Queue* queue,int* num){
    if(!getQueueIsEmpty(queue)){//���зǿղſ��Խ��г��Ӳ���. 
        //������front��1(ѭ��ʽ��+1Ŷ)
        *num=queue->data[queue->front];
        queue->front=( (queue->front) + 1) % queue->maxCount;
        return 1;
    }
    return 0;
}

//��ȡ�����ѱ����Ԫ�ظ���. 
unsigned int getQueueCount(Queue* queue){
    //�ѵ��Ƶ���.�Ϲ�ʽ:��rear-front+maxcount )mod maxcount
    return (queue->rear - queue->front + queue->maxCount) % queue->maxCount;
}

//������ķ�ʽ���ض��������е�Ԫ��.������Ϊ���򷵻�NULL 
int* queueToArray(Queue* queue){
    //һ��int���ռ10�ַ�(2147483647)
    if(getQueueIsEmpty(queue))
        return NULL;
    int frontTmp=queue->front;  //����һ�ε���β��������ԭ�Ӳ���. 
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
    queueInit(&queue,6);//���ɱ���Ԫ��Ϊmaxcount-1��. 
    printf("%d\n",getQueueIsEmpty(&queue));//Ԥ����:1 
    
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
