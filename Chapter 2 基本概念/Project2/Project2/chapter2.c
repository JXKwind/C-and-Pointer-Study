/*
**
**	�����¼��C��ָ�롷�ڶ��µı����Ŀ
**			ʹ�ú궨����й���
**  2021/12/14   Chapter2 ����
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
	/*	��������ĸ��	*/
	/*
	**	��ubuntu�µ�gcc������ ʹ������ cc -thrigraphs filename.c
	**	���Դ�ӡ������ĸ��
	**	����ʽ�ı�������Ҳ�ǿ��е�
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

	/*	\bbb	ת��Ϊ�˽�����ֵ������ַ�
		\xbbb   ת��Ϊʮ��������ֵ������ַ�zhu'shi
	*/
	printf("\060  \n");
	printf("\x030 \n");
	printf("\0123  \n");
	return EXIT_SUCCESS;
}
#endif