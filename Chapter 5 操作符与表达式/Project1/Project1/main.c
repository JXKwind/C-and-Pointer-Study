#define	_CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/*
*	如何获得整型值中的单个位
*	value = value | 1 << bitnumber;
*	value |= 1 << bitnumber;
*
*	如何清零整型值中的单个位
*	value = value & ~(1 << bitnumber);
*	value &= ~(1 << bitnumber);
*   
*	如何测试整型值中的某个位
*	value & (1 << bitnumber)	value 为 1 结果是非零值
*/

/* 课后习题 */

/* 书上样例 */
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
	/* 初级版本 */
	/*
	for (ones = 0; value != 0; value >>= 1)
	{
		if (value % 2 != 0)
			ones += 1;
	}
	*/

	/* 最终版本 */
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
*		在计算有符号数据类型的值时
*	符号位为0，直接计算；符号位为1，计算出来的值 - 无符号时的最大值
*		0x80 0b1000_0000  有符号时   2^7 = 128  128-256 = -128
*		x - 256 = -5  x= 251
*/
int
main(void)
{
	char a = 5;				/* 00000101		5	*/
	char b = a << 5;		/* 10100000		-96	*/
	char c = a >> 5;		/* 00000000		0	*/
	/*char d = a << -5;*/	/* 该行为未定义 不可移植，不使用为好 */
	printf("%d %d %d %d\n", a, b, c, d);

	a = -5;					/* 11111011		-5	*/	
	b = a << 5;				/* 01100000		96 */
	c = a >> 5;				/* 11111111		-1  */	/* 00000111		7 */


	/* 由此可见 VS在负数右移时，补充的是符号位 */
	printf("%d %d %d \n", a, b, c);
	return EXIT_SUCCESS;
}

#endif