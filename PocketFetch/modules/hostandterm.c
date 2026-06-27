#include <stdio.h>
#include <stdlib.h>

#include "mods.h"

char *username(void){
	
	return getenv("USER");
}

char *terminal(void){
	
	return getenv("TERM");
}

char *host(void){
	static char hostname[100];
	FILE *fp = fopen("/proc/sys/kernel/hostname","r");
	if (fgets(hostname, sizeof(hostname),fp) == NULL){
		fclose(fp);
		return NULL;
	}
	return hostname;

}

void topbar_print(void){
	char *hostname = host();
	char *ptr_user =username();


	printf("\n>> %s@%s",ptr_user,hostname);
}

void terminal_print(void){
	char *ptr_term = terminal();
	printf(" Terminal: %s\n",ptr_term);
}


