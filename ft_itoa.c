#include "libft.h"

static int ft_len(int nb)
{
    int len;
    len = 0;
    if (nb == 0)
        return (1);
    if (nb < 0)
    {
        nb *= -1;
        len++;
    }
    while (nb > 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
}

static void ft_res(int i, int n, char *ans)
{
    while (i-- && n > 0)
    {
        ans[i] = (n % 10) + 48;
        n /= 10;
    }
}

char *ft_itoa(int n)
{
    char *ans;
    int i;

    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    i = ft_len(n);
    ans = (char *) malloc(sizeof(char) * (i + 1));
    if (ans == NULL)
        return (NULL);
    ans[i--] = '\0';
    if (n == 0)
    {
        ans[0] = '0';
        return (ans);
    }
    if (n < 0)
    {
        ans[0] = '-';
        n *= -1;
    }
    ft_res(++i, n, ans);
    return (ans);
}
