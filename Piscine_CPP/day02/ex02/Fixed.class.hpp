
#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>
# include <cmath>

class Fixed {
    public:

        /* Constructor */

        Fixed(void);
        Fixed(Fixed const &  src);
        Fixed(int const fixed);
        Fixed(float const fixed);

        /* Destructor */

        ~Fixed(void);

        /* Operator */

        Fixed & operator=(Fixed const &  rhs);
        Fixed operator+(Fixed const & rhs) const;
        Fixed & operator++(void);
        Fixed operator++(int);
        Fixed operator-(Fixed const & rhs) const;
        Fixed & operator--(void);
        Fixed operator--(int);
        Fixed operator*(Fixed const & rhs) const;
        Fixed operator/(Fixed const & rhs) const;

        bool operator>(Fixed const & rhs) const;
        bool operator<(Fixed const & rhs) const;
        bool operator>=(Fixed const & rhs) const;
        bool operator<=(Fixed const & rhs) const;
        bool operator==(Fixed const & rhs) const;
        bool operator!=(Fixed const & rhs) const;

        /* Member functions*/

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        static const Fixed & max(Fixed const & a, Fixed const & b);
        static const Fixed & min(Fixed const & a, Fixed const & b);
        static Fixed & max(Fixed & a, Fixed & b);
        static Fixed & min(Fixed & a, Fixed & b);
    private:
        int _fixed;
        static const int _fixed_8bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & wahiba);

#endif
