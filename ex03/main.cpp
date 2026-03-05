/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:50:29 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 13:46:11 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
    AForm* rrf = NULL;
    try
    {
        std::cout << "---WELCOME TO THE OFFICE, NEW INTERN---\n\n";
        Intern someRandomIntern;
        
        std::cout << "\n\n---NEW BUREAUCRAT NOVA---\n\n";
        Bureaucrat nova("Nova", 5);
        std::cout << nova;
        
        std::cout << "\n\n---INTERN IS CREATING A NEW FORM... PLEASE WAIT---\n\n";
        rrf = someRandomIntern.makeForm("presidential pardon", "hehe");
        std::cout << "\n" << *rrf;
    
        std::cout << "\n\n---NOVA WILL NOW TRY TO SIGN THE FORM---\n\n";
        nova.signForm(*rrf);
        
        std::cout << "\n\n---IS THE FORM SIGNED ? LET'S SEE...---\n\n";
        std::cout << *rrf;
        if (rrf->getIsSigned() == true)
            std::cout << "\n---THE FORM IS SIGNED!---\n\n";
        
        std::cout << "\n\n---NOW, LET'S SEE IF NOVA CAN EXECUTE THE FORM!---\n\n";
        rrf->execute(nova);
        
        std::cout << "\n\n---IF WE'RE STILL HERE, IT MEANS THAT NOVA CAN ACTUALLY EXECUTE THIS FORM! LET'S TRY---\n\n";
        nova.executeForm(*rrf);
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete rrf;
}