# 20140310

1.矩阵的乘法  

    矩阵转置

2. strcpy等不要realloc 

3. 指针中包含两个信息 
    
    1.base
    2.type  

4. void＊ 不能进行解引用

5
```C
struct Matrix mutl(struct Matrix *A, struct Matrix *B)
{
	struct Matrix _ret;

	return _ret;
}

```

避免结构体的复制


6 
```C
void bubble_sort(struct Student *arr, int n, int (*comp)(struct Student *, struct Student *))
```
函数指针作为一种策略

7
不要返回局部变量的地址

```C
int *func()
{
	int a;
	return &a;
}

```



8 
```C
char* func(char *_p)
{
	_p = (char*)malloc(100*sizeof(char));
	printf("in function the pointer is: %p\n", _p);
	return _p;
}

```

改变某一个变量 必须去传入他的指针 必须要高一个级别

9 链表的操作哪些需要传入L的指针 （哪些需要改变L本身）
究竟是改变L指向的内存，还是改变L本身



#链表总结

1. 遍历操作 
2 找第k个结点  

3 插入 删除 
4 头插法  tail 


