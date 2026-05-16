/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 08:33:09 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/12 18:00:22 by ssadi-ou         ###   ########.fr       */
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
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
  private:
	  Serializer();
	  Serializer(Serializer const &);
	  ~Serializer();

	  Serializer	&operator=(Serializer const &);
  public:
	  static uintptr_t serialize(Data *ptr);
	  static Data *deserialize(uintptr_t raw);
};
