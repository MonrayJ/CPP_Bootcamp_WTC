//
// Created by monray1 on 04/06/2019.
//

#include "FragTrap.hpp"

int main() {

    cout << endl;
//    Start!!
    FragTrap fr4g_tp("FR4G_TP");
    FragTrap merc("Merc");

    int i = 1;
    while (i) {
        cout << endl << "<------>   ROUND " << i << "   <------>" << endl;
        if (merc.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 1 || i == 7 || i == 13)) {
            fr4g_tp.rangedAttack(merc.getName());
            merc.takeDamage(fr4g_tp.getRangedAttackDamage());
        } else if (merc.getHitPoints() <= 0) {
            cout << merc.getName() << " Joined the FireHawk in eternal flames" << endl;
            cout << fr4g_tp.getName() << " Leveled up" << endl;
            return (0);
        } else if (fr4g_tp.getHitPoints() <= 0) {
            cout << fr4g_tp.getName() << " Became a pile of scrap metal" << endl;
            return (0);
        }

        if (merc.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 2 || i == 8 || i == 14)) {
            merc.rangedAttack(fr4g_tp.getName());
            fr4g_tp.takeDamage(merc.getRangedAttackDamage());
        } else if (fr4g_tp.getHitPoints() <= 0) {
            cout << fr4g_tp.getName() << " Became a pile of scrap metal" << endl;
            cout << fr4g_tp.getName() << " Leveled up" << endl;
            return (0);
        } else if (merc.getHitPoints() <= 0) {
            cout << merc.getName() << " Joined the FireHawk in eternal flames" << endl;
            return (0);
        }

        if (merc.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 3 || i == 9 || i == 15)) {
            fr4g_tp.meleeAttack(merc.getName());
            merc.takeDamage(fr4g_tp.getMeleeAttackDamage());
        } else if (merc.getHitPoints() <= 0) {
            cout << merc.getName() << " Joined the FireHawk in eternal flames" << endl;
            cout << fr4g_tp.getName() << " Leveled up" << endl;
            return (0);
        } else if (fr4g_tp.getHitPoints() <= 0) {
            cout << fr4g_tp.getName() << " Became a pile of scrap metal" << endl;
            return (0);
        }

        if (merc.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 4 || i == 10 || i == 16)) {
            merc.meleeAttack(fr4g_tp.getName());
            fr4g_tp.takeDamage(merc.getMeleeAttackDamage());
        } else if (fr4g_tp.getHitPoints() <= 0) {
            cout << fr4g_tp.getName() << " Became a pile of scrap metal" << endl;
            cout << fr4g_tp.getName() << " Leveled up" << endl;
            return (0);
        } else if (merc.getHitPoints() <= 0) {
            cout << merc.getName() << " Joined the FireHawk in eternal flames" << endl;
            return (0);
        }

        if (merc.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 5 || i == 11 || i == 17)) {
            fr4g_tp.repair(50);
        }

        if (merc.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 6 || i == 12 || i == 18)) {
            cout << fr4g_tp.getName() << ": Activating VaultHunter.EXE" << endl;
            merc.takeDamage(fr4g_tp.vaultHunter_dot_exe(merc.getName()));
        } else if (merc.getHitPoints() <= 0) {
            cout << merc.getName() << " Joined the FireHawk in eternal flames" << endl;
            cout << fr4g_tp.getName() << " Leveled up" << endl;
            return (0);
        } else if (fr4g_tp.getHitPoints() <= 0) {
            cout << fr4g_tp.getName() << " Became a pile of scrap metal" << endl;
            return (0);
        }

        if (i > 20) {
            return (0);
        }

        i++;
    }
    return (0);

}


