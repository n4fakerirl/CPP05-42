/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:50:29 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 12:35:00 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    AForm *petition = new PresidentialPardonForm("nova");
    try
    {
        std::cout << "---NEW BUREAUCRAT BOB---\n\n";
        Bureaucrat bob("bob", 5);
        std::cout << bob;
        std::cout << "\n\n---NEW SHRUBBERYCREATIONFORM---\n\n";   
        std::cout << *petition;
        std::cout << "\n\n---BOB WILL NOW TRY TO SIGN THE FORM---\n\n";
        bob.signForm(*petition);
        std::cout << "\n\n---IS THE FORM SIGNED ? LET'S SEE...---\n\n";
        std::cout << *petition;
        if (petition->getIsSigned() == true)
            std::cout << "\n---THE FORM IS SIGNED!---\n\n";
        std::cout << "\n\n---NOW, LET'S SEE IF BOB CAN EXECUTE THE FORM!---\n\n";
        petition->execute(bob);
        std::cout << "\n\n---IF WE'RE STILL HERE, IT MEANS THAT BOB CAN ACTUALLY EXECUTE THIS FORM! LET'S TRY---\n\n";
        bob.executeForm(*petition);
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete petition;
}