#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  目的：练习C语言基本的知识点
  内容：主要包括1.交换数据函数输入输出 2.算法中的冒泡排序 3.递归调用 4.数据结构中的链表添加遍历 5.文件写入 6.函数指针和回调
  7.结构枚举宏定义 8字符串库函数的使用
  面试相关：与零值的比较 memcpy的使用 位操作 函数返回指针(不能局部除非static) typedef  数组退化 位操作
  */

#define NUM1 20
#define NUM2 40

//宏定义测试
#define MIN(a,b) ((a)<(b)?(a):(b))

//-----------------------------------------------------------------链表练习
static int count = 0;

struct node {
    int a;
    struct node* next;
};

struct node* head = NULL;
struct node* end = NULL;

void addlist(int a) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->a = a;
    newnode->next =NULL;
    if(head == NULL) {
        head = newnode;
        end = newnode;
    }
    else {
        end->next = newnode;
        end = newnode;
    }
}

void scanlist() {
    struct node* tmp = head;
    while(tmp!=NULL) {
        printf("in list %d\n",tmp->a);
        tmp = tmp->next;
    }
}

void freelist(){
    struct node *tmp = head;
    while(tmp!=NULL) {
        struct node *fp = tmp;
        tmp = tmp->next;
        printf("in list free %d\n",fp->a);
        free(fp);
    }
}
//----------------------------------------------------------------------------

//排序练习---------------------------------------------------------------------
void swap1(int *a,int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;

    count++;
    printf("count is %d\n",count);
}

void sort1(int *arr,int lengh) {
    int i=lengh-1;
    for(;i>0;i--) {
        int j=0;
        for(;j<i;j++) {
            if(arr[j]>arr[j+1]) {
                swap1(&arr[j],&arr[j+1]);
            }
        }
    }
}

void sort2(int *arr,int lengh) {
    int i=lengh-1;
    for(;i>0;i--) {
        int j=0;
        for(;j<i;j++) {
            if(arr[j]<arr[j+1]) {
                swap1(&arr[j],&arr[j+1]);
            }
        }
    }
}

int* sort3(int *arr,int lengh) {
    int i=lengh-1;
    for(;i>0;i--) {
        int j=0;
        for(;j<i;j++) {
            if(arr[j]<arr[j+1]) {
                swap1(&arr[j],&arr[j+1]);
            }
        }
    }
    return arr;
}
//-----------------------------------------------------------------

//文件读写----------------------------------------------------------
void writeText(int *aar) {
FILE *fl;
fl = fopen("a.txt","a");

int i =0;
fputs("print start\n",fl);
for(;i<6;i++) {
    fprintf(fl,"arr[%d] = %d\n",i,aar[i]);
}
fputs("print end\n",fl);
fclose(fl);
}
//------------------------------------------------------------------

//递归练习-----------------------------------------------------------
int digui(int a) {
    if(a==1)
        return 1;
    return a*digui(a-1);
}
//------------------------------------------------------------------

//枚举---------------------------------------------------------------
typedef enum DAY {
    first=18,second,third,fouth
} day;
//-------------------------------------------------------------------

int main(void)
{
    //输入输出和基础测试
    int a,b;
    printf("please input like int,int\n");
    scanf("%d,%d",&a,&b);
    swap1(&a,&b);
    printf("a = %d\n",a);

    //枚举测试
    day myday;
    myday = first;
    int arr[]  = {NUM1,NUM2,myday,67,39,22};

    //函数指针测试
    void (*sort)(int *a,int b) = sort1;
    sort(arr,6);
    int i=0;
    for(;i<6;i++) {
        printf("arr[%d] = %d\n",i,arr[i]);
    }

    //文件读写测试
    writeText(arr);

    //递归测试
    int result = digui(4);
    printf("digui result is %d\n",result);

    //链表测试
    addlist(5);
    addlist(6);
    scanlist();
    freelist();

    printf("MIN(66,88) = %d\n",MIN(66,88));

    //strcpy库函数测试
    char dest[6];
    strcpy(dest,"testStrcpy");
    printf("dest is %s\n",dest);

    //0值比较测试
    float EX = 0.000001;
    float fl = 0.0001;
    if (fl>=-EX && fl<=EX) {
        printf("fl is zero\n");
    } else {
        printf("fl is not zero\n");
    }

    //链表测试
    struct node mynode;
    struct node srcnode;
    srcnode.a = 6;
    srcnode.next = NULL;
    memcpy(&mynode,&srcnode,sizeof(srcnode));
    printf("memcpy test is %d\n",mynode.a);

    //intarr作为参数则退化成指针大小为4个字节
    int intarr[] = {4,5,6,7,8,9};
    printf("sizeof(intarr) test is %d\n",sizeof(intarr));

    //返回函数指针
    int j=0;
    int *tmp = sort3(intarr,6);
    for(;j<6;j++) {
        printf("intarr[%d] = %d\n",i,tmp[j]);
    }

    //bit练习
    unsigned int bit = 60; //60 = 0011 1100
    printf("~bit 60 is %d\n",~bit);
    printf("bit<<2 is %d\n",bit<<2);

    return 0;
}

