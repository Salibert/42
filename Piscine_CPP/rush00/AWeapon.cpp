/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:31:53 by aaleksov          #+#    #+#             */
/*   Updated: 2018/10/05 21:31:53 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() {
    return;
}
AWeapon::~AWeapon() {
    return;
}

AWeapon::AWeapon(std::string const &name, int damage): _Name(name), _Damage(damage) {
	return;
}

AWeapon::AWeapon( AWeapon const & weapon ) {
	*this = weapon;
    return;
}

std::string AWeapon::getName() const {
    return this->_Name;
}

int AWeapon::getDamage() const {
    return this->_Damage;
}

AWeapon &AWeapon::operator=(AWeapon const & right) {
	this->_Name = right.getName();
	this->_Damage = right.getDamage();
	return *this;
}