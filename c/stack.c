#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    char name[20];
    float score;
    struct NODE * next;
};

struct STACK
{
    struct NODE * top;
    struct NODE * bottom;
};

struct NODE * Push(struct NODE *);
struct NODE * Pop(struct NODE *);
void GetTop (struct NODE *);
struct STACK * CreateStack(void);
int StackEmpty(struct STACK *);
void OutputStack(struct STACK *);
void DestroyStack(struct STACK *);

int main(void)
{
    int num;
    int ret;
    struct STACK * S;
    printf("Do you want to create STACK(Y/N):");
    while(1)
    {
        char ch;
        scanf("%c", &ch);
        while(getchar() != '\n');
        if (('Y' == ch) || ('y' == ch)) {
            S = CreateStack();
            break;
        } else if  (('N' == ch) || ('n' == ch)) {
            return 0;
        } else {
            printf("Please input (Y/N) again:");
        }
    }

    printf("1, Judge stack empty\n");
    printf("2, Push to stack\n");
    printf("3, Output stack\n");
    printf("4, GetTop stack\n");
    printf("5, Pop from stack\n");
    printf("6, Destory stack\n");
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
                ret = StackEmpty(S);
                if (ret == 1) {
                    puts("Stack is Empty");
                } else {
                    puts("Stack is not Empty");
                }
                break;
            }
        case 2:
            {
                S->top = Push(S->top);
                break;
            }
        case 3:
            {
                OutputStack(S);
                break;
            }
        case 4:
            {
                GetTop(S->top);
                break;
            }
        case 5:
            {
                if (!(StackEmpty(S))) {
                    S->top = Pop(S->top);
                    printf("Pop from stack succeed\n");
                } else {
                    printf("Pop from stack failed\n");
                }
                break;
            }
        case 6:
            {
                DestroyStack(S);
                puts("Stack destroied");
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
                break;
            }
        }
    }
    return 0;
}

struct NODE * Push(struct NODE *top)
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
    node->next = top;
    top = node;
    return top;
}

struct NODE *Pop(struct NODE *top)
{
    struct NODE *buf;
    buf = top;
    top = top->next;
    free(buf);
    buf = NULL;
    return top;
}

void GetTop(struct NODE *top)
{
    printf("1st: [name: %s, score: %.1f]\n", top->name, top->score);
}

struct STACK * CreateStack(void)
{
    struct STACK *S = malloc(sizeof*S);
    S->top = S->bottom = malloc(sizeof*S->top);
    if (S->top == NULL) {
        printf("malloc S->top failed\n");
        exit(-1);
    }
    S->top->next = NULL;
    return S;
}

int StackEmpty(struct STACK *S)
{
    if (S->top == S->bottom) {
        return 1;
    }
    return 0;
}

void OutputStack(struct STACK *S)
{
    struct NODE * move = S->top;
    while (S->bottom != move)
    {
        printf("[name: %s, score: %.1f]\n", move->name, move->score);
        move = move->next;
    }
}

void DestroyStack(struct STACK *S)
{
    while (!(StackEmpty(S)))
    {
        S->top=Pop(S->top);
    }
}
