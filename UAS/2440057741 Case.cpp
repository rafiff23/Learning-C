#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
  char name[35];
  char cond[35];
  int rate;
  Node *next, *prev;
} * head, *tail;
Node *createNode(char name[], char cond[], int rate)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  strcpy(newNode->cond, cond);
  newNode->rate = rate;
  newNode->next = newNode->prev = NULL;
  return newNode;
}
int calcRate(char cond[])
{
  if (strcmp(cond, "Critical") == 0)
  {
    return 1;
  }
  else if (strcmp(cond, "Serious") == 0)
  {
    return 2;
  }
  else if (strcmp(cond, "Fair") == 0)
  {
    return 3;
  }
  else if (strcmp(cond, "Good") == 0)
  {
    return 4;
  }
}
void pushHead(char name[], char cond[], int rate)
{
  Node *temp = createNode(name, cond, rate);
  if (!head)
  {
    head = tail = temp;
  }
  else
  {
    head->prev = temp;
    temp->next = head;
    head = temp;
  }
}
void pushTail(char name[], char cond[], int rate)
{
  Node *temp = createNode(name, cond, rate);
  if (!head)
  {
    head = tail = temp;
  }
  else
  {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}
void pushMid(char name[], char cond[], int rate)
{
  Node *temp = createNode(name, cond, rate);
  if (!head)
  {
    head = tail = temp;
  }
  else if (rate < head->rate)
  {
    pushHead(name, cond, rate);
  }
  else if (rate >= tail->rate)
  {
    pushTail(name, cond, rate);
  }
  else
  {
    Node *curr = head;
    while (rate >= curr->rate)
    {
      curr = curr->next;
    }
    temp->prev = curr->prev;
    temp->next = curr;
    curr->prev->next = temp;
    curr->prev = temp;
  }
}
void popHead()
{
  if (!head)
  {
    return;
  }
  else if (head == tail)
  {
    head == tail == NULL;
    free(head);
  }
  else
  {
    Node *temp = head->next;
    head->next = temp->prev = NULL;
    free(head);
    head = temp;
  }
}
void traverse()
{
  printf("Waiting Room: ");
  if (!head)
  {
    printf("None\n");
  }
  else
  {
    Node *curr = head;
    int flag = 0;
    while (curr)
    {
      if (flag == 0)
      {
        printf("%s", curr->name);
      }
      else
      {
        printf(", %s", curr->name);
      }
      curr = curr->next;
      flag = 1;
    }
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    char cmd[10], name[35], cond[35];
    scanf("%s", cmd);
    getchar();
    if (strcmp(cmd, "ADD") == 0)
    {
      scanf("%s %s", name, cond);
      pushMid(name, cond, calcRate(cond));
    }
    else if (strcmp(cmd, "CALL") == 0)
    {
      if (head->rate == 1)
      {
        printf("%s is in the Emergency Room\n", head->name);
      }
      else if (head->rate == 2)
      {
        printf("%s is in the Examination Room\n", head->name);
      }
      else
      {
        printf("%s is in the Consultation Room\n", head->name);
      }
      popHead();
    }
  }
  traverse();
  return 0;
}
