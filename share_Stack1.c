#include <stdio.h>
#define ShareStackMaxSize 1000
typedef char ShareStackType;
typedef struct ShareStack
{
    ShareStackType data[ShareStackMaxSize];
    size_t top1;
    size_t top2;
}ShareStack;

//初始化
void ShareStackInit(ShareStack* stack)
{
    if(stack == NULL)
    {
        //非法操作
        return ;
    }
    stack->top1=0;
    stack->top2=ShareStackMaxSize;
}

//插入元素
void ShareStackPush1(ShareStack* stack,ShareStackType value)
{
    if(stack == NULL)
    {
        //非法操作
        return;
    }
    if(stack->top1>=stack->top2)
    {
        //棧满
        return;
    }
    stack->data[stack->top1++]=value;
    return;
}
void ShareStackPush2(ShareStack* stack,ShareStackType value)
{
    if(stack == NULL)
    {
        //非法操作
        return;
    }
    if(stack->top1>=stack->top2)
    {
        //棧满
        return;
    }
    stack->data[--stack->top2]=value;
    return;
}

//取棧顶元素
int ShareStackTop1(ShareStack* stack,ShareStackType* value)
{
    if(stack == NULL || value == NULL)
    {
        //非法操作
        return 0;
    }
    if(stack->top1 == 0)
    {
        //棧为空
        return 0;
    }
    *value=stack->data[stack->top1-1];
        return 1;
}
int ShareStackTop2(ShareStack* stack,ShareStackType* value)
{
    if(stack == NULL || value == NULL)
    {
        //非法操作
        return 0;
    }
    if(stack->top2 == ShareStackMaxSize)
    {
        //棧为空
        return 0;
    }
    *value=stack->data[stack->top2];
    return 1;
}

//删除元素
void ShareStackPop1(ShareStack* stack)
{
    if(stack == NULL)
    {
        return;
    }
    if(stack->top1 == 0)
    {
        return;
    }
    --stack->top1;
    return;
}
void ShareStackPop2(ShareStack* stack)
{
    if(stack == NULL)
    {
        return;
    }
    if(stack->top2=ShareStackMaxSize)
    {
        return;
    }
    ++stack->top2;
    return;
}
