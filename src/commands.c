#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "commands.h"

int do_cd(int argc, char** argv) {
	if (!validate_cd_argv(argc, argv))
		return -1;
	else if (chdir(argv[1]==-1))
		return 1;
	else
		return 0;
}

int do_pwd(int argc, char** argv) {
	if (!validate_pwd_argv(argc, argv))
		return -1;

	char *buf;
	buf=getcwd(NULL,100);
	printf("directory: %s",buf);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
	if ((argc==2) && (strcmp(argv[0],"cd")==0))
		return 1;
  
	else
		return 0;
}

int validate_pwd_argv(int argc, char** argv) {
	if (argc >1)
		return 0;
	
	else if (strcmp(argv[0], "pwd")!=0)
		return 0;
	else 
		return 1;
}
