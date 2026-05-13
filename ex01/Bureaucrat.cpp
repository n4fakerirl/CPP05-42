/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:51:39 by ocviller          #+#    #+#             */
/*   Updated: 2026/05/13 21:51:29 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "Default Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    this->_grade = grade;
    std::cout << "Bureaucrat constructor " << this->getName() << " called\n";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor Bureaucrat called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	*this = other;
	std::cout << "Copy Constructor called of Bureaucrat\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
    {
        this->_grade = other._grade;
    }
	return (*this);
}

void Bureaucrat::operator++(void)
{
    if ((this->getGrade() - 1) < 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::operator--(void)
{
    if ((this->getGrade() + 1) > 150)
        throw GradeTooLowException();
    this->_grade++;
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "error: bureaucrat grade too high!\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "error: bureaucrat grade too low!\n";
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
    return (os);
}

void Bureaucrat::signForm(Form &f)
{
    f.beSigned(*this);
    if (f.getIsSigned() == true)
        std::cout << this->getName() << " signed " << f.getName() << "\n";
    else
        std::cout << this->getName() << " couldn’t sign " << f.getName() << " because this bureacrat grade is too low to sign this form\n";
}
