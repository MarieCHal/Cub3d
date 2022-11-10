#include "../cube.h"

//init color numbers to negative 
//at the end of the initialization check if there is
// a field empty to be sure that all element needed are present;
// ->> the check for the color range can be done at that point
void    free_tab(char **tofree)
{
    int j;

    j = 0;
    while (tofree[j])
    {
        free(tofree[j]);
        j++;
    }
    free(tofree);
}

int check_range(t_data *data)
{
    if (data->param.cb > 255 || data->param.cb < 0)
        return (1);
    if (data->param.cg > 255 || data->param.cg < 0)
        return (1);
    if (data->param.cr > 255 || data->param.cr < 0)
        return (1);
    if (data->param.fb > 255 || data->param.fb < 0)
        return (1);
    if (data->param.fg > 255 || data->param.fg < 0)
        return (1);
    if (data->param.fg > 255 || data->param.fg < 0)
        return (1);
    return (0);
}

int color_set(char **params)
{
    int i;
    int j;

    j = 0;
    while (params[j])
    {
        i = 0;
        while (params[j][i])
        {
            if (params[j][i] < 48 || params[j][i] > 57)
                return (1);
            i++;
        }
        j++;
    }
    if (j > 3)
        return (1);
    return (0);
}


//atoi??
int init_color(char *info, t_data *data)
{
    static int  countc = 0;
    static int  countf = 0;
    char        *new;
    char        **params;

    if (info[0] == 'C')
    {
        new = ft_parse_spaces(info, 'C');
        params = ft_split(new, ',');
        if (color_set(params) == 1)
            return (1);
        data->param.cr = ft_atoi(params[0]);
        data->param.cg = ft_atoi(params[1]);
        data->param.cb = ft_atoi(params[2]);
        countc++;
    }
    else if (info[0] == 'F')
    {
        new = ft_parse_spaces(info, 'F');
        params = ft_split(new, ',');
        if (color_set(params) == 1)
            return (1);
        data->param.fr = ft_atoi(params[0]);
        data->param.fg = ft_atoi(params[1]);
        data->param.fb = ft_atoi(params[2]);
        countf++;

    }
    if (countc > 1 || countf > 1 )
        return (1);
    free(new);
    free_tab(params);
    return (0);
}


//check the validity of the color settings
int check_color(t_data *data, char *param)
{
    if (init_color(param, data) == 1)
        printf("Error in color settings\n");
    //free(param);
    return (0);
}
