#include "UI.h"
#include "Valid.h"
Valid valid;
//constructor
UI::UI(Admin admin, User user) {
    this->admin = admin;
    this->user = user;
}
//meniu principal
void UI::main_menu() {
    string menu = " Main Menu \n 0. Exit \n 1. User Menu \n 2. Admin Menu \n";
    int key;
    cout << menu;
    cout << "wahl: ";
    key = valid.read_range(2);

    while (key != 0) {
        if (key == 1)
            user_menu();
        if (key == 2)
            admin_menu();
        cout << menu;
        cout << "wahl: ";
        key = valid.read_range(2);
    }
}
//meniu pentru user
void UI::user_menu() {
    string menu = " User Menu \n 1. Add to WatchList \n 2. Rate Film \n 3. Print Watchlist \n 0. Back\n";
    int key;
    cout << menu;
    cout << "wahl: ";
    key = valid.read_range(3);
    while (key != 0) {
        if (key == 1)
            add_to_watch();
        if (key == 2)
            rate();
        if (key == 3)
            user.print_watch();
        cout << menu;
        cout << "wahl: ";
        key = valid.read_range(3);
    }
}
//meniu filme
void UI::add_to_watch() {
    string genre;
    cout << "Select Genre: "; cin >> genre;
    vector<Film> filme = user.get_repo().sort_genre(genre);
    string menu = " User Menu \n 1. Add to WatchList \n 2. Next \n 0. Back\n";
    int key,current=0;
    if (!filme.empty()) {
        cout << filme[current];
        system(std::string("start " + filme[current].get_trailer()).c_str());
        cout << menu;
        cout << "wahl: ";
        key = valid.read_range(2);

        while (key != 0) {
            if (key == 1) { //adauga film
                std::vector<Film> watch = user.get_watch();
                Film find = filme[current];
                if (user.find_film(find)) {
                    cout << "Film existiert schon";
                    break;
                }
                user.add_to_watch(find);
                cout << "Filme: " << user.get_watch().size() << '\n';
                current++;
            }
            if (key == 2) {//trece la urmatorul film din lista
                if (current == filme.size() - 1) {
                    cout << "\nKeine"<<genre<<"mehr. \n";
                    break;
                }
                current++;
                cout << filme[current];
                system(std::string("start " + filme[current].get_trailer()).c_str());
            }
            cout << menu;
            cout << "wahl: ";
            key = valid.read_range(2);
        }
    }
    else
    {
        cout << "Es gibt keine " << genre << " Filme";
        user.get_repo().print_filme();
    }
}
void UI::rate() {
    // cauta un film in watchlist, daca este gasit intreaba user-ul daca doreste sa il stearga sau sa il evalueze(rate)
    string film;
    cout << "Film: ";
    getline(cin, film);
    std::vector<Film> watch = user.get_watch();
    Film find = Film("", "", 0, 0, "");
    for (int i = 0; i < user.get_repo().get_filme().size(); i++) {  // cauta daca exista filmul
        if (film == user.get_repo().get_filme()[i].get_titel()) {
            find = user.get_repo().get_filme()[i];
            break;
        }
    }
    if (user.find_film(find)) { // in cazul in care nu e gasit
        cout << "Error 404\n";
    }

    else {
        cout << "Film beverten?\n";
        int key;
        string menu = "1. Ja\n 2. Loschen\n 0. Exit\n";
        cout << menu;
        key = valid.read_range(2);
        //3 optiuni posibile
        while (key != 0) {
           

            // valideaza input-ul

            if (key == 1) {
                user.add_like(find);
                admin.edit_like(find, find.get_like() + 1);
                user.remove_from_watch(find);
                break;
            }
            else if (key == 2) {
                user.remove_from_watch(find);
                break;
            }
            cout << menu;
            key = valid.read_range(2);
        }
    }
}
//meniu admin
void UI::admin_menu() {
  
    string Menu = " 1. Add\n 2. remove\n 3. Edit\n 4. Print\n 0. Back\n";
    int key;
    cout << "Admin Menu\n";
    cout << "\n" << Menu;
    cout << "\nwahl: ";
    key = valid.read_range(4);
    while (key!=0) {
        

        // valideaza input-ul
        // citeste toate atributele filmului si adauga in repo
        if (key == 1) {
            string title;
            string genre;
            double jahr;
            double likes;
            string trailer;
            cout << "Enter Title: ";  getline(cin, title);
           
            cout << "Enter Genre: ";  getline(cin, genre);
           
            cout << "Enter Jahr: "; jahr=valid.read_nr();
         
            cout << "Enter Likes: "; cin >> likes;

            cout << "Enter Trailer: "; getline(cin, trailer);
           
            Film film = Film(title, genre, jahr, likes, trailer);
            admin.add(film);
        }
        // cauta filmul pentru a fi sters
        else if (key == 2) {
            string title;
            Film film = Film("", "", 0, 0, "");
            cout << "Enter Title to delete: ";
            getline(cin, title);
            for (int i = 0; i < admin.get_repo().get_filme().size(); i++) {  
               //sterge daca e gasit
                if (title == admin.get_repo().get_filme()[i].get_titel()) {
                    film = admin.get_repo().get_filme()[i]; 
                    break;
                }
            }
            //"eroare" daca nu e gasit
            if (film.get_titel() == "") {
                cout << "Error 404\n";
            }
            else {
                admin.remove(film);
                user.remove_from_watch(film);
            }

        }// cauta filmul pentru a edita atributele
        else if (key == 3) {
            string title;
            Film film = Film("", "", 0, 0, "");
            cout << "Film zu bearbeiten: "; cin.ignore(); getline(cin, title);
            for (int i = 0; i < admin.get_repo().get_filme().size(); i++) {  // cauta daca filmul este existent
                if (title == admin.get_repo().get_filme()[i].get_titel()) {
                    film = admin.get_repo().get_filme()[i];
                    break;
                }
            }
            if (film.get_titel() == "") {
                cout << "Error 404\n";
                break;

            }
            //pentru a alege ce se editeaza la film
            string menu2 = " 1. edit title\n 2. edit genre\n 3. edit jahr\n 4. edit likes\n 5. edit trailer\n";
            cout << menu2;
            int key2;
            cout << "\nwahl: ";
            key2 = valid.read_range(5);
            while (true) {

                if (key2 == 1) { //editare titlu
                    string title2;
                    cout << "New Title: ";
                    getline(cin, title2);

                    admin.edit_titel(film, title2);
                    if (user.find_film(film)) {
                        user.remove_from_watch(film);
                        film.set_titel(title2);
                        user.add_to_watch(film);
                    }
                    break;
                }
                else if (key2 == 2) { // editare gen
                    string genre;
                    cout << "New Genre: ";
                    getline(cin, genre);

                    admin.edit_genre(film, genre);
                    if (user.find_film(film)) {
                        user.remove_from_watch(film);
                        film.set_genre(genre);
                        user.add_to_watch(film);
                    }
                    break;
                }
                else if (key2 == 3) { //editare an
                    int jahr;
                    cout << "New Jahr: ";
                    jahr=valid.read_nr();
                    admin.edit_jahr(film, jahr);
                    if (user.find_film(film)) {
                        user.remove_from_watch(film);
                        film.set_jahr(jahr);
                        user.add_to_watch(film);
                    }
                    break;
                }
                else if (key2 == 4) {// editare likes
                    int likes;
                    cout << "Likes: ";
                    likes=valid.read_nr();
                    admin.edit_like(film, likes);
                    if (user.find_film(film)) {
                        user.remove_from_watch(film);
                        film.set_like(likes);
                        user.add_to_watch(film);
                    }
                    break;
                }
                else if (key2 == 5) {// editare trailer
                    string trailer;
                    cout << "New Trailer: ";
                    cin.ignore();
                    getline(cin, trailer);
                    admin.edit_trailer(film, trailer);
                    if (user.find_film(film)) {
                        user.remove_from_watch(film);
                        film.set_trailer(trailer);
                        user.add_to_watch(film);
                    }
                    break;
                }
                cout << "\nwahl: ";
                key2 = valid.read_range(5);
            }
        }// printeaza filmele
        else if (key == 4) {
            admin.print_filme();

            cout << "\n" << Menu;
            cout << "\nwahl: ";
            key = valid.read_range(4);
        }
    }
}