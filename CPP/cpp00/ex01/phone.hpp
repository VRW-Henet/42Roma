/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:13:17 by dpadrini          #+#    #+#             */
/*   Updated: 2023/06/26 15:13:17 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contacts.hpp"

class PhoneBook{
	public:
		Contacts	phone_book[8];
        int         index;
};

#endif