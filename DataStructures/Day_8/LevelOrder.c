#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXQSIZE 100
typedef int Status;

// 二叉树节点结构定义
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 栈结构定义
typedef struct {
    BiTree *base;  // 栈底指针
    BiTree *top;   // 栈顶指针
    int size;      // 栈容量
} Stack;

// 初始化栈
Status InitStack(Stack *S, int size) {
    S->base = (BiTree *)malloc(sizeof(BiTree) * size);
    if (!S->base) return ERROR;
    S->top = S->base;
    S->size = size;
    return OK;
}

// 判断栈是否为空
Status StackEmpty(Stack S) {
    return S.top == S.base;
}

// 入栈操作
Status Push(Stack *S, BiTree e) {
    if (S->top - S->base >= S->size) return ERROR;
    *(S->top) = e;
    S->top++;
    return OK;
}

// 出栈操作
Status Pop(Stack *S, BiTree *e) {
    if (StackEmpty(*S)) return ERROR;
    S->top--;
    *e = *(S->top);
    return OK;
}

// 中序遍历函数
Status InOrderTraverse(BiTree T) {
    Stack S;
    BiTree p, q;
    InitStack(&S, 100);  // 初始化栈容量为100
    p = T;
    
    while (p || !StackEmpty(S)) {
        if (p) {
            Push(&S, p);
            p = p->lchild;
        } else {
            Pop(&S, &q);
            printf("%c ", q->data);
            p = q->rchild;
        }
    }
    return OK;
}


//层次遍历
// 初始化队列
// 队列结构定义
typedef struct {
    BiTree *base;  // 存储空间基址
    int front;     // 队头指针
    int rear;      // 队尾指针
} Queue;

// 判断队列是否为空
Status QueueEmpty(Queue Q) {
    return Q.front == Q.rear;
}
Status InitQueue(Queue *Q) {
    Q->base = (BiTree *)malloc(MAXQSIZE * sizeof(BiTree));
    if (!Q->base) return ERROR;
    Q->front = Q->rear = 0;
    return OK;
}

// 入队操作
Status EnQueue(Queue *Q, BiTree e) {
    if ((Q->rear + 1) % MAXQSIZE == Q->front)  // 队满
        return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return OK;
}

// 出队操作
Status DeQueue(Queue *Q, BiTree *e) {
    if (QueueEmpty(*Q))  // 队空判断
        return ERROR;
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return OK;
}

// 层次遍历（使用队列）
void LevelOrder(BiTree T) {
    Queue Q;
    InitQueue(&Q);
    EnQueue(&Q, T);
    
    while (!QueueEmpty(Q)) {  // 队列判空
        BiTree p;
        DeQueue(&Q, &p);
        printf("%c ", p->data);
        if (p->lchild) EnQueue(&Q, p->lchild);
        if (p->rchild) EnQueue(&Q, p->rchild);
    }
}

// 创建测试用二叉树
BiTree CreateTestTree() {
    // 构建如下二叉树：
    //      A
    //    /   \
    //   B     C
    //  / \   /
    // D   E F
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = 'A';
    
    root->lchild = (BiTree)malloc(sizeof(BiTNode));
    root->lchild->data = 'B';
    
    root->rchild = (BiTree)malloc(sizeof(BiTNode));
    root->rchild->data = 'C';
    
    root->lchild->lchild = (BiTree)malloc(sizeof(BiTNode));
    root->lchild->lchild->data = 'D';
    root->lchild->lchild->lchild = root->lchild->lchild->rchild = NULL;
    
    root->lchild->rchild = (BiTree)malloc(sizeof(BiTNode));
    root->lchild->rchild->data = 'E';
    root->lchild->rchild->lchild = root->lchild->rchild->rchild = NULL;
    
    root->rchild->lchild = (BiTree)malloc(sizeof(BiTNode));
    root->rchild->lchild->data = 'F';
    root->rchild->lchild->lchild = root->rchild->lchild->rchild = NULL;
    
    root->rchild->rchild = NULL;
    return root;
}

int main() {
    BiTree T = CreateTestTree();
    printf("Inorder Traversal: ");
    InOrderTraverse(T);  // 输出: D B E A F C
    return 0;
}//AI