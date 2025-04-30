#include "push_swap.h"

static int  is_num(char *str);
static int  check_number(char *str);
static int  check_overflow(char *str);
static int  check_len_sign(char *str);
static char f(unsigned int i, char c);

void    parse_args(int ac, char **av, t_stack **a)
{
    int i;
    t_stacknode *num;

    i = ac - 1;
    while (i >= 1)
    {
        if (is_num(av[i]) && ac >= 2)
        {
            // TODO: transform into s_node
            num = (t_stacknode *)malloc(sizeof(t_stacknode));
            if (!num)
            {
                ft_printf("Error\n");
                free_stack(a);
                free(*a);
                exit(-1);
            }
            num->value = ft_atoi(av[i]);
            push(a, num);
            i--;
        }
        else
        {
            ft_printf("Error\n");
            free_stack(a);
            free(*a);
            exit(-1);
        }
        // printf("\n");
    }
    // check_duplicates(*a);
}

// validate length
// validate only digits
// validate int range

static int  is_num(char *str)
{
    if (!check_len_sign(str))
        return (0);
    if (!check_number(str))
        return (0);
    if (!check_overflow(str))
        return (0);
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
    if (len > 10)
    {
        if (len > 11 && (str[0] == '-' || str[0] == '+'))
            return (0);
        else
            return (1);
    }
    return (1);
}