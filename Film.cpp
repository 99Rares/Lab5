#include "Film.h"
Film::Film(string titel, string genre, int jahr, int likes, string trailer) {
	this->titel = titel;
	this->genre = genre;
	this->jahr = jahr;
	this->like = likes;
	this->trailer = trailer;
}

//get
string Film::get_titel()const {
	return titel;
}

string Film::get_genre()const {
	return genre;
}

string Film::get_trailer()const {
	return trailer;
}

int Film::get_jahr() const {
	return jahr;
}

int Film::get_like() const {
	return like;
}

//set
void Film::set_titel(string titel) {
	this->titel = titel;
}

void Film::set_genre(string genre) {
	this->genre = genre;
}

void Film::set_trailer(string trailer) {
	this->trailer = trailer;
}

void Film::set_jahr(double jahr) {
	this->jahr = jahr;
}

void Film::set_like(double like) {
	this->like = like;
}
//operators
std::ostream& operator << (std::ostream& output, const Film& film) {
	output << "Film:\nTitel: " << film.titel << "\nGenre: " << film.genre << "\nJahr: " << film.jahr << "\nLikes: " << film.like << "\nTrailer: " << film.trailer << "\n";
	return output;
}

bool operator==(const Film& film1, const Film& film2) {
	return (film1.titel == film2.titel && film1.genre == film2.genre && film1.jahr == film2.jahr && film1.like == film2.like && film1.trailer == film2.trailer);
}

bool operator!=(const Film& film1, const Film& film2) {
	return !(film1 == film2);
}