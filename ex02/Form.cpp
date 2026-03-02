/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:59:43 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/02 15:32:12 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

    // const std::string _name;
    // bool _signed;
    // const int _grade_sign;
    // const int _grade_exec;

Form::Form() : _name("default"), _grade_sign(150), _grade_exec(150)
{
    this->_signed = false;
    std::cout << "Default Form constructor called\n";
}

Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
    if (this->_grade_sign < 1)
        throw this->GradeTooHighException("sign");
    else if (this->_grade_sign > 150)
        throw this->GradeTooLowException("sign");
    if (this->_grade_exec < 1)
        throw this->GradeTooHighException("exec");
    else if (this->_grade_exec > 150)
        throw this->GradeTooLowException("exec");
    this->_signed = false;
    std::cout << "Form constructor " << this->getName() << " called\n";
}

Form::~Form()
{
    std::cout << "Destructor Form called\n";
}

Form::Form(const Form &other) : _name(other._name), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec), _signed(false)
{
	*this = other;
	std::cout << "Copy Constructor called of Form\n";
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
    {
        
    }
	return (*this);
}

const std::exception Form::GradeTooHighException(std::string type)
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign form is too high!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute form is too high!\n";
    return (e);
}

const std::exception Form::GradeTooLowException(std::string type)
{
    const std::exception e;
    if (type == "sign")
        std::cout << "error: grade required to sign form is too low!\n";
    else if (type == "exec")
        std::cout << "error: grade required to execute form is too low!\n";
    else if (type == "bureaucrat sign")
        std::cout << "error: bureaucrat grade is too low to sign this form!\n";
    else if ((type == "bureaucrat exec"))
        std::cout << "error: bureaucrat grade is too low to execute this form!\n";
    return (e);
}

std::string Form::getName(void) const
{
    return (this->_name);
}

bool Form::getIsSigned(void) const
{
    return (this->_signed);
}

int Form::getGradeSign(void) const
{
    return (this->_grade_sign);
}

int Form::getGradeExec(void) const
{
    return (this->_grade_exec);
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->getGradeSign())
        throw this->GradeTooLowException("bureaucrat sign");
    else
        this->_signed = true;
}

std::ostream& operator<<(std::ostream &os, const Form &f)
{
    std::string str;
    if (f.getIsSigned() == true)
        str = "yes";
    else
        str = "no";
    os << "- Form name : " << f.getName() << "\n- Grade required to sign : " << f.getGradeSign() << ", Grade required to execute : " << f.getGradeExec() << "\n- Is the form signed ? : " << str << "\n"; 
    return (os);
}
