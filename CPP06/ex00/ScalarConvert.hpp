/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 08:33:09 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/10 08:43:37 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <climits>
#include <string>
#include <cerrno>

class ScalarConvert
{
  private:
	ScalarConvert();
	ScalarConvert(ScalarConvert const &);
	~ScalarConvert();

	ScalarConvert &operator=(ScalarConvert const &);

  public:
	static void convert(std::string const &str);
};
