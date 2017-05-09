#ifndef PERSON
#define PERSON

#include <iostream>
#include <string>

// read and print functions
struct Person
{
    friend std::istream &read_person(std::istream& is, Person &person);
    friend std::ostream &print_person(std::ostream &os, const Person &person);
public:
    Person() = default;
    Person(const std::string &n, const std::string &add):name(n),address(add){};
    Person(const std::string &n):name(n){};
    Person(std::istream &is);
    std::string const& getName()    const { return name; }
    std::string const& getAddress() const { return address; }
private:
    std::string name;
    std::string address;
};

std::istream &read_person(std::istream& is, Person &person)
{
    return is >> person.name >> person.address;
}

std::ostream &print_person(std::ostream &os, const Person &person)
{
    return os << person.name << person.address;
}

Person::Person(std::istream &is){read_person(is,*this);};

#endif // PERSON

