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
		public void StudentPar(string name, uint age)
		{
			this.age = age;
			this.name = name;
		}
		public static void Great(string name)
		{
			Console.WriteLine("Hello my name is: {0}", name);
		}
	}
	class Program
	{
		static void Main(string[] args)
		{
			Student john = new Student();
			john.StudentPar("John", 21);
			Student.Great(john.name);
			Console.ReadKey();
		}
	}
}
