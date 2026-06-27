#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mods.h"

void OSprint(void){
	char buffer[3000];
	char OSname[100];

	FILE *fp= fopen("/etc/os-release","r");
	
	size_t ram= fread(buffer, 1, 2999, fp);

	buffer[ram] = '\0';
	
	char *start = strstr(buffer, "PRETTY");
	char *end = strstr(start, "\n");
	int len = end - start;

	strncpy(OSname, start+12, len-12);

	OSname[len-12] = '\0';


	printf(" OS: %s\n",OSname);

}

