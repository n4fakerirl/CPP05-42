/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:38:22 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 11:57:22 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
    const std::string _target;
    const int _grade_sign;
    const int _grade_exec;
    bool _signed;

    public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
    virtual ~PresidentialPardonForm();

    const std::exception GradeTooHighException(std::string type) const;
    const std::exception GradeTooLowException(std::string type) const;

    std::string getTarget(void) const;

    void formAction(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream &os, const PresidentialPardonForm &f);