#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "impl.h"

void get_team(struct team* team_)
{
	if (!team_)
		return;
	char* str_end;

	printf("Team name: ");
	if (fgets(team_->title, MAX_STRLEN, stdin) == NULL)
		die("fgets error", READ_ERR);
	if ((str_end = strchr(team_->title, '\n')) != NULL)
		*str_end = '\0';

	printf("Coach name: ");
	if (fgets(team_->coach_name, MAX_STRLEN, stdin) == NULL)
		die("fgets error", READ_ERR);
	if ((str_end = strchr(team_->coach_name, '\n')) != NULL)
		*str_end = '\0';

	if (!strcmp(team_->coach_name, "") || !strcmp(team_->title, ""))
		die("invalid team name or coach name.", READ_ERR);

	printf("Last year place: ");
	if (scanf("%d", &team_->last_place) != 1 || team_->last_place < 1)
		die("scanf error", READ_ERR);
	stdin_flush();

	printf("This year place: ");
	if (scanf("%d", &team_->current_place) != 1 || team_->current_place < 1)
		die("scanf error", READ_ERR);
	stdin_flush();
}

void for_team(struct team* team_arr,
	      int n_teams,
	      void (*handler)(struct team* team_))
{
	for (int i = 0; i < n_teams; i++) {
		printf("Team #%d out of %d:\n", i + 1, n_teams);
		handler(team_arr + i);
	}
}

void print_team(struct team* team_)
{
	if (team_) {
		printf("Name: %s\nCoach: %s\nLast year place: %d\n"
		       "This year place: %d\n",
		       team_->title,
		       team_->coach_name,
		       team_->last_place,
		       team_->current_place);
	}
}

void check_team(struct team* team_)
{
	if (team_ && team_->current_place <= team_->last_place)
		print_team(team_);
	else
		puts("The team didn't pass.");
}

inline void die(char const* msg, int err_code)
{
	fprintf(stderr, "%s\n", msg);
	exit(err_code);
}

inline void stdin_flush()
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}
