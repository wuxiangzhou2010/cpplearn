//
// Created by wuxiang on 4/10/2019.
//

#ifndef TEST_PERSON_H
#define TEST_PERSON_H

#include <string>

class Person
{
  public:
    Person();
    Person(const Person &);
    Person(std::string _name, int _age = 10);
    ~Person();
    std::string getName();
    void setName(std::string _name);
    int getAge();
    void setAge(int _age);
    void print() const;

  protected:
    std::string m_strName;

  private:
    int m_iAge;
};

#endif //TEST_PERSON_H
