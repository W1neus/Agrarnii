#include <iostream>
#include <memory>
#include <typeinfo>
#include "warrior.h"
#include "wizard.h"
#include "paladin.h"
#include "player.h"
#include "playerclass.h"
#include "weaponquality.h"

using namespace std;

int main()
{
    Player player;
    cout << "Присядь путник у костра и расскажи кто ты" << endl;
    cout << "\t1 - воин\n\t2 - маг \n\t3 - паладин" << endl;
    short choice = 0;
    cin >> choice;

    switch (static_cast<PlayerClass>(choice))
    {
        case PlayerClass::warrior:
            player.Create(make_unique<Warrior>());
            break;
        case PlayerClass::wizard:
            player.Create(make_unique<Wizard>());
            break;
        case PlayerClass::paladin:
            player.Create(make_unique<Paladin>());
            break;
        default:
            cout << "Таких героев еще не было в наших краях" << endl;
            break;
    }

    cout << endl;
    cout << "Ты выбрал героя, вот его характеристики:" << endl;
    player.GetInfo();
    cout << endl;
    cout << "Теперь выбери качество оружия для своего героя" << endl;
    cout << "\t1 - обычное\n\t2 - необычное \n\t3 - редкое\n\t4 - эпическое\n\t5 - легендарное" << endl;
    short weaponChoice = 0;
    cin >> weaponChoice;

    if (typeid(*player.GetCharacter()) == typeid(Warrior))
    {
        dynamic_cast<Warrior*>(player.GetCharacter())->GetWeapon().quality = static_cast<WeaponQuality>(weaponChoice);
    }
    else if (typeid(*player.GetCharacter()) == typeid(Wizard))
    {
        dynamic_cast<Wizard*>(player.GetCharacter())->LearnSpell().quality = static_cast<WeaponQuality>(weaponChoice);
    }
    else if (typeid(*player.GetCharacter()) == typeid(Paladin))
    {
        dynamic_cast<Paladin*>(player.GetCharacter())->GetWeapon().quality = static_cast<WeaponQuality>(weaponChoice);
        dynamic_cast<Paladin*>(player.GetCharacter())->LearnSpell().quality = static_cast<WeaponQuality>(weaponChoice);
    }

    switch (static_cast<WeaponQuality>(weaponChoice))
    {
        case WeaponQuality::common:
            cout << "Ты выбрал обычное оружие" << endl;
            break;
        case WeaponQuality::uncommon:
            cout << "Ты выбрал необычное оружие" << endl;
            break;
        case WeaponQuality::rare:
            cout << "Ты выбрал редкое оружие" << endl;
            break;
        case WeaponQuality::epic:
            cout << "Ты выбрал эпическое оружие" << endl;
            break;
        case WeaponQuality::legendary:
            cout << "Ты выбрал легендарное оружие" << endl;
            break;
        default:
            cout << "Такого качества не существует!" << endl;
            break;
    }
    return 0;
}