#pragma once
#include "FilmRepo.h"
class User
{
private:
	FilmRepo repo;
	vector<Film>WatchList;
public:
	User(){}
	User(FilmRepo);

	FilmRepo get_repo();
	vector<Film>get_watch()const;
	void set_watch(vector<Film>);

	void add_to_watch(Film);

	void remove_from_watch(Film);

	void add_like(Film);

	void print_watch();

	bool find_film(Film);
};

