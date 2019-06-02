
#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>
# include <cmath>

class Fixed {
    public:
        Fixed(void);
        Fixed(Fixed const &  src);
        Fixed(int const fixed);
        Fixed(float const fixed);
        ~Fixed(void);

        Fixed & operator=(Fixed const &  rhs);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int _fixed;
        static const int _fixed_8bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & wahiba);

#endif
