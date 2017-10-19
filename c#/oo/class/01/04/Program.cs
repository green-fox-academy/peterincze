using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Create a new instace of the Student class and set it's name to "John" and
// it's age to 21 with it's constructor


namespace _04
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
	}

	class Program
	{
		static void Main(string[] args)
		{
			Student john = new Student("John", 21);
			Console.WriteLine("{0}, {1}", john.name, john.age);
			Console.ReadKey();
		}

	}
}
