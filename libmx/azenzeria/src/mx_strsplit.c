#include "../inc/libmx.h"


char **mx_strsplit(const char *s, char c){

if (!s)
{
    return  NULL;
}

    int countWords = mx_count_words(s, c);

    char **str = (char **)malloc(countWords  * sizeof(char *));

    char *newStr = mx_strnew(mx_strlen(s));
    mx_strcpy(newStr, s);


int count = 0;
int n = 0;

for (int i = 0; s[i] != '\0'; i++)  //s[i] != '\0'
{
    if (s[i] == c)
    {
        newStr = mx_cut_string_on_num(newStr, 1);
    }
    if (s[i]!= c)
    {
        count++;
    }
    if (s[i] != c && s[i + 1] == c)
    {
            char *timeStr = mx_strnew(count);
            mx_strncpy(timeStr, newStr, count - 1);
            newStr = mx_cut_string_on_num(newStr, count);
            str[n] = timeStr;
            count = 0;
            
            n++;
            timeStr = NULL;
            
    }
    
}

s  = NULL;

return str;
}


