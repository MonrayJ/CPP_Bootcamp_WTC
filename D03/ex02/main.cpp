//
// Created by monray1 on 04/06/2019.
//

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main() {

    cout << endl << "2 PowerFull VaultHunters, one awesome cave... Who will claim it? " << endl << endl;
//    Start!!
    FragTrap fr4g_tp("FR4G_TP");
    ScavTrap sc4v_tp("SC4V_TP");

    int i = 1;
    while (i) {
        cout << endl << "<------>   ROUND " << i << "   <------>" << endl;

        if (sc4v_tp.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 1 || i == 8 || i == 15)) {
            fr4g_tp.rangedAttack(sc4v_tp.getName());
            sc4v_tp.takeDamage(fr4g_tp.getRangedAttackDamage());
        } else if (fr4g_tp.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 2 || i == 9 || i == 16)) {
            sc4v_tp.rangedAttack(fr4g_tp.getName());
            fr4g_tp.takeDamage(sc4v_tp.getRangedAttackDamage());
        } else if (sc4v_tp.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 3 || i == 10 || i == 17)) {
            fr4g_tp.meleeAttack(sc4v_tp.getName());
            sc4v_tp.takeDamage(fr4g_tp.getMeleeAttackDamage());
        } else if (fr4g_tp.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 4 || i == 11 || i == 18)) {
            sc4v_tp.meleeAttack(fr4g_tp.getName());
            fr4g_tp.takeDamage(sc4v_tp.getMeleeAttackDamage());
        } else if (sc4v_tp.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 5 || i == 12 || i == 19)) {
            fr4g_tp.repair(50);
            sc4v_tp.repair(50);
        } else if (sc4v_tp.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 6 || i == 13 || i == 20)) {
            cout << fr4g_tp.getName() << ": Activating VaultHunter.EXE" << endl;
            sc4v_tp.takeDamage(fr4g_tp.vaultHunter_dot_exe(sc4v_tp.getName()));
        } else if (sc4v_tp.getHitPoints() > 0 && fr4g_tp.getHitPoints() > 0 && (i == 7 || i == 14 || i == 21)) {
            cout << sc4v_tp.getName() << ": A new Challenger I see!" << endl;
            fr4g_tp.takeDamage(sc4v_tp.challengeNewcomer(fr4g_tp.getName()) - fr4g_tp.getArmourDamageReduction());
        } else if (i > 21) {
            cout << fr4g_tp.getName() << ": Yay! We both win!" << endl;
            return (0);
        }

        if (sc4v_tp.getHitPoints() <= 0) {
            cout << sc4v_tp.getName() << " Got shut down!" << endl;
            fr4g_tp.levelUp();
            return (0);
        } else if (fr4g_tp.getHitPoints() <= 0) {
            cout << fr4g_tp.getName() << " Returned to the Metal scrap yard from whence he came!" << endl;
            sc4v_tp.levelUp();
            return (0);
        }
        i++;

    }
    return (0);

}


