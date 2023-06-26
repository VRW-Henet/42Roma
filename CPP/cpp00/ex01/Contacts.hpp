/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:13:03 by dpadrini          #+#    #+#             */
/*   Updated: 2023/06/26 15:13:04 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>

class Contacts{
	private:
		int n_contacts;
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	Phone;
		std::string	Secret;

	public:
		Contacts();
		~Contacts();

		void		increase_contact_n();
		void		setFirstName(std::string str);
		void		setLastName(std::string str);
		void		setNickName(std::string str);
		void		setPhone(std::string str);
		void		setSecret(std::string str);

		int get_n_contcts();
		std::string	get_FirstName();
		std::string	get_LastName();
		std::string	get_Nickname();
		std::string get_Phone();
		std::string get_Secret();
};

#endif