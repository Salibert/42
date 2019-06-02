#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# define MAX_CONTACTS 8
# include <stdlib.h>
# include <iostream>

 class Contact {
    std::string login,
        first_name,
        last_name,
        nickname,
        postal_address,
        email_address,
        phone_number,
        birthday_date,
        favorite_meal,
        underwear_color,
        darkest_secret;

    void truncated(std::string s) const ;
    public:
        Contact(void);
        ~Contact(void);
        Contact init(void);
        void put_data(void) const ;
        void put_data_search(int index) const;
 };
#endif