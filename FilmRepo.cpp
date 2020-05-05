#include "FilmRepo.h"
#include <iostream>
#include <vector>

using std::cout;

//constructor
vector<Film> FilmRepo::get_filme() const {
	return filme;
}
//adauga film 
void FilmRepo::add(Film film) {
	for (int i = 0; i < filme.size(); i++)
		//daca il gaseste atunci nu il mai adauga
		if (film.get_titel() == filme[i].get_titel() && film.get_jahr() == filme[i].get_jahr()) {
			cout << "Das Film " << film.get_titel() << " ist schon in der liste\n";
			return;
		} 
		filme.push_back(film);
}
//editarea numelui filmului
void FilmRepo::edit_titel(Film film, string titel) {
	for (int i = 0; i < filme.size(); i++)
		//il editeaza daca il gaseste dupa titlu si an
		if (film.get_titel() == filme[i].get_titel() && film.get_jahr() == filme[i].get_jahr()) {
			filme[i].set_titel(titel);
			return;
		}
}
//editeaza genul filmului
void FilmRepo::edit_genre(Film film, string genre) {
	for (int i = 0; i < filme.size(); i++)
		//il editeaza daca il gaseste dupa titlu si an
		if (film.get_titel() == filme[i].get_titel() && film.get_jahr() == filme[i].get_jahr()) {
			filme[i].set_genre(genre);
			return;
		}
}
//editeaza trailerul
void FilmRepo::edit_trailer(Film film, string trailer) {
	for (int i = 0; i < filme.size(); i++)
		//il editeaza daca il gaseste dupa titlu si an
		if (film.get_titel() == filme[i].get_titel() && film.get_jahr() == filme[i].get_jahr()) {
			filme[i].set_trailer(trailer);
			return;
		}
}
//schimba anul filmului
void FilmRepo::edit_jahr(Film film, int jahr) {
	for (int i = 0; i < filme.size(); i++)
		//il editeaza daca il gaseste dupa titlu si an
		if (film.get_titel() == filme[i].get_titel() && film.get_jahr() == filme[i].get_jahr()) {
			filme[i].set_jahr(jahr);
			return;
		}
}

//schimba nr de likeuri
void FilmRepo::edit_like(Film film, int like) {
	for (int i = 0; i < filme.size(); i++)
		//il editeaza daca il gaseste
		if (film.get_titel() == filme[i].get_titel() && film.get_jahr() == filme[i].get_jahr()) {
			filme[i].set_jahr(like);
			return;
		}
}

//sterge
void FilmRepo::remove(Film film) {
	for (int i = 0; i < filme.size(); i++)
		//il sterge daca il gaseste dupa titlu si an
		if (film.get_titel() == filme[i].get_titel() && film.get_jahr() == filme[i].get_jahr()) {
			filme.erase(filme.begin() + i);
			return;
		}
	cout << "Error 404: Film " << film.get_titel()<<'\n';
}
// afiseaza filmele
void FilmRepo::print_filme() const {
	for (int i = 0; i < filme.size(); i++)
		cout << filme[i];
}

//cauta filmul
Film FilmRepo::find_film(Film film)const {
	for (int i = 0; i < filme.size(); i++)   // cauta filmul in lista si returneaza daca e gasit
		if (film.get_titel() == filme[i].get_titel() && film.get_jahr() == filme[i].get_jahr())
			return film;
}

double FilmRepo::find_likes(Film film)const {
	for (int i = 0; i < filme.size(); i++)  //cauta filmul in lista si returneaza nr de like uri
		if (film.get_titel() == filme[i].get_titel() && film.get_jahr() == filme[i].get_jahr())
			return film.get_like();
	return 0;
}

vector<Film> FilmRepo::sort_genre(string g) const {
	std::vector <Film> aux;
	for (int i = 0; i < filme.size(); i++) {   // cauta filmul specific unui gen in lista si il adauga intr o lista noua
		if (filme[i].get_genre() == g)
			aux.push_back(filme[i]);
	}
	return aux;
}