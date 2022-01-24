#define	_CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define Squareroot
//#define Triangle
//#define CopyString
//#define Prime
//#define FindSameStr
//#define FindStrFromStr
//#define DeBlank


int
main(void)
{
	int test_arr[10] = { 0x44,0x45,0 };

	return EXIT_SUCCESS;
}

#ifdef DeBlank
#include <assert.h>
void deblank(char string[]);

int
main(void)
{
	char string[60] = "1     1     2    3 1 2    3  qwer     1  2     4 3";
	printf("%s\n",string);
	deblank(string);
	printf("%s\n", string);
	return EXIT_SUCCESS;
}

void deblank(char string[])
{
	assert(string != NULL);
	char string_copy[60];
	strcpy(string_copy, string);
	int blank_num = 0;
	int len = strlen(string);
	int i,j;
	int move = 0;
	int flag = 0;
	char *p_str = string_copy;
	while (*p_str++ != '\0')
	{
		/* 检测空格数 */
		if (*p_str == ' ')
		{
			/* 舍弃检测到的第一个空格 */
			if (flag == 1)
			{
				blank_num += 1;
				continue;
			}
			flag = 1;
		}

		/* 单独空格后是数字，丢弃 */
		if (flag = 1)
		{
			if (*p_str != ' ')
			{
				flag = 0;
			}
		}

		move++;
		/* 移动数组 */
		if (blank_num >= 1)
		{
			for (j = blank_num; j > 0; j--)
			{
				for (i = move; i < len; i++)
				{
					string[i] = string[i+1];
					if (string[i] == '\0')
						break;
				}
			}
			flag = 0;
		}
		blank_num = 0;
	}
}
#endif


#ifdef FindStrFromStr
#include <assert.h>
int substr(char dst[],const char src[], int start, int len);

int
main(void)
{
	char dst[20];
	char src[20] = "abcdefghjkl";
	substr(dst, src,1,25);
	printf("%s\n", dst);
	return EXIT_SUCCESS;
}

/* 该函数存在溢出的风险，最好将数组的大小当作参数传递进来 */
int substr(char dst[],const char src[], int start, int len)
{
	/* 将dst与src当作指针来用 */
	assert(src != NULL);
	assert(dst != NULL);
	int i = 0;
	int src_len = strlen(src);
	if (start > src_len || start < 0 || len < 0)
	{
		dst[0] = '\0';
		return 0;
	}
	src += start;
	for (i = 0; i < len; i++)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
		{
			break;
		}
	}
	dst[i] = '\0';
	return i;
}

#endif


#ifdef FindSameStr 
int
main(void)
{
	signed char str[128] = { "\0" };
	signed char pervious_str[128] = { "\0" };
	int same_flag = 0;
	while (gets_s(str,128) != NULL)
	{
		if (strcmp(str, pervious_str) == 0)
		{
			if(same_flag == 0)
				printf("-------%s\n", str);
			same_flag = 1;
		}
		else
		{
			same_flag = 0;
			strcpy(pervious_str, str);
		}
			
	}
	return EXIT_SUCCESS;
}
#endif

#ifdef CopyString
void copy_n(char dest[], const char source[], int num);

int
main(void)
{
	char str[7] = {"asbdef"};
	char *p_str = "Test_Sasdfasdasd";
	int num = 15;
	copy_n(str, p_str, num);
	printf("%s\n", str);

	return EXIT_SUCCESS;
}

void copy_n(char dest[],const char source[], int num)
{
	int dest_len = strlen(dest);
	int source_len = strlen(source);
	int i;
	for (i = 0; i < num; i++)
	{
		if (i > dest_len)
		{
			dest[i-1] = '\0';
			break;
		}

		if (i > source_len)
		{
			dest[i] = '\0';
		}
		else
			dest[i] = source[i];
	}
}

#endif

#ifdef Triangle
int
main(void)
{
	int line[3];
	int wrong_flag = 0;
	printf("输入三角型的三条边>:");
	scanf("%d%d%d", &line[0], &line[1], &line[2]);

	if (!wrong_flag)
	{
		if (line[0] + line[1] > line[2])
		{
			if (line[0] > line[2] - line[1])
			{
				;
			}
			else
				wrong_flag = 1;
		}
		else
			wrong_flag = 1;
	}

	if (!wrong_flag)
	{
		if (line[1] + line[2] > line[0])
		{
			if (line[1] > line[0] - line[2])
			{
				;
			}
			else
				wrong_flag = 1;
		}
		else
			wrong_flag = 1;
	}

	if (!wrong_flag)
	{
		if (line[0] + line[2] > line[1])
		{
			if (line[2] > line[1] - line[0])
			{
				;
			}
			else
				wrong_flag = 1;
		}
		else
			wrong_flag = 1;
	}

	if (!wrong_flag)
	{
		if (line[0] == line[2] && line[2] == line[1])
		{
			printf("等边三角形\n");
		}
		else if ((line[0] == line[1]) || (line[1] == line[2] ) || (line[0] == line[2]))
		{
			printf("等腰三角形\n");
		}
		else
		{
			printf("不规则三角形\n");
		}
	}
	else
	{
		printf("边长错误！\n");
	}

	return EXIT_SUCCESS;
}
#endif

#ifdef Prime
int
main(void)
{
	int i;
	int j;
	int is_prime_flag;
	for (i = 2; i <= 100; i += 1)
	{
		is_prime_flag = 1;
		for (j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{
				is_prime_flag = 0;
				break;
			}
		}
		if (is_prime_flag)
		{
			printf("%d\n", i);
		}
	}

	return EXIT_SUCCESS;
}
#endif

#ifdef Squareroot
int
main(void)
{
	unsigned int n;
	float answer = 1, previous_answer = 0;

	scanf("%d", &n);

	do
	{
		previous_answer = answer;
		answer = (answer + n/ answer ) / 2;
		printf("%lf\n", answer);
	} 
	while (answer != previous_answer);

	return EXIT_SUCCESS;
}
#endif