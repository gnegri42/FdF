/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:07:54 by gnegri            #+#    #+#             */
/*   Updated: 2017/11/22 11:50:21 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"


/************************************ PART 1 **********************************/

/*************************************/
/********* TEST FT_MEMSET ************/
/*************************************/

void	ft_test_memset(void)
{
	printf("******************************** PART 1 ******************************\n");
	printf("******TEST FT_MEMSET*****\n");

	char	b1[100];

	if (strcmp(memset(b1, 99, 0), ft_memset(b1, 99, 0)) == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_BZERO ************/
/*************************************/

void	ft_test_bzero(void)
{
	printf("******TEST FT_BZERO*****\n");

	char a[20] = "Hello World!";
	char b[20] = "Salut les amis";
	static int int_bzero;

	int_bzero = 0;
	bzero(a, 6);
	ft_bzero(b, 6);
	while (int_bzero < 6)
	{
		if (a[int_bzero] == b[int_bzero])
			int_bzero++;
		else
			printf("FAUX\n");
	}
	printf("OK\n");
}

/*************************************/
/********* TEST FT_MEMCPY ************/
/*************************************/

void	ft_test_memcpy(void)
{
	printf("******TEST FT_MEMCPY*****\n");

	char a_memcpy[20] = "Hello World!";
	char b_memcpy[20] = "!dlroW olleH";
	char c_memcpy[20] = "Hello World!";
	char d_memcpy[20] = "!dlroW olleH";
	char e_memcpy[20] = "";
	char f_memcpy[20] = "";

	if ((strcmp(memcpy(a_memcpy, b_memcpy, 6), ft_memcpy(c_memcpy, d_memcpy, 6))) == 0)
	{
		if ((strcmp(memcpy(e_memcpy, b_memcpy, 6), ft_memcpy(f_memcpy, d_memcpy, 6))) == 0)
			printf("OK\n");
	}
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_MEMCCPY ************/
/*************************************/

void	ft_test_memccpy(void)
{
	printf("******TEST FT_MEMCCPY*****\n");

	char a_memccpy[20] = "Salut oh toi";
	char b_memccpy[20] = "Test123Testa";
	char c_memccpy[20] = "Salut oh toi";
	char d_memccpy[20] = "Salut oh toi";
	char e_memccpy[20] = "Salut oh toi";
	char f_memccpy[20] = "Salut oh toi";
	char g_memccpy[20] = "Salut oh toi";

	char h_memccpy[20] = "";
	char i_memccpy[20] = "";
	char j_memccpy[20] = "";

	memccpy(a_memccpy, b_memccpy, '\0', 12);
	ft_memccpy(d_memccpy, b_memccpy, '\0', 12);
	if ((strcmp(a_memccpy, d_memccpy)) == 0)
	{
		memccpy(c_memccpy, b_memccpy, 'l', 6);
		ft_memccpy(e_memccpy, b_memccpy, 'l', 6);
		if ((strcmp(c_memccpy, e_memccpy)) == 0)
		{
			memccpy(f_memccpy, b_memccpy, 'o', 6);
			ft_memccpy(g_memccpy, b_memccpy, 'o', 6);
			if ((strcmp(f_memccpy, g_memccpy)) == 0)
			{
				memccpy(i_memccpy, h_memccpy, 'a', 6);
				ft_memccpy(j_memccpy, h_memccpy, 'a', 6);
				if ((strcmp(i_memccpy, j_memccpy)) == 0)
					printf("OK\n");
			}
		}
	}
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_MEMMOVE ************/
/*************************************/

void	ft_test_memmove(void)
{
	printf("******TEST FT_MEMMOVE*****\n");

	char	testA1[] = "abcdef";
	char	testA2[] = "abcdef";

	ft_memmove(testA1 + 1, testA1, 5);
	ft_memmove(testA1 + 1, testA1, 0);
	memmove(testA2 + 1, testA2, 5);
	memmove(testA2 + 1, testA2, 0);
	if ((strcmp(testA1, "aabcde") == 0)
			&& (strcmp(testA1, testA2) == 0))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_MEMCHR ************/
/*************************************/

void	ft_test_memchr(void)
{
	printf("******TEST FT_MEMCHR*****\n");

	char a[12] = "Hello World!";

    if (memchr(a, 'r', 6) == (ft_memchr(a, 'r', 6)) &&
    	(strcmp(memchr(a, 'r', 12), ft_memchr(a, 'r', 12)) == 0))
    	printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST TF_MEMCMP ************/
/*************************************/

void	ft_test_memcmp(void)
{
	printf("******TEST TF_MEMCMP*****\n");

    if (ft_memcmp("ab\0ab", "ab\0ab", 6) == memcmp("ab\0ab", "ab\0ab", 6) && 
		ft_memcmp("aaa", "aab", 4) == memcmp("aaa", "aab", 4) &&
		ft_memcmp("aww", "bpp", 0) == memcmp("aww", "bpp", 0))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRLEN ************/
/*************************************/
void	ft_test_strlen(void)
{
	printf("******TEST FT_STRLEN*****\n");
	if (ft_strlen("blablabla") == strlen("blablabla") &&
		ft_strlen("test1234") == strlen("test1234") &&
		ft_strlen("") == strlen(""))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRDUP ************/
/*************************************/
void	ft_test_strdup(void)
{
	printf("******TEST FT_STRDUP*****\n");
	if (strcmp(ft_strdup("blablabla"), strdup("blablabla")) == 0 &&
		strcmp(ft_strdup("test1234"), strdup("test1234")) == 0 &&
		strcmp(ft_strdup(""), strdup("")) == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRCPY ************/
/*************************************/

void	ft_test_strcpy(void)
{

	char	buf1[6], buf2[6];

	bzero(buf1, 6);
	bzero(buf2, 6);

	printf("******TEST FT_STRCPY*****\n");
	if ((strcmp(ft_strcpy(buf1, "abcde"), strcpy(buf1, "abcde")) == 0) &&
		(strcmp(ft_strcpy(buf1, "abc"), strcpy(buf1, "abc")) == 0))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRNCPY ************/
/*************************************/

void	ft_test_strncpy(void)
{

	char	buf1[6], buf2[6];

	memset(buf1, 33, 6);
	memset(buf2, 33, 6);

	printf("******TEST FT_STRNCPY*****\n");
	if ((strcmp(ft_strncpy(buf1, "abc", 6), strncpy(buf1, "abc", 6)) == 0) &&
		(strcmp(ft_strncpy(buf2, "abcdefghi", 6), strncpy(buf2, "abcdefghi", 6)) == 0))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRCAT ************/
/*************************************/

void	ft_test_strcat(void)
{

	char	buf[9];
	bzero(buf, 9);

	printf("******TEST FT_STRCAT*****\n");
	if (strcmp(ft_strcat(buf, ""), strcat(buf, "")) == 0 &&
		strcmp(ft_strcat(buf, "Bon"), strcat(buf, "Bon")) == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRNCAT ************/
/*************************************/

void	ft_test_strncat(void)
{

	char	buf[20];
	char	buf2[20];

	printf("******TEST FT_STRNCAT*****\n");

	strcpy(buf, "1234567890123456789");
	strcpy(buf, "To be ");
	ft_strncat(buf, "or not to be", 6);
	if (strcmp(buf, "To be or not") == 0)
		printf("OK 1\n");
	else
		printf("FAUX 1\n");

	strcpy(buf2, "To be ");
	ft_strncat(buf2, "or not to be", 6);
	ft_strncat(buf2, "efefef", 0);
	if (strcmp(buf2, "To be or not") == 0 &&
		buf2 == ft_strncat(buf2, "", 0))
		printf("OK 2\n");
	else
		printf("FAUX 2\n");
}

/*************************************/
/********* TEST FT_STRCHR ************/
/*************************************/
void	ft_test_strchr(void)
{
	printf("******TEST FT_STRCHR*****\n");
	/*printf("%s\n", ft_strchr("Je suis un poisson.", 'p'));
	printf("%s\n", strchr("Je suis un poisson.", 'p'));
	printf("%s\n", ft_strchr("Je suis un poisson.", 'z'));
	printf("%s\n", strchr("Je suis un poisson.", 'z'));*/
	if (ft_strchr("Je suis un poisson.", 'p') == strchr("Je suis un poisson.", 'p') &&
		ft_strchr("Je suis un poisson.", '0') == strchr("Je suis un poisson.", '0') &&
		ft_strchr("Je suis un poisson.", 'J') == strchr("Je suis un poisson.", 'J') &&
		ft_strchr("Je suis un poisson.", 'z') == strchr("Je suis un poisson.", 'z'))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRRCHR ************/
/*************************************/
void	ft_test_strrchr(void)
{
	printf("******TEST FT_STRRCHR*****\n");
	/*printf("%s\n", ft_strrchr("Je suis un poisson.", 'p'));
	printf("%s\n", strrchr("Je suis un poisson.", 'p'));
	printf("%s\n", ft_strrchr("Je suis un poisson.", 'z'));
	printf("%s\n", strrchr("Je suis un poisson.", 'z'));
	printf("%s\n", ft_strrchr("Je suis un poisson.", 's'));
	printf("%s\n", strrchr("Je suis un poisson.", 's'));*/
	if (ft_strrchr("Je suis un poisson.", 'p') == strrchr("Je suis un poisson.", 'p') &&
		ft_strrchr("Je suis un poisson.", '0') == strrchr("Je suis un poisson.", '0') &&
		ft_strrchr("Je suis un poisson.", 'J') == strrchr("Je suis un poisson.", 'J') &&
		ft_strrchr("Je suis un poisson.", 'z') == strrchr("Je suis un poisson.", 'z'))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRSTR ************/
/*************************************/
void	ft_test_strstr(void)
{
	printf("******TEST FT_STRSTR*****\n");
	if (ft_strstr("Ceci n'est pas une pipe.", "une") == strstr("Ceci n'est pas une pipe.", "une") &&
		ft_strstr("Ceci n'est pas une pipe.", "C") == strstr("Ceci n'est pas une pipe.", "C") &&
		ft_strstr("Ceci n'est pas une pipe.", ".") == strstr("Ceci n'est pas une pipe.", ".") &&
		ft_strstr("Ceci n'est pas une pipe.", "") == strstr("Ceci n'est pas une pipe.", "") &&
		ft_strstr("Ceci n'est pas une pipe.", "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA") == strstr("Ceci n'est pas une pipe.", "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA") &&
		ft_strstr("J'ai fait pipapipapou en LV2", "pipapou") == strstr("J'ai fait pipapipapou en LV2", "pipapou"))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRNSTR ************/
/*************************************/
void	ft_test_strnstr(void)
{
	printf("******TEST FT_STRNSTR*****\n");
	if (ft_strnstr("Ceci n'est pas une pipe.", "une", 23) == strnstr("Ceci n'est pas une pipe.", "une", 23) &&
		ft_strnstr("Ceci n'est pas une pipe.", "C", 5) == strnstr("Ceci n'est pas une pipe.", "C", 5) &&
		ft_strnstr("Ceci n'est pas une pipe.", ".", 0) == strnstr("Ceci n'est pas une pipe.", ".", 0) &&
		ft_strnstr("Ceci n'est pas une pipe.", "", 10) == strnstr("Ceci n'est pas une pipe.", "", 10) &&
		ft_strnstr("Ceci n'est pas une pipe.", "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 5) == strnstr("Ceci n'est pas une pipe.", "BWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 5) &&
		ft_strnstr("J'ai fait pipapipapou en LV2", "pipapou", 6) == strnstr("J'ai fait pipapipapou en LV2", "pipapou", 6))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRCMP ************/
/*************************************/
void	ft_test_strcmp(void)
{
	printf("******TEST FT_STRCMP*****\n");
	if (ft_strcmp("blablabla", "blablabla") == strcmp("blablabla", "blablabla") &&
		ft_strcmp("", "") == strcmp("", "") &&
		ft_strcmp("123", "1") == strcmp("123", "1"))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRNCMP ************/
/*************************************/
void	ft_test_strncmp(void)
{
	printf("******TEST FT_STRNCMP*****\n");
	if (ft_strncmp("blabla", "blablabla", 5) == strncmp("blabla", "blablabla", 5) &&
		ft_strncmp("abc", "abcde", 3) == strncmp("abc", "abcde", 3) &&
		ft_strncmp("abce", "abcde", 5) == strncmp("abce", "abcde", 5) &&
		ft_strncmp("", "", 3) == strncmp("", "", 3) &&
		ft_strncmp("r", "3", 0) == strncmp("r", "3", 0) &&
		ft_strncmp("123", "1", 2) == strncmp("123", "1", 2))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/*********** TEST FT_ATOI ************/
/*************************************/

void	ft_test_atoi(void)
{
	printf("******TEST FT_ATOI*****\n");
	if (ft_atoi("+123") == atoi("+123") &&
		ft_atoi("-2598") == atoi("-2598") &&
		ft_atoi("    165ew1654") == atoi("    165ew1654") &&
		ft_atoi("-2147483648") == atoi("-2147483648") &&
		ft_atoi("++5823") == atoi("++5823") &&
		ft_atoi("") == atoi("") &&
		ft_atoi("  \t\n  \r\r\v\f-899") == atoi("  \t\n  \r\r\v\f-899") &&
		ft_atoi("000000000000000110") == atoi("000000000000000110") &&
		ft_atoi("123qwe123") == atoi("123qwe123"))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/*********** TEST FT_ISALPHA ************/
/*************************************/

void	ft_test_isalpha(void)
{
	printf("******TEST FT_ISALPHA*****\n");
	if (ft_isalpha('a') == isalpha('a') &&
		ft_isalpha('2') == isalpha('2') &&
		ft_isalpha(9999) == isalpha(9999) &&
		ft_isalpha('Z') == isalpha('Z') &&
		ft_isalpha('\n') == isalpha('\n') &&
		ft_isalpha(' ') == isalpha(' '))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/*********** TEST FT_ISDIGIT ************/
/*************************************/

void	ft_test_isdigit(void)
{
	printf("******TEST FT_ISDIGIT*****\n");
	if (ft_isdigit('a') == isdigit('a') &&
		ft_isdigit('2') == isdigit('2') &&
		ft_isdigit(9999) == isdigit(9999) &&
		ft_isdigit('Z') == isdigit('Z') &&
		ft_isdigit('\n') == isdigit('\n') &&
		ft_isdigit(' ') == isdigit(' '))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/*********** TEST FT_ISALNUM ************/
/*************************************/

void	ft_test_isalnum(void)
{
	printf("******TEST FT_ISALNUM*****\n");
	if (ft_isalnum('a') == isalnum('a') &&
		ft_isalnum('2') == isalnum('2') &&
		ft_isalnum(9999) == isalnum(9999) &&
		ft_isalnum('Z') == isalnum('Z') &&
		ft_isalnum('\n') == isalnum('\n') &&
		ft_isalnum(' ') == isalnum(' '))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/*********** TEST FT_ISASCII ************/
/*************************************/

void	ft_test_isascii(void)
{
	printf("******TEST FT_ISASCII*****\n");
	if (ft_isascii('a') == isascii('a') &&
		ft_isascii('2') == isascii('2') &&
		ft_isascii(9999) == isascii(9999) &&
		ft_isascii('a' + 0x100) == isascii('a' + 0x100) &&
		ft_isascii('\n') == isascii('\n') &&
		ft_isascii('%') == isascii('%') &&
		ft_isascii(' ') == isascii(' '))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/****************************************/
/*********** TEST FT_ISPRINT ************/
/****************************************/

void	ft_test_isprint(void)
{
	printf("******TEST FT_ISPRINT*****\n");
	if (ft_isprint('a') == isprint('a') &&
		ft_isprint('2') == isprint('2') &&
		ft_isprint(9999) == isprint(9999) &&
		ft_isprint('a' + 0x100) == isprint('a' + 0x100) &&
		ft_isprint('\n') == isprint('\n') &&
		ft_isprint('%') == isprint('%') &&
		ft_isprint(' ') == isprint(' '))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/****************************************/
/*********** TEST FT_TOUPPER ************/
/****************************************/

void	ft_test_toupper(void)
{
	printf("******TEST FT_TOUPPER*****\n");
	if (ft_toupper('a') == toupper('a') &&
		ft_toupper('2') == toupper('2') &&
		ft_toupper(9999) == toupper(9999) &&
		ft_toupper('a' + 0x100) == toupper('a' + 0x100) &&
		ft_toupper('\n') == toupper('\n') &&
		ft_toupper('%') == toupper('%') &&
		ft_toupper('A') == toupper('A') &&
		ft_toupper('Z') == toupper('Z') &&
		ft_toupper(' ') == toupper(' '))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/****************************************/
/*********** TEST FT_TOLOWER ************/
/****************************************/

void	ft_test_tolower(void)
{
	printf("******TEST FT_TOLOWER*****\n");
	if (ft_tolower('a') == tolower('a') &&
		ft_tolower('2') == tolower('2') &&
		ft_tolower(9999) == tolower(9999) &&
		ft_tolower('a' + 0x100) == tolower('a' + 0x100) &&
		ft_tolower('\n') == tolower('\n') &&
		ft_tolower('%') == tolower('%') &&
		ft_tolower('A') == tolower('A') &&
		ft_tolower('B') == tolower('B') &&
		ft_tolower(' ') == tolower(' '))
		printf("OK\n");
	else
		printf("FAUX\n");
}

/************************************ PART 2 **********************************/

/*************************************/
/********* TEST FT_STRCLR ************/
/*************************************/
void	ft_test_strclr(void)
{
	printf("******************************** PART 2 ******************************\n");
	printf("******TEST FT_STRCLR*****\n");
	char	str[] = "tttttt";

	ft_strclr(str);
	if (memcmp(str, "\0\0\0\0\0\0", 7) == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRITER ************/
/*************************************/

void	it_test(char *c)
{
	*c = *c + 1;
}

void	ft_test_striter(void)
{
	printf("******TEST FT_STRITER*****\n");
	char	str[] = "aBcDeF";

	ft_striter(str, it_test);
	if (strcmp(str, "bCdEfG") == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRITERI ************/
/*************************************/

void	iti_test(unsigned int i, char *c)
{
	*c = *c + i;
}

void	ft_test_striteri(void)
{
	printf("******TEST FT_STRITERI*****\n");
	char	str[] = "aBcDeF";

	ft_striteri(str, iti_test);
	if (strcmp(str, "aCeGiK") == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRMAP ************/
/*************************************/

char	map_test(char c)
{
	return (c + 1);
}

void	ft_test_strmap(void)
{
	printf("******TEST FT_STRMAP*****\n");
	char	*src;
	char	*dst;

	src = strdup("abcde");
	dst = ft_strmap(src, map_test);

	free(src); 
	src = NULL;

	if (strcmp(dst, "bcdef") == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRMAPI ************/
/*************************************/

char	mapi_test(unsigned int i, char c)
{
	return (c - i);
}

void	ft_test_strmapi(void)
{
	printf("******TEST FT_STRMAPI*****\n");
	char	*src;
	char	*dst;

	src = strdup("eeeee");
	dst = ft_strmapi(src, mapi_test);

	free(src);
	src = NULL;

	if (strcmp(dst, "edcba") == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STREQU ************/
/*************************************/

void	ft_test_strequ(void)
{
	printf("******TEST FT_STREQU*****\n");
	if (ft_strequ("", "") == 1 &&
		ft_strequ("abcDEF", "abcDEF") == 1 &&
		ft_strequ("abcDEF", "abcDEf") == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRNEQU ************/
/*************************************/

void	ft_test_strnequ(void)
{
	printf("******TEST FT_STRNEQU*****\n");
	if (ft_strnequ("ededeqdf", "", 0) == 1 &&
		ft_strnequ("abcde", "abdfe", 2) == 1 &&
		ft_strnequ("abc", "abc", 100) == 1 &&
		ft_strnequ("abcde", "abdde", 5) == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRSUB ************/
/*************************************/

void	ft_test_strsub(void)
{
	printf("******TEST FT_STRSUB*****\n");
	static char	*str = "Un jour je serai, le meilleur dresseur !";

	if (ft_strsub(str, 0, (size_t)-10) == NULL &&
		strcmp(ft_strsub(str, 8, 8), "je serai") == 0 &&
		strcmp(ft_strsub(str, 0, 0), "") == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRJOIN ************/
/*************************************/

void	ft_test_strjoin(void)
{
	printf("******TEST FT_STRJOIN*****\n");

	if (strcmp(ft_strjoin("abc", "def"), "abcdef") == 0 &&
		strcmp(ft_strjoin("", ""), "") == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_STRTRIM ************/
/*************************************/

void	ft_test_strtrim(void)
{
	printf("******TEST FT_STRTRIM*****\n");

	if (strcmp(ft_strtrim("\t\n  \tAAA \t BBB\t\n  \t"), "AAA \t BBB") == 0 &&
		strcmp(ft_strtrim("\t\t\n\t\t   "), "") == 0 &&
		strcmp(ft_strtrim(""), "") == 0 &&
		strcmp(ft_strtrim("abc"), "abc") == 0)
		printf("OK\n");
	else
		printf("FAUX\n");
}

/*************************************/
/********* TEST FT_PUTCHAR ************/
/*************************************/
void	ft_test_putchar(void)
{
	printf("******TEST FT_PUTCHAR*****\n");
	ft_putchar('a');
	ft_putchar('b');
	ft_putchar('c');
	ft_putchar('d');
	printf("\n");
}

/*************************************/
/********* TEST FT_PUTSTR ************/
/*************************************/
void	ft_test_putstr(void)
{
	printf("******TEST FT_PUTSTR*****\n");
	ft_putstr("blablabla");
	ft_putstr("");
	ft_putstr("1234");
	ft_putstr("ohohoihowehoh294jn");
	printf("\n");
}

/*************************************/
/********* TEST FT_PUTENDL ************/
/*************************************/
void	ft_test_putendl(void)
{
	printf("******TEST FT_PUTENDL*****\n");
	ft_putendl("blablabla");
	ft_putendl("");
	ft_putendl("1234");
	ft_putendl("ohohoihowehoh294jn");
}

/*************************************/
/********* TEST FT_PUTNBR ************/
/*************************************/
void	ft_test_putnbr(void)
{
	printf("******TEST FT_PUTNBR*****\n");
	ft_putnbr(5);
	ft_putnbr(10);
	ft_putnbr(890);
	ft_putnbr(-1565);
	ft_putnbr(-2147483648);
	printf("\n");
}

int		main(void)
{
	/**** PART 1 ***/
	ft_test_memset();
	ft_test_bzero();
	ft_test_memcpy();
	ft_test_memccpy();
	ft_test_memmove();
	ft_test_memchr();
	ft_test_memcmp();
	ft_test_strlen();
	ft_test_strdup();
	ft_test_strcpy();
	ft_test_strncpy();
	ft_test_strcat();
	ft_test_strncat();
	ft_test_strchr();
	ft_test_strrchr();
	ft_test_strstr();
	ft_test_strnstr();
	ft_test_strcmp();
	ft_test_strncmp();
	ft_test_atoi();
	ft_test_isalpha();
	ft_test_isdigit();
	ft_test_isalnum();
	ft_test_isascii();
	ft_test_isprint();
	ft_test_toupper();
	ft_test_tolower();

	/**** PART 2 ***/
	ft_test_strclr();
	ft_test_striter();
	ft_test_striteri();
	ft_test_strmap();
	ft_test_strmapi();
	ft_test_strequ();
	ft_test_strnequ();
	ft_test_strsub();
	ft_test_strjoin();
	ft_test_strtrim();
	ft_test_putchar();
	ft_test_putstr();
	ft_test_putendl();
	ft_test_putnbr();
	return (0);
}
