#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int p[12] , q[12];
    char s1[10] , s2[10] , s3[10] ;
    int t ;
    scanf("%d", &t);
    while(t--)
    {
        int s = 3 ;
        memset(p,0,sizeof(p));
        memset(q,0,sizeof(q));
        while(s--)
        {
            scanf("%s %s %s", s1, s2 , s3);
            if(!strcmp(s3,"up"))
            {
                int i ;
                for(i = 0 ; s1[i] != '\0' ; i++)
                    p[ s1[i]-'A' ]++ ;///
                for(i = 0 ; s2[i] != '\0' ; i++)
                    p[ s2[i]-'A' ]-- ;
            }
            else if(!strcmp(s3,"down"))
            {
                int i ;
                for(i = 0 ; s2[i] != '\0' ; i++)
                    p[ s2[i]-'A' ]++ ;
                for(i = 0 ; s1[i] != '\0' ; i++)
                    p[ s1[i]-'A' ]-- ;
            }
            else
            {
                int i ;
                for(i = 0 ; s1[i] != '\0' ; i++)
                    q[ s1[i]-'A' ] = 1 ;
                for(i = 0 ; s2[i] != '\0' ; i++)
                    q[ s2[i]-'A' ] = 1 ;
            }
        }
        int k , flag = 0 , i ;
        for(i = 0 ; i < 12 ; i++)
            if(fabs(flag) < fabs(p[i]) && q[i] == 0)
            {
                flag = p[i] ;
                printf("p[i]=%d\n",p[i]);
                k = i ;
            }
        if(p[k] < 0 )
        {
            printf("%c is the counterfeit coin and it is light.\n", k+'A');
        }
        else
            printf("%c is the counterfeit coin and it is heavy.\n", k+'A');
    }
    return 0;
}
