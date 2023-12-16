#include "shell.h"

/**
 * custom_strdup - Duplicate a string.
 * @string: The string to duplicate.
 * Return: A pointer to the duplicated string.
 */

char *custom_strdup(const char *string)
{
char *ptr;
int i, len = 0;
if (string == NULL)
{
return (NULL);
}
while (*string != '\0')
{
len++;
string++;
}
string = string - len;
ptr = malloc(sizeof(char) * (len + 1));
if (ptr == NULL)
return (NULL);
for (i = 0; i <= len; i++)
ptr[i] = string[i];
return (ptr);
}
/**
 * custom_strcmp - Compare two strings.
 * @string1: The first string.
 * @string2: The second string.
 * Return: 0 if the strings are equal, a negative value if s1 < s2,
 *         or a positive value if s1 > s2.
 */

int custom_strcmp(char *string1, char *string2)
{
int cmp;
cmp = (int)*string1 - (int)*string2;
while (*string1)
{
if (*string1 != *string2)
break;
string1++;
string2++;
cmp = (int)*string1 - (int)*string2;
}
return (cmp);
}
/**
 * custom_strlen - Calculate the length of a string.
 * @string: The string.
 * Return: The length of the string.
 */

int custom_strlen(char *string)
{
int len = 0;
while (string[len])
len++;
return (len);
}
/**
 * custom_strcat - Concatenate two strings.
 * @d: The destination string.
 * @s: The source string.
 * Return: A pointer to the concatenated string.
 */

char *custom_strcat(char *d, char *s)
{
char *p = d;
while (*p)
p++;
while (*s)
{
*p = *s;
p++;
s++;
}
*p = '\0';
return (d);
}
/**
 * custom_strcopy - Copy a string.
 * @d: The destination string.
 * @s: The source string.
 * Return: A pointer to the destination string.
 */

char *custom_strcopy(char *d, char *s)
{
int i = 0;
while (s[i])
{
d[i] = s[i];
i++;
}
d[i] = '\0';
return (d);
}

