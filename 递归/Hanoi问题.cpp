#include<stdio.h>

void Hanoil(int n, char x, char y, char z)
{
    if(n == 1)
    {
        printf("将第%d个圆盘由%c移到%c上\n", n, x, z);
    }
    else
    {
        Hanoil(n-1, x, z, y);
        printf("将第%d个圆盘由%c移到%c上\n", n, x, z);
        Hanoil(n-1, y, x, z);
    }   
}

int main(void)
{
	char x, y, z;
	Hanoil(5, 'x', 'y', 'z');
	return 0;
}
