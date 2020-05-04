#include "FilmRepo.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;
using std::cout;

//constructor
vector<Film> FilmRepo::get_filme() const {
	return filme;
}
//adauga film 
void FilmRepo::add(Film film) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		//daca il gaseste atunci nu il mai adauga
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
			cout << "Das Film " << film.get_titel() << " ist schon in der liste\n";
			return;
		} 
		filme.push_back(film);
}
//editarea numelui filmului
void FilmRepo::edit_titel(Film film, string titel) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		//il editeaza daca il gaseste dupa titlu si an
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
			i->set_titel(titel);
			return;
		}
	cout << "Repo Error 404: Film " << film.get_titel() << '\n';
}
//editeaza genul filmului
void FilmRepo::edit_genre(Film film, string genre) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		//il editeaza daca il gaseste dupa titlu si an
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
			i->set_genre(genre);
			return;
		}
	cout << "Repo Error 404: Film " << film.get_titel() << '\n';
}
//editeaza trailerul
void FilmRepo::edit_trailer(Film film, string trailer) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		//il editeaza daca il gaseste dupa titlu si an
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
			i->set_trailer(trailer);
			return;
		}
	cout << "Repo Error 404: Film " << film.get_titel() << '\n';
}
//schimba anul filmului
void FilmRepo::edit_jahr(Film film, int jahr) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		//il editeaza daca il gaseste dupa titlu si an
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
			i->set_jahr(jahr);
			return;
		}
	cout << "Repo Error 404: Film " << film.get_titel() << '\n';
}

//schimba nr de likeuri
void FilmRepo::edit_like(Film film, int like) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		//il editeaza daca il gaseste
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
			i->set_like(like);
			return;
		}
	cout << "Repo Error 404: Film " << film.get_titel()<<'\n';
}

//sterge
void FilmRepo::remove(Film film) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		//il sterge daca il gaseste dupa titlu si an
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr()) {
			filme.erase(i);
			cout << "Film " << film.get_titel() <<" removed."<< '\n';
			return;
		}
	cout << "Repo Error 404: Film " << film.get_titel()<<'\n';
}
// afiseaza filmele
void FilmRepo::print_filme() {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)
		cout << *i;
}

//cauta filmul
Film FilmRepo::find_film(Film film) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)   // cauta filmul in lista si returneaza daca e gasit
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr())
			return film;
	exception f;
	throw f;
	
}

double FilmRepo::find_likes(Film film) {
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++)   //cauta filmul in lista si returneaza nr de like uri
		if (film.get_titel() == i->get_titel() && film.get_jahr() == i->get_jahr())
			return film.get_like();
	return 0;
}

vector<Film> FilmRepo::sort_genre(string g) {
	std::vector <Film> aux;
	for (vector<Film>::iterator i = filme.begin(); i < filme.end(); i++) {   // cauta filmul specific unui gen in lista si il adauga intr o lista noua
		if (i->get_genre() == g)
			aux.push_back(*i);
	}
	return aux;
}