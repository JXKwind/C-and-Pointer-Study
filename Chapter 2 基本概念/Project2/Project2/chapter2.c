/*
**
**	这边收录《C与指针》第二章的编程题目
**			使用宏定义进行管理
**  2021/12/14   Chapter2 二道
**
*/
#define	_CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//#define CheckBrackets
//#define IncreaseAndNegate


#ifdef CheckBrackets
int 
main(void)
{

	char ch = '\0';
	unsigned int num = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch == '{')
		{
			num++;
		}

		if (ch == '}')
		{
			if (num == 0)
			{
				printf("extra } !\n");
			}
			else
				num--;
		}
	}

	if (num == 0)
	{
		printf("OK\n");
	}
	else
	{
		printf("Error number is %d\n", num);
	}


	return EXIT_SUCCESS;
}
#endif


#ifdef IncreaseAndNegate
int
negate(int param);
int
increment(int param);

int
main(void)
{
	printf("%d\n", negate(10));
	printf("%d\n", negate(0));
	printf("%d\n", negate(-10));

	printf("%d\n", increment(10));
	printf("%d\n", increment(0));
	printf("%d\n", increment(-10));

	return EXIT_SUCCESS;
}
#endif



#ifdef Test
int
main(void)
{
	/*	测试三字母词	*/
	/*
	**	于ubuntu下的gcc编译器 使用命令 cc -thrigraphs filename.c
	**	可以打印出三字母词
	**	在老式的编译器下也是可行的
	*/
	printf("??(\n");
	printf("??)\n");
	printf("??!\n");
	printf("??<\n");
	printf("??>\n");
	printf("??'\n");
	printf("??=\n");
	printf("??/\n");
	printf("??-\n");

	/*	\bbb	转义为八进制数值代表的字符
		\xbbb   转义为十六进制数值代表的字符zhu'shi
	*/
	printf("\060  \n");
	printf("\x030 \n");
	printf("\0123  \n");
	return EXIT_SUCCESS;
}
#endif