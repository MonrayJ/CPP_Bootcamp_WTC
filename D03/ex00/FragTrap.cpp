//
// Created by monray1 on 04/06/2019.
//

#include "FragTrap.hpp"

FragTrap::FragTrap(string name) {

    if (name == "FR4G_TP") {
        cout << "Scary Badass dude, over there!" << endl;
    } else
        cout << "Look at me when I'm charging at you!" << endl;

    this->_name = name;
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_armourDamageReduction = 5;
    //  standard
    this->_rangedAttackDamage = 20;
    this->_meleeAttackDamage = 30;
    //  special
    this->_funZerkerAttackDamage = 5;
    this->_meatUnicycleAttackDamage = 45;
    this->_shhhTrapAttackDamage = 35;
    this->_laserInfernoAttackDamage = 50;
    this->_torgueFiestaAttackDamage = 60;

}

FragTrap::~FragTrap() {

    if (this->_name == "FR4G_TP" && this->_hitPoints <= 0)
        cout << "Oh yeah? Well, uh... yeah." << endl;
    else if (this->_name == "FR4G_TP" && this->_hitPoints > 0)
        cout << "Don't tell me that wasn't awesome" << endl;
    else
        cout << "STOP LOOKING AT ME!" << endl;

    return;
}

/* <------------------>    GetMethods Below    <------------------> */

string
FragTrap::getName(void) {
    return (this->_name);
}

unsigned
FragTrap::getHitPoints(){
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

/* <------------------>    GetMethods Above    <------------------> */


/* <------------------>    HealthMethods Below    <------------------> */

void
FragTrap::takeDamage(unsigned amount) {

    unsigned damage;

    damage = amount - (this->_armourDamageReduction);
    if (damage >= this->_hitPoints && this->_name == "FR4G_TP") {
        this->_hitPoints = 0;
        cout << this->_name << ": Recompiling combat code, Unit nonOperational!" << endl;
    } else if (damage >= this->_hitPoints && this->_name != "FR4G_TP") {
        this->_hitPoints = 0;
        cout << this->_name << ": It's so... dark and... cold... no, mommy...!" << endl;
    } else if (this->_name == "FR4G_TP" && damage < this->_hitPoints) {
        this->_hitPoints -= damage;
        cout << this->_name << ": Ow hohoho, that hurts! Yipes!" << endl;
        cout << this->_name << " took " << damage << " damage" << endl;
    } else {
        this->_hitPoints -= damage;
        cout << this->_name << ": Pleasure in pain!" << endl;
        cout << this->_name << " took " << damage << " damage" << endl;
    }
}

void
FragTrap::repair(unsigned amount) {
    if (this->_hitPoints > amount) {
        this->_hitPoints = 100;
        cout << this->_name << ": Health! Eww, what flavor is red?" << endl;
        cout << this->_name << " recovered all his health" << endl;
    } else {
        this->_hitPoints += amount;
        cout << this->_name << ": Sweet life juice!" << endl;
        cout << this->_name << " recovered " << amount << " hitPoints" << endl;
    }
}

/* <------------------>    HealthMethods Above    <------------------> */


/* <------------------>    AttackMethods Below    <------------------> */

void
FragTrap::rangedAttack(string const &target) {

    cout << this->_name << " attacks " << target << " at range, causing " \
 << this->_rangedAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::meleeAttack(string const &target) {

    cout << this->_name << " melee attacks " << target << " causing " \
 << this->_meleeAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::funZerkerAttack(string const &target) {

    cout << this->_name << ": I'm a sexy dinosaur! Rawr!" << endl;
    cout << this->_name << " hits " << target << " with a Candy Cane and deals " \
 << this->_funZerkerAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::meatUnicycleAttack(string const &target) {

    cout << this->_name << ": It's the only way to stop the voices!" << endl;
    cout << this->_name << " uses Siren Powers to cast a meat tornado at " << target << " causing " \
 << this->_meatUnicycleAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::shhhTrapAttack(string const &target) {

    cout << this->_name << ": I'm a robot ninja..." << endl;
    cout << this->_name << " sneak attacks " << target << " from behind, causing " \
 << this->_shhhTrapAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::laserInfernoAttack(string const &target) {

    cout << this->_name << ": (unintelligible snarling)" << endl;
    cout << this->_name << " sets " << target << " ablaze, causing " \
 << this->_laserInfernoAttackDamage << " points of damage!" << endl;

    return;
}

void
FragTrap::torgueFiestaAttack(string const &target) {

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

    srand(time(0));
    int i = (rand() % 5) + 1;

    if (this->_energyPoints >= 25) {
        if (i == 1) {
            this->funZerkerAttack(target);
            return this->_funZerkerAttackDamage;
        }
        if (i == 2) {
            this->meatUnicycleAttack(target);
            return this->_meatUnicycleAttackDamage;
        }
        if (i == 3) {
            this->shhhTrapAttack(target);
            return this->_shhhTrapAttackDamage;
        }
        if (i == 4) {
            this->laserInfernoAttack(target);
            return this->_laserInfernoAttackDamage;
        }
        if (i == 5) {
            this->torgueFiestaAttack(target);
            return this->_torgueFiestaAttackDamage;
        }
        this->_energyPoints -= 25;
    } else {
        cout << this->_name << ": Darn, Eriduim cells are Drained!!" << endl;
        return (0);
    }
    return (0);
}

/* <------------------>    VaultHunter.exe Above    <------------------> */

