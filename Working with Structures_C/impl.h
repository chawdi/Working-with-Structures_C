#define _CRT_SECURE_NO_WARNINGS

#ifndef IMPL_H_
#define IMPL_H_

#define MAX_STRLEN 129
#define READ_ERR 1
#define MEM_ERR 2

struct team {
	char title[MAX_STRLEN], coach_name[MAX_STRLEN];
	int last_place, current_place;
};

void get_team(struct team* team_);
void for_team(struct team* team_arr,int n_teams,void (*handler)(struct team* team_));
void print_team(struct team* team_);
void check_team(struct team* team_);

void die(char const* msg, int err_code);
void stdin_flush();
#endif
