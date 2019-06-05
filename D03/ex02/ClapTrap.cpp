//
// Created by monray1 on 05/06/2019.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
    return;
}

ClapTrap::ClapTrap(string name) {

    cout << "New Claptrap unit: " << name << "." << std::endl;

    this->_name = name;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_level = 1;

    return;
}

ClapTrap::~ClapTrap() {
    if (this->_hitPoints <= 0) {
        cout << this->_name << ": Unit Destroyed." << std::endl;
        return;
    } else
        cout << "Unit still operational." << std::endl;
    return;
}

string
ClapTrap::getName() {
    return this->_name;
}

unsigned
ClapTrap::getHitPoints() {
    return this->_hitPoints;
}

unsigned
ClapTrap::getRangedAttackDamage() {
    return this->_rangedAttackDamage;
}

unsigned ClapTrap::getMeleeAttackDamage() {
    return this->_meleeAttackDamage
}

unsigned
ClapTrap::getArmourDamageReduction(void) {
    return (this->_armourDamageReduction);
}

/* <------------------>    HealthMethods Below    <------------------> */

void
ClapTrap::takeDamage(unsigned amount) {

    unsigned damage;

    damage = amount - (this->_armourDamageReduction);
    if (damage >= this->_hitPoints) {
        this->_hitPoints = 0;
        cout << this->_name << ": Unit no longer operational!" << std::endl;
        return;
    } else {
        this->_hitPoints -= damage;
        cout << this->_name << " received " << damage << " damage." << std::endl;
        return;
    }
}

void
ClapTrap::repair(unsigned amount) {
    if (this->_hitPoints > amount) {
        this->_hitPoints = 100;
        cout << this->_name << " Fully repaired" << std::endl;
        return;
    } else {
        this->_hitPoints += amount;
        cout << this->_name << " recovered " << amount << " hitPoints" << std::endl;
        return;
    }
}

void
ClapTrap::levelUp() {
    this->_level++;
    cout << this->_name << ": Upgrade Complete." << std::endl;
}

/* <------------------>    HealthMethods Above    <------------------> */

/* <------------------>    AttackMethods Below    <------------------> */

void
ClapTrap::rangedAttack(const string &target) {

    cout << this->_name << " attacks " << target << " at range, dealing "
         << this->_rangedAttackDamage << " points of damage!" << std::endl;

    return;
}

void
ClapTrap::meleeAttack(const string &target) {

    cout << this->_name << " melee attacks " << target << " dealing "
         << this->_meleeAttackDamage << " points of damage!" << std::endl;

    return;
}

/* <------------------>    AttackMethods Above    <------------------> */
