/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:59:46 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/02 14:47:34 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
    const std::string _name;
    const int _grade_sign;
    const int _grade_exec;
    bool _signed;

    public:
    Form();
    Form(std::string name, int grade_sign, int grade_exec);
    Form(const Form &other);
    Form& operator=(const Form &other);
    ~Form();

    const std::exception GradeTooHighException(std::string type);
    const std::exception GradeTooLowException(std::string type);

    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getGradeSign(void) const;
    int getGradeExec(void) const;

    void beSigned(Bureaucrat &b);
};

std::ostream& operator<<(std::ostream &os, const Form &f);