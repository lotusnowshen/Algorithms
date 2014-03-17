#include <stdio.h>
#include <string.h>


char *replace_blank_in_string(char *s)
{
    int cnt_blank = 0;
    int length_string = strlen(s);
    int ix;
    for(ix=0; ix != length_string; ++ix)
    {
        if(s[ix]==' ')
        {
            cnt_blank++;
        }
    }
    s[length_string+2*cnt_blank] = '\0';
    int first = length_string-1;
    int second = length_string + 2*cnt_blank-1;
    for(; first>=0; first--)
    {
        if(s[first]==' ')
        {
            s[second--] = '0';
            s[second--] = '2';
            s[second--] = '%';
        }else
        {
            s[second--] = s[first];
        }
        if(first == second)
        {
            break;
        }
    }

    return s;
}


int main(void)
{
    char str[100] = "hello world foo bar";
    replace_blank_in_string(str);
    printf("%s\n", str);
    return 0;
}
