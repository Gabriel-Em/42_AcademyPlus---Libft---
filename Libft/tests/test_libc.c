#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <ctype.h>

void test_ft_memset()
{
	char x23[10] = "XXXXXXXXX";
	char x32[10] = "XXXXXXXXX";
	unsigned char *ft;
	unsigned char *original;

	// we copy the character 'a' 7 times at the begining of x23 and x32	
	ft = (unsigned char*)ft_memset(x23, 97, 7);
	original = (unsigned char*)memset(x32, 97, 7);

	for (int i = 0; i < 10; i++)
		if (ft[i] != original[i])
		{
			printf("ft_memset FAILED\n");
			return;
		}

	// there are 20 bytes in x2 and x3 since they're int, and we're trying
	// to copy the byte for 23 13 times into x2 and x3 so that the 4th int
	// has only its first byte modified

	int x2[5] = { 3, 3, 3, 3, 3 };
	int x3[5] = { 3, 3, 3, 3, 3 };
	ft = (unsigned char*)ft_memset(x2, 23, 13);
	original = (unsigned char*)memset(x3, 23, 13);
	for (int i = 0; i < 5 * sizeof(int); i++)
		if (ft[i] != original[i])
		{
			printf("ft_memset FAILED\n");
			return;
		}

	printf("ft_memset PASSED\n");
}

void test_ft_bzero()
{
	char x23[10] = "XXXXXXXXX";
	char x32[10] = "XXXXXXXXX";

	// we make the first 5 bytes of x23 and x32 0
	ft_bzero(x23, 5);
	bzero(x32, 5);
	for (int i = 0; i < 10; i++)
		if (x23[i] != x32[i])
		{
			printf("ft_bzero FAILED\n");
			return;
		}

	// there are 20 bytes in x2 and x3 since they're int, and we're turning
	// the first 15 bytes of those arrays into zero bytes so that the 5th
	// int has only its first byte modified

	int x2[5] = { 3, 3, 3, 3, 3 };
	int x3[5] = { 3, 3, 3, 3, 3 };
	ft_bzero(x2, 15);
	bzero(x3, 15);
	for (int i = 0; i < 5; i++)
		if (x2[i] != x3[i])
		{
			printf("ft_bzero FAILED\n");
			return;
		}
	printf("ft_bzero PASSED\n");
}

void	test_ft_memcpy()
{
	char x23[10] = "xxxxxxxxx";
	char x32[10] = "xxxxxxxxx";
	char x18[20] = "_______________";
	unsigned char *ft;
	unsigned char *original;

	// we copy the first 5 bytes from x18 into x23 and x32
	ft = (unsigned char*)ft_memcpy(x23, x18, 5);
	original = (unsigned char*)memcpy(x32, x18, 5);

	for (int i = 0; i < 10; i++)
		if (x23[i] != x32[i])
		{
			printf("ft_memcpy FAILED!\n");
			return;
		}

	// there are 20 bytes in x16 and x61 since they're int, and we're copying
	// the first 15 bytes of x18 into x16 and x61 so that they're 5th int
	// has only their first byte modified

	int x16[5] = { 3, 3, 3, 3, 3 };
	int x61[5] = { 3, 3, 3, 3, 3 };

	ft = (unsigned char*)ft_memcpy(x16, x18, 15);
	original = (unsigned char*)memcpy(x61, x18, 15);

	for (int i = 0; i < 5; i++)
		if (x16[i] != x61[i])
		{
			printf("ft_memcpy FAILED\n");
			return;
		}

	printf("ft_memcpy PASSED\n");
}

void test_ft_memccpy()
{
	char x[10] = "abcdefghi";
	char y[10] = "abcdefghi";
	char *src = "12345x6789";

	unsigned char *ft;
	unsigned char *or ;

	// we try to copy the first 8 bytes from src into x and y but the copy
	// should stop after the 6th byte (which is 'x' with ASCII 120) therefore
	// a pointer to 'g' from x and y should be returned

	ft = (unsigned char*)ft_memccpy(x, src, 120, 8);
	or = (unsigned char*)memccpy(y, src, 120, 8);

	for (int i = 0; i < 10; i++)
		if (x[i] != y[i])
		{
			printf("ft_memccpy FAILED\n");
			return;
		}
	// we're using ft_memccpy on y to initialize ft with the same adress or 
	// got when we initialized it above using memccpy (they should be the same)
	ft = (unsigned char*)ft_memccpy(y, src, 120, 8);

	if (ft != or || *ft != 'g')
	{
		printf("ft_memccpy FAILED\n");
		return;
	}

	// a, b and c contain 20 bytes because they're int, and we're trying to copy
	// 20 bytes from c into a and b, but the int 341 contains the byte 01010101 (85 in decimal) 
	// so the copy should stop and a pointer to the 10th byte from a and b should be returned
	// that byte should be 01010000 (80 decimal) since 20735 is being written as 0101000011111111
	// ******little endian*******

	int a[5] = { 20735,20735,20735,20735 };
	int b[5] = { 20735,20735,20735,20735 };
	int c[5] = { 1, 2, 341, 3, 4 };

	ft = (unsigned char*)ft_memccpy(a, c, 85, 20);
	or = (unsigned char*)memccpy(b, c, 85, 20);
	for (int i = 0; i<5; i++)
		if (a[i] != b[i])
		{
			printf("ft_memccpy FAILED\n");
			return;
		}
	// we point ft to the same adress as or
	ft = (unsigned char*)ft_memccpy(b, c, 85, 20);
	if (ft != or || *ft != 80)
	{
		printf("ft_memccpy FAILED\n");
		return;
	}

	// lastly we copy any ammount of bytes to any array that does not contain the value
	// that we send to memccpy as its third parameter to check if the function returns NULL

	ft = ft_memccpy(x, src, 'K', 8);
	or = memccpy(y, src, 'K', 8);

	if (ft != or)
	{
		printf("ft_memccpy FAILED\n");
		return;
	}

	printf("ft_memccpy PASSED\n");
}

void    test_ft_memmove()
{
	char x23[10] = "xxxxxxxxx";
	char x32[10] = "xxxxxxxxx";
	char x18[20] = "_______________";
	unsigned char *ft;
	unsigned char *original;

	// we copy the first 5 bytes from x18 into x23 and x32
	ft = (unsigned char*)ft_memmove(x23, x18, 5);
	original = (unsigned char*)memmove(x32, x18, 5);

	for (int i = 0; i < 10; i++)
		if (x23[i] != x32[i])
		{
			printf("ft_memmove FAILED!\n");
			return;
		}

	// there are 20 bytes in x16 and x61 since they're int, and we're copyin
	// the first 15 bytes of x18 into x16 and x61 so that they're 5th int
	// has only their first byte modified

	int x16[5] = { 3, 3, 3, 3, 3 };
	int x61[5] = { 3, 3, 3, 3, 3 };

	ft = (unsigned char*)ft_memmove(x16, x18, 15);
	original = (unsigned char*)memmove(x61, x18, 15);

	for (int i = 0; i < 5; i++)
		if (x16[i] != x61[i])
		{
			printf("ft_memmove FAILED\n");
			return;
		}

	printf("ft_memmove PASSED\n");
}

void test_ft_memchr()
{
	unsigned char *x23 = "abcdefghijklmnopqrstuvwxyz";
	unsigned char *ft;
	unsigned char *or;

	// we're looking for 'n' (110) in x23 - since it is present a pointer to it should be returned

	ft = (unsigned char*)ft_memchr(x23, 110, 26);
	or = (unsigned char*)memchr(x23, 110, 26);

	if (ft != or || *ft != 'n')
	{
		printf("ft_memchr FAILED\n");
		return ;
	}

	// we're looking for 'K' (75) in x23 - since it isn't present NULL should be returned
	ft = ft_memchr(x23, 75, 26);
	or = memchr(x23, 75, 26);

	if (ft != or)
	{
		printf("ft_memchr FAILED\n");
		return ;
	}

	printf("ft_memchr PASSED\n");
}

void test_ft_memcmp()
{
	unsigned char *s1 = "abcdef";
	unsigned char *s2 = "abcde_";
	unsigned char *s3 = "abcdaf";
	unsigned char *s4 = "abcdzf";

	// memcmp(s1, s2, 5) = 0	[equal]
	// memcmp(s1, s3, 5) = 4	[greater than]
	// memcmp(s1, s4, 5) = -21	[less than]

	if (ft_memcmp(s1, s2, 5) != memcmp(s1, s2, 5) ||
		ft_memcmp(s1, s3, 5) != memcmp(s1, s3, 5) ||
		ft_memcmp(s1, s4, 5) != memcmp(s1, s4, 5))
	{
		printf("ft_memcmp FAILED\n");
		return ;
	}
	printf("ft_memcmp PASSED\n");
}

void test_ft_strlen()
{
	char *x = "abcdef";
	char *y = "";

	// we compare simply compare our strlen to the original
	if (ft_strlen(x) != strlen(x) || ft_strlen(y) != strlen(y))
	{
		printf("ft_strlen FAILED\n");
		return;
	}

	printf("ft_strlen PASSED\n");
}

void test_ft_strdup()
{
	char *x = "abcdef";
	char *ft;
	char *original;

	// we simply compare our strdup with the original
	ft = ft_strdup(x);
	original = strdup(x);

	for (int i = 0; i < strlen(original) + 1; i++)
		if (ft[i] != original[i])
		{
			printf("ft_strdup FAILED\n");
			free(ft);
			free(original);
			return;
		}

	free(ft);
	free(original);
	printf("ft_strdup PASSED\n");
}

void test_ft_strcpy()
{
	char dst_ft[10] = "xxxxxxxxx";
	char dst_original[10] = "xxxxxxxxx";
	char *src = "123";

	char *ft;
	char *original;

	// we simply compare our strcpy with the original

	ft = ft_strcpy(dst_ft, src);
	original = strcpy(dst_original, src);

	for (int i = 0; i < strlen(original) + 1; i++)
		if (ft[i] != original[i])
		{
			printf("ft_strcpy FAILED\n");
			return;
		}

	printf("ft_strcpy PASSED\n");
}

void test_ft_strncpy()
{
	char dst_ft[20] = "abcdef";
	char dst_original[20] = "abcdef";
	char *src = "123456";

	char *ft;
	char *original;

	// we make a simple copy of only 3 chars from src to dst_ft and dst_original
	ft = ft_strncpy(dst_ft, src, 3);
	original = strncpy(dst_original, src, 3);

	for (int i = 0; i < strlen(original) + 1; i++)
		if (ft[i] != original[i])
		{
			printf("ft_strncpy FAILED\n");
			return;
		}

	// this time we copy more bytes than there are in src to test if the function
	// fills the remaining bytes with '\0' as stated in man

	ft = ft_strncpy(dst_ft, src, 20);
	original = strncpy(dst_original, src, 20);

	for (int j = strlen(original); j < 20; j++)
		if (ft[j] != original[j])
		{
			printf("ft_strncpy FAILED\n");
			return;
		}
	printf("ft_strncpy PASSED\n");
}

void test_ft_strcat()
{
	char dst_ft[10] = "abc";
	char dst_or[10] = "abc";
	char *src = "123";

	char *ft;
	char * or ;

	// we simply compare our strcat with the original

	ft = ft_strcat(dst_ft, src);
	or = strcat(dst_or, src);

	for (int i = 0; i < strlen(or) + 1; i++)
		if (ft[i] != or[i])
		{
			printf("ft_strcat FAILED\n");
			return;
		}
	printf("ft_strcat PASSED\n");
}

void test_ft_strncat()
{
	char dst_ft[15] = "abcdef";
	char dst_or[15] = "abcdef";
	char *src = "12345";

	char *ft;
	char *or;

	// we first try to copy only 3 bytes from src to dst_ft and dst_or

	ft = ft_strncat(dst_ft, src, 3);
	or = strncat(dst_or, src, 3);

	for (int i = 0; i < strlen(or) + 1; i++)
		if (ft[i] != or[i])
		{
			printf("ft_strncat FAILED\n");
			return;
		}

	// then we try to copy more bytes than there are in src to dst_ft and dst_or
	ft = ft_strncat(dst_ft, src, 10);
	or = strncat(dst_or, src, 10);
	for (int i = 0; i < strlen(or ) + 1; i++)
		if (ft[i] != or[i])
		{
			printf("ft_strncat FAILED\n");
			return;
		}
	printf("ft_srncat PASSED\n");
}

void test_ft_strlcat()
{
	char *src = "abc";
	char dst1_ft[10] = "123";
	char dst1_or[10] = "123";
	char dst2_ft[5] = "123";
	char dst2_or[5] = "123";
	char dst3_ft[10] = { '1','2','3','4','5','6','7','8','9','0'};
	char dst3_or[10] = { '1','2','3','4','5','6','7','8','9','0'};
	size_t ft;
	size_t or;

	// we try copying src into dst1_ft and dst1_or 
	// since they have enough space src should fully be copied at the end of dst1_ft and dst1_or

	ft = ft_strlcat(dst1_ft,src,sizeof(dst1_ft));
	or = strlcat(dst1_or,src,sizeof(dst1_or));
	if (ft != or)
	{
		printf("ft_strlcat FAILED\n");
		return ;
	}

	for (int i = 0;i < or;i++)
		if (dst3_ft[i] != dst3_or[i])
		{
			printf("ft_strlcat FAILED\n");
			return ;
		}

	// we try to copy src into dst2_ft and dst2_or
	// since the size of dst2_ft and dst2_or is 5, there's space for only one character from src
	// to be concatenated at the end of the strings before terminating them with '\0'

	ft = ft_strlcat(dst2_ft,src,sizeof(dst2_ft));
	or = strlcat(dst2_or,src,sizeof(dst2_or));

	if (ft != or)
	{
		printf("ft_strlcat FAILED\n");
		return ;
	}

	for (int i = 0;i < 5; i++)
		if (dst2_ft[i] != dst2_or[i])
		{
			printf("ft_strlcat FAILED\n");
			return ;
		}
	// we try to copy src at the end of dst3_ft and dst3_or
	// since dst3_ft and dst3_or are not NUL terminated no change to either of them should occur
	// sizeof(dst3_ft) + strlen(src) and sizeof(dst3_or) + strlen(src) should be returned

	ft = ft_strlcat(dst3_ft, src, sizeof(dst3_ft));
	or = strlcat(dst3_or, src, sizeof(dst3_or));

	if (ft != or)
	{
		printf("ft_strlcat FAILED\n");
		return ;
	}

	for (int i = 0;i < 10;i++)
		if (dst3_ft[i] != dst3_or[i])
		{
			printf("ft_strlcat FAILED\n");
			return ;
		}

	printf("ft_strlcat PASSED\n");
}

void test_ft_strchr()
{
	char *x23 = "abcdeffedcba";
	char *ft;
	char *or;

	// we try to locate 'f' in x23

	ft = ft_strchr(x23, 102);
	or = strchr(x23, 102);

	if (ft != or || *ft != 'f')
	{
		printf("ft_strchr FAILED\n");
		return ;
	}

	// we try to locate '\0' in x23

	ft = ft_strchr(x23, 0);
	or = strchr(x23, 0);

	if (ft != or || *ft != '\0')
	{
		printf("ft_strchr FAILED\n");
		return ;
	}

	// we try to locate 'K' in x23

	ft = ft_strchr(x23, 75);
	or = strchr(x23, 75);

	if (ft != or)
	{
		printf("ft_strchr FAILED\n");
		return ;
	}
	printf("ft_strchr PASSED\n");
}

void test_ft_strrchr()
{
	char *x23 = "abcdeffedcba";
	char *ft;
	char *or;

	// we try to locate the last occurence of 'f' in x23
	// a pointer to that occurence should be returned

	ft = ft_strrchr(x23, 102);
	or = strrchr(x23, 102);

	if (ft != or || *ft != 'f')
	{
		printf("ft_strrchr FAILED\n");
		return ;
	}

	// we try to locate '\0' in x23
	// a pointer to '\0' at the end of x23 should be returned
	
	ft = ft_strrchr(x23, 0);
	or = strrchr(x23, 0);

	if (ft != or || *ft != '\0')
	{
		printf("ft_strrchr FAILED\n");
		return ;
	}

	// we try to locate 'K' in x23
	// since 'K' is not in x23, NULL should be returned
	
	ft = ft_strrchr(x23, 75);
	or = strrchr(x23, 75);

	if (ft != or)
	{
		printf("ft_strrchr FAILED\n");
		return ;
	}
	printf("ft_strrchr PASSED\n");
}

void test_ft_strstr()
{
	char *x23 = "abcdefghijkabcdefghijk";
	char *first = "";
	char *second = "def";
	char *third = "xyz";

	char *ft;
	char *or;

	// since first is an empty string a pointer to the begining of x23 should be returned
	
	ft = ft_strstr(x23, first);
	or = strstr(x23, first);

	if (ft != or)
	{
		printf("ft_strstr FAILED\n");
		return ;
	}

	// a pointer to the first occurence of "def" in x23 should be returned

	ft = ft_strstr(x23, second);
	or = strstr(x23, second);

	if (ft != or)
	{
		printf("ft_strstr FAILED\n");
		return ;
	}

	// NULL should be returned

	ft = ft_strstr(x23, third);
	or = strstr(x23, third);

	if (ft != or)
	{
		printf("ft_strstr FAILED\n");
		return ;
	}
	printf("ft_strstr PASSED\n");
}

void test_ft_strnstr()
{
	char *x23 = "abcdefghijkabcdefghijk";
	char *first = "";
	char *second = "def";

	char *ft;
	char *or;

	// since first is an empty string a pointer to the begining of x23 should be returned
	
	ft = ft_strnstr(x23, first, 7);
	or = strnstr(x23, first, 7);

	if (ft != or)
	{
		printf("ft_strnstr FAILED\n");
		return ;
	}

	// a pointer to the first occurence of "def" in x23 should be returned

	ft = ft_strnstr(x23, second, 6);
	or = strnstr(x23, second, 6);

	if (ft != or)
	{
		printf("ft_strnstr FAILED\n");
		return ;
	}

	// NULL should be returned

	ft = ft_strnstr(x23, second, 5);
	or = strnstr(x23, second, 5);

	if (ft != or)
	{
		printf("ft_strnstr FAILED\n");
		return ;
	}
	printf("ft_strnstr PASSED\n");
}

void test_ft_strcmp()
{
	char *s1 = "abc";
	char *s2 = "aba";
	char *s3 = "abz";
	char *s4 = "ab";
	char *s5 = "abcd";
	char *s6 = "abç";

	if (ft_strcmp(s1, s1) != strcmp(s1, s1) ||
		ft_strcmp(s1, s2) != strcmp (s1, s2) ||
		ft_strcmp(s1, s3) != strcmp (s1, s3) ||
		ft_strcmp(s1, s4) != strcmp (s1, s4) ||
		ft_strcmp(s1, s5) != strcmp (s1, s5) ||
		ft_strcmp(s1, s6) != strcmp (s1, s6))
	{
		printf("ft_strcmp FAILED\n");
		return ;
	}

	printf("ft_strcmp PASSED\n");
}

void test_ft_strncmp()
{
	char *s1 = "abc";
	char *s2 = "aba";
	char *s3 = "abz";
	char *s4 = "ab";
	char *s23 = "abç";

	if (ft_strncmp(s1, s2, 2) != strncmp(s1, s2, 2) ||
		ft_strncmp(s1, s2, 3) != strncmp(s1, s2, 3) ||
		ft_strncmp(s1, s3, 3) != strncmp(s1, s3, 3) ||
		ft_strncmp(s1, s4, 3) != strncmp(s1, s4, 3) ||
		ft_strncmp(s4, s1, 3) != strncmp(s4, s1, 3) ||
		ft_strncmp(s1, s23, 23) != strncmp(s1, s23, 23))
	{
		printf("ft_strncmp FAILED\n");
		return ;
	}

	printf("ft_strncmp PASSED\n");
}

void test_ft_atoi()
{
	char *t1 = "123";
	char *t2 = "-123";
	char *t3 = "123a123";
	char *t4 = "-000123a123";
	char *t5 = "+000123\n123";
	char *t6 = "+-123\r123";
	char *t7 = "-+123 123";
	char *t8 = " \n\t\f\r\v123/123";
	char *t9 = " \n\t\f\r\v-123/123";
	char *t10 = "            2147483647_max_int";
	char *t23 = "            -2147483648_min_int";
	char *t66 = "     +99999999999999";
	char *t32 = "     -99999999999999";
	char *t99 = "`99";

	if (ft_atoi(t1) != atoi(t1) ||
		ft_atoi(t2) != atoi(t2) ||
		ft_atoi(t3) != atoi(t3) ||
		ft_atoi(t4) != atoi(t4) ||
		ft_atoi(t5) != atoi(t5) ||
		ft_atoi(t6) != atoi(t6) ||
		ft_atoi(t7) != atoi(t7) ||
		ft_atoi(t8) != atoi(t8) ||
		ft_atoi(t9) != atoi(t9) ||
		ft_atoi(t10) != atoi(t10) ||
		ft_atoi(t23) != atoi(t23) ||
		ft_atoi(t32) != atoi(t32) ||
		ft_atoi(t66) != atoi(t66) ||
		ft_atoi(t99) != atoi(t99))
	{
		printf("ft_atoi FAILED\n");
		return ;
	}
	printf("ft_atoi PASSED\n");
}

void	test_ft_isalpha()
{
	if (!ft_isalpha('a') || !isalpha('a') ||
		!ft_isalpha('Z') || !isalpha('Z') ||
		ft_isalpha('7') || isalpha('7') ||
		ft_isalpha('\\') || isalpha('\\') ||
		ft_isalpha(127) || isalpha(127))
	{
		printf("ft_isalpha FAILED\n");
		return ;
	}
	printf("ft_isalpha PASSED\n");
}

void	test_ft_isdigit()
{
	if (!ft_isdigit('0') || !isdigit('0') ||
		!ft_isdigit('9') || !isdigit('9') ||
		ft_isdigit(' ') || isdigit(' ') ||
		ft_isdigit('\\') || isdigit('\\'))
	{
		printf("ft_isdigit FAILED\n");
		return ;
	}
	printf("ft_isdigit PASSED\n");
}

void	test_ft_isalnum()
{
	if (!ft_isalnum('a') || !isalnum('a') ||
		!ft_isalnum('Z') || !isalnum('Z') ||
		!ft_isalnum('0') || !isalnum('0') ||
		!ft_isalnum('9') || !isalnum('9') ||
		ft_isalnum(' ') || isalnum(' ') ||
		ft_isalnum('=') || isalnum('=') ||
		ft_isalnum('\\') || isalnum('\\') ||
		ft_isalnum(127) || isalnum(127))
	{
		printf("ft_isalnum FAILED\n");
		return ;
	}
	printf("ft_isalnum PASSED\n");
}

void	test_ft_isascii()
{
	if (!ft_isascii(0) || !isascii(0) ||
		!ft_isascii(64) || !isascii(64) ||
		!ft_isascii(127) || !isascii(127) ||
		ft_isascii(128) || isascii(128) ||
		ft_isascii(-1) || isascii(-1))
	{
		printf("ft_isascii FAILED\n");
		return ;
	}
	printf("ft_isascii PASSED\n");
}

void	test_ft_isprint()
{
	if (!ft_isprint(32) || !isprint(32) ||
		!ft_isprint(126) || !isprint(126) ||
		ft_isprint(31) || isprint(31) ||
		ft_isprint(127) || isprint(127))
	{
		printf("ft_isprint FAILED\n");
		return ;
	}
	printf("ft_isprint PASSED\n");
}

void	test_ft_toupper()
{
	if (ft_toupper('a') != toupper('a') ||
		ft_toupper('z') != toupper('z') ||
		ft_toupper('K') != toupper('K') ||
		ft_toupper(0) != toupper(0) ||
		ft_toupper(127) != toupper(127) ||
		ft_toupper(-999) != toupper(-999))
	{
		printf("ft_toupper FAILED\n");
		return ;
	}
	printf("ft_toupper PASSED\n");
}

void	test_ft_tolower()
{
	if (ft_tolower('A') != tolower('A') ||
		ft_tolower('Z') != tolower('Z') ||
		ft_tolower('k') != tolower('k') ||
		ft_tolower(0) != tolower(0) ||
		ft_tolower(127) != tolower(127) ||
		ft_tolower(-999) != tolower(-999))
	{
		printf("ft_tolower FAILED\n");
		return ;
	}
	printf("ft_tolower PASSED\n");
}

int main()
{
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memccpy();
	test_ft_memmove();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strlen();
	test_ft_strdup();
	test_ft_strcpy();
	test_ft_strncpy();
	test_ft_strcat();
	test_ft_strncat();
	test_ft_strlcat();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strstr();
	test_ft_strnstr();
	test_ft_strcmp();
	test_ft_strncmp();
	test_ft_atoi();
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_toupper();
	test_ft_tolower();

	return (0);
}
