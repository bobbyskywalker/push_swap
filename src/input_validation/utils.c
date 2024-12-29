#include "../../includes/push_swap.h"

int ft_isspace(int c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
        c == '\f' || c == '\r')
        return (1);
    return (0);
}

int ft_safe_atoi(const char *str, long *result)
{
    long num;
    int sign;

    num = 0;
    sign = 1;
    while (*str && ft_isspace((unsigned char)*str))
        str++;
    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    while (*str && ft_isdigit((unsigned char)*str))
    {
        int digit = *str - '0';
        if ((num > (LONG_MAX / 10)) || 
            (num == (LONG_MAX / 10) && digit > (LONG_MAX % 10)))
        {
            *result = 0;
            return (1);
        }
        num = num * 10 + digit;
        str++;
    }
    *result = num * sign;
    return (0);
}