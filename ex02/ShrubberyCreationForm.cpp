/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:38:29 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 11:13:46 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("null"), _grade_sign(145), _grade_exec(137)
{
    this->_signed = false;
    std::cout << "Default ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target), _grade_sign(145), _grade_exec(137)
{
    this->_signed = false;
    std::cout << "ShrubberyCreationForm constructor " << this->getName() << " called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor ShrubberyCreationForm called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(), _target(other._target), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec), _signed(false)
{
	*this = other;
	std::cout << "Copy Constructor called of ShrubberyCreationForm\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
    {
        
    }
	return (*this);
}

const std::exception ShrubberyCreationForm::GradeTooHighException(std::string type) const
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign ShrubberyCreationForm is too high!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute ShrubberyCreationForm is too high!\n";
    return (e);
}

const std::exception ShrubberyCreationForm::GradeTooLowException(std::string type) const
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign ShrubberyCreationForm is too low!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute ShrubberyCreationForm is too low!\n";
    else if (type == "bureaucrat sign")
        std::cout << "error: bureaucrat grade is too low to sign this ShrubberyCreationForm!\n";
    else if ((type == "bureaucrat exec"))
        std::cout << "error: bureaucrat grade is too low to execute this ShrubberyCreationForm!\n";
    return (e);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

bool ShrubberyCreationForm::getIsSigned(void) const
{
    return (this->_signed);
}

int ShrubberyCreationForm::getGradeSign(void) const
{
    return (this->_grade_sign);
}

int ShrubberyCreationForm::getGradeExec(void) const
{
    return (this->_grade_exec);
}

void ShrubberyCreationForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->getGradeSign())
        throw this->GradeTooLowException("bureaucrat sign");
    else
        this->_signed = true;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() == false)
        throw this->GradeTooLowException("bureaucrat sign");
    if (executor.getGrade() > this->getGradeExec())
        throw this->GradeTooLowException("bureaucrat exec");
}

void ShrubberyCreationForm::formAction(Bureaucrat const &executor) const
{
    this->execute(executor);
    std::string filename = this->_target + "_shrubbery";
    std::ofstream file;
    file.open(filename.c_str());
    file << "test";
}

std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &f)
{
    std::string str;
    if (f.getIsSigned() == true)
        str = "yes";
    else
        str = "no";
    os << "- ShrubberyCreationForm : " << f.getName() << "\n- Grade required to sign : " << f.getGradeSign() << ", Grade required to execute : " << f.getGradeExec() << "\n- Is the ShrubberyCreationForm signed ? : " << str << "\n"; 
    return (os);
}
