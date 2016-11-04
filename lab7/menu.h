  /************************************************/
/* FILE NAME 	: menu.c						*/
/* MODULE NAME 	: menu							*/
/* DESCRIPTION  : This is a menu program		*/
/* AUTHOR      	: qzh							*/
/* DATE		: 2016/11/4							*/
/************************************************/

/* Set Input Prompt */
int SetPrompt(char * p);
/* add cmd to menu */
int MenuConfig(char * cmd, char * desc, int (*handler)());

/* Menu Engine Execute */
int ExecuteMenu();


