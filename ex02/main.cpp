/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:50:29 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/02 17:39:56 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat bob("bob", 12);
        std::cout << bob;
        AForm *petition = new PresidentialPardonForm("petition pour les abeilles");
        std::cout << *petition;
        bob.signForm(*petition);
        std::cout << *petition;
        ShrubberyCreationForm a("city");
        std::cout << "\nTEST ICI\n\n";
        std::cout << a;
        bob.signForm(a);
        a.execShrubbery(bob);
        std::cout << "\n\nTEST FINI\n\n";
        delete petition;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}