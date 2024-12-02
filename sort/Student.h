#ifndef SORT_STUDENT_H
#define SORT_STUDENT_H

#include <iostream>

using namespace std;

struct Student
{
    string name;
    int score;

    // 重载<运算符
    bool operator<(const Student &otherStudent){
        return score!=otherStudent.score ? score>otherStudent.score : name<otherStudent.name;
    }

    // 重载输出运算符
    // 友元函数：可以直接访问该类的任何成员(包括private成员变量)
    friend ostream& operator<<(ostream &os, const Student &student){
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }

    // 运算符函数的第一个参数是调用者
};

#endif  // SORT_STUDENT_H