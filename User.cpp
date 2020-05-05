#include "User.h"

//constructor
User::User(FilmRepo repo) {
    this->repo = repo;
}
//get-er repo
FilmRepo User::get_repo() {
    return this->repo;
}
//get-er watchlist
vector<Film> User::get_watch()const {
    return WatchList;
}
//setter watchlist
void User::set_watch(vector<Film> watch) {
    WatchList = watch;
}
//adauga la watchlist
void User::add_to_watch(Film film) {
	for (int i = 0; i < WatchList.size(); i++)
		//daca e gasit returneaza ca filmul deja exista in lista
		if (film.get_titel() == WatchList[i].get_titel() && film.get_jahr() == WatchList[i].get_jahr()) {
			cout << "Das Film " << film.get_titel() << "ist schon in der liste\n";
			return;
		}
	WatchList.push_back(film);
}

//adauga like uri la film
void User::add_like(Film film) {
	repo.edit_like(film, film.get_like() + 1);
}
//elimina din watchlist
void User::remove_from_watch(Film film) {
	for (int i = 0; i < WatchList.size(); i++)
		//daca nu e gasit nu se sterge si se afiseaza error 404 film (cout)
		if (film.get_titel() == WatchList[i].get_titel() && film.get_jahr() == WatchList[i].get_jahr()) {
			WatchList.erase(WatchList.begin() + i);
			return;
		}
	cout << "Error 404: Film" << film.get_titel() << '\n'; //"eroarea"
}

//printeaza watchlist-ul
void User::print_watch() {
	for (int i = 0; i < WatchList.size(); i++)
		cout << WatchList[i];
}

//cauta filmul
bool User::find_film(Film film) {
	for (int i = 0; i < WatchList.size(); i++)    // verifiva daca filmul exista deja in watchlist
		if (film.get_titel() == WatchList[i].get_titel() && film.get_jahr() == WatchList[i].get_jahr())
			return true;
	return false;
}