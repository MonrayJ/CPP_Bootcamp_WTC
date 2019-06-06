//
// Created by monray1 on 06/06/2019.
//

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ScavTrap scav("SC4V_TP");
    FragTrap frag("FR4G_TP");

    int i = 1;
    while(i <= 10) {
        if (scav.getHitPoints() > 0 && frag.getHitPoints() > 0) {
            std::cout << std::endl << "<---------> ROUND "<< i <<" <--------->" << std::endl;
            if (i == 1) {
                frag.rangedAttack(scav.getName());
                scav.takeDamage(frag.getRangedAttackDamage());
                scav.rangedAttack(frag.getName());
                frag.takeDamage(scav.getRangedAttackDamage());
            }
            if (i == 2) {
                frag.meleeAttack(scav.getName());
                scav.takeDamage(frag.getMeleeAttackDamage());
                scav.meleeAttack(frag.getName());
                frag.takeDamage(scav.getMeleeAttackDamage());
            }
            if (i == 3) {
                frag.repair(30);
                scav.repair(30);
            }
            if (i == 4) {
                scav.takeDamage(frag.vaulthunter_dot_exe(scav.getName()));
                frag.takeDamage(scav.challengeNewcomer(frag.getName()));
            }
        } else
            return (0);
        i++;
    }

    return 0;
}