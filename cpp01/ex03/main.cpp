#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }
    return 0;
}

/*
case HumanA:
    better to use a reference to the weapon, as it is more efficient and avoids unnecessary copying.
case HumanB:
    better to use a pointer to the weapon, as it allows for the possibility of not having a weapon set (i.e., the pointer can be null).
    This is useful for cases where the character may not always have a weapon.
*/