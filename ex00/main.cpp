/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:50:29 by ocviller          #+#    #+#             */
/*   Updated: 2026/02/26 13:45:21 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
    return (os);
}

int main(void)
{
    try
    {
        Bureaucrat test;
        std::cout << test;
        Bureaucrat bob("bob", 14);
        std::cout << bob;
        bob.operator++();
        std::cout << bob;
        bob.operator++();
        std::cout << bob;
        bob.operator++();
        std::cout << bob;
        Bureaucrat annie(bob);
        std::cout << annie;
        annie.operator--();
        annie.operator--();
        annie.operator--();
        std::cout << annie;
        Bureaucrat paul("paul", 150);
        paul.operator++();
        paul.operator++();
        paul.operator++();
        std::cout << paul;
        paul.operator--();
        std::cout << paul;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}