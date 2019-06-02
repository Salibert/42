
#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed {
    public:
        Fixed(void);
        Fixed(Fixed const &  src);
        ~Fixed(void);

        Fixed & operator=(Fixed const &  rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _fixed;
        static const int number_frational_bits = 8;
};

#endif
