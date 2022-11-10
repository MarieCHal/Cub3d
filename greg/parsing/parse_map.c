#include "../cube.h"

int check_empty_line(char *gnl, int i)
{
    int i2;

    i2 = i;
    i--;
    printf("ok check empty line\n");
    while (gnl[i] != '\n')
    {
        if (gnl[i] == '1' || gnl[i] == '0' || gnl[i] == 'N' 
        || gnl[i] == 'S' || gnl[i] == 'W' || gnl[i] == 'E' || 
        gnl[i] == ' ' )
            i--;
        else
            return (-1);
    }
    printf("i: %d\n", i);
    return (i);
}

int get_map(char *gnl, t_data *data)
{
    int i;
    int i2;
    char    *tmp;

    i = 0;
    i2 = 0;
    i = ft_strlen(gnl) - 1;
    while (i > 0)
    {
        printf("gnl i: %c\n", gnl[i]);
        while (gnl[i] == '1' || gnl[i] == '0' || gnl[i] == 'N' 
        || gnl[i] == 'S' || gnl[i] == 'W' || gnl[i] == 'E' || 
        gnl[i] == ' ' || gnl[i] ==  '\n')
        {
            if (gnl[i] == '\n')
            { 
                if ((i = check_empty_line(gnl, i)) == -1)
                    break;
            }
            else
                i--;
        }
        printf("iiiii: %d\n", i);
        tmp = malloc(sizeof(char) * i + 1);
        if (i < ft_strlen(gnl))
        {
            i++;
            while (gnl[i])
            {
                tmp[i2] = gnl[i];
                i++;
                i2++;
            }
            tmp[i2] = '\0';
            printf("map ----- %s\n", tmp);
            return (0);
        }
    }
    return (1);
}

/*int check_zero(char **map, int i, int j)
{
    if (map[j + 1][i] != '1' && map[j + 1][i] != 'N' &&
    map[j + 1][i] != 'S' && map[j + 1][i] != 'W' && map[j + 1][i] != 'E')
        return (1);
    else if (map[j - 1][i] != '1' && map[j - 1][i] != 'N' &&
    map[j - 1][i] != 'S' && map[j - 1][i] != 'W' && map[j - 1][i] != 'E')
        return (1);
    else if (map[j][i + 1] != '1' && map[j][i + 1] != 'N' &&
    map[j][i + 1] != 'S' && map[j][i + 1] != 'W' && map[j][i + 1] != 'E')
        return (1);
    else if (map[j][i - 1] != '1' && map[j][i - 1] != 'N' &&
    map[j][i - 1] != 'S' && map[j][i - 1] != 'W' && map[j][i - 1] != 'E')
        return (1);
    return (0);
}

int parse_map(t_data *data, char **params, int j)
{
    int i;
    char    *tmp;

    i = 0;
    while (params[j])
    {
        while (tmp[0] == 1)
        tmp = ft_parse_spaces(params[j]);
        
    }
}*/