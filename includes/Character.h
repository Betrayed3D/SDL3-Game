#pragma once
#include<string>

class Character
{
private:
    struct Stats
    {
        int Health;
        int Defense;
        int ComebackDefense;
        float MoveSpeed;
        float JumpHeight;
    };

    Stats* CharacterStats;
public:
    Character();
    ~Character();
};