
#include "Test.h"
#include "UI.h"
#include <cassert>

Film a("The Dark Knight", "Action", 2008, 98, "https://youtu.be/EXeTwQWrcwY");
Film b("Spidermann", "Action", 2019, 56, "https://youtu.be/Nt9L1jCKGnE");
Film c("Star Wars", "Sci-Fi", 2015, 81, "https://youtu.be/sGbxmsDFVnE");
Film d("The Dictator", "Comedy", 2012, 82, "https://youtu.be/cYplvwBvGA4");
Film e("The Lord of the Rings", "Fantasy", 2003, 9, "https://youtu.be/r5X-hFf6Bwo");
Film f("Thor", "Action", 2017, 28, "https://youtu.be/ue80QwXMRHg");
Film g("Joker", "Drama", 2019, 9, "https://youtu.be/rgXplohCw5o");
Film h("Avengers: Endgame", "Action", 2019, 55, "https://youtu.be/TcMBFSGVi1c");
Film i("Justice League", "", 2017, 42, "https://youtu.be/3cxixDgHUYw");
Film j("Mission: Impossible", "Action", 2018, 69, "https://youtu.be/wb49-oV0F78");

void Test::test() {

	FilmRepo r;
	cout << "Test Add\n";
	r.add(a);
	r.add(b);
	r.add(c);
	r.add(a);
	assert(r.get_filme().size() == 3);

	cout << "Test Remove\n";
	r.remove(a);
	r.remove(b);
	r.remove(c);
	r.remove(a);
	assert(r.get_filme().size() == 0);

	cout << "Test Edit\n\n";
	r.add(a);
	
	r.edit_titel(a, "aaa");
	a.set_titel("aaa");
	r.edit_genre(a, "aaa");
	a.set_genre("aaa");
	r.edit_jahr(a, 1);
	a.set_jahr(1);
	r.edit_like(a, 1);
	a.set_like(1);
	r.edit_trailer(a, "aaa");
	a.set_trailer("aaa");

	assert(r.find_film(a).get_titel() == a.get_titel());
	r.remove(a);
	assert(r.get_filme().size() == 0);
}