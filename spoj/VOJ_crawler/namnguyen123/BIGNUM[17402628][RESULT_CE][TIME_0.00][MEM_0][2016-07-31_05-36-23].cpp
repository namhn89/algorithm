##include<bits/stdc++.h>
#define MAXLEN 5002
typedef char string[MAXLEN];
void reverse(string a)
{
    int i, n = strlen(a);
    char c;
    for(i=0; i<n/2; i++)
    {
        c = a[n-i-1];
        a[n-i-1] = a[i];
        a[i] = c;
    }
}
void add_zero(string a, string b)
{
    while(strlen(a)<strlen(b))
        strcat(a, "0");
    while(strlen(b)<strlen(a))
        strcat(b, "0");
}
void remove_zero(string a, string b)
{
    int n = strlen(a)-1;
    while(n>1 && a[n]=='0')
        n--;
    strncpy(a, a, n);
    a[n+1] = '\0';
    n = strlen(b)-1;
    while(n>1 && b[n]=='0')
        n--;
    strncpy(b, b, n);
    b[n+1] = '\0';
}
int greater(string a, string b)
{
    remove_zero(a, b);
    int na = strlen(a), nb = strlen(b), i;
    if(na>nb)
        return 1;
    else if(na<nb)
        return 0;
    for(i = na-1; i>=0; i--)
        if(a[i]>b[i])
            return 1;
        else if(a[i]<b[i])
            return 0;
    return 1;
}
void add(string a, string b, string c)
{
    strcpy(c, "");
    int i, n, s, r = 0;
    char z;
    add_zero(a, b);
    n = strlen(a);
    for(i=0; i<n; i++)
    {
        s = (a[i]-'0') + (b[i]-'0') + r;
        c[i] = s%10 + '0';
        r = s/10;
    }
    if(r>0)
    {
        c[n] = r + '0';
        n++;
    }
    while(c[n-1]=='0' && n>1)
        n--;
    c[n] = '\0';
    reverse(c);
}
void sub(string a, string b, string c)
{
    strcpy(c, "");
    int i, n, s, r = 0;
    char z;
    add_zero(a, b);
    n = strlen(a);
    for(i=0; i<n; i++)
    {
        s = a[i] - b[i] - r;
        if(s<0)
        {
            s += 10;
            r = 1;
        }
        else
            r = 0;
        c[i] = s%10 + '0';
    }
    while(c[n-1]=='0' && n>1)
        n--;
    c[n] = '\0';
    reverse(c);
}
void multiply(string a, string b, string c)
{
    strcpy(c, "");
    int i, j, len, s, r = 0, n = strlen(a)-1, m;
    remove_zero(a, b);
    n = strlen(a);
    m = strlen(b);
    len = n+m-1;
    for(i=0; i<len; i++)
    {
        s = 0;
        for(j=0; j<=i; j++)
            if(j<n && (i-j)<m)
                s += (a[j]-'0')*(b[i-j]-'0');
        s += r;
        r = s/10;
        c[i] = s%10+'0';
    }
    if(r>0)
    {
        c[len] = r+'0';
        len++;
    }
    while(c[len-1]=='0' && len>1)
        len--;
    c[len] = '\0';
    reverse(c);
}
int main()
{
    string a, b, c;
    gets(a);
    gets(b);
    reverse(a);
    reverse(b);
    add(a,b,c);
    puts(c);
    if(greater(a, b))
        sub(a, b, c);
    else
    {
        sub(b, a, c);
        printf("-");
    }
    puts(c);
    multiply(a,b,c);
    puts(c);

    return 0;
}
