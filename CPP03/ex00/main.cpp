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

#include "ClapTrap.hpp"

#include <iostream>
#include "ClapTrap.hpp"

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
    return 0;
}
