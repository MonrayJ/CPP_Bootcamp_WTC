//
// Created by monray1 on 06/06/2019.
//

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>


class ClapTrap {

public:

    ClapTrap();
    explicit ClapTrap(std::string);
    virtual ~ClapTrap();

//    getMethods
    virtual const std::string       &getName() const;
    virtual unsigned int    getHitPoints() const;
    virtual unsigned int    getEnergyPoints() const;
    virtual unsigned int    getArmourDamageReduction() const;
    virtual unsigned int    getLevel() const;
    virtual unsigned int    getRangedAttackDamage() const;
    virtual unsigned int    getMeleeAttackDamage() const;
    virtual unsigned int    getMaxHitPoints() const;
    virtual unsigned int    getMaxEnergyPoints() const;

//    Health end Level
    virtual void            levelUp();
    virtual void            takeDamage(unsigned amount);
    virtual void            repair(unsigned amount);

//    Default Attack
    virtual void            rangedAttack(std::string const &target);
    virtual void            meleeAttack(std::string const &target);

protected:

//    Attributes
    std::string             _name;
    unsigned                _hitPoints{};
    unsigned                _maxHitPoints{};
    unsigned                _energyPoints{};
    unsigned                _maxEnergyPoints{};
    unsigned                _armourDamageReduction{};
    unsigned                _level{};

//    Damage values
    //  standard
    unsigned                _rangedAttackDamage{};
    unsigned                _meleeAttackDamage{};

};


#endif //CLAPTRAP_HPP
