#include<Character.h>

Character::Character()
{
    CharacterStats->Health = 100;
    CharacterStats->Defense = 50;
    CharacterStats->ComebackDefense = 70;
    CharacterStats->MoveSpeed = 10;
    CharacterStats->JumpHeight = 20;
}

Character::~Character()
{
    // Destructor code
}