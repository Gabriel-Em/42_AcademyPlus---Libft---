#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

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

	return (0);
}
