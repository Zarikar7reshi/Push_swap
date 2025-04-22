#include "push_swap.h"

static int  is_num(char *str);
static int  check_number(char *str);
static int  check_overflow(char *str);
static int  check_len_sign(char *str);
static char f(unsigned int i, char c);

void    parse_args(int ac, char **av, t_stack **a)
{
    int i;
    int *num;

    i = 1;
    while (i < ac)
    {
        printf("\n");
        if (is_num(av[i]) && ac >= 2)
        {
            num = (int*)malloc(sizeof(int));
            if (!num)
            {
                printf("Error\n");
                free(num);
                exit(-1);
            }
            *num = ft_atoi(av[i]);
            push(a, num);
            i++;
        }
        else
        {
            // ft_printf("Error\n");
            printf("Error\n");
            free(num);
            exit(-1);
        }
    }
}

// validate length
// validate only digits
// validate int range

static int  is_num(char *str)
{
    printf("cls\t");
    if (!check_len_sign(str))
        return (0);
    printf("cn\t");
    if (!check_number(str))
        return (0);
    printf("co\t");
    if (!check_overflow(str))
        return (0);
    printf("all");
    return (1);
}

static int  check_number(char *str)
{
    char    *ctrl;
    char    *tmp;

    if(!str || *str == '\0')
        return (0);
    if(*str == '-' || *str == '+')
        str++;
    ctrl = ft_strmapi(str, f);
    if(!ctrl || *ctrl == '\0')
        return (0);
    tmp = ft_strchr(ctrl, '0');
    if (!tmp || *tmp == '\0')
        return (free(ctrl), 1);
    else
        return (free(ctrl), 0);
}

static int  check_overflow(char *str)
{
    int num;
    int err;

    num = atoi_checked(str, &err);
    printf("num: %d, errno: %d\t", num, err);
    if (err == ATOI_ERRNO)
        return (0);
    return (1);
}

static char f(unsigned int i, char c)
{
    (void)i;
    if (ft_isdigit(c))
        return ('1');
    return ('0');
}

static int  check_len_sign(char *str)
{
    int len;

    len = ft_strlen(str);
    printf("len: %d\t", len);
    if (len > 10)
    {
        if (len > 11 && (str[0] == '-' || str[0] == '+'))
            return (0);
        else
            return (1);
    }
    return (1);
}