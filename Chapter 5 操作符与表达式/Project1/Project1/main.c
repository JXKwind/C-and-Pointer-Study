#define	_CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
*	��λ������ֵ�еĵ���λ
*	value = value | 1 << bitnumber;
*	value |= 1 << bitnumber;
*
*	�����������ֵ�еĵ���λ
*	value = value & ~(1 << bitnumber);
*	value &= ~(1 << bitnumber);
*   
*	��β�������ֵ�е�ĳ��λ
*	value & (1 << bitnumber)	value Ϊ 1 ����Ƿ���ֵ
*/

/* �κ�ϰ�� */

/* �������� */
//#define SHIFT_CLAC
#define COUNT_ONE



#ifdef COUNT_ONE

int
count_one_bits(unsigned value);

int
main(void)
{
	int a = 1;
	int b = 3;
	int c = -1;

	printf("%d %d %d\n", count_one_bits(a), count_one_bits(b), count_one_bits(c));

	return EXIT_SUCCESS;
}

int
count_one_bits(unsigned value)
{
	int ones;
	/* �����汾 */
	/*
	for (ones = 0; value != 0; value >>= 1)
	{
		if (value % 2 != 0)
			ones += 1;
	}
	*/

	/* ���հ汾 */
	for (ones = 0; value != 0; value >>= 1)
	{
		if ( (value & 1) != 0 )
			ones += 1;
	}


	return ones;
}
#endif


#ifdef SHIFT_CLAC
/*
*		�ڼ����з����������͵�ֵʱ
*	����λΪ0��ֱ�Ӽ��㣻����λΪ1�����������ֵ - �޷���ʱ�����ֵ
*		0x80 0b1000_0000  �з���ʱ   2^7 = 128  128-256 = -128
*		x - 256 = -5  x= 251
*/
int
main(void)
{
	char a = 5;				/* 00000101		5	*/
	char b = a << 5;		/* 10100000		-96	*/
	char c = a >> 5;		/* 00000000		0	*/
	/*char d = a << -5;*/	/* ����Ϊδ���� ������ֲ����ʹ��Ϊ�� */
	printf("%d %d %d %d\n", a, b, c, d);

	a = -5;					/* 11111011		-5	*/	
	b = a << 5;				/* 01100000		96 */
	c = a >> 5;				/* 11111111		-1  */	/* 00000111		7 */


	/* �ɴ˿ɼ� VS�ڸ�������ʱ��������Ƿ���λ */
	printf("%d %d %d \n", a, b, c);
	return EXIT_SUCCESS;
}

#endif