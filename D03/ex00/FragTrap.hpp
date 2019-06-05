//
// Created by monray1 on 04/06/2019.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class FragTrap {

public:

    FragTrap(void);
    FragTrap(string);
    ~FragTrap(void);

//    Operator
    FragTrap  &operator=(FragTrap const &overload);

//    Health
    void        takeDamage(unsigned amount);
    void        repair(unsigned amount);

//    Default attack
    void        rangedAttack(string const &target);
    void        meleeAttack(string const &target);

//    Activate VaultHunter_dot_exe
    unsigned    vaultHunter_dot_exe(string const &target);

//    Random Attacks
    void        funZerkerAttack(string const &target);
    void        meatUnicycleAttack(string const &target);
    void        shhhTrapAttack(string const &target);
    void        laserInfernoAttack(string const &target);
    void        torgueFiestaAttack(string const &target);

//    Get attributes
    string      getName(void);
    unsigned    getHitPoints(void);
    unsigned    getEnergyPoints(void);

//    Get damage values
    // standard
    unsigned    getRangedAttackDamage(void);
    unsigned    getMeleeAttackDamage(void);
    // special
    unsigned    getFunZerkerAttackDamage(void);
    unsigned    getMeatUnicycleAttackDamage(void);
    unsigned    getShhhTrapAttackDamage(void);
    unsigned    getLaserInfernoAttackDamage(void);
    unsigned    getTorgueFiestaAttackDamage(void);

//    Set Hp and Energy
    void        setHitPoints(unsigned val);
    void        setEnergyPoints(unsigned val);

private:

//    Attributes
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
    //  special
    unsigned    _funZerkerAttackDamage;
    unsigned    _meatUnicycleAttackDamage;
    unsigned    _shhhTrapAttackDamage;
    unsigned    _laserInfernoAttackDamage;
    unsigned    _torgueFiestaAttackDamage;

};


#endif //FRAGTRAP_HPP
