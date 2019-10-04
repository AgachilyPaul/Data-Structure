#include<stdio.h>
#include<stdlib.h>
#define Size 5 //˳����ʼ��С

typedef struct Table
{
  int* head;
  int length; //��ǰ����
  int size; //�ܳ���
}table;

table initialize(); //��ʼ��
table insert_num(); //��������
void table_display(); //�����
table delete_num(); //ɾ������
void destroy_table(); //���ٱ� 

table initialize()
{
	table t;
	t.head = (int*)malloc(Size*sizeof(int));
	if(!t.head)
	{
		printf("��ʼ��ʧ��");
		exit(0);
	}

    t.length = 0;
    t.size = Size;
    return t;
}

table insert_num(table &t, int site, int num) //num�ǲ��������site�ǲ����λ��
{
    //�ж�����λ���Ƿ���ȷ
    if(site > t.length+1 || site < 1)
    {
        printf("��������λ�ô���");
        return t;
    }

    //�ж�˳���ռ��Ƿ��㹻
    if(t.length == t.size)
    {
        t.head = (int*)realloc(t.head, (t.size+1)*sizeof(int)); //�˴�ע��realloc()������ʹ��
        if(!t.head)
        {
            printf("�洢����ʧ��\n");
            return t;
        }
        t.size += 1;
    }

    //��������
    int count = t.length-1;
    //����ʱҪ�Ӻ���ǰ����
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
    //�ж�ɾ��λ���Ƿ���ȷ
    if(site>t.length || site<1)
    {
        printf("ɾ��λ�ô���");
        return t;
    }

    //ɾ��Ԫ��
    int count = site-1;
    //ɾ��ʱҪ��ǰ������
    for(count; count<t.length-1; count++)
    {
        t.head[count] = t.head[count+1];
    }

    //t.head[t.length-1] = 0; //��Ϊ����length--���Ͳ���Ҫ��һ����
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
    //��ʼ��
    table t = initialize();
    int count = 0;
    for(count; count<t.size; count++)
    {
        t.head[count] = count;
        t.length++;
    }
    table_display(t);
    //��������
    insert_num(t, 4, 7);
    table_display(t);
    //ɾ������
    delete_num(t, 2);
    table_display(t);
    
    destroy_table(t);
    return 0;
}