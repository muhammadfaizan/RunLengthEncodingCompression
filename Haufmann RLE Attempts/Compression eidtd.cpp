#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
// Function to compress a string
int main()
{
      int k=0;
      char str[50]="boy Yooooyu are geeenius",hold,cstr[50];
      //cstr=(char *)malloc(sizeof(char)*(strlen(str)+2));
      FILE *fw=fopen("D:\\check.txt","w+");

      //clrscr();
      for (int count=0,j=0, i = 0; i <strlen(str) ;)
      {

	      cstr[k++]=str[i];                           // i=(0,1),(2)||j=0,1,2||k=(0,1)
			                                          		    //str="bhoooot naa ajaaye     p"
          count=0;                                          //cstr="bh
	      while (str[i]==str[++j] && count < 9)            //hold =b,h
	      {
       	      count++;                                         //count=0,0
          }
	      if(count>0)
	      {
                     //snprintf((cstr+k),1,"%d",count);
			         hold=count+188;
			         cstr[k++]=hold;

          }

	      i=j;
      }
      cstr[k]='\0';
      fprintf(fw,"%s",cstr);
      //puts(cstr);
      getch();

      return 0;
}
