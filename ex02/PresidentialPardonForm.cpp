/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:55:19 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 11:58:25 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("null"), _grade_sign(25), _grade_exec(5)
{
    this->_signed = false;
    std::cout << "Default PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target), _grade_sign(25), _grade_exec(5)
{
    this->_signed = false;
    std::cout << "PresidentialPardonForm constructor " << this->getName() << " called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor PresidentialPardonForm called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec), _signed(false)
{
	*this = other;
	std::cout << "Copy Constructor called of PresidentialPardonForm\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
    {
        
    }
	return (*this);
}

const std::exception PresidentialPardonForm::GradeTooHighException(std::string type) const
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign PresidentialPardonForm is too high!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute PresidentialPardonForm is too high!\n";
    return (e);
}

const std::exception PresidentialPardonForm::GradeTooLowException(std::string type) const
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign PresidentialPardonForm is too low!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute PresidentialPardonForm is too low!\n";
    else if (type == "bureaucrat sign")
        std::cout << "error: bureaucrat grade is too low to sign this PresidentialPardonForm!\n";
    else if ((type == "bureaucrat exec"))
        std::cout << "error: bureaucrat grade is too low to execute this PresidentialPardonForm!\n";
    return (e);
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::formAction(Bureaucrat const &executor) const
{
    this->execute(executor);
}

std::ostream& operator<<(std::ostream &os, const PresidentialPardonForm &f)
{
    std::string str;
    if (f.getIsSigned() == true)
        str = "yes";
    else
        str = "no";
    os << "- PresidentialPardonForm : " << f.getName() << "\n- Grade required to sign : " << f.getGradeSign() << ", Grade required to execute : " << f.getGradeExec() << "\n- Is the PresidentialPardonForm signed ? : " << str << "\n"; 
    return (os);
}
