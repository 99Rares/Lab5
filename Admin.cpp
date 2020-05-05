#include "Admin.h"
Admin::Admin(FilmRepo repo) {
    this->repo= repo;
}
FilmRepo Admin::get_repo() {
	return repo;
}
void Admin::add(Film film) {
	repo.add(film);
}
void Admin::remove(Film film) {
	repo.remove(film);
}
void Admin::edit_titel(Film film, string _new) {
	repo.edit_titel(film, _new);
}
void Admin::edit_genre(Film film, string _new) {
	repo.edit_genre(film, _new);
}
void Admin::edit_trailer(Film film, string _new) {
	repo.edit_trailer(film, _new);
}
void Admin::edit_jahr(Film film, int _new) {
	repo.edit_jahr(film, _new);
}
void Admin::edit_like(Film film, int _new) {
	repo.edit_like(film, _new);
}
void Admin::print_filme() {
	repo.print_filme();
}
