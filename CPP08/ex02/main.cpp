/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:45:04 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/21 12:03:32 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	std::stack<int>		st;
	st.push(54);
	st.push(78);
	st.push(12);
	MutantStack<int>	ms(st);
	MutantStack<int>::iterator i = ms.begin();
	MutantStack<int>::const_iterator	const_begin = ms.begin();
	MutantStack<int>::const_iterator	const_end = ms.end();
	int	index = 0;
	std::cout << "---------------------------------------" << std::endl << "check MutantStack copy : " << std::endl;
	std::cout << "MutantStack const_iterator begin = " << *const_begin << std::endl;
	while (i != const_end)
	{
		std::cout << "MutantStack[" << index << "] = " << *i <<  std::endl;
		i++;
		index++;
	}
	std::cout << std::endl << "MutantStack size = " << ms.size() << std::endl;
	std::cout << std::endl << "---------------------------------------" << std::endl << "check stack copy :" << std::endl;
	std::stack<int>	mscpy(ms);
	std::cout << "mscpy std::stack last index = " << mscpy.top() << std::endl;
	std::cout << "std::stack size = " << mscpy.size() << std::endl;
	i = ms.end();
	--i;
	std::cout << "ms MutantStack last index = " << *i << std::endl;
	std::cout << "MutantStack size = " << ms.size() << std::endl;

	std::cout << std::endl;
	MutantStack<int>	ms2;
	ms2 = ms;
	std::cout << "---------------------------------------" << std::endl << "check operator = :" << std::endl;
	index = 0;
	i = ms.begin();
	const_end = ms.end();
	MutantStack<int>::iterator i2 = ms2.begin();
	while (i != const_end)
        {
                std::cout << "MutantStack[" << index << "] = " << *i << "     MutantStack2[" << index << "] = " << *i2 << std::endl;
                i++;
		i2++;
                index++;
        }
	std::cout << std::endl << "MutantStack size = " << ms.size();
	std::cout << "    MutantStack2 size = " << ms2.size() << std::endl << std::endl;
	std::cout << "---------------------------------------" << std::endl << "check MutantStack push(42) :" << std::endl;
	ms.push(42);
	i = ms.begin();
	const_end = ms.end();
	index = 0;
	std::cout << "new MustantStack: " << std::endl;
	while (i != const_end)
        {
                std::cout << "MutantStack[" << index << "] = " << *i <<  std::endl;
                i++;
                index++;
        }
	std::cout << std::endl << "MutantStack size = " << ms.size() << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl << "check MutantStack top :" << std::endl;
	std::cout << "MutantStack top of stack = " << ms.top() << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl << "check MutantStack pop :" << std::endl << "new MutantStack :" << std::endl;
	index = 0;
	ms.pop();
	i = ms.begin();
	const_end = ms.end();
	while (i != const_end)
        {
                std::cout << "MutantStack[" << index << "] = " << *i <<  std::endl;
                i++;
                index++;
        }
	std::cout << std::endl << "MutantStack size = " << ms.size() << std::endl << std::endl << "---------------------------------------" << std::endl;
	std::cout << "check empty MutantStack :" << std::endl;
	MutantStack<int>	empty;
	if (empty.begin() == empty.end())
		std::cout << "MutantStack is empty" << std::endl;
	else
	{
		std::cerr << "Error: MutantStack is not empty !" << std::endl;
		return (1);
	}
	std::cout << "MutantStack empty size = " << empty.size() << std::endl << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "No behavior, const_iterator end check" << std::endl;
	std::cout << "---------------------------------------" << std::endl << "check const MutantStack :" << std::endl;
	const	MutantStack<int> const_ms(ms);
	const_begin = const_ms.begin();
	const_end = const_ms.end();
	std::cout << "const MutantStack begin = " << *const_begin << std::endl;
	std::cout << "const MutantStack top = " << const_ms.top() << std::endl;
	std::cout << std::endl << "const MutantStack size = " << const_ms.size() << std::endl << std::endl;
	if (const_begin != const_end)
		std::cout << "No behavior, const_iterator for const MutantStack check" << std::endl << std::endl;
	else
	{
		std::cerr << "Error: const_iterator for const MutantStack !" << std::endl;
		return (1);
	}
	std::cout << "---------------------------------------" << std::endl;
	return (0);
}

// int	main(void)
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return (0);
// }
