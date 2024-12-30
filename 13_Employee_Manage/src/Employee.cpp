#include "Employee.h"

int Employee::employeeCount = 0;
Employee::Employee(int id, std::string fullName, std::string email,
                   std::string phone, std::string birthday)
    : id(id), fullName(fullName), email(email),
      phone(phone), birthday(birthday)
{
    employeeCount++;
}

void Employee::inputInfor()
{
    int type;
    std::cout << "Enter your ID: ";
    std::cin >> id;
    std::cout << "Enter your FullName: ";
    std::getline(std::cin >> std::ws, fullName);
    std::cout << "Enter your Email: ";
    std::cin >> email;
    std::cout << "Enter your Phone: ";
    std::cin >> phone;
    std::cout << "Enter your Birthday: ";
    std::cin >> birthday;
    std::cout << "Enter Employee Type: ";
    std::cin >> type;
    if (type >= 0 && type <= 2)
    {
        employeeType = static_cast<EmployeeType>(type);
    }
    else
    {
        std::cerr << "Invalid Employee Type! Defaulting to Experience." << std::endl;
        employeeType = EmployeeType::Exprience;
    }
}

void Employee::showInfor()
{
    std::cout << "Your ID: " << id << std::endl;
    std::cout << "Your FullName: " << fullName << std::endl;
    std::cout << "Your Email: " << email << std::endl;
    std::cout << "Your Phone: " << phone << std::endl;
    std::cout << "Your Birthday: " << birthday << std::endl;
    std::cout << "Employee Type: ";
    switch (employeeType)
    {
    case EmployeeType::Exprience:
        std::cout << "Exprience" << std::endl;
        break;
    case EmployeeType::Fresher:
        std::cout << "Fresher" << std::endl;
        break;
    case EmployeeType::Intern:
        std::cout << "Intern" << std::endl;
        break;
    }

    std::cout << "Certificates: " << std::endl;
    for (const auto &cert : certificates)
    {
        cert->showCertificate();
    }
}

int Employee::getEmployeeCount()
{
    return employeeCount;
}