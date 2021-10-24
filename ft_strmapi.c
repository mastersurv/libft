#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int i;
    int		len;
    char	*str;

    i = 0;
    len = 0;
    if (!s || !f)
        return (NULL);
    while (s[len])
        len++;
    str = (char*)malloc(sizeof(*str) * (len + 1));
    if (str == NULL)
        return (str);
    while (i < len)
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}
