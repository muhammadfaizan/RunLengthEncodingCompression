#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

void file_to_string(FILE *fpr,char *str)
{
     int i=0;
     while((str[i]=getc(fpr))!=EOF)
     {
		   i++;
     }
     str[i]='\0';
}
main()
{
      FILE *fp,*fw=fopen("D:\\check.txt","r");
      fp=fopen("D:\\checkout.txt","w+");
      
      char str[50],hold,temp[2];
      file_to_string(fw,str);
      //puts(str);
      int count=0,i=0,l;
      /*
      printf("\n");
      for( i=0; i<strlen(str);i++)
      {
           printf("%d ",str[i]);
      }*/
      int upr=-59,lwr= -66;
      
      while (str[i] != '\0')
      {
            if ( str[i] >= lwr && str[i] <= upr )
            {
                 printf("if");
                      temp[0]=str[i]+114;
                      temp[1]='\0';
                      count=atoi(temp);
                      
                      for (l=0; l<=count+1;l++)
                      {
                          fputc(hold,fp);
                      }
            }
            else
            {
                printf("else");
                hold=str[i];
                fputc(hold,fp);
            }
            i++;
      }
      getch();
      fclose(fw);
      fclose(fp);
}
