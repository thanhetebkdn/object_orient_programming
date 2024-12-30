#include <EmployeeManage.h>
#include <Employee.h>
#include <algorithm>
void EmployeeManage::addNewEmployee()
{
    auto newEmployee = std::make_unique<Employee>();
    newEmployee->inputInfor();
    listEmployee.push_back(std::move(newEmployee));
    std::cout << "New employee added success...!";
}
void EmployeeManage::modifyID()
{
    int searchID, newID;
    std::cout << "Enter ID need modify";
    std::cin >> searchID;

    for (auto &employee : listEmployee)
    {
        if (employee->getEmployeeCount() == searchID)
        {
            std::cout << "Enter the new ID: ";
            std::cin >> newID;
            employee->setId(newID);
            std::cout << "ID updated successfully!\n";
            return;
        }
    }
    std::cout << "Employee with ID " << searchID << " not found.\n";
}
void EmployeeManage::deleteByID()
{
    int searchID;
    std::cout << "Enter ID need delete";
    std::cin >> searchID;

    auto it = std::remove_if(listEmployee.begin(), listEmployee.end(),
                             [searchID](const std::unique_ptr<Employee> &employee)
                             {
                                 return employee->getEmployeeCount() == searchID; // Giả sử Employee có phương thức getID
                             });

    if (it != listEmployee.end())
    {
        listEmployee.erase(it, listEmployee.end());
        std::cout << "Employee deleted successfully!\n";
    }
    else
    {
        std::cout << "Employee with ID " << searchID << " not found.\n";
    }
}
void EmployeeManage::showAllEmployee()
{
    int select;
    std::cout << "1. Exprience\n";
    std::cout << "2. Fresher\n";
    std::cout << "3. Intern\n";
    std::cout << "4. Show All\n";
    std::cout << "Enter your Option: ";
    std::cin >> select;

    if (listEmployee.empty())
    {
        std::cout << "No employees to show.\n";
        return;
    }

    switch (select)
    {
    case 1:
        std::cout << "\nEmployees of type Exprience:\n";
        for (const auto &employee : listEmployee)
        {
            employee->showInfor();
            std::cout << "----------------------\n";
        }
        break;

    case 2:
        std::cout << "\nEmployees of type Fresher:\n";
        for (const auto &employee : listEmployee)
        {

            employee->showInfor();
            std::cout << "----------------------\n";
        }
        break;

    case 3:
        std::cout << "\nEmployees of type Intern:\n";
        for (const auto &employee : listEmployee)
        {

            employee->showInfor();
            std::cout << "----------------------\n";
        }
        break;

    case 4:
        std::cout << "\nAll Employees:\n";
        for (const auto &employee : listEmployee)
        {
            employee->showInfor();
            std::cout << "----------------------\n";
        }
        break;

    default:
        std::cout << "Invalid option. Please try again.\n";
        break;
    }
}
void EmployeeManage::exitProgram()
{
    std::cout << "Exiting program.\n";
    exit(0);
}