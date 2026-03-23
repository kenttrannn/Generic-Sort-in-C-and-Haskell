/* Name: Kent Tran
CECS 342 Assignment 6
Algorithm: generic sorting Language: C++
Compiler: gcc
Editor: VSCode
Resources: previous C code
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Person 
{
    string name;
    int age;
};

bool sortNames(const Person &a, const Person &b)
{
    return a.name < b.name;
}

bool sortAges(const Person &a, const Person &b)
{
    if (a.age != b.age)
    {
        return a.age < b.age;
    }
    return a.name < b.name;
}

int main()
{
    vector<double> numbers =
    {
        645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25
    };

    vector<Person> people = 
    {
        {"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, 
        {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, 
        {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, 
        {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26},
        {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25}
    };

    //Sort numbers in ascending order by numerical value.
    vector<double> sortedNums = numbers;
    sort(sortedNums.begin(), sortedNums.end());

    //Sort people alphabetically (lexicographically) by name.
    vector<Person> sortedNames = people;
    sort(sortedNames.begin(), sortedNames.end(), sortNames);

    //Sort people in descending order by age. If two people have the same age, sort them alphabetically by name.
    vector<Person> sortedAges = people;
    sort(sortedAges.begin(), sortedAges.end(), sortAges);

    cout << "Sorted numbers: " << endl;
    for (double n : sortedNums)
    {
        cout << fixed << setprecision(2) << n << endl;
    }

    cout << "\nSorted people by name: " << endl;
    for (const Person &p : sortedNames)
    {
        cout << p.name << ", " << p.age << endl;
    }

    cout << "\nSorted by age, then name: " << endl;
    for (const Person &p : sortedAges)
    {
        cout << p.name << ", " << p.age << endl;
    }

    return 0;
}