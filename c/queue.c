#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    char name[20];
    float score;
    struct NODE * next;
};

struct QUEUE
{
    struct NODE * front;
    struct NODE * rear;
};

struct NODE * EnQueue(struct NODE *);
struct QUEUE * DeQueue(struct QUEUE *);
void GetTop (struct NODE *);
struct QUEUE * CreateQueue(void);
int QueueEmpty(struct QUEUE *);
void OutputQueue(struct QUEUE *);
void DestroyQueue(struct QUEUE *);

int main(void)
{
    int num;
    int ret;
    struct QUEUE *Q;
    printf("Do you want to create QUEUE(Y/N):");
    while(1)
    {
        char ch;
        scanf("%c", &ch);
        while(getchar() != '\n');
        if (('Y' == ch) || ('y' == ch)) {
            Q = CreateQueue();
            break;
        } else if  (('N' == ch) || ('n' == ch)) {
            return 0;
        } else {
            printf("Please input (Y/N) again:");
        }
    }

    printf("1, Judge queue empty\n");
    printf("2, Push to queue\n");
    printf("3, Output queue\n");
    printf("4, GetTop queue\n");
    printf("5, Pop from queue\n");
    printf("6, Destory queue\n");
    printf("7, exit\n");
    while(1)
    {
        num = -1;
        printf("Please input the step number: ");
        scanf("%d", &num);
        while(getchar() != '\n');
        switch(num)
        {
        case 1:
            {
                ret = QueueEmpty(Q);
                if (ret == 1) {
                    puts("Queue is Empty");
                } else {
                    puts("Queue is not Empty");
                }
                break;
            }
        case 2:
            {
                Q->rear = EnQueue(Q->rear);
                break;
            }
        case 3:
            {
                OutputQueue(Q);
                break;
            }
        case 4:
            {
                GetTop(Q->front);
                break;
            }
        case 5:
            {
                if (Q->front != Q->rear) {
                    Q = DeQueue(Q);
                    printf("Pop from queue succeed\n");
                } else {
                    printf("Pop from queue failed\n");
                }
                break;
            }
        case 6:
            {
                DestroyQueue(Q);
                free(Q->front);
                Q->front = NULL;
                puts("queue destroied");
                break;
            }
        case 7:
            {
                return 0;
                break;
            }
        default:
            {
                puts("Unsupport step, Please input again!");
            }
        }
    }
    return 0;
}

struct NODE * EnQueue(struct NODE *rear)
{
    struct NODE * node = malloc(sizeof * node);
    if (node == NULL) {
        printf("malloc node failed\n");
        exit(-1);
    }
    node->score = -123456;
    while(1)
    {
        printf("input the name and score of student: ");
        scanf("%s%f", node->name, &(node->score));
        while(getchar() != '\n');
        if (node->score == -123456) {
            printf("score not support, please input again\n");
        } else {
            break;
        }
    }
    node->next = NULL;
    rear->next = node;
    rear = node;
    return rear;
}

struct QUEUE * DeQueue(struct QUEUE *Q)
{
    struct NODE *buf;
    if (Q->front->next == Q->rear) {
        Q->rear = Q->front;
    }
    buf = Q->front->next;
    Q->front->next = buf->next;
    free(buf);
    buf = NULL;
    return Q;
}

void GetTop(struct NODE *top)
{
    printf("1st: [name: %s, score: %.1f]\n", top->next->name, top->next->score);
}

struct QUEUE * CreateQueue(void)
{
    struct QUEUE *Q = malloc(sizeof*Q);
    Q->front = Q->rear = malloc(sizeof*Q->rear);
    if (Q->front == NULL) {
        printf("malloc Q->front failed\n");
        exit(-1);
    }
    Q->front->next = NULL;
    return Q;
}

int QueueEmpty(struct QUEUE *Q)
{
    if (Q->front == Q->rear) {
        return 1;
    }
    return 0;
}

void OutputQueue(struct QUEUE *Q)
{
    if (Q->front != NULL) {
        struct NODE * move = Q->front->next;
        while (move != NULL)
        {
            printf("[name: %s, score: %.1f]\n", move->name, move->score);
            move = move->next;
        }
    } else {
        printf("The queue is not exit\n");
    }
}

void DestroyQueue(struct QUEUE *Q)
{
    while (Q->front != Q->rear)
    {
        Q=DeQueue(Q);
    }
}
