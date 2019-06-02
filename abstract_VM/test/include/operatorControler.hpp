#ifndef OPERATERCONTROLER_HPP
# define OPERATERCONTROLER_HPP

#include "IOperand.hpp"
#include "operatorFactory.hpp"
#include "errorControler.hpp"
#include <cmath>

template <typename T> class OperatorControler : public IOperand {
	private:
		std::string _value;
	 	eOperandType _type;

	public:
		OperatorControler(void);
		OperatorControler(T value, eOperandType type);
		OperatorControler(OperatorControler const &src);
		virtual ~OperatorControler(void);

		int						getPrecision( void ) const ;
		long double getMax(void) const;
		long double getMin(void) const;
		IOperand const * operator+(IOperand const & rhs) const;
		IOperand const * operator-(IOperand const & rhs) const;
		IOperand const * operator*(IOperand const & rhs) const;
		IOperand const * operator/(IOperand const & rhs) const;
		IOperand const * operator%(IOperand const & rhs) const;
		IOperand const * operator^(IOperand const & rhs) const;

		std::string const & toString( void ) const;
		eOperandType getType( void ) const;
};

template<typename T> OperatorControler<T>::OperatorControler(void) {
	this->_value = std::to_string(static_cast<T>(0));
	this->_type = eOperandType::enum_double;
}
template<typename T> OperatorControler<T>::OperatorControler(T value, eOperandType type) {
	this->_value = std::to_string(value);
	this->_type = type;
}
template<typename T> OperatorControler<T>::OperatorControler(OperatorControler const &src) {
	this->_value = src->_value;
	this->_type = src->_type;
	return this;
}

template<typename T> OperatorControler<T>::~OperatorControler(void) {
	return;
}

template <typename T> IOperand const * OperatorControler<T>::operator+(IOperand const & rhs) const {
	OperatorFactory factory;

	ErrorControler::overflow(&rhs, this, ADD);
	ErrorControler::underflow(&rhs, this, ADD);
	if(this->getPrecision() < rhs.getPrecision()) {
		return factory.createOperand(rhs.getType(), std::to_string(std::stod(this->_value) + std::stod(rhs.toString())));
	} else {
		return factory.createOperand(this->_type, std::to_string(std::stod(this->_value) + std::stod(rhs.toString())));
	}
}

template <typename T> IOperand const * OperatorControler<T>::operator-(IOperand const & rhs) const {
	OperatorFactory factory;

	ErrorControler::overflow(&rhs, this, SUB);
	ErrorControler::underflow(&rhs, this, SUB);
	if (this->getPrecision() < rhs.getPrecision()) {
		return factory.createOperand(rhs.getType(), std::to_string(std::stod(this->_value) - std::stod(rhs.toString())));
	} else {
		return factory.createOperand(this->_type, std::to_string(std::stod(this->_value) - std::stod(rhs.toString())));
	}
}

template <typename T> IOperand const * OperatorControler<T>::operator*(IOperand const & rhs) const {
	OperatorFactory factory;

	ErrorControler::overflow(&rhs, this, MUL);
	ErrorControler::underflow(&rhs, this, MUL);
	if (this->getPrecision() < rhs.getPrecision()) {
		return factory.createOperand(rhs.getType(), std::to_string(std::stod(this->_value) * std::stod(rhs.toString())));
	} else {
		return factory.createOperand(this->_type, std::to_string(std::stod(this->_value) * std::stod(rhs.toString())));
	}
}

template <typename T> IOperand const * OperatorControler<T>::operator/(IOperand const & rhs) const {
	OperatorFactory factory;
	
	if(this->getPrecision() < rhs.getPrecision()) {
		return factory.createOperand(rhs.getType(), std::to_string(std::stod(this->_value) / std::stod(rhs.toString())));
	} else {
		return factory.createOperand(this->_type, std::to_string(std::stod(this->_value) / std::stod(rhs.toString())));
	}
}

template <typename T> IOperand const * OperatorControler<T>::operator%(IOperand const & rhs) const {
	OperatorFactory factory;

	if(this->getPrecision() < rhs.getPrecision()) {
		return factory.createOperand(rhs.getType(), std::to_string(std::fmod(std::stod(this->_value), std::stod(rhs.toString()))));
	} else {
		return factory.createOperand(this->_type, std::to_string(std::fmod(std::stod(this->_value), std::stod(rhs.toString()))));
	}
}

template <typename T> IOperand const * OperatorControler<T>::operator^(IOperand const & rhs) const {
	OperatorFactory factory;

	ErrorControler::overflow(&rhs, this, POW);
	ErrorControler::underflow(&rhs, this, POW);
	if(this->getPrecision() < rhs.getPrecision()) {
		return factory.createOperand(rhs.getType(), std::to_string(pow(std::stod(this->_value),std::stod(rhs.toString()))));
	} else {
		return factory.createOperand(this->_type, std::to_string(pow(std::stod(this->_value),std::stod(rhs.toString()))));
	}
}

template <typename T> int OperatorControler<T>::getPrecision( void ) const {
	return static_cast<int>(this->_type);
}

template<typename T> eOperandType OperatorControler<T>::getType( void ) const {
	return this->_type;
}

template<typename T> long double OperatorControler<T>::getMax( void ) const {
	return static_cast<long double>(std::numeric_limits<T>::max());
}

template<typename T> long double OperatorControler<T>::getMin( void ) const {
	return static_cast<long double>(std::numeric_limits<T>::lowest());
}

template<typename T> std::string const & OperatorControler<T>::toString( void ) const {
	return this->_value;
}

#endif
