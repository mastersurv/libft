#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
    size_t s_len;

    if (s == NULL)
        return (0);
    s_len = ft_strlen(s);
    if (s_len < start)
        return (ft_strdup(""));
    if (start + len < s_len)
        str = (char *)malloc((len + 1) * sizeof(char));
    else
        str = (char *)malloc((s_len - start + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    ft_strlcpy(str, s + start, len + 1);
    return (str);
}
