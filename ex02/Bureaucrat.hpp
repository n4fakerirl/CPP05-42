/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:50:40 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/02 15:46:39 by ocviller         ###   ########.fr       */
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
    
    const std::exception GradeTooHighException(void);
    const std::exception GradeTooLowException(void);

    void signForm(AForm &f);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);