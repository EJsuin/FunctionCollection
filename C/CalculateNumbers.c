int calculateNumbers(char *str)
{
    char *pat = (char *)malloc(1024);
    int sum = 0, cur = 0, cnt = 0;
    int is_cop = 0;
    while (cur < strlen(str))
    {
        if (str[cur + cnt] >= '0' && str[cur + cnt] <= '9')
        {
            cnt++;
            is_cop = 0;
        }
        else if ((str[cur + cnt] < '0' || str[cur + cnt] > '9') && is_cop)
        {
            cur++;
        }
        else
        {
            strncpy(pat, str + cur, cnt);
            pat[cnt] = '\0';
            sum += atoi(pat);
            cur += cnt;
            cnt = 0;
            is_cop = 1;
        }
    }
    free(pat);
    return sum;
}