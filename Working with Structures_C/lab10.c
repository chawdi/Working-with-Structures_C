#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "impl.h"

int main(void)
{
	int n_teams;
	printf("Number of teams: ");
	if(scanf("%d", &n_teams) != 1 || n_teams < 1)
		die("scanf error", READ_ERR);
	stdin_flush();
	
	struct team* team_arr;
	if(NULL == (team_arr = malloc(n_teams * sizeof(struct team))))
		die("malloc error", MEM_ERR);
	for_team(team_arr, n_teams, get_team);

	puts("\n\nResult:");
	for_team(team_arr, n_teams, check_team);
	
	free(team_arr);
	getchar();
	return 0;
}
