#include "../cube.h"

char    *ft_cpy_index(char *str, int i)
{
    int     i2;
    char   *new;

    i2 = 0;
    new = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
    while (i < ft_strlen(str))
    {
        new[i2] = str[i];
        i2++;
        i++;
    }
    new[i2] = '\0';
    return (new);
}

int check_path(char *path)
{
    int fd;

    if ((fd = open(path, O_WRONLY)) == -1)
        return (1);
    else
        close (fd);
    return (0);
}


int check_text_north(t_data *data, char *param)
{
    static int countn = 0;
    char   *path;

    countn++;
    if (param[0] == 'N' && param[1] == 'O')
        path = ft_cpy_index(param, 2);
    else if (param[0] == 'N')
        path = ft_cpy_index(param, 1);
    //if (check_path(path) || countn > 1)
            //return (1);
    data->param.npath = path;
    printf("npath: %s\n", data->param.npath);
    return (0);
}

int check_text_south(t_data *data, char *param)
{
    static int counts = 0;
    char   *path;

    counts++;
    if (param[0] == 'S' && param[1] == 'O')
        path = ft_cpy_index(param, 2);
    else if (param[0] == 'S')
        path = ft_cpy_index(param, 1);
    //if (check_path(path) || counts > 1)
            //return (1);
    data->param.spath = path;
    printf("spath: %s\n", data->param.spath);
    return (0);
}

int check_text_east(t_data *data, char *param)
{
    static int counte = 0;
    char   *path;

    counte++;
    if (param[0] == 'E' && param[1] == 'A')
        path = ft_cpy_index(param, 2);
    else if (param[0] == 'E')
        path = ft_cpy_index(param, 1);
    //if (check_path(path) || counte > 1)
            //return (1);
    data->param.epath = path;
    printf("epath: %s\n", data->param.epath);
    return (0);
}

int check_text_west(t_data *data, char *param)
{
    static int countw = 0;
    char   *path;

    countw++;
    if (param[0] == 'W' && param[1] == 'E')
        path = ft_cpy_index(param, 2);
    else if (param[0] == 'W')
        path = ft_cpy_index(param, 1);
    //if (check_path(path) || countw > 1)
            //return (1);
    data->param.wpath = path;
    printf("wpath: %s\n", data->param.wpath);
    return (0);
}

int check_texture(t_data *data, char *param)
{
    if (param[0] == 'N' )
    {
        if (check_text_north(data, param))
            return (1);
    }
    if (param[0] == 'S')
    {
        if (check_text_south(data, param))
            return (1);
    }
    if (param[0] == 'E')
    {
        if (check_text_east(data, param))
            return (1);
    }
    if (param[0] == 'W')
    {
        if (check_text_west(data, param))
            return (1);
    }
    return (0);
}