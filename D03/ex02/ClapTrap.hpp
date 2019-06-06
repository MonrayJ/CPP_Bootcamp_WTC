//
// Created by monray1 on 05/06/2019.
//

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ClapTrap {

public:

    ClapTrap(string);
    ~ClapTrap(void);

    Operator
    ClapTrap &operator=(ClapTrap const &overload);

//    Health
    void        levelUp(void);
    void        takeDamage(unsigned amount);
    void        repair(unsigned amount);

//    Default attack
    void        rangedAttack(string const &target);
    void        meleeAttack(string const &target);

//    Get attributes
    string      getName(void);
    unsigned    getHitPoints(void);
    unsigned    getEnergyPoints(void);
    unsigned    getArmourDamageReduction(void);

//    Get damage values
    // standard
    unsigned    getRangedAttackDamage(void);
    unsigned    getMeleeAttackDamage(void);

protected:

    Attributes
    string      _name;
    unsigned    _hitPoints;
    unsigned    _maxHitPoints;
    unsigned    _energyPoints;
    unsigned    _maxEnergyPoints;
    unsigned    _armourDamageReduction;
    unsigned    _level;

//    Damage values
    //  standard
    unsigned    _rangedAttackDamage;
    unsigned    _meleeAttackDamage;

};


#endif //CLAPTRAP_HPP
