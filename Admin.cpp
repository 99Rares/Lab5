#include "Admin.h"
//constructor
Admin::Admin(FilmRepo repo) {
    this->repo= repo;
}
//get-er repo
FilmRepo Admin::get_repo() {
	return repo;
}
//adauga film
void Admin::add(Film film) {
	repo.add(film);
}
//elimina film
void Admin::remove(Film film) {
	repo.remove(film);
}
//editeaza titlul
void Admin::edit_titel(Film film, string _new) {
	repo.edit_titel(film, _new);
}
//editeaza genul filmului
void Admin::edit_genre(Film film, string _new) {
	repo.edit_genre(film, _new);
}
//editeaza trailerul
void Admin::edit_trailer(Film film, string _new) {
	repo.edit_trailer(film, _new);
}
//schimba anul
void Admin::edit_jahr(Film film, int _new) {
	repo.edit_jahr(film, _new);
}
//schimba nr de like uri
void Admin::edit_like(Film film, int _new) {
	repo.edit_like(film, _new);
}
//print lista filme
void Admin::print_filme() {
	repo.print_filme();
}
