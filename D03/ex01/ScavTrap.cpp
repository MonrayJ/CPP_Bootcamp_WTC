//
// Created by monray1 on 04/06/2019.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
    return;
}

ScavTrap::ScavTrap(string name) {

    cout << "Who goes there?? Angel? Activate All Defence Systems!!" << endl;

    this->_name = name;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 50;
    this->_maxEnergyPoints = 50;
    this->_armourDamageReduction = 3;
    this->_level = 1;
    //  standard
    this->_rangedAttackDamage = 20;
    this->_meleeAttackDamage = 15;
    //  special
    this->_spikeTrapAttackDamage = 25;
    this->_tripWireAttackDamage = 45;
    this->_freezeTrapAttackDamage = 35;
    this->_mountedTurretAttackDamage = 50;
    this->_explosiveBarrelAttackDamage = 60;

    return;
}

ScavTrap::~ScavTrap() {

    if (this->_hitPoints <= 0) {
        cout << "Defeated!! impossible" << endl;
        return;
    }
    else
        cout << "Go back from whence you came!" << endl;
    return;
}

/* <------------------>    Operator Below    <------------------> */

ScavTrap
&ScavTrap::operator= (ScavTrap const &overload)
{
    this->_name = overload._name;
    this->_hitPoints = overload._hitPoints;
    this->_maxHitPoints = overload._maxHitPoints;
    this->_energyPoints = overload._energyPoints;
    this->_maxEnergyPoints = overload._maxEnergyPoints;
    this->_level = overload._level;
    this->_meleeAttackDamage = overload._meleeAttackDamage;
    this->_rangedAttackDamage = overload._rangedAttackDamage;
    this->_armourDamageReduction = overload._armourDamageReduction;
    this->_spikeTrapAttackDamage = overload._spikeTrapAttackDamage;
    this->_tripWireAttackDamage = overload._tripWireAttackDamage;
    this->_freezeTrapAttackDamage = overload._freezeTrapAttackDamage;
    this->_mountedTurretAttackDamage = overload._mountedTurretAttackDamage;
    this->_explosiveBarrelAttackDamage = overload._explosiveBarrelAttackDamage;
    return (*this);
}

/* <------------------>    Operator Below    <------------------> */

/* <------------------>    GetMethods Below    <------------------> */

string
ScavTrap::getName(void) {
    return (this->_name);
}

unsigned
ScavTrap::getHitPoints(){
    return (this->_hitPoints);
}

unsigned
ScavTrap::getRangedAttackDamage(void) {
    return (this->_rangedAttackDamage);
}

unsigned
ScavTrap::getMeleeAttackDamage(void) {
    return (this->_meleeAttackDamage);
}

/* <------------------>    GetMethods Above    <------------------> */

/* <------------------>    HealthMethods Below    <------------------> */

void
ScavTrap::takeDamage(unsigned amount) {

    unsigned damage;

    damage = amount - (this->_armourDamageReduction);
    if (damage >= this->_hitPoints) {
        this->_hitPoints = 0;
        cout << this->_name << ": Recompiling combat code, Unit nonOperational!" << endl;
        return;
    } else {
        this->_hitPoints -= damage;
        cout << this->_name << ": Who are you to Strike at me?" << endl;
        cout << this->_name << " took " << damage << " damage" << endl;
        return;
    }
}

void
ScavTrap::repair(unsigned amount) {
    if (this->_hitPoints > amount) {
        this->_hitPoints = 100;
        cout << this->_name << ": Red liquid, Give me STRENGTH!!" << endl;
        cout << this->_name << " recovered all his health" << endl;
        return;
    } else {
        this->_hitPoints += amount;
        cout << this->_name << ": Nectar of life!" << endl;
        cout << this->_name << " recovered " << amount << " hitPoints" << endl;
        return;
    }
}

void
ScavTrap::levelUp() {
    this->_level++;
    cout << this->_name << " Leveled up" << endl;
}

/* <------------------>    HealthMethods Above    <------------------> */

/* <------------------>    AttackMethods Below    <------------------> */

void
ScavTrap::rangedAttack(const string &target) {

    cout << this->_name << " attacks " << target << " at range, causing " \
 << this->_rangedAttackDamage << " points of damage!" << endl;

    return;
}

void
ScavTrap::meleeAttack(const string &target) {

    cout << this->_name << " melee attacks " << target << " causing " \
 << this->_meleeAttackDamage << " points of damage!" << endl;

    return;
}

void
ScavTrap::spikeTrapAttack(const string &target) {

    cout << this->_name << ": Your Blindness will be your end!" << endl;
    cout << this->_name << " witnesses " << target << " trigger a spike trap dealing " \
 << this->_spikeTrapAttackDamage << " points of damage!" << endl;

    return;
}

void
ScavTrap::tripWireAttack(const string &target) {

    cout << this->_name << ": Did't see that one did ya?" << endl;
    cout << this->_name << " witnesses " << target << " triggering a trip wire dealing " \
 << this->_tripWireAttackDamage << " points of damage!" << endl;

    return;
}

void
ScavTrap::freezeTrapAttack(const string &target) {

    cout << this->_name << ": Ohhh that's cold..." << endl;
    cout << this->_name << " witnesses " << target << " triggering a cryo trap dealing " \
 << this->_freezeTrapAttackDamage << " points of damage!" << endl;

    return;
}

void
ScavTrap::mountedTurretAttack(const string &target) {

    cout << this->_name << ": (unintelligible snarling)" << endl;
    cout << this->_name << " witnesses " << target << " being gunned down dealing " \
 << this->_mountedTurretAttackDamage << " points of damage!" << endl;

    return;
}

void
ScavTrap::explosiveBarrelAttack(const string &target) {

    cout << this->_name << ": Heads up!!" << endl;
    cout << this->_name << " hits " << target << " with a explosive barrel from above, dealing " \
 << this->_explosiveBarrelAttackDamage << " points of damage!" << endl;

    return;
}

/* <------------------>    AttackMethods Above    <------------------> */

/* <------------------>    VaultHunter.exe Below    <------------------> */

unsigned
ScavTrap::challengeNewcomer(const string &target) {

    cout << this->_name << ": Aha ha ha, walked right into it..." << endl;

    int i;
    srand (time(NULL));
    i = rand() % 5 + 1;

    if (this->_energyPoints >= 25) {
        if (i == 1) {
            this->spikeTrapAttack(target);
            return this->_spikeTrapAttackDamage;
        }
        if (i == 2) {
            this->tripWireAttack(target);
            return this->_tripWireAttackDamage;
        }
        if (i == 3) {
            this->freezeTrapAttack(target);
            return this->_freezeTrapAttackDamage;
        }
        if (i == 4) {
            this->mountedTurretAttack(target);
            return this->_mountedTurretAttackDamage;
        }
        if (i == 5) {
            this->explosiveBarrelAttack(target);
            return this->_explosiveBarrelAttackDamage;
        }
        this->_energyPoints -= 25;
    } else {
        cout << this->_name << ": Noo!! Eriduim cells need be replenished!!" << endl;
        return (0);
    }
    return (0);
}

/* <------------------>    VaultHunter.exe Above    <------------------> */