 #include "Contact.class.hpp"

 Contact::Contact(void) {
     return;
 }

 Contact::~Contact(void) {
     return;
 }

 Contact Contact::init(void) {
    first_name:
        std::cout << "Enter your FIRST NAME and press Enter" << std::endl;
        getline(std::cin, this->first_name);
        if (this->first_name.empty())
            goto first_name;
    last_name:
        std::cout << "Enter your LAST NAME and press Enter" << std::endl;
        getline(std::cin, this->last_name);
        if (this->last_name.empty())
            goto last_name;
    nickname:
        std::cout << "Enter your NICKNAME and press Enter" << std::endl;
        getline(std::cin, this->nickname);
        if (this->nickname.empty())
            goto nickname;
    std::cout << "Enter your LOGIN and press Enter" << std::endl;
    getline(std::cin, this->login);
    std::cout << "Enter your POSTAL ADDRESS and press Enter" << std::endl;
    getline(std::cin, this->postal_address);
    std::cout << "Enter your EMAIL ADDRESS and press Enter" << std::endl;
    getline(std::cin, this->email_address);
    std::cout << "Enter your PHONE NUMBER and press Enter" << std::endl;
    getline(std::cin, this->phone_number);
    std::cout << "Enter your BIRTHDAY DATE and press Enter" << std::endl;
    getline(std::cin, this->birthday_date);
    std::cout << "Enter your FAVORITE MEAL and press Enter" << std::endl;
    getline(std::cin, this->favorite_meal);
    std::cout << "Enter your UNDERWEAR COLOR and press Enter" << std::endl;
    getline(std::cin, this->underwear_color);
    std::cout << "Enter your DARKEST SECRET and press Enter" << std::endl;
    getline(std::cin, this->darkest_secret);
    std::cout << std::string( 100, '\n' );
    std::cout << "Contact create" << std::endl;
     return *this;
 }

void Contact::truncated(std::string s) const {
    size_t len = s.length();
    int i = 0;
    int offset = 10 - len;

    if (offset > 0 && offset < 10)
        for(; i < offset; i++){
            std::cout << " ";
        }
    else
        offset = 0;
    for (i = 0; offset + i < 10; i++){
        if (((offset + i) == 9) && ((int)(10 - len) < 0)) {
            std::cout << ".";
            break;
        }
        std::cout << s[i];
    }
}

void Contact::put_data_search(int index) const {
     std::cout << "|";
     std::cout << "         " << index;
     std::cout << "|";
     truncated(this->first_name);
     std::cout << "|";
     truncated(this->last_name);
     std::cout << "|";
     truncated(this->nickname);
     std::cout << "|" << std::endl;
 }

 void Contact::put_data(void) const {
     std::cout << std::string( 100, '\n' );
    std::cout << "first_name :" << std::endl << this->first_name << std::endl;
    std::cout << "last_name :" << std::endl << this->last_name << std::endl;
    std::cout << "nickname :" << std::endl << this->nickname << std::endl;
    if (!this->login.empty())
        std::cout << "Login :" << std::endl << this->login << std::endl;
    if (!this->postal_address.empty())
        std::cout << "Postal_address :" << std::endl << this->postal_address << std::endl;
    if (!this->email_address.empty())
        std::cout << "Email_address :" << std::endl << this->email_address << std::endl;
    if (!this->phone_number.empty())
        std::cout << "Phone_number :" << std::endl << this->phone_number << std::endl;
    if (!this->birthday_date.empty())
        std::cout << "Birthday_date :" << std::endl << this->birthday_date << std::endl;
    if (!this->favorite_meal.empty())
        std::cout << "Favorite_meal :" << std::endl << this->favorite_meal << std::endl;
    if (!this->underwear_color.empty())
        std::cout << "Underwear_color :" << std::endl << this->underwear_color << std::endl;
    if (!this->darkest_secret.empty())
        std::cout << "Darkest_secret :" << std::endl << this->darkest_secret << std::endl;
 }
