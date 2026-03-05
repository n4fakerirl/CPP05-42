/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:05:01 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 13:33:44 by ocviller         ###   ########.fr       */
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

AForm *Intern::makeForm(std::string form, std::string target)
{
    AForm *dest = NULL;
    int i;
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (i = 0; i < 3; i++)
    {
        if (form == forms[i])
            break;
    }
    switch (i)
    {
    case 0:
        dest = new ShrubberyCreationForm(target);
        break;
    case 1:
        dest = new RobotomyRequestForm(target);
        break;
    case 2:
        dest = new PresidentialPardonForm(target);
        break;
    default:
        throw this->NoMatchFound();
    }
    std::cout << "Intern creates " << dest->getName() << "\n";
    return (dest);
}

std::exception Intern::NoMatchFound(void)
{
    const std::exception e;
    std::cout << "No matching form name found, please, enter a new one !\nPossible options: shrubbery creation, robotomy request, presidential pardon\n";
    return (e);
}
