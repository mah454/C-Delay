/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/09/2021 11:13:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mahdi Sheikh Hosseini, 
 *        Company:  Moke 
 *        License:  GPLv3
 *
 * =====================================================================================
 */

#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>

static volatile sig_atomic_t flag = 0;

static void sig_stop(int signum) { 
	switch (signum) {
			case SIGTERM : printf ("\nReceive SIGTERM\n"); break;
			case SIGINT  : printf ("\nReceive SIGINT\n"); break;
	} 
	flag = 1 ;
}

void handle_signals() {
    signal(SIGTERM, sig_stop);
    signal(SIGINT, sig_stop);
}

void process(int count) {
		int a = 0 ; 
    while (a <= count && !flag) { 
				int p = a*100/count; 
        printf("[%d%s] Process Completed.\n",p,"%");
				sleep(1); 
				a++; 
    }
}

int main(int argc, const char *argv[]) 
{
		handle_signals() ; 

		if (argc < 2) {
				printf ("Usage: main [delay]\n"); 
				printf ("Example: main 120\n"); 
				exit(1);
		}

		int count=atoi(argv[1]); 
		process(count) ;
    return 0;
}
