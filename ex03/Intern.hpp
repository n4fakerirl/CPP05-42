/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:05:21 by ocviller          #+#    #+#             */
/*   Updated: 2026/03/05 13:07:23 by ocviller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Intern
{
    private:


    public:
    Intern();
    Intern(const Intern &other);
    Intern& operator=(const Intern &other);
    ~Intern();

    void makeForm(void);
};