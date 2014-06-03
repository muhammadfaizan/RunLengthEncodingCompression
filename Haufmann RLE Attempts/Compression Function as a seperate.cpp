#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
main()
{
      int k=0;
      char hold,*cstr,*str="bhoooot naa ajaaye     p";
      cstr=(char *)malloc(sizeof(char)*(strlen(str)+2));
      clrscr();
      for (int count=0,j=0, i = 0; i <strlen(str) ;)
      {
	cstr[k++]=str[i];                           // i=(0,1),(2)||j=0,1,2||k=(0,1)
	//hold=str[i];                                      //str="bhoooot naa ajaaye     p"
	count=0;                                          //cstr="bh
	while (str[i]==str[++j] && count < 9)            //hold =b,h
	{                                                 //count=0,0
	      count++;
	}
	if(count>0)
	{
		//snprintf((cstr+k),1,"%d",count);
		hold=count+'0';
		cstr[k++]=hold;

	}

	i=j;
      }
      cstr[k]='\0';
      printf("%s",cstr);
}
