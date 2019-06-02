#include "Contact.class.hpp"

void create_header_search(){
    std::cout << "|";
    std::cout << "     index";
    std::cout << "|";
    std::cout << "first_name";
    std::cout << "|";
    std::cout << " last_name";
    std::cout << "|";
    std::cout << "  nickname";
    std::cout << "|" << std::endl;
}

int select_contact_to_be_overwritten(Contact *list_contact, int nb_contacts){
    reset:
    std::cout << std::string( 100, '\n' );
    std::string buffer;
    int index = -1;
    create_header_search();
    for (int i = 0; i < nb_contacts; i++){
        list_contact[i].put_data_search(i + 1);
    }
    std::cout << "Maximum number of contacts has been reached, indicate the index of the contact you wanted to replace with this new, If you want to give up to type CANCEL" << std::endl;
    getline(std::cin, buffer);
    if (buffer != "CANCEL") {
        index = atoi(buffer.c_str());
        if (index < 1  || index > (nb_contacts)) {
            std::cout << "Bad index" << std::endl;
            goto reset;
        }
        index -= 1;
        std::cout << std::endl << "Contact deleted" << std::endl;
    }
    return index;
}

void picked_create_or_replace(Contact *list_contact, int *nb_contacts) {
    if (*nb_contacts >= MAX_CONTACTS){
        int i = select_contact_to_be_overwritten(list_contact, *nb_contacts);
        if (i >= 0 && i < *nb_contacts){
            Contact new_contact;
            list_contact[i] = new_contact.init();
        }
        return;
    } else {
        Contact new_contact;
        list_contact[*nb_contacts] = new_contact.init();
        *nb_contacts += 1;
    }
    return ;
}
void search(Contact *list_contact, int nb_contacts) {
    reset:
    std::cout << std::string( 100, '\n' );
    std::string buffer;
    if (nb_contacts == 0) {
        std::cout << "Phone Book is Empty" << std::endl;
        return ;
    }

    create_header_search();
    for (int i = 0; i < nb_contacts; i++){
        list_contact[i].put_data_search(i + 1);
    }
    std::cout << "Select your contact and press Enter, If you want to give up to type CANCEL " << std::endl;
    getline(std::cin, buffer);
    if (buffer != "CANCEL") {
        int index = atoi(buffer.c_str());
        if (index < 1  || index > nb_contacts) {
            std::cout << "Bad index" << std::endl;
            goto reset;
        }
        list_contact[index - 1].put_data();
    }
}
int main() {
    std::string buffer;
    Contact list_contact[MAX_CONTACTS];
    int nb_contacts = 0;
    std::cout << std::string( 100, '\n' );
    std::cout << "=> Welcome to the awesome PhoneBook <=" << std::endl;
    std::cout << "You have the choise between 3 commands:" << std::endl;
    std::cout << "- ADD" << std::endl ;
    std::cout << "- SEARCH" << std::endl;
    std::cout << "- EXIT" << std::endl;
    while(1){
        std::cout << "Command: ";
        getline(std::cin, buffer);    
        if(buffer == "EXIT")
            return 0;
        else if (buffer == "ADD")
            picked_create_or_replace(list_contact, &nb_contacts);
        else if (buffer == "SEARCH")
            search(list_contact ,nb_contacts);
    }
    return 0;
}