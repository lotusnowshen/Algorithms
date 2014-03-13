# 递归

1. 子问题的性质与父问题类似 
    规模有所缩小
  
2. 一定要有终止条件


递归容易导致栈

3 
```C
struct Array
{
	/* data */
	int A[M][N];
	int m;
	int n;
};

```

4.
```C
    int **p = (int**)malloc(10*sizeof(int*));
	int i;
	for(i = 0; i< 10; ++i)
	{
		p[i] = (int*)malloc(sizeof(int)*4);
	}
```


5
```C


```
