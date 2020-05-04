#pragma once
#include "Film.h"
#include <vector>
using std::vector;
class FilmRepo
{
private:
	vector <Film> filme;
public:

	vector<Film> get_filme() const;

	void add(Film);

	void remove(Film);

	void edit_titel(Film, string);

	void edit_genre(Film, string);

	void edit_jahr(Film, int);

	void edit_like(Film, int);

	void edit_trailer(Film, string);

	void print_filme();

	Film find_film(Film);

	vector<Film> sort_genre(string);

	double find_likes(Film);
};

