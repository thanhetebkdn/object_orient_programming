#include "Employee.h"
#include "Certificate.h"
#include "Valid.h"
#include "Exception.h"

int Employee::employeeCount = 0;

Employee::Employee() : id(0), fullName(""), email(""), phone(""), birthday("")
{
    employeeCount++;
}

Employee::Employee(int id, std::string fullName, std::string email,
                   std::string phone, std::string birthday)
    : id(id), fullName(fullName), email(email),
      phone(phone), birthday(birthday) {}

void Employee::addCertificate(std::unique_ptr<Certificate> cert)
{
    certificates.push_back(std::move(cert));
}

void Employee::inputInfor()
{
    int type;

    do
    {
        std::cout << "Enter your ID: ";
        std::cin >> id;

        if (std::cin.fail())
        {
            std::cerr << "Invalid input. Please enter a positive integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            continue;
        }

        if (id <= 0)
        {
            std::cerr << "Invalid ID. Please enter a positive integer." << std::endl;
        }

    } while (id <= 0);

    do
    {
        std::cout << "Enter your FullName: ";
        std::getline(std::cin >> std::ws, fullName);
        try
        {
            isValidName(fullName);
        }
        catch (const FullNameException &e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
        break;
    } while (true);

    do
    {
        std::cout << "Enter your Email: ";
        std::cin >> email;
        try
        {
            isValidEmail(email);
        }
        catch (const EmailException &e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
        break;

    } while (true);

    do
    {
        std::cout << "Enter your Phone: ";
        std::cin >> phone;
        try
        {
            isValidPhone(phone);
        }
        catch (const PhoneException &e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
        break;

    } while (true);

    do
    {
        std::cout << "Enter your Birthday (dd/mm/yyyy): ";
        std::cin >> birthday;
        try
        {
            isValidBirthday(birthday);
        }
        catch (const BirthdayException &e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
        break;

    } while (true);

    std::cout << "Enter Employee Type (0: Experience, 1: Fresher, 2: Intern): ";
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

    int certCount;
    do
    {
        std::cout << "Enter number of Certificates: ";
        std::cin >> certCount;

        try
        {
            isValidCertificateCount(certCount);
            break;
        }
        catch (const CertificateCountException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);

    for (int i = 0; i < certCount; i++)
    {
        std::cout << "Enter details for Certificate " << i + 1 << ":" << std::endl;
        auto cert = std::make_unique<Certificate>();
        cert->inputCer();
        addCertificate(std::move(cert));
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
        std::cout << "Experience" << std::endl;
        break;
    case EmployeeType::Fresher:
        std::cout << "Fresher" << std::endl;
        break;
    case EmployeeType::Intern:
        std::cout << "Intern" << std::endl;
        break;
    }

    std::cout << "Certificates: " << std::endl;
    if (certificates.empty())
    {
        std::cout << "No certificates available." << std::endl;
    }
    else
    {
        for (const auto &cert : certificates)
        {
            cert->showCertificate();
            std::cout << "----------------------" << std::endl;
        }
    }
}

int Employee::getEmployeeCount()
{
    return employeeCount;
}

EmployeeType Employee::getEmployeeType() const
{
    return employeeType;
}
