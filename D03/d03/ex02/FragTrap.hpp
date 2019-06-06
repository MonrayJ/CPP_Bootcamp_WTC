//
// Created by monray1 on 06/06/2019.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap : ClapTrap {

public:

    FragTrap();
    explicit FragTrap(const std::string &string);

///* <------------>   Inherited Methods   <------------> */

    const std::string &getName() const  override {
        return ClapTrap::getName();
    }
    unsigned int getHitPoints() const override {
        return ClapTrap::getHitPoints();
    };
    unsigned int getEnergyPoints() const override {
        return ClapTrap::getEnergyPoints();
    };
    unsigned int getArmourDamageReduction() const override {
        return ClapTrap::getArmourDamageReduction();
    };
    unsigned int getLevel() const override {
        return ClapTrap::getLevel();
    };
    unsigned int getRangedAttackDamage() const override {
        return ClapTrap::getRangedAttackDamage();
    };
    unsigned int getMeleeAttackDamage() const override {
        return ClapTrap::getMeleeAttackDamage();
    };
    unsigned int getMaxHitPoints() const override {
        return ClapTrap::getMaxHitPoints();
    };
    unsigned int getMaxEnergyPoints() const override {
        return ClapTrap::getMaxEnergyPoints();
    };
    void levelUp() override {
        ClapTrap::levelUp();
    };
    void takeDamage(unsigned amount) override {
        ClapTrap::takeDamage(amount);
    };
    void repair(unsigned amount) override {
        ClapTrap::repair(amount);
    };
    void rangedAttack(std::string const &target) override {
        ClapTrap::rangedAttack(target);
    };
    void meleeAttack(std::string const &target) override {
        ClapTrap::meleeAttack(target);
    };

///* <------------>   Class Specific Methods   <------------> */

    unsigned int vaulthunter_dot_exe(const std::string &target);

    void        spikeTrapAttack(std::string const &target);
    void        tripWireAttack(std::string const &target);
    void        freezeTrapAttack(std::string const &target);
    void        mountedTurretAttack(std::string const &target);
    void        explosiveBarrelAttack(std::string const &target);

private:

///* <------------>   Class Specific Properties   <------------> */

    unsigned    _spikeTrapAttackDamage{};
    unsigned    _tripWireAttackDamage{};
    unsigned    _freezeTrapAttackDamage{};
    unsigned    _mountedTurretAttackDamage{};
    unsigned    _explosiveBarrelAttackDamage{};

};


#endif //FRAGTRAP_HPP
