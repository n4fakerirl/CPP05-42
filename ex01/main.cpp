/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:50:29 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/02 15:33:14 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat bob("bob", 12);
        std::cout << bob;
        Form petition("petition pour les abeilles", 119, 12);
        std::cout << petition;
        bob.signForm(petition);
        std::cout << petition;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}