using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Create a method on the Student class called "greet" that returns a string
// like: "Hello my name is: <student name>"


namespace _05
{
	class Student
	{
		public string name;
		public uint age;
		public Student(string name, uint age)
		{
			this.age = age;
			this.name = name;
		}
		public static string Greet(string name)
		{
			return "Hello my name is: " + name;
		}
	}
	class Program
	{
		static void Main(string[] args)
		{
			Student john = new Student("John", 42);
			Console.WriteLine("{0}", Student.Greet(john.name));
			Console.ReadKey();
		}
	}
}
