#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE * next;
};

struct NODE * CreateLink(void);
void InsertLink(struct NODE * head);
void DeleteLink(struct NODE * head);
void UpdateLink(struct NODE * head);
int SearchLink(struct NODE * head);
int OutputLink(struct NODE * head);
void DestroyLink(struct NODE * head);

int main(void)
{
    struct NODE * head;
    head = CreateLink();
    InsertLink(head);
    DeleteLink(head);
    UpdateLink(head);
    OutputLink(head);
    SearchLink(head);
    DestroyLink(head);
    return 0;
}

struct NODE * CreateLink(void)
{
    int len;
    int i;
    int val;
    struct NODE * head = malloc(sizeof*head);
    struct NODE * move = head;
    move->next = NULL;
    if (NULL == head)
    {
        printf("malloc head failed, system exit!\n");
        exit(-1);
    }
    printf("Please input the link number you want to create: len = ");
    scanf("%d", &len);
    for (i=0; i<len; ++i)
    {
        struct NODE * fresh = malloc(sizeof*fresh);
        if (NULL == fresh)
        {
            printf("malloc fresh failed, system exit!\n");
            exit(-1);
        }
        printf("Please input the value of the %d NODE: ", i+1);
        scanf("%d", &val);
        fresh->data = val;
        fresh->next = NULL;
        move->next = fresh;
        move = move->next; //指针指向下一个的起始位置，如果没有该行，链表将永远只有两个节点块（头节点+尾节点）
    }
    return head;
}

void InsertLink(struct NODE * head)
{
    int inode;
    int i;
    int val;
    struct NODE * move = head;
    printf("Please input the inode you want to insert: ");
    scanf("%d", &inode);
    for (i=1; i<inode; ++i)
    {
        if (NULL == move->next)
        {
            printf("inode: %d is disable\n", inode);
            //return head;
            return;
        }
        move = move->next;
    }
    
    struct NODE * fresh = malloc(sizeof*fresh);
    if (NULL == fresh)
    {
        printf("malloc fresh failed, system exit!\n");
        //return head;
        return;
    }
    printf("Please input the value of the %d NODE: ", inode);
    scanf("%d", &val);
    fresh->data = val;
    fresh->next = move->next;
    move->next = fresh;
    //return head;
    return;
}

void DeleteLink(struct NODE * head)
{
    int inode;
    int i;
    struct NODE * move = head;
    printf("Please input the inode you want to delete: ");
    scanf("%d", &inode);
    for (i=1; i<inode; ++i)
    {
        if (NULL == move->next)
        {
            printf("inode: %d is disable\n", inode);
            //return head;
            return;
        }
        move = move->next;
    }
    
    move->next = move->next->next;
    //return head;
    return;
}

void UpdateLink(struct NODE * head)
{
    int inode;
    int i;
    int val;
    struct NODE * move = head;
    move = move->next;
    printf("Please input the inode you want to update: ");
    scanf("%d", &inode);
    for (i=1; i<inode; ++i)
    {
        if (NULL == move->next)
        {
            printf("inode: %d is disable\n", inode);
            //return head;
            return;
        }
        move = move->next;
    }
    
    printf("Please input the value of the %d NODE: ", inode);
    scanf("%d", &val);
    move->data = val;
    //return head;
    return;
}

int SearchLink(struct NODE * head)
{
    int i=1;
    int val;
    struct NODE * move = head;
    move = move->next;
    printf("Please input the value you want to search: ");
    scanf("%d", &val);
    while (move != NULL)
    {
        if (move->data == val)
        {
            printf("value: %d search succeed. the inode = %d\n", val, i);
            return 0;
        }
        i++;
        move = move->next;
    }
    printf("value: %d search failed.\n", val);
    return 1;
}

int OutputLink(struct NODE * head)
{
    struct NODE * move = head;
    move = move->next;
    printf("Link as below:\n");
    while (move != NULL)
    {
        printf("%d ", move->data);
        move = move->next;
    }
    printf("\n");
    return 0;
}

void DestroyLink(struct NODE * head)
{
    struct NODE * save = head;
    printf("Destroy Link begging\n");
    while (head != NULL)
    {
        save = head->next;
        free(head);
        head = save;
    }
    printf("Destroy Link has been done.\n");
    return;
}
