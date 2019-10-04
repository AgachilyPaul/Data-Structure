#include<stdio.h>
#include<stdlib.h>
#define Size 5 //顺序表初始大小

typedef struct Table
{
  int* head;
  int length; //当前长度
  int size; //总长度
}table;

table initialize(); //初始化
table insert_num(); //插入数据
void table_display(); //输出表
table delete_num(); //删除数据
void destroy_table(); //销毁表 

table initialize()
{
	table t;
	t.head = (int*)malloc(Size*sizeof(int));
	if(!t.head)
	{
		printf("初始化失败");
		exit(0);
	}

    t.length = 0;
    t.size = Size;
    return t;
}

table insert_num(table &t, int site, int num) //num是插入的数，site是插入的位置
{
    //判读插入位置是否正确
    if(site > t.length+1 || site < 1)
    {
        printf("插入数字位置错误");
        return t;
    }

    //判断顺序表空间是否足够
    if(t.length == t.size)
    {
        t.head = (int*)realloc(t.head, (t.size+1)*sizeof(int)); //此处注意realloc()函数的使用
        if(!t.head)
        {
            printf("存储分配失败\n");
            return t;
        }
        t.size += 1;
    }

    //插入数据
    int count = t.length-1;
    //插入时要从后向前遍历
    for(count; count >= site-1; count--)
    {
        t.head[count+1] = t.head[count];
    }

    t.head[site-1] = num;
    t.length = t.length+1;
    return t;
}

table delete_num(table &t, int site)
{
    //判断删除位置是否正确
    if(site>t.length || site<1)
    {
        printf("删除位置错误");
        return t;
    }

    //删除元素
    int count = site-1;
    //删除时要从前向后遍历
    for(count; count<t.length-1; count++)
    {
        t.head[count] = t.head[count+1];
    }

    //t.head[t.length-1] = 0; //因为后面length--，就不需要这一操作
    t.length--;
    return t;
}

void destroy_table(table &t)
{
	free(&t);
	return;
}

void table_display(table t)
{
	int count = 0;
	for(count; count<t.length; count++)
	{
		printf("%d ", t.head[count]);
	}
    printf("\n");
	return;
}

int main(void)
{
    //初始化
    table t = initialize();
    int count = 0;
    for(count; count<t.size; count++)
    {
        t.head[count] = count;
        t.length++;
    }
    table_display(t);
    //插入数据
    insert_num(t, 4, 7);
    table_display(t);
    //删除数据
    delete_num(t, 2);
    table_display(t);
    
    destroy_table(t);
    return 0;
}