#define	_CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
/* #define CHANGE_LETTER */
/* #define CHANGE_LETTER_ENCODE */
/* #define REVERSE_BITS */
/* #define BIT_ARRAY */
/* #define BIT_STORE_INT */

/* 书上样例 */
/* #define SHIFT_CLAC */
/* #define COUNT_ONE */


#ifdef BIT_STORE_INT

#include <limits.h>

#define INT_BITS	(CHAR_BIT * sizeof(int))

int store_bit_field(int original, int value_to_store, unsigned starting_bit, unsigned ending_bit);

int
main(void)
{
	printf("%x\n", store_bit_field(0xffff, 0x123, 13, 9));

	return EXIT_SUCCESS;
}



int
store_bit_field(int original, int value_to_store, unsigned starting_bit, unsigned ending_bit)
{
#if 1
	int mask;
	int mask_reverse;
	int i;
	int answer;
	int use_value = 0;
	unsigned bit_count = 0;

	/* 判断 */
	if (starting_bit < ending_bit)
		return original;

	/* 将对应的位设为1 starting_bit ~ ending_bit */
	mask = 0;
	mask_reverse = 0;
	for (i = 1; i != 0; i <<= 1)			/* 运行效率不高 */
	{
		if (bit_count >= ending_bit && bit_count <= starting_bit)
		{
			mask |= (1 << bit_count);
		}
		bit_count++;
	}

	/* 掩码的反码对原值进行AND操作 */
	mask_reverse = ~mask;
	original &= mask_reverse;

	/* 将新值左移 */
	use_value = value_to_store << ending_bit; 

	/* 将新值和掩码位与 结果与原值或 */
	answer = (use_value & mask) | original;

	return answer;
#else
	
	unsigned mask;

	if (starting_bit < INT_BITS && ending_bit < INT_BITS && starting_bit >= ending_bit)
	{
		mask = (unsigned)-1;		/* (unsigned)  类型转换  (unsigned)-1 表示无符号整数的最大值 */
		mask >>= INT_BITS - (starting_bit - ending_bit + 1); /* 无符号变量右移 逻辑移位 补0 */
		mask <<= ending_bit;		/* 右移也补0 */

		original &= ~mask;

		value_to_store <<= ending_bit;

		original |= value_to_store & mask;

	}

	return original;

#endif
}

#endif


#ifdef BIT_ARRAY

#include <limits.h>

void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);
unsigned character_offset(unsigned bit_number);
unsigned bit_offset(unsigned bit_number);

int
main(void)
{
	return EXIT_SUCCESS;
}

void
set_bit(char bit_array[], unsigned bit_number)
{
	bit_array[character_offset(bit_number)] |= 1 << bit_offset(bit_number);
}

void
clear_bit(char bit_array[], unsigned bit_number)
{
	bit_array[character_offset(bit_number)] &= ~1 << bit_offset(bit_number);
}

void
assign_bit(char bit_array[], unsigned bit_number,int value)
{
	if (value == 0)
		claer_bit(bit_array, bit_number);
	else
		set_bit(bit_array, bit_number);
}

int
test_bit(char bit_array[], unsigned bit_number)
{
	return (bit_array[character_offset(bit_number)] & 1 << bit_offset(bit_number)) != 0;
}

unsigned 
character_offset(unsigned bit_number)
{
	return (bit_number / CHAR_BIT);
}

unsigned 
bit_offset(unsigned bit_number)
{
	return (bit_number % CHAR_BIT);
}

#endif


#ifdef REVERSE_BITS

unsigned int reverse_bits(unsigned int value);

int
main(void)
{
	int i = 0;
	unsigned int number = 25;
	unsigned int ret = reverse_bits(number);
	printf("Before reverse_bits:");
	for (i = sizeof(unsigned int) * 8 - 1; i >= 0;i--)
	{
		printf("%d ", (number >> i) & 0x1);
	}
	printf("\nAfter  reverse_bits:");
	
	for (i = sizeof(unsigned int) * 8 - 1; i >= 0; i--)
	{
		printf("%d ", (ret >> i) & 0x1);
	}

	return EXIT_SUCCESS;
}

unsigned int 
reverse_bits(unsigned int value)
{
#if 0
	unsigned int ret = 0;
	unsigned int bit_count = sizeof(bit_count) * 8;

	while (value != 0)
	{
		bit_count--;
		if ((value & 0x1) == 1)
		{
			ret |= 1 << bit_count;
		}
		else
		{
			ret &= ~1 << bit_count;
		}
		if (bit_count < 0)
		{
			break;
		}

		value >>= 1;
	}
	return ret;
#else
	unsigned int answer;
	unsigned int i;

	answer = 0;

	for (i = 1; i != 0; i <<= 1)
	{
		answer <<= 1;

		if (value & 1)
			answer |= 1;
		value >>= 1;
	}

	return answer;
#endif
}

#endif


#ifdef CHANGE_LETTER_ENCODE
int 
main(void)
{
	int ch = 0;
	while( (ch = getchar()) != EOF )
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			if(ch - 13 < 'A' )
			{
				ch += 13;
			} 
			else if(ch + 13 > 'Z')
			{
				ch -= 13;
			}
		}
		else if(ch >= 'a' && ch <= 'z')
		{
			if(ch - 13 < 'a' )
			{
				ch += 13;
			} 
			else if(ch + 13 > 'z')
			{
				ch -= 13;
			}
		}
		putchar(ch);
	}
	
	return EXIT_SUCCESS;
}
#endif

#ifdef CHANGE_LETTER
int
main(void)
{
	int ch = 0;

	while ( (ch = getchar()) != EOF)
	{
		if (ch >= 'A' && ch <= 'Z')	/* A = 0x41 a = 0x61 */
		{
			ch += 'a' - 'A';
		}
		putchar(ch);
	}

	return EXIT_SUCCESS;
}

#endif


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
*		
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
