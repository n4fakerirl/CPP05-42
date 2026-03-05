/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:44:58 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 11:34:34 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _grade_sign(150), _grade_exec(150)
{
    this->_signed = false;
    std::cout << "Default AForm constructor called\n";
}

AForm::AForm(std::string name, int grade_sign, int grade_exec) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
    this->_signed = false;
    std::cout << "AForm constructor " << this->getName() << " called\n";
}

AForm::~AForm()
{
    std::cout << "Destructor AForm called\n";
}

AForm::AForm(const AForm &other) : _name(other._name), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec), _signed(false)
{
	*this = other;
	std::cout << "Copy Constructor called of AForm\n";
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
    {
        
    }
	return (*this);
}

const std::exception AForm::GradeTooHighException(std::string type) const
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign AForm is too high!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute AForm is too high!\n";
    return (e);
}

const std::exception AForm::GradeTooLowException(std::string type) const
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign AForm is too low!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute AForm is too low!\n";
    else if (type == "bureaucrat sign")
        std::cout << "error: bureaucrat grade is too low to sign this AForm!\n";
    else if ((type == "bureaucrat exec"))
        std::cout << "error: bureaucrat grade is too low to execute this AForm!\n";
    return (e);
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getIsSigned(void) const
{
    return (this->_signed);
}

int AForm::getGradeSign(void) const
{
    return (this->_grade_sign);
}

int AForm::getGradeExec(void) const
{
    return (this->_grade_exec);
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->getGradeSign())
        throw this->GradeTooLowException("bureaucrat sign");
    else
        this->_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() == false)
        throw this->GradeTooLowException("bureaucrat sign");
    if (executor.getGrade() > this->getGradeExec())
        throw this->GradeTooLowException("bureaucrat exec");
}

void AForm::formAction(Bureaucrat const &executor) const
{
    (void)executor;
}

std::ostream& operator<<(std::ostream &os, const AForm &f)
{
    std::string str;
    if (f.getIsSigned() == true)
        str = "yes";
    else
        str = "no";
    os << "- Form name : " << f.getName() << "\n- Grade required to sign : " << f.getGradeSign() << ", Grade required to execute : " << f.getGradeExec() << "\n- Is the AForm signed ? : " << str << "\n"; 
    return (os);
}