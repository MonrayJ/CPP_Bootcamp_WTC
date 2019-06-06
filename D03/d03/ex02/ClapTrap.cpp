#include <utility>

#include <ctime>

//
// Created by monray1 on 06/06/2019.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() = default;

ClapTrap::~ClapTrap() {
    if (this->_hitPoints <= 0) {
        std::cout << this->_name << ": Unit non operational" << std::endl;
    } else
        std::cout << this->_name << ": Unit " << this->_hitPoints << "% Operational." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(std::move(name)) {

    std::cout << "New ClapTrap Unit: " << this->_name << std::endl;

    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_armourDamageReduction = 5;
    this->_level = 1;

    this->_rangedAttackDamage = 20;
    this->_meleeAttackDamage = 30;

}

//    GetMethods

const std::string &ClapTrap::getName() const {
    return _name;
}

unsigned int ClapTrap::getHitPoints() const {
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

unsigned int ClapTrap::getArmourDamageReduction() const {
    return _armourDamageReduction;
}

unsigned int ClapTrap::getLevel() const {
    return _level;
}

unsigned int ClapTrap::getRangedAttackDamage() const {
    return _rangedAttackDamage;
}

unsigned int ClapTrap::getMeleeAttackDamage() const {
    return _meleeAttackDamage;
}

unsigned int ClapTrap::getMaxHitPoints() const {
    return _maxHitPoints;
}

unsigned int ClapTrap::getMaxEnergyPoints() const {
    return _maxEnergyPoints;
}

//    Health and Level

void ClapTrap::levelUp() {
    this->_level++;
    std::cout << this->_name << ": Unit Leveled up. Current Level" << this->_level << std::endl;
}

void ClapTrap::takeDamage(unsigned amount) {

    unsigned    damage;

    damage = amount - (this->_armourDamageReduction);
    if (damage >= this->_hitPoints) {
        this->_hitPoints = 0;
        std::cout << this->_name << ": Unit no longer operational!" << std::endl;
        return;
    } else {
        this->_hitPoints -= damage;
        std::cout << this->_name << ": Unit received " << damage << " damage." << std::endl;
        return;
    }
}

void ClapTrap::repair(unsigned amount) {
    if (this->_hitPoints >= amount) {
        this->_hitPoints = 100;
        std::cout << this->_name << ": Fully Repaired" << std::endl;
        return;
    } else {
        this->_hitPoints += amount;
        std::cout << this->_name << ": Unit Repair. Unit " << amount << "% Operational." << std::endl;
        return;
    }
}

//    Default Attack

void ClapTrap::rangedAttack(std::string const &target) {

    std::cout << this->_name << ": Performing Ranged Assault. "
              << target << " Sustained " << this->_rangedAttackDamage << " Damage" << std::endl;
}


void ClapTrap::meleeAttack(std::string const &target){

    std::cout << this->_name << ": Performing Melee Attack. "
              << target << " Sustained " << this->_meleeAttackDamage << " Damage" << std::endl;
}

