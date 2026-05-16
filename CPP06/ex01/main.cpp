/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:01:38 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/11 20:02:21 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
  Data *data = new Data;

  data->i = 42;
  data->str = "Hello, World!";
  data->c = 'A';

  std::cout << "ptr: " << data << std::endl;
  std::cout << "Original Data:" << std::endl;
  std::cout << "Integer: " << data->i << std::endl;
  std::cout << "String: " << data->str << std::endl;
  std::cout << "Character: " << data->c << std::endl;

  uintptr_t serialized = Serializer::serialize(data);

  std::cout << "\nSerialized Data (uintptr_t): " << serialized << std::endl;

  data = Serializer::deserialize(serialized);

  std::cout << std::endl << "ptr: " << data;
  std::cout << "\ndata Data:" << std::endl;
  std::cout << "Integer: " << data->i << std::endl;
  std::cout << "String: " << data->str << std::endl;
  std::cout << "Character: " << data->c << std::endl;

  serialized = Serializer::serialize(data);
  std::cout << "\nSerialized Data (uintptr_t): " << serialized << std::endl;
  delete data;
}

