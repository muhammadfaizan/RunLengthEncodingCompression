/*
  Name: MF Compressor
  Author: Muhammad Faizan
  Seat no. : B11101045
  Date: 28/10/12 11:41
  Description: To compress a text file Using RLE technique
  Note : This Program is compatible with TC not DEV-C &
         I haven't tried borland or visual studio to run this
  Copyright: You are not allowed to reproduce, copy, modify or use any of my works
	   unless you have my written authorization.
	   Copyright © 2012 - 2013 Pakistan. All rights reserved */


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
#include<alloc.h>
#define p printf

// Function to get size of file
int size_of_file(FILE *f)
{
    int size;
    fseek(f,0,SEEK_END);
    size=ftell(f);
    fseek(f,0,SEEK_SET);
    return size;
}
// Function to write file into string
void file_to_string(FILE *fpr,char *str)
{
     int i=0;
     while((str[i]=getc(fpr))!=EOF)
     {
		   i++;
     }
     str[i]='\0';
}


// Function to compress a string
char * compress(char *str)
{
      int k=0;
      char hold,*cstr;
      cstr=(char *)malloc(sizeof(char)*(strlen(str)+2));
      clrscr();
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

      return cstr;
}

// Function to decompress
void decompress(FILE *fw,char *str)
{
      char hold,temp[2];
      file_to_string(fw,str);

      int count=0,i=0,l;
      // found upper and lower limit of ASCII code
      int upr=-59,lwr= -66;

      // Loop to run till string ends
      while (str[i] != '\0')
      {
	  if ( str[i] >= lwr && str[i] <= upr )
	  {
		  temp[0]=str[i]+114;
		  temp[1]='\0';
		  count=atoi(temp);
                      
                      for (l=0; l<=count+1;l++)
                      {
                          fputc(hold,fw);
                      }
            }
            else
            {
                hold=str[i];
                fputc(hold,fw);
            }
            i++;
      }
      

}
main()
{
      char choice;
      FILE *fw,*fr;
      char filename[50],file_loc[100],file_locw[100],*str;
      int sof;
      clrscr();
      gotoxy(13,0);
      p("This is a file compression program ");
      // Asking for file Name
      reenter:
      p("\n\nEnter your file name : ");
      gets(filename);
      // Asking for file format
      askfile:
      p("\nWhat is file format?");
      p("\n1) .C\n2) .CPP \n3) .txt \nEnter your choice here :");
      choice=getche();
      switch (choice)
      {
	   case '1':
	        {
		  strcat(filename,".C");
		  break;
	        }

	   case '2':
	        {
		  strcat(filename,".CPP");
		  break;
	        }

	   case '3':
	        {
		  strcat(filename,".txt");
		  break;
	        }

	   default :
	        {
		  p("\nInvalid Choice");
		  goto askfile;

	        }

      }

      p("\nIs \"%s\" on default location i.e.(C:\\TC\\BIN)? (Y/N)",filename);
      choice = getche();

      if ( choice == 'y' || choice == 'Y')
      {
	       strcpy(file_loc,"C:\\TC\\BIN");
      }
      else if ( choice == 'n' || choice == 'N')
      {
	 p("\nEnter File directory :");

	 // A loop to take input of file location
	 char ch;
	 for (int i=0; ;i++)
	 {
	     ch=getche();
	     // Escape sequence
	     if (ch== '\r')
	     {
		    file_loc[i]='\0';
		    break;
	     }
	     /*if (ch == '\\')
	     {
		  file_loc[i++]=ch;
	     } */

	     file_loc[i]=ch;
	 }
      }

      // creating a copy of destinatopn for further use
      strcpy(file_locw,file_loc);

      // writing whole destination with filename into a string
      strcat(file_loc,filename);

      // Openning Desired file
      fr=fopen(file_loc,"r+");
      if ( fr == NULL )
      {
	 p("Sorry Source File cannot be accessed\nMake sure you entered right directory, filename & format");
	 p("\nDo You wish To re-enter File name and location? (Y//N) : ");
	 choice = getche();
	 if ( choice == 'y' || choice == 'Y')
	 {
	      clrscr();
	      goto reenter;
	 }
	 if ( choice == 'n' || choice == 'N')
	 {
	      p("Thank You For Using this program\n Hope to see you again !");
	      getch();
	      exit(1);
	 }
      }
      // Getting size of file through function
      sof =size_of_file(fr);
      sof+=10;
      str=(char *)malloc(sof* sizeof(char));

      // Writing file to the address of string
      file_to_string(fr,str);
      fclose(fr);
      clrscr();
      p("What do you wish to do with this file?\n");
      p("1. Compress\n2. Decompress\nNOTE: DO NOT ATTEMPT TO DECOMPRESS A NORMAL(UN-COMPRESSED) TEXT FILE\n");
      p("\nEnter your desired work");
      choice=getche();
      switch(choice)
      {
                    // Case of compression
                    case '1':
                         {
                             p("\nDo you wish to compress the file and replace the original source? (Y/N) ");
                             char ch=getche();
                             switch (ch)
                             {
                                    case 'y':
                                    case 'Y':
                                         {
                                             // Clearing file to right the compressed file
                                             fw=fopen(file_loc,"w+");
				     char *cstr=compress(str);

                                             // Writing compressed string to file
				     fprintf(fw,"%s",cstr);
                                             printf("Your file has been compressed\n");
                                             
                                             // Closing file since its no longer needed
                                             fclose(fw);
                                             
                                             // giving user option to view that file
                                             p("To view the file press 'V' or anyother key to quit: ");
                                             char v=getche();
                                             if ( v== 'v' || v=='V')
                                             {
                                                  system(file_loc);
                                                  exit(1);
                                             }
                                             else
                                             {
                                                 p("You chose to quit program\nHave a nice day !");
                                                 getch();
                                                 exit(1);
                                             }
                                             
                                             break;
                                         }
                                    case 'n':
                                    case 'N':
                                         {
                                             clrscr();
                                             p("Enter your compressed file name : ");
                                             gets(filename);
                                             strcat(filename,".txt");
                                             char *cstr=compress(str);
                                             strcat(file_locw,filename);
				                             fw=fopen(file_locw,"w+");
                                             fprintf(fw,"%s",cstr);
                                             fclose(fw);
                                             
                                             // giving user option to view that file
                                             p("To view the file press 'V' or anyother key to quit: ");
                                             char v=getche();
                                             if ( v== 'v' || v=='V')
                                             {
                                                  
                                                  system(file_locw);
                                                  exit(1);
                                             }
                                             else
                                             {
                                                 p("You chose to quit program\nHave a nice day !");
                                                 getch();
                                                 exit(1);
                                             }
                                             break;
                                         }
                             }
                             break;
                         }
                    
                    //case of decompression         
                    case '2':
                         {
                             clrscr();
                             p("\nDo you wish to decompress the file and replace the original source? (Y/N) ");
                             char ch=getche();
                             switch (ch)
                             {
                                    case 'y':
                                    case 'Y':
                                         {
                                             // Clearing file to right the decompressed file
                                             fw=fopen(file_loc,"w+");
                                             decompress(fw,str);
                                             fclose(fw);
                                             break;
                                         }
                                         
                                    case 'n':
                                    case 'N':
                                         {
                                             //asking for filename and concating in destination
                                             p("\nEnter file name :");
                                             gets(filename);
                                             strcat(filename,".txt");
                                             strcat(file_locw,filename);
                                             fw=fopen(file_locw,"w");
                                             decompress(fw,str);
                                             fclose(fw);
                                             p("Do you wish to view this file? \nPress 'V' : ");
                                             char ch=getch();
                                             if (ch== 'v' || ch=='V')
                                             {
                                                      system(file_locw);
                                                      exit(1);
                                             }
                                             
                                             else
                                             {
                                                 p("You chose to quit program\nHave a nice day !");
                                                 getch();
                                                 exit(1);
                                             }
                                         }
                             }
                         }
      }
}
                             
