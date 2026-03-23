/* Name: Kent Tran
CECS 342 Assignment 6
Algorithm: generic sorting Language: C#
Compiler:
Editor: VSCode
Resources: 
*/

using System;
using Systen.Collections.Generic;
using System.Linq;

class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }
}

class Program
{
    static void Main()
    {
        List<double> numbers = new List<double>
        {
            645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25
        };

        List<Person> people = new List<double>
        {
        new Person("Hal", 20), new Person("Susann", 31), new Person("Dwight", 19), 
        new Person("Kassandra", 21), new Person("Lawrence", 25), new Person("Cindy", 22), 
        new Person("Cory", 27), new Person("Mac", 19), new Person("Romana", 27), new Person("Doretha", 32), 
        new Person("Danna", 20), new Person("Zara", 23), new Person("Rosalyn", 26),
        new Person("Risa", 24), new Person("Benny", 28), new Person("Juan", 33), new Person("Natalie", 25)
        };

        List<double> sortedNumbers = numbers.OrderBy(n => n).ToList();

        List<Person> sortedNames = people.OrderBy(p => p.name).ToList();

        List<Person> sortedAges = people
            .OrderByDescending(p => p.age)
            .ThenBy(p => p.Name)
            .ToList();

        Console.WriteLine("Sorted numbers: ");
        foreach (double n in sortedNumbers)
            Console.WriteLine($"{n:F2}");

        Console.WriteLine("\nSorted by name: ");
        foreach (Person p in sortedNames)
            Console.WriteLine($"{p.Name}, {p.Age}");

        Console.WriteLine("\nSorted by age, then name: ")
        foreach (Person p in sortedAges)
            Console.WriteLine($"{p.Name}, {p.Age}");
    }
}