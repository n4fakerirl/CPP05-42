/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:05:01 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 13:07:40 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Default Intern constructor called\n";
}

Intern::~Intern()
{
    std::cout << "Destructor Intern called\n";
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Copy Constructor called of Intern\n";
}

Intern& Intern::operator=(const Intern &other)
{
	if (this != &other)
    {
    }
	return (*this);
}

void Intern::makeForm(void)
{
    
}