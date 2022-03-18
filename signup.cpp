#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
#define SPACE 32
#define one 49
#define two 50
#define three 51


void takepassword(char pwd[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
}
char generateUsername(char email[50],char username[50])
{
	//abc123@gmail.com
	for(int i=0;i<strlen(email);i++){
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
}

void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}

struct signup
{
    char name[50];
    char email[50];
    char username[100];
    char phone[20];
    char add[50];
    char pass[30];
    
};


int main()
{   
	system("color 2");
    FILE *fp;
	char opt;
    char p;
    int usrfound = 0;
    char password2[20];
    struct signup signup_details;
    while (1)
    {
    
    system("cls");
    gotoxy(45,0);
    for(int i = 0; i<20; i++)
    {
        printf("_");
        _sleep(35);
    }
    printf("SIGNUP");
    for(int i = 0; i<20; i++)
    {
        printf("_");
        _sleep(35);
    }
    gotoxy(45,2);
    for (int i = 0; i < 46; i++)
    {
        printf("-");
        _sleep(35);
    }
    

    _sleep(300);
    gotoxy(60,4);
    printf("PRESS 1 FOR SINGUP");
     _sleep(300);
    gotoxy(60,5);
    printf("PRESS 2 FOR LOGIN");
    _sleep(300);
    gotoxy(60,6);
    printf("PRESS 3 FOR EXIT");
    gotoxy(45,8);
    for (int i = 0; i < 46; i++)
    {
        printf("_");
        _sleep(35);
    }
    
    opt = getch();
    switch (opt)
    {
      case (49):
      { 
           system("cls");
           gotoxy(33,0);
          for (int i = 0; i < 20; i++)
          {
              printf("_"); 
              _sleep(35);
               
          }
          _sleep(50);
          printf("welcome to signup page.");
          _sleep(50);
          for (int i = 0; i < 20; i++)
              {
                  printf("_");
                  _sleep(35);
              }
           gotoxy(53,3);
           printf("NAME: ");
           scanf("%s",&signup_details.name);  
           gotoxy(53,4);
           printf("EMAIL: ");
           scanf("%s",signup_details.email);
           gotoxy(53,5);
           printf("ADDRESS: ");
           scanf("%s",signup_details.add);
           gotoxy(53,6);
           printf("PHONE: ");  
           scanf("%s",signup_details.phone);
           gotoxy(53,7);
           printf("PASSWORD: ");  
		   takepassword(signup_details.pass);
		   gotoxy(53,8);
		   printf("CONFIRM PASSWORD: ");
		   takepassword(password2);
		   if (!strcmp(signup_details.pass,password2))
		   {
		   	 generateUsername(signup_details.email,signup_details.username);
		   	 fp = fopen("Users.dat","a+");
		   	 fwrite(&signup_details,sizeof(struct signup),1,fp);
		   	 if(fwrite != 0 )
		   	 {
			  gotoxy(0,10);
		   	  printf("USER REGISTRATION SUCESS, YOUR USERNAME IS %s",signup_details.username);
		       _sleep(4000);
			}
		   	 else{
			    gotoxy(0,10);
		   	    printf("SOMETHING WENT WRONG!!");
		   	    _sleep(2000);
		   	    fclose(fp);	
				 }
		   	 }
		   else
		   {
		   	gotoxy(0,10);
			Beep(750,300);
		   	printf("PASSWORD DO NOT MATCH");
		   	_sleep(2000);
		   	
		   	
		   }
		   getch();
		   break;
		   }
         case (51):
         {  
             exit(0);
             getch();
			 break;
         }
         case (50):
         	{
         	  char uname[100];
			   char pword[100];
			   int chkp;
			   int chku;
			   struct signup login;
			   system("cls");
           gotoxy(33,0);
          for (int i = 0; i < 20; i++)
          {
              printf("_"); 
              _sleep(35);
               
          }
          _sleep(50);
          printf("welcome to login page.");
          _sleep(50);
          for (int i = 0; i < 20; i++)
              {
                  printf("_");
                  _sleep(35);
              }
              gotoxy(53,3);
              printf("USERNAME: ");
              scanf("%s",&uname);
              gotoxy(53,4);
              printf("PASSWORD: ");
              takepassword(pword);
              
              fp = fopen("Users.dat","r");
              while(fread(&signup_details,sizeof(struct signup),1,fp))
              {
                 chku = strcmp(signup_details.username, uname);
				 chkp = strcmp(signup_details.pass, pword);
				   if(chku == 0 && chkp == 0)
				  {
                         system("cls");
							gotoxy(45,0);
							for(int i = 0; i<20; i++)
							{
								printf("_");
								_sleep(35);
							}
							printf("WELCOME %s",uname);
							for(int i = 0; i<20; i++)
							{
								printf("_");
								_sleep(35);
							}
							gotoxy(45,2);
							for (int i = 0; i < 46; i++)
							{
								printf("-");
								_sleep(35);
							}
							gotoxy(53,3);
				           printf("NAME: %s",signup_details.name);
				           gotoxy(53,4);
				           printf("EMAIL: %s",signup_details.email);
				           gotoxy(53,5);
				           printf("ADDRESS: %s",signup_details.add);
				           gotoxy(53,6);
				           printf("PHONE: %s",signup_details.phone);  
				           gotoxy(53,7);
				           printf("USERNAME: %s",signup_details.username);
				           gotoxy(0,9);
				           printf("PRESS ENTER TO LOGOUT");
	
				  }
				  else if(chku == 0 && chkp != 0)
				  {
				  	gotoxy(53,10);
				  	printf("INVALID PASSWORD!");
				  //	printf("your pass: %s",pword);
				  	Beep(750,300);
				  	break;
	
				  }
				  else if(chku != 0 && chkp == 0)
				  {
				  	gotoxy(53,10);
				  	printf("INVALID USERNAME!");
	                Beep(750,300);
	                break;
				  }
			     } 
			  getch();
              break;
			 }
    }
    }
    return 0;
}