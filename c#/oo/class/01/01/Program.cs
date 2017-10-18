using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01
{
	class Student
	{
		public string name;
		public int age; 
	}
	class Program
	{
		static void Main(string[] args)
		{
			Student john = new Student();

			john.name = "John";
			john.age = 12;

			Console.WriteLine("{0},\t {1}", john.age, john.name);
			Console.ReadLine();

		}
	}
}
