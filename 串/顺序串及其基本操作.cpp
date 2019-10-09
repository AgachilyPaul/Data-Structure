#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef struct 
{
    char data[MaxSize];
    int length;
}SqString;

//在本次算法中，顺序串的参数采用直接传递顺序串的方法，而不是通过顺序串指针来传递
//在本次算法中，通过非紧缩格式来存储串
//生成串
void Str_Assign(SqString &s, char cstr[]);
//销毁串
void Destory_Str(SqString &s);
//串的复制
void Str_Copy(SqString &s, SqString t);
//判断串相等
bool Str_Equal(SqString s, SqString t);
//求串长
int Str_length(SqString s);
//串的连接
SqString Connact(SqString s, SqString t);
//求子串,i为起始位置，j子串长度
SqString Sub_Str(SqString s, int i, int j);
//子串的插入, i为插入的位置， 1<= i <= n+1
SqString Ins_Str(SqString s1, int i, SqString s2);
//子串的删除, 在顺序串中删除从第i个字符开始的长度为j的子串
SqString Del_Str(SqString s, int i, int j);
//子串的替换
SqString Rep_Str(SqString s, int i, int j, SqString t);
//输出串
void Disp_Str(SqString s);

void Str_Assign(SqString &s, char cstr[])
{
    int i = 0;
    for(i; cstr[i] != '\0'; i++)
    {
        s.data[i] = cstr[i];  //注意用变量和用指针访问结构体的区别
    }
    s.length = i;
}

void Destory_Str(SqString &s)
{
    /*因为是直接采用顺序串本身来表示的，而不是顺序串指针，所以其
    存储空间由操作系统管理，由操作系统分配其存储空间，并在超出作用域
    时释放其存储空间*/
}

void Str_Copy(SqString &s, SqString t)
{
    int i = 0;
    for(i; i<s.length; i++)
    {
        t.data[i] = s.data[i];
    }
    t.length = s.length;
}

bool Str_Equal(SqString s, SqString t)
{
    int i;
    if(s.length != t.length)
    {
        return false;
    }
    else
    {
        for(i=0; i<s.length; i++)
        {
            if(s.data[i] != t.data[i])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

int Str_length(SqString s)
{
    return s.length;
}

SqString Connact(SqString s, SqString t)
{
    SqString str;
    str.length = 0;
    int i;
    for(i=0; i<s.length; i++)
    {
        str.data[i] = s.data[i];
    }
    for(i=0; i<t.length; i++)
    {
        str.data[s.length+i] = t.data[i];
    }
    str.length = s.length + t.length;
    return str;
}

SqString Sub_Str(SqString s, int i, int j)
{
    int k;
    SqString str;
    str.length = 0;
    if(j<0 || i>s.length || i<=0 || i+j-1>s.length)
    {
        return str; //参数错误返回空串
    }
    else
    {
        for(k=i-1; k<i-1+j; k++)
        {
            str.data[k-i+1] = s.data[k];
        }
    }
    str.length = j;
    return str;
}

SqString Ins_Str(SqString s1, int i, SqString s2)
{
    SqString str;
    str.length = 0;
    int k,p;
    if(i<1 || i>s1.length+1)
    {
        return str;
    }
    else
    {
        for(k=0; k<i-1; k++)
        {
            str.data[k] = s1.data[k];
        }
        for(p=0; p<s2.length; p++)
        {
            str.data[k] = s2.data[p]; 
            k++;
        }
        for(p=i-1; p<s1.length; p++)
        {
            str.data[k] = s1.data[p];
            k++;
        }
    }
    str.length = s1.length + s2.length;
    return str;
}

SqString Del_Str(SqString s, int i, int j)
{
    SqString str;
    str.length = 0; 
    int t, a;
    if(i<1 || i>s.length)
    {
        return str; //参数错误时返回空串
    }
    else
    {
        for(a=0; a<i-1; a++)
        {
           str.data[a] = s.data[a];
        }
        for(t=i+j-1; t<s.length; t++)
        {
            str.data[a] = s.data[t];
            a++;
        }        
    }
    str.length = s.length-j;
    return str;
}

SqString Rep_Str(SqString s, int i, int j, SqString t)
{
    int k;
    SqString str;
    str.length = 0;
    if(i <= 0 || i>s.length || i+j-1>s.length)
    {
        return str;
    }
    for(k=0; k<i-1; k++)
    {
        str.data[k] = s.data[k];
    }
    for(k=0; k<t.length; k++)
    {
        str.data[i+k-1] = t.data[k];
    }
    for(k = i+j-1; k<s.length; k++)
    {
        str.data[t.length+k-1] = s.data[k];
    }
    str.length = s.length-j+t.length;
    return str;
}

void Disp_Str(SqString s)
{
    int i;
    if(s.length > 0)
    {
        for(i=0; i<s.length; i++)
        {
            printf("%c", s.data[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    SqString s;
    char cstr[20]="charlie loves apple";
    Str_Assign(s, cstr);
    Disp_Str(Sub_Str(s, 2, 8));
}
