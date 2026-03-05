/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:38:24 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 10:12:58 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("null"), _grade_sign(72), _grade_exec(45)
{
    this->_signed = false;
    std::cout << "Default RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target), _grade_sign(72), _grade_exec(45)
{
    this->_signed = false;
    std::cout << "RobotomyRequestForm constructor " << this->getName() << " called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor RobotomyRequestForm called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(), _target(other._target), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec), _signed(false)
{
	*this = other;
	std::cout << "Copy Constructor called of RobotomyRequestForm\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
    {
        
    }
	return (*this);
}

const std::exception RobotomyRequestForm::GradeTooHighException(std::string type) const
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign RobotomyRequestForm is too high!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute RobotomyRequestForm is too high!\n";
    return (e);
}

const std::exception RobotomyRequestForm::GradeTooLowException(std::string type) const
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign RobotomyRequestForm is too low!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute RobotomyRequestForm is too low!\n";
    else if (type == "bureaucrat sign")
        std::cout << "error: bureaucrat grade is too low to sign this RobotomyRequestForm!\n";
    else if ((type == "bureaucrat exec"))
        std::cout << "error: bureaucrat grade is too low to execute this RobotomyRequestForm!\n";
    return (e);
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

bool RobotomyRequestForm::getIsSigned(void) const
{
    return (this->_signed);
}

int RobotomyRequestForm::getGradeSign(void) const
{
    return (this->_grade_sign);
}

int RobotomyRequestForm::getGradeExec(void) const
{
    return (this->_grade_exec);
}

void RobotomyRequestForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->getGradeSign())
        throw this->GradeTooLowException("bureaucrat sign");
    else
        this->_signed = true;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() == false)
        throw this->GradeTooLowException("bureaucrat sign");
    if (executor.getGrade() > this->getGradeExec())
        throw this->GradeTooLowException("bureaucrat exec");
}

std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm &f)
{
    std::string str;
    if (f.getIsSigned() == true)
        str = "yes";
    else
        str = "no";
    os << "- RobotomyRequestForm : " << f.getName() << "\n- Grade required to sign : " << f.getGradeSign() << ", Grade required to execute : " << f.getGradeExec() << "\n- Is the RobotomyRequestForm signed ? : " << str << "\n"; 
    return (os);
}
