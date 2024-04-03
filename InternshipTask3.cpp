#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ContactInformation
{
public:
    string name;
    string mobileNo;
    string email;

    ContactInformation(const string &, const string &, const string &);

    void addNewContact();
    void displayContacts();
    void updateContact();
    void deleteContact();
};

vector<ContactInformation> contacts;

ContactInformation::ContactInformation(const string &name, const string &mobileNo, const string &email) : name(name), mobileNo(mobileNo), email(email) {}

void ContactInformation::addNewContact()
{
    string name,mobileNo,email;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter mobile number: ";
    getline(cin, mobileNo);
    cout << "Enter email address: ";
    getline(cin, email);
    ContactInformation newContact(name, mobileNo, email);
    contacts.push_back(newContact);
    cout << "New Contact added successfully!" << endl;
}

void ContactInformation::displayContacts()
{
    if (contacts.empty())
    {
        cout << "You do not have any contact details. Select add new contact option to add new contact." << endl;
        return;
    }
    cout << "Contacts:" << endl;
    for (int i = 0; i < contacts.size(); ++i)
    {
        cout << i + 1 << ". Name: " << contacts[i].name << "\n   Mobile Number: " << contacts[i].mobileNo << "\n   Email: " << contacts[i].email << endl;
    }
}
void ContactInformation::updateContact()
{
    displayContacts();
    if (contacts.empty())
    {
        return;
    }
    int index;
    cout << "Enter index of contact to edit: ";
    cin >> index;
    cin.ignore(); // Clear newline from input buffer
    if (index > 0 && index <= contacts.size())
    {
        cout << "Enter new name: ";
        getline(cin, contacts[index - 1].name);
        cout << "Enter new mobile number: ";
        getline(cin, contacts[index - 1].mobileNo);
        cout << "Enter new email address: ";
        getline(cin, contacts[index - 1].email);
        cout << "Contact edited successfully!" << endl;
    }
    else
    {
        cout << "Invalid index!" << endl;
    }
}

void ContactInformation::deleteContact()
{
    displayContacts();
    if (contacts.empty())
    {
        return;
    }
    int index;
    cout << "Enter index of contact to delete: ";
    cin >> index;
    cin.ignore(); // Clear newline from input buffer
    if (index > 0 && index <= contacts.size())
    {
        contacts.erase(contacts.begin() + index - 1);
        cout << "Contact deleted successfully!" << endl;
    }
    else
    {
        cout << "Invalid index!" << endl;
    }
}

int main()
{
    ContactInformation MyContact("Noor Fatma", "8989898989", "abc123@gmail.com");
    int choice;
    do
    {
        cout << "\nWhich operation you want to perform?" << endl;
        cout << "1. To Add new contact information, Press 1" << endl;
        cout << "2. To View your contact information, Press 2" << endl;
        cout << "3. To Update your contact information, Press 3" << endl;
        cout << "4. To Delete your contact infomation, Press 4" << endl;
        cout << "5. To Exit, Press 5" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            MyContact.addNewContact();
            break;
        case 2:
            MyContact.displayContacts();
            break;
        case 3:
            MyContact.updateContact();
            break;
        case 4:
            MyContact.deleteContact();
            break;
        case 5:
            cout << "Exiting program....." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}