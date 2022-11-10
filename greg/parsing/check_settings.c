#include "../cube.h"
//QUESTIONS:
//-> how to check the tab

//check the settings
int check_settings(t_data *data, char **params)
{
    int j;
    char *tmp;

    j = 0;
    while ( j < 6)
    {
        tmp = ft_parse_spaces(params[j], ' ');
        if (tmp[0] == 'N' || tmp[0] == 'S' 
            || tmp[0] == 'E'|| tmp[0] == 'W')
        {
               if(check_texture(data, tmp))
               {
                    printf("Error in texture settings\n");
                    return (1);
               }
        }
        else if (tmp[0] == 'C' || tmp[0] == 'F')
        {
            if (check_color(data, tmp))
                return (1);
        }
        else
        {
            printf("Error: Invalid character found in file\n");
            return (1);
        }
        free(tmp);
        j++;
    }
    if (check_range(data) == 1)
        printf("Error in color range\n");
    return (0);
}