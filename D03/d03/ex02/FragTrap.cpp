//
// Created by monray1 on 06/06/2019.
//

#include <time.h>
#include "FragTrap.hpp"

FragTrap::FragTrap() = default;
FragTrap::FragTrap(const std::string &string) : ClapTrap(string) {

    this->_spikeTrapAttackDamage = 25;
    this->_tripWireAttackDamage = 45;
    this->_freezeTrapAttackDamage = 35;
    this->_mountedTurretAttackDamage = 30;
    this->_explosiveBarrelAttackDamage = 25;
}

///* <------------>   Attack Methods   <------------> */

void FragTrap::spikeTrapAttack(const std::string &target) {
    std::cout << this->_name << ": " << target << " triggered spike trap dealing " \
 << this->_spikeTrapAttackDamage << " damage." << std::endl;
}

void FragTrap::tripWireAttack(const std::string &target) {
    std::cout << this->_name << ": " << target << " triggered trip wire dealing " \
 << this->_tripWireAttackDamage << " damage." << std::endl;
}

void FragTrap::freezeTrapAttack(const std::string &target) {
    std::cout << this->_name << ": " << target << " triggered cryo trap dealing " \
 << this->_freezeTrapAttackDamage << " damage." << std::endl;
}

void FragTrap::mountedTurretAttack(const std::string &target) {
    std::cout << this->_name << ": " << target << " spotted by auto turret dealing " \
 << this->_mountedTurretAttackDamage << " damage." << std::endl;
}

void FragTrap::explosiveBarrelAttack(const std::string &target) {
    std::cout << this->_name << ": " << target << " knocked over explosive barrel dealing " \
 << this->_explosiveBarrelAttackDamage << " damage." << std::endl;
}

///* <------------>   Challenger Method   <------------> */

unsigned
FragTrap::vaulthunter_dot_exe(const std::string &target) {

    std::cout << this->_name << ": Activating VaultHunter.EXE" << std::endl;

    srand((unsigned)time(nullptr));
    int i;
    int lowest=1, highest=5;
    int range=(highest-lowest)+1;
    i = lowest+int(range*rand()/(RAND_MAX + 1.0));

    if (i > 5 || i < 1) {
        i = 3;
    }
    if (this->_energyPoints >= 25) {
        if (i == 1) {
            this->spikeTrapAttack(target);
            this->_energyPoints -= 25;
            return this->_spikeTrapAttackDamage;
        } else if (i == 2) {
            this->tripWireAttack(target);
            this->_energyPoints -= 25;
            return this->_tripWireAttackDamage;
        } else if (i == 3) {
            this->freezeTrapAttack(target);
            this->_energyPoints -= 25;
            return this->_freezeTrapAttackDamage;
        } else if (i == 4) {
            this->mountedTurretAttack(target);
            this->_energyPoints -= 25;
            return this->_mountedTurretAttackDamage;
        } else if (i == 5) {
            this->explosiveBarrelAttack(target);
            this->_energyPoints -= 25;
            return this->_explosiveBarrelAttackDamage;
        } else {
            this->_energyPoints -= 25;
            return (0);
        }
    } else {
        std::cout << this->_name << ": Energy low. Refill Eredium cells!!" << std::endl;
        return (0);
    }
}
