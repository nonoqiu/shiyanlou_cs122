nclude <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 30
char appCmd[8][MAX_LENGTH] = { "Register", "Login", "Logout", "ChangePsd", "Readme", "Publish", "Help", "Exit"}; 
char appRemark[8][MAX_LENGTH] = { "register a useraccount.", "login shiyanlou.", "logout to shiyanlou.", "change your password.",
				 "this is shiyanlou.", "publish a message.", "get help.", "exit application."}; 
int main()
{
	int i;
	char cmd[128];
	while(1)
	{
		scanf("%s",  cmd);
		for( i=0; i<8; i++ )
		{
			if( strcmp(cmd, appCmd[i])==0 )
			{
				switch( i )
				{
					case 7:
						exit(0);
						break;
					default:
						printf("%s\n", appRemark[i]);
						break;
				}
				break;
			}
		}
		
		if( i==8 )
		{
			printf("Wrong cmd!\n");
		}
	}
}
