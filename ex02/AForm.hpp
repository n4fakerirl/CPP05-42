/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:59:46 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/02 15:43:37 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
    const std::string _name;
    const int _grade_sign;
    const int _grade_exec;
    bool _signed;

    public:
    AForm();
    AForm(std::string name, int grade_sign, int grade_exec);
    AForm(const AForm &other);
    AForm& operator=(const AForm &other);
    virtual ~AForm();

    virtual const std::exception GradeTooHighException(std::string type) const = 0;
    virtual const std::exception GradeTooLowException(std::string type) const = 0;

    virtual std::string getName(void) const;
    virtual bool getIsSigned(void) const;
    virtual int getGradeSign(void) const;
    virtual int getGradeExec(void) const;

    virtual void beSigned(Bureaucrat &b) = 0;
    void execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream &os, const AForm &f);