/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:50:40 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 09:53:15 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
    const std::string _name;
    int _grade;

    public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();
    
    std::string getName(void) const;
    int getGrade(void) const;
    void operator++(void);
    void operator--(void);
    
    const std::exception GradeTooHighException(void) const;
    const std::exception GradeTooLowException(void) const;

    void signForm(AForm &f);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);