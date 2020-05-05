//#include "Tests.h"
#include "FilmRepo.h"
#include "UI.h"
#include "Test.h"
#include <iostream>

using std::cout;

int main() {
	Test test;
	test.test();
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

	FilmRepo filmRepo;
	filmRepo.add(a);
	filmRepo.add(b);
	filmRepo.add(c);
	filmRepo.add(d);
	filmRepo.add(e);
	filmRepo.add(f);
	filmRepo.add(g);
	filmRepo.add(h);
	filmRepo.add(i);
	filmRepo.add(j);

	User user = User(filmRepo);
	Admin admin = Admin(filmRepo);

	user.add_to_watch(a);
	user.add_to_watch(h);


	UI ui(admin, user);
	ui.main_menu();
}