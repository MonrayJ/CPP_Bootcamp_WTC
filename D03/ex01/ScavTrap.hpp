//
// Created by monray1 on 04/06/2019.
//

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ScavTrap {

public:

    ScavTrap(void);
    ScavTrap(string);
    ~ScavTrap(void);

//    Operator
    ScavTrap  &operator=(ScavTrap const &overload);

//    Health
    void        levelUp(void);
    void        takeDamage(unsigned amount);
    void        repair(unsigned amount);

//    Default attack
    void        rangedAttack(string const &target);
    void        meleeAttack(string const &target);

//    Activate VaultHunter_dot_exe
    unsigned    challengeNewcomer(string const &target);

//    Evil Lair Defences
    void        spikeTrapAttack(string const &target);
    void        tripWireAttack(string const &target);
    void        freezeTrapAttack(string const &target);
    void        mountedTurretAttack(string const &target);
    void        explosiveBarrelAttack(string const &target);

//    Get attributes
    string      getName(void);
    unsigned    getHitPoints(void);
    unsigned    getEnergyPoints(void);

//    Get damage values
    // standard
    unsigned    getRangedAttackDamage(void);
    unsigned    getMeleeAttackDamage(void);
    // special
    unsigned    getSpikeTrapAttackDamage(void);
    unsigned    getTripWireAttackDamage(void);
    unsigned    getFreezeTrapAttackDamage(void);
    unsigned    getMountedTurretAttackDamage(void);
    unsigned    getExplosiveBarrelAttackDamage(void);


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
    unsigned    _spikeTrapAttackDamage;
    unsigned    _tripWireAttackDamage;
    unsigned    _freezeTrapAttackDamage;
    unsigned    _mountedTurretAttackDamage;
    unsigned    _explosiveBarrelAttackDamage;

};


#endif //SCAVTRAP_HPP
