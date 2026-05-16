/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:42:01 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/29 18:42:02 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec(), deq()
{
}

PmergeMe::PmergeMe(PmergeMe const &copy) : vec(copy.vec), deq(copy.deq)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
	this->vec = copy.vec;
	this->deq = copy.deq;
	return (*this);
}

std::vector<int>    PmergeMe::GetVec() const
{
    return (this->vec);
}

std::deque<int>    PmergeMe::GetDeq() const
{
    return (this->deq);
}

bool    PmergeMe::set_containersvec(char *av)
{
    char    *end;
    long    tmp;
    int     result;

    errno = 0;
    tmp = std::strtol(av, &end, 10);
    if (end == av || *end != 0)
        return (false);
    if (errno == ERANGE)
        return false;
    if (tmp <= 0 || tmp > 2147483647)
        return (false);
    result = static_cast<int>(tmp);
    this->vec.push_back(result);
    return (true);
}

bool    PmergeMe::set_containersdeq(char *av)
{
    char    *end;
    long    tmp;
    int     result;

    errno = 0;
    tmp = std::strtol(av, &end, 10);
    if (end == av || *end != 0)
        return (false);
    if (errno == ERANGE)
        return false;
    if (tmp < 0 || tmp > 2147483647)
        return (false);
    result = static_cast<int>(tmp);
    this->deq.push_back(result);
    return (true);
}

bool    PmergeMe::set_argsvec(char **av)
{
    size_t  i = 0;
    while (av[i])
    {
        if (this->set_containersvec(av[i]) == false)
            return (false);
        i++;
    }
    return (true);
}

bool    PmergeMe::set_argsdeq(char **av)
{
    size_t  i = 0;
    while (av[i])
    {
        if (this->set_containersdeq(av[i]) == false)
            return (false);
        i++;
    }
    return (true);
}
void    PmergeMe::printvecbefore()
{
    std::vector<int>::iterator  itvec = this->vec.begin();
    std::cout << "Before:  ";
    while (itvec != this->vec.end())
    {
        std::cout << *itvec;
        itvec++;
        if (itvec != this->vec.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printdeqbefore(std::deque<int> v)
{
    std::deque<int>::iterator  itvec = v.begin();
    std::cout << "Before:  ";
    while (itvec != v.end())
    {
        std::cout << *itvec;
        itvec++;
        if (itvec != v.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printvecafter(std::vector<int> v)
{
    std::vector<int>::iterator  itvec = v.begin();
    std::cout << "After:  ";
    while (itvec != v.end())
    {
        std::cout << *itvec;
        itvec++;
        if (itvec != v.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printdeqafter(std::deque<int> v)
{
    std::deque<int>::iterator  itvec = v.begin();
    std::cout << "After:  ";
    while (itvec != v.end())
    {
        std::cout << *itvec;
        itvec++;
        if (itvec != v.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

std::size_t SearchVector(std::vector<int> const &v, int value)
{
	std::size_t left = 0;
	std::size_t right = v.size();

	while (left < right)
	{
		std::size_t mid = left + (right - left) / 2;

		if (v[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

void    insertSortedVector(std::vector<int> &v, int value)
{
    std::size_t pos = SearchVector(v, value);

    v.insert(v.begin() + pos, value);
}

std::vector<std::size_t> jacobsthalordervec(std::size_t size)
{
    std::vector<std::size_t> order;

    if (size == 0)
        return order;
    order.push_back(0);
    std::size_t previous = 1;
    std::size_t current = 3;
    std::size_t i = 0;

    while (previous < size)
    {
        std::size_t limit = current;
        if (limit > size)
            limit = size;
        i = limit;
        while (i > previous)
        {
            order.push_back(i - 1);
            i--;
        }
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return (order);
}

std::vector<int>    PmergeMe::sortvector(std::vector<int> input)
{
    std::vector<int>    big;
    std::vector<int>    small;
    std::vector<std::size_t> order;
    int                 rest = -1;
    bool                has_rest = false;
    std::size_t  i = 0;

    if (input.size() <= 1)
        return (input);
    while ((i + 1) < input.size())
    {
        if (input[i] > input[i + 1])
        {
            big.push_back(input[i]);
            small.push_back(input[i + 1]);
        }
        else
        {
            big.push_back(input[i + 1]);
            small.push_back(input[i]);
        }
        i++;
        i++;
    }
    if (input.size() % 2 != 0)
    {
        rest = input[input.size() - 1];
        has_rest = true;
    }
    big = sortvector(big);
    order = jacobsthalordervec(small.size());
    i = 0;
    while (i < order.size())
    {
        insertSortedVector(big, small[order[i]]);
        i++;
    }
    if (has_rest == true)
        insertSortedVector(big, rest);
    return (big);
}

std::size_t SearchDeque(std::deque<int> const &v, int value)
{
    std::size_t left = 0;
    std::size_t right = v.size();

    while (left < right)
    {
        std::size_t mid = left + (right - left) / 2;

        if (v[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void    insertSortedDeque(std::deque<int> &v, int value)
{
    std::size_t pos = SearchDeque(v, value);

    v.insert(v.begin() + pos, value);
}

std::deque<std::size_t> jacobsthalorderdeque(std::size_t size)
{
    std::deque<std::size_t> order;

    if (size == 0)
        return order;
    order.push_back(0);
    std::size_t previous = 1;
    std::size_t current = 3;
    std::size_t i = 0;

    while (previous < size)
    {
        std::size_t limit = current;
        if (limit > size)
            limit = size;
        i = limit;
        while (i > previous)
        {
            order.push_back(i - 1);
            i--;
        }
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return (order);
}

std::deque<int>    PmergeMe::sortdeque(std::deque<int> input)
{
    std::deque<int>    big;
    std::deque<int>    small;
    std::deque<std::size_t> order;
    int                 rest = -1;
    bool                has_rest = false;
    std::size_t  i = 0;

    if (input.size() <= 1)
        return (input);
    while ((i + 1) < input.size())
    {
        if (input[i] > input[i + 1])
        {
            big.push_back(input[i]);
            small.push_back(input[i + 1]);
        }
        else
        {
            big.push_back(input[i + 1]);
            small.push_back(input[i]);
        }
        i++;
        i++;
    }
    if (input.size() % 2 != 0)
    {
        rest = input[input.size() - 1];
        has_rest = true;
    }
    big = sortdeque(big);
    order = jacobsthalorderdeque(small.size());
    i = 0;
    while (i < order.size())
    {
        insertSortedDeque(big, small[order[i]]);
        i++;
    }
    if (has_rest == true)
        insertSortedDeque(big, rest);
    return (big);
}

void	PmergeMe::checkvec(char **av)
{
    if (set_argsvec(av) == false)
        throw (std::runtime_error("Error"));
}

void	PmergeMe::checkdeq(char **av)
{
    if (set_argsdeq(av) == false)
        throw (std::runtime_error("Error"));
}
