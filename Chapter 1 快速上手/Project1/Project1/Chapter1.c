/*
**
**	这边收录《C与指针》第一章的编程题目
**			使用宏定义进行管理
**  2021/12/14   Chapter1 四道编程题
**
*/
#define	_CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int a;

//#define PrintfLongestString
//#define StringOutputCheckSum
//#define StringOutput
//#define HelloWorld


int
main(void)
{
	a = 10;
	printf("%d\n", a);
	return EXIT_SUCCESS;
}



#ifdef PrintfLongestString
int
main(void)
{
	unsigned int length = 0;
	unsigned int length_MAX = 0;
	char ch = '\0';
	unsigned char begin_flag = 1;
	char str[1200] = {'\0'};
	char str_deal[1200] = { '\0' };

	while ((ch = getchar()) != EOF)
	{
		if (begin_flag)
		{
			begin_flag = 0;
			if (length > length_MAX)
			{
				/*		拷贝字符串		*/	
				strcpy(str, str_deal);
				length_MAX = length;
			}
			length = 0;
		}
		str_deal[length] = ch;
		length++;
		if (ch == '\n')
		{
			begin_flag = 1;
		}
	}

	printf("Longest str is %s", str);
	printf("Length is %d", length_MAX);
	return EXIT_SUCCESS;
}
#endif


#ifdef StringOutputCheckSum
int
main(void)
{
	unsigned int Line = 0;
	char ch = '\0';
	unsigned char begin_flag = 1;
	signed char Sum = -1;

	while ((ch = getchar()) != EOF)
	{
		if (begin_flag)
		{
			begin_flag = 0;
			printf("%d.", Line);
			Line++;
		}
		putchar(ch);
		Sum += ch;

		if (ch == '\n')
		{
			begin_flag = 1;
			printf("\nCheckSum is %d\n", Sum);
			Sum = -1;
		}
	}

	return EXIT_SUCCESS;
}
#endif

#ifdef StringOutput
int 
main(void)
{
	unsigned int Line = 0;
	char ch = '\0';
	unsigned char begin_flag = 1;

	while ((ch = getchar()) != EOF)
	{
		if (begin_flag)
		{
			begin_flag = 0;
			printf("%d.", Line);
			Line++;
		}
		putchar(ch);

		if (ch == '\n')
		{
			begin_flag = 1;
		}
	}

	return EXIT_SUCCESS;
}
#endif

#ifdef HelloWorld
int 
main(void)
{
	printf("Hello World\n");
	return EXIT_SUCCESS;
}
#endif