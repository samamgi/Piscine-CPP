/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 01:01:44 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/10/04 01:01:45 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

static void sep(const char* title) {
    std::cout << "\n===== " << title << " =====\n";
}

int main() {
    sep("Constructors");
    ClapTrap a("Alpha");
    ClapTrap b("Beta");
    ClapTrap c(a);            // copy ctor
    ClapTrap d("Delta");
    d = b;                    // copy assignment

    sep("Basic actions with energy > 0 and HP > 0");
    a.attack("training dummy");
    a.beRepaired(3);
    a.takeDamage(4);
    a.beRepaired(1);

    sep("Drain energy to zero (10 actions)");
    for (int i = 1; i <= 10; ++i) {
        std::cout << "[Action " << i << "] ";
        a.attack("dummy");
    }

    sep("No energy left: actions should fail");
    a.attack("dummy");
    a.beRepaired(5);

    sep("Take damage to zero HP, then try actions");
    b.takeDamage(1000);     // drop to 0
    b.attack("dummy");      // should fail
    b.beRepaired(1);        // should fail (no HP)

    sep("Repair from positive HP (costs 1 energy)");
    c.takeDamage(5);
    c.beRepaired(2);
    c.attack("dummy");

    sep("Mix: repair/attack until energy exhaustion");
    for (int i = 0; i < 5; ++i) c.beRepaired(1);
    for (int i = 0; i < 6; ++i) c.attack("target"); // last ones should fail

    sep("Big damage clamp");
    d.takeDamage(9);
    d.takeDamage(2);        // overkill → HP should stay at 0
    d.attack("dummy");      // should fail
    d.beRepaired(2);        // should fail (no HP)

    sep("End of tests");

    // ---------------- ScavTrap tests ----------------
    sep("ScavTrap constructors / chaining");
    ScavTrap sa("Serena");
    ScavTrap sb;              // default
    ScavTrap sc(sa);          // copy ctor (inherited if you wrote it) or use assignment
    sc = sa;                  // ensure copy assign path exists

    sep("ScavTrap stats-based behavior");
    sa.attack("training bot");    // overridden message
    sa.beRepaired(10);
    sa.takeDamage(15);
    sa.beRepaired(5);

    sep("ScavTrap guardGate mode");
    sa.guardGate();

    sep("ScavTrap drain energy to zero (50 actions)");
    for (int i = 1; i <= 50; ++i) {
        std::cout << "[S-Action " << i << "] ";
        sa.attack("target");
    }

    sep("ScavTrap when out of energy");
    sa.attack("target");
    sa.beRepaired(3);

    sep("ScavTrap drop to 0 HP then try actions");
    sa.takeDamage(150);        // should reach 0 HP even from 100
    sa.attack("target");
    sa.beRepaired(1);

    sep("ScavTrap mix repair/attack until exhaustion");
    for (int i = 0; i < 5; ++i) sc.beRepaired(2);
    for (int i = 0; i < 55; ++i) sc.attack("spam"); // some will fail after EP runs out

    sep("End of tests");
    // ---- FragTrap tests ----
    sep("FragTrap constructors / copy / assign");
    FragTrap f1("Franco");
    FragTrap f2;           // default (if you provided one)
    FragTrap f3(f1);       // copy ctor
    f2 = f1;               // copy assign

    sep("FragTrap stats & actions");
    f1.attack("bot");
    f1.highFivesGuys();
    f1.takeDamage(40);
    f1.beRepaired(20);

    sep("FragTrap energy drain (100 EP)");
    for (int i = 1; i <= 105; ++i) {
        std::cout << "[F-Action " << i << "] ";
        f1.attack("bot");
    }
    f1.highFivesGuys(); // should still print (no EP cost)

    sep("FragTrap drop to 0 HP, then try actions");
    f2.takeDamage(150); // HP -> 0
    f2.attack("bot");   // should fail
    f2.beRepaired(5);   // should fail
    f2.highFivesGuys(); // can still print (no state change)

    // ---- Polymorphic delete check (virtual dtor) ----
    sep("Polymorphic delete (virtual destructor check)");
    ClapTrap* p = new FragTrap("Poly");
    p->attack("poly-dummy");
    delete p; // must call ~FragTrap then ~ClapTrap

    sep("End of tests");
    return 0;
}

