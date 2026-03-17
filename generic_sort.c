/* Name: Kent Tran
CECS 342 Assignment 5
Algorithm: generic sorting Language: C
Compiler: gcc
Editor: VSCode
Resources: https://www.geeksforgeeks.org/dsa/generic-implementation-of-quicksort-algorithm-in-c/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    const char *name;
    int age;
} Person;

int compareNums(const void *a, const void *b)
{
    double x = *(const double*)a;
    double y = *(const double*)b;
    if (x < y) return -1; 
    if (x > y) return 1;
    return 0;
}

int compareNames(const void *a, const void *b)
{
    Person *p1 = (const Person *)a;
    Person *p2 = (const Person *)b;
    return strcmp(p1->name, p2->name);
}

int compareAge(const void *a, const void *b)
{
    Person *p1 = (const Person *)a;
    Person *p2 = (const Person *)b;

    if (p1->age != p2->age)
        return p2->age - p1->age;

    return strcmp(p1->name, p2->name); // tie
}

void printNums(const double numbers[], int count)
{
    int i;
    for (i=0; i < count; i++)
    {
        printf("%.2f\n", numbers[i]);
    }
}

void printPeople(const Person people[], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("%s, %d\n", people[i].name, people[i].age);
    }
}

int main(void)
{
    double numbers[] =
    {
        645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25
    };
    // gets total byte / 4(byte of first array only)
    int num_count = sizeof numbers / sizeof numbers[0];

    Person people[] = 
    {
        {"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, 
        {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, 
        {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, 
        {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26},
        {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25}
    };
    int people_count = sizeof(people) / sizeof(people[0]);

    Person peopleByName[17];
    Person peopleByAge[17];

    memcpy(peopleByName, people, sizeof(people));
    memcpy(peopleByAge, people, sizeof(people));

    qsort(numbers, num_count, sizeof(double), compareNums);
    qsort(peopleByName, people_count, sizeof(Person), compareNames);
    qsort(peopleByAge, people_count, sizeof(Person), compareAge);

    printf("Sorted numbers (ascending):\n");
    printNums(numbers, num_count);

    printf("\nSorted people by name:\n");
    printPeople(peopleByName, people_count);

    printf("\nSorted people by age (descending, then name):\n");
    printPeople(peopleByAge, people_count);

    return 0;
}