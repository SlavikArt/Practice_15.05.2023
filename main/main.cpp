#include <iostream>
#include <map>
#include <vector>

class Student
{
    std::string name;
    double age;
public:
    Student(std::string name, double age)
    {
        this->name = name;
        this->age = age;
    }

    bool operator < (const Student& s) const
    {
        return this->name < s.name;
    }
};

int main()
{
    std::map<Student, double> dict;
    
    Student students[] = {
        { "Vasya", 18 },
        { "Petya", 17.5 },
        { "Oleksandr", 16.5 },
        { "Yevheniia", 18 },
        { "Anastasiia", 16 },
        { "Dmytro", 17 }
    };
    double grades[] = { 10.2, 12.0, 9.7, 8.0, 10.5, 11.6 };

    for (int i = 0; i < 6; i++)
    {
        Student student = students[i];
        double grade = grades[i];

        dict[student] = grade;
    }

    auto it = dict.find({ "Petya", 17.5 });

    if (it != dict.end())
        std::cout << "Found: " << it->second << "\n";
    else
        std::cout << "Not Found :(\n";
}
