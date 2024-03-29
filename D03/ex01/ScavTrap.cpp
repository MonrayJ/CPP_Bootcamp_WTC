//
// Created by monray1 on 04/06/2019.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
    return;
}

ScavTrap::ScavTrap(string name) {

    cout << "Who goes there?? Angel? Activate All Defence Systems!!" << std::endl;

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
        cout << "Defeated!! impossible" << std::endl;
        return;
    } else
        cout << "Go back from whence you came!" << std::endl;
    return;
}

/* <------------------>    Operator Below    <------------------> */

ScavTrap
&ScavTrap::operator=(ScavTrap const &overload) {
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
ScavTrap::getHitPoints() {
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

unsigned
ScavTrap::getArmourDamageReduction(void) {
    return (this->_armourDamageReduction);
}

/* <------------------>    GetMethods Above    <------------------> */

/* <------------------>    HealthMethods Below    <------------------> */

void
ScavTrap::takeDamage(unsigned amount) {

    unsigned damage;

    damage = amount - (this->_armourDamageReduction);
    if (damage >= this->_hitPoints) {
        this->_hitPoints = 0;
        cout << this->_name << ": Recompiling combat code, Unit nonOperational!" << std::endl;
        return;
    } else {
        this->_hitPoints -= damage;
        cout << this->_name << ": Who are you to Strike at me?" << std::endl;
        cout << this->_name << " took " << damage << " damage" << std::endl;
        return;
    }
}

void
ScavTrap::repair(unsigned amount) {
    if (this->_hitPoints > amount) {
        this->_hitPoints = 100;
        cout << this->_name << ": Red liquid, Give me STRENGTH!!" << std::endl;
        cout << this->_name << " recovered all his health" << std::endl;
        return;
    } else {
        this->_hitPoints += amount;
        cout << this->_name << ": Nectar of life!" << std::endl;
        cout << this->_name << " recovered " << amount << " hitPoints" << std::endl;
        return;
    }
}

void
ScavTrap::levelUp() {
    this->_level++;
    cout << this->_name << " Leveled up" << std::endl;
}

/* <------------------>    HealthMethods Above    <------------------> */

/* <------------------>    AttackMethods Below    <------------------> */

void
ScavTrap::rangedAttack(const string &target) {

    cout << this->_name << " attacks " << target << " at range, causing " \
 << this->_rangedAttackDamage << " points of damage!" << std::endl;

    return;
}

void
ScavTrap::meleeAttack(const string &target) {

    cout << this->_name << " melee attacks " << target << " causing " \
 << this->_meleeAttackDamage << " points of damage!" << std::endl;

    return;
}

void
ScavTrap::spikeTrapAttack(const string &target) {

    cout << this->_name << ": Your Blindness will be your end!" << std::endl;
    cout << this->_name << " witnesses " << target << " trigger a spike trap dealing " \
 << this->_spikeTrapAttackDamage << " points of damage!" << std::endl;

    return;
}

void
ScavTrap::tripWireAttack(const string &target) {

    cout << this->_name << ": Did't see that one did ya?" << std::endl;
    cout << this->_name << " witnesses " << target << " triggering a trip wire dealing " \
 << this->_tripWireAttackDamage << " points of damage!" << std::endl;

    return;
}

void
ScavTrap::freezeTrapAttack(const string &target) {

    cout << this->_name << ": Ohhh that's cold..." << std::endl;
    cout << this->_name << " witnesses " << target << " triggering a cryo trap dealing " \
 << this->_freezeTrapAttackDamage << " points of damage!" << std::endl;

    return;
}

void
ScavTrap::mountedTurretAttack(const string &target) {

    cout << this->_name << ": (unintelligible snarling)" << std::endl;
    cout << this->_name << " witnesses " << target << " being gunned down dealing " \
 << this->_mountedTurretAttackDamage << " points of damage!" << std::endl;

    return;
}

void
ScavTrap::explosiveBarrelAttack(const string &target) {

    cout << this->_name << ": Heads up!!" << std::endl;
    cout << this->_name << " hits " << target << " with a explosive barrel from above, dealing " \
 << this->_explosiveBarrelAttackDamage << " points of damage!" << std::endl;

    return;
}

/* <------------------>    AttackMethods Above    <------------------> */

/* <------------------>    VaultHunter.exe Below    <------------------> */

unsigned
ScavTrap::challengeNewcomer(const string &target) {

    cout << this->_name << ": Aha ha ha, walked right into it..." << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    int random;

    random = rand() % 5;

    if (this->_energyPoints >= 25) {
        if (arr[random] == 1) {
            this->spikeTrapAttack(target);
            this->_energyPoints -= 25;
            return this->_spikeTrapAttackDamage;
        } else if (arr[random] == 2) {
            this->tripWireAttack(target);
            this->_energyPoints -= 25;
            return this->_tripWireAttackDamage;
        } else if (arr[random] == 3) {
            this->freezeTrapAttack(target);
            this->_energyPoints -= 25;
            return this->_freezeTrapAttackDamage;
        } else if (arr[random] == 4) {
            this->mountedTurretAttack(target);
            this->_energyPoints -= 25;
            return this->_mountedTurretAttackDamage;
        } else if (arr[random] == 5) {
            this->explosiveBarrelAttack(target);
            this->_energyPoints -= 25;
            return this->_explosiveBarrelAttackDamage;
        } else {
            this->_energyPoints -= 25;
            return (0);
        }
    } else {
        cout << this->_name << ": Noo!! Eriduim cells need be replenished!!" << std::endl;
        return (0);
    }
}

/* <------------------>    VaultHunter.exe Above    <------------------> */