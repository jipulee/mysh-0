#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#include "utils.h"

void mysh_parse_command(const char* command, int *argc, char*** argv)
{
	int i = 0,nl = 0; 
	char *buf,*tokedcmd,*delim;

	nl = strlen(command);
	buf = (char*)malloc(sizeof(char)*nl);
	
	strcpy(buf,command);

	delim = "' ',\n,\t";
	tokedcmd = strtok(buf,delim);
	
	(*argv) = (char**)malloc(sizeof(char*)*100);
	(*argv)[i]= (char*)malloc(sizeof(char)*100);	


	if (tokedcmd!=NULL)
	{
		while (tokedcmd !=NULL)
		{
			strcpy((*argv)[i],tokedcmd);
			(*argv)[++i] = (char*)malloc(sizeof(char)*100);
			tokedcmd = strtok(NULL,delim);
		}
	}
	else {
		
		(*argc) = 1;
		strcpy((*argv)[0],"");
		return;
	}

	*argc = i;
	free(tokedcmd);

}
