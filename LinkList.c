#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int score;
    struct student *next;
} LinkList;
LinkList *creat(int n)
{
    LinkList *head, *node, *end;
    head = (LinkList *)malloc(sizeof(LinkList));
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = (LinkList *)malloc(sizeof(LinkList));
        scanf("%d", &node->score);
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}
void change(LinkList *list, int n)
{
    LinkList *t = list;
    int i = 0;
    while (i < n && t != NULL)
    {
        t = t->next;
        i++;
    }
    if (t != NULL)
    {
        printf("Please input\n");
        scanf("%d", &t->score);
    }
    else
    {
        printf("Unexit\n");
    }
}
void print(LinkList *list)
{
    LinkList *t = list;
    while (t->next != NULL)
    {
        t = t->next;
        printf("%d ", t->score);
    }
}
void delet(LinkList *list, int n)
{
    LinkList *t = list, *in;
    int i = 0;
    while (i < n && t->next != NULL)
    {
        in = t;
        t = t->next;
        i++;
    }
    if (t != NULL)
    {
        in->next = t->next;
        free(t);
    }
    else
    {
        printf("Unexit\n");
    }
}
void insert(LinkList *list, int n) // n代表插到第几个后面
{
    LinkList *t = list, *in;
    int i = 0;
    while (i < n && t->next != NULL)
    {
        t = t->next;
        i++;
    }
    if (t != NULL)
    {
        in = (LinkList *)malloc(sizeof(LinkList));
        printf("Please input\n");
        scanf("%d", &in->score);
        in->next = t->next;
        t->next = in;
    }
    else
    {
        printf("Unexit\n");
    }
}
int main()
{
    int number;
    scanf("%d", &number);
    LinkList *students = creat(number);
    int n;
    scanf("%d", &n);
    change(students, n);
    int m;
    scanf("%d", &m);
    delet(students, m);
    int q;
    scanf("%d", &q);
    insert(students, q);
    print(students);
    return 0;
}