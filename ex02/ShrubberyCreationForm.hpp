/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:38:31 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 11:11:25 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
    const std::string _target;
    const int _grade_sign;
    const int _grade_exec;
    bool _signed;

    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
    virtual ~ShrubberyCreationForm();

    const std::exception GradeTooHighException(std::string type) const;
    const std::exception GradeTooLowException(std::string type) const;

    std::string getTarget(void) const;
    bool getIsSigned(void) const;
    int getGradeSign(void) const;
    int getGradeExec(void) const;

    void beSigned(Bureaucrat &b);
    void execute(Bureaucrat const &executor) const;
    void formAction(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &f);