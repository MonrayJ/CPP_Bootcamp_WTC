//
// Created by monray1 on 04/06/2019.
//

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
    return;
}

FragTrap::FragTrap(string name) {

    cout << "Ohhh look... a creapy door in a cave! Knock-Knock!!" << endl;

    this->_name = name;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_armourDamageReduction = 5;
    this->_level = 1;
    //  standard
    this->_rangedAttackDamage = 20;
    this->_meleeAttackDamage = 30;
    //  special
    this->_funZerkerAttackDamage = 5;
    this->_meatUnicycleAttackDamage = 45;
    this->_shhhTrapAttackDamage = 35;
    this->_laserInfernoAttackDamage = 50;
    this->_torgueFiestaAttackDamage = 60;

    return;
}

FragTrap::~FragTrap() {

    if (this->_hitPoints <= 0) {
        cout << "Oh yeah? Well, uh... yeah." << endl;
        return;
    } else
        cout << "Don't tell me that wasn't awesome" << endl;
    return;
}

/* <------------------>    Operator Below    <------------------> */

FragTrap
&FragTrap::operator=(FragTrap const &overload) {
    this->_name = overload._name;
    this->_hitPoints = overload._hitPoints;
    this->_maxHitPoints = overload._maxHitPoints;
    this->_energyPoints = overload._energyPoints;
    this->_maxEnergyPoints = overload._maxEnergyPoints;
    this->_level = overload._level;
    this->_meleeAttackDamage = overload._meleeAttackDamage;
    this->_rangedAttackDamage = overload._rangedAttackDamage;
    this->_armourDamageReduction = overload._armourDamageReduction;
    this->_funZerkerAttackDamage = overload._funZerkerAttackDamage;
    this->_meatUnicycleAttackDamage = overload._meatUnicycleAttackDamage;
    this->_shhhTrapAttackDamage = overload._shhhTrapAttackDamage;
    this->_laserInfernoAttackDamage = overload._laserInfernoAttackDamage;
    this->_torgueFiestaAttackDamage = overload._torgueFiestaAttackDamage;
    return (*this);
}

/* <------------------>    Operator Below    <------------------> */

/* <------------------>    GetMethods Below    <------------------> */

string
FragTrap::getName(void) {
    return (this->_name);
}

unsigned
FragTrap::getHitPoints() {
    return (this->_hitPoints);
}

unsigned
FragTrap::getRangedAttackDamage(void) {
    return (this->_rangedAttackDamage);
}

unsigned
FragTrap::getMeleeAttackDamage(void) {
    return (this->_meleeAttackDamage);
}

unsigned
FragTrap::getArmourDamageReduction(void) {
    return (this->_armourDamageReduction);
}

/* <------------------>    GetMethods Above    <------------------> */

/* <------------------>    HealthMethods Below    <------------------> */

void
FragTrap::takeDamage(unsigned amount) {

    unsigned damage;

    damage = amount - (this->_armourDamageReduction);
    if (damage >= this->_hitPoints) {
        this->_hitPoints = 0;
        cout << this->_name << ": Recompiling combat code, Unit nonOperational!" << endl;
        return;
    } else {
        this->_hitPoints -= damage;
        cout << this->_name << ": Ow hohoho, that hurts! Yipes!" << endl;
        cout << this->_name << " took " << damage << " damage" << endl;
        return;
    }
}

void
FragTrap::repair(unsigned amount) {
    if (this->_hitPoints > amount) {
        this->_hitPoints = 100;
        cout << this->_name << ": Health! Eww, what flavor is red?" << endl;
        cout << this->_name << " recovered all his health" << endl;
        return;
    } else {
        this->_hitPoints += amount;
        cout << this->_name << ": Sweet life juice!" << endl;
        cout << this->_name << " recovered " << amount << " hitPoints" << endl;
        return;
    }
}

void
FragTrap::levelUp() {
    this->_level++;
    cout << this->_name << " Leveled up" << endl;
}

/* <------------------>    HealthMethods Above    <------------------> */

/* <------------------>    AttackMethods Below    <------------------> */

void
FragTrap::rangedAttack(const string &target) {

    cout << this->_name << " attacks " << target << " at range, causing " \
 << this->_rangedAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::meleeAttack(const string &target) {

    cout << this->_name << " melee attacks " << target << " causing " \
 << this->_meleeAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::funZerkerAttack(const string &target) {

    cout << this->_name << ": I'm a sexy dinosaur! Rawr!" << endl;
    cout << this->_name << " hits " << target << " with a Candy Cane and deals " \
 << this->_funZerkerAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::meatUnicycleAttack(const string &target) {

    cout << this->_name << ": It's the only way to stop the voices!" << endl;
    cout << this->_name << " uses Siren Powers to cast a meat tornado at " << target << " causing " \
 << this->_meatUnicycleAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::shhhTrapAttack(const string &target) {

    cout << this->_name << ": I'm a robot ninja..." << endl;
    cout << this->_name << " sneak attacks " << target << " from behind, causing " \
 << this->_shhhTrapAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::laserInfernoAttack(const string &target) {

    cout << this->_name << ": (unintelligible snarling)" << endl;
    cout << this->_name << " sets " << target << " ablaze, causing " \
 << this->_laserInfernoAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::torgueFiestaAttack(const string &target) {

    cout << this->_name << ": It's time for my free grenade giveaway!" << endl;
    cout << this->_name << " hits " << target << " in the face with a grenade, causing " \
 << this->_torgueFiestaAttackDamage << " points of damage!" << endl;

    return;
}

/* <------------------>    AttackMethods Above    <------------------> */

/* <------------------>    VaultHunter.exe Below    <------------------> */

unsigned
FragTrap::vaultHunter_dot_exe(const string &target) {

    cout << this->_name << ": Place your bets!" << endl;

    int arr[] = {1, 2, 3, 4, 5};
    int random;

    random = rand() % 5;

    if (this->_energyPoints >= 25) {
        if (arr[random] == 1) {
            this->funZerkerAttack(target);
            this->_energyPoints -= 25;
            return this->_funZerkerAttackDamage;
        } else if (arr[random] == 2) {
            this->meatUnicycleAttack(target);
            this->_energyPoints -= 25;
            return this->_meatUnicycleAttackDamage;
        } else if (arr[random] == 3) {
            this->shhhTrapAttack(target);
            this->_energyPoints -= 25;
            return this->_shhhTrapAttackDamage;
        } else if (arr[random] == 4) {
            this->laserInfernoAttack(target);
            this->_energyPoints -= 25;
            return this->_laserInfernoAttackDamage;
        } else if (arr[random] == 5) {
            this->torgueFiestaAttack(target);
            this->_energyPoints -= 25;
            return this->_torgueFiestaAttackDamage;
        } else {
            this->_energyPoints -= 25;
            return (0);
        }
    } else {
        cout << this->_name << ": Darn, Eriduim cells are Drained!!" << endl;
        return (0);
    }
}

/* <------------------>    VaultHunter.exe Above    <------------------> */