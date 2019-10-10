/*定义是递归，有许多数学公式，数列等的定义是递归的，
对于这些问题的求解，可以通过将其递归定义直接转化为对应的递归算法*/

//求斐波那契数列的递归算法如下
int Fib1(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return (Fib1(n-1)+Fib1(n-2));
    }
}

/*数据结构是递归的，比如单链表就是一种递归的数据结构*/
typedef struct LNode
{
    int data;
    LNode *next;
};
/*对于递归的数据结构，采用递归的方法编写算法更为方便有效*/
//对于不带头节点的单向链表的求和
int sum(LNode *s)
{
    if(s->next = NULL)
    {
        return 0;
    }
    else
    {
        return (s->data + sum(s->next));
    } 
}
/*问题的求解方法是递归的*/
//Hanoi问题
void Hanoil(int n, char x, char y, char z)
{
    if(n == 1)
    {
        printf("将第%d个圆盘由%c移到%c上\n", n, x, z);
    }
    else
    {
        //核心步骤
        Hanoil(n-1, x, z, y); //将前n-1个圆盘借助z，由x移动到y上。
        printf("将第%d个圆盘由%c移到%c上\n", n, x, z); //将剩下的最后一个圆盘由x移动到y上
        Hanoil(n-1, y, x, z); //将前n-1个由y借助x移动到z上
    }   
}

int main(void)
{
	char x, y, z;
	Hanoil(5, 'x', 'y', 'z');
	return 0;
}


