#include "Employee.h"
#include "Certificate.h"
#include "Valid.h"

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

    // Kiểm tra tính hợp lệ của ID (giả sử ID là một số dương)
    do
    {
        std::cout << "Enter your ID: ";
        std::cin >> id;
        if (id <= 0)
        {
            std::cerr << "Invalid ID. Please enter a positive integer." << std::endl;
        }
    } while (id <= 0);

    // Kiểm tra tính hợp lệ của tên
    do
    {
        std::cout << "Enter your FullName: ";
        std::getline(std::cin >> std::ws, fullName);
        if (!isValidName(fullName))
        {
            std::cerr << "Invalid name. Please enter again." << std::endl;
        }
    } while (!isValidName(fullName));

    // Kiểm tra tính hợp lệ của email
    do
    {
        std::cout << "Enter your Email: ";
        std::cin >> email;
        if (!isValidEmail(email))
        {
            std::cerr << "Invalid email. Please enter again." << std::endl;
        }
    } while (!isValidEmail(email));

    // Kiểm tra tính hợp lệ của số điện thoại
    do
    {
        std::cout << "Enter your Phone: ";
        std::cin >> phone;
        if (!isValidPhone(phone))
        {
            std::cerr << "Invalid phone number. Please enter again." << std::endl;
        }
    } while (!isValidPhone(phone));

    // Kiểm tra tính hợp lệ của ngày sinh
    do
    {
        std::cout << "Enter your Birthday (dd/mm/yyyy): ";
        std::cin >> birthday;
        if (!isValidBirthday(birthday))
        {
            std::cerr << "Invalid birthday. Please enter again." << std::endl;
        }
    } while (!isValidBirthday(birthday));

    // Nhập loại nhân viên và kiểm tra
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

    // Nhập số lượng chứng chỉ
    int certCount;
    std::cout << "Enter number of Certificates: ";
    std::cin >> certCount;

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
