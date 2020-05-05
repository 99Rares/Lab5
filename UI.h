#pragma once
#include "User.h"
#include "Admin.h"
class UI
{
private:

    Admin admin;
    User user;
public:
    UI(Admin, User);

    void main_menu();

    void admin_menu();

    void user_menu();

    void add_to_watch();

    void rate();
};
