using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Írjunk olyan programot, amely számjegyenként bekér egy 3 jegyű kettes számrendszerbeli számot, 
//majd kiszámolja ezen szám tízes számrendszerbeli alakját.

namespace _03
{
	class Program
	{
		static void Main(string[] args)
		{
			string a, b, c;
			a = Console.ReadLine();
			b = Console.ReadLine();
			c = Console.ReadLine();

			double x, y, z;
			x = double.Parse(a);
			y = int.Parse(b);
			z = int.Parse(c);

			double sum = 0;

			if (x == 1)
			{
				sum += Math.Pow(2, 2);
			}
			if (y == 1)
			{
				sum += Math.Pow(2, 1);
			}
			if (z == 1)
			{
				sum += Math.Pow(2, 0);
			}
			Console.WriteLine("{0}", sum);
			Console.ReadLine();
		}
	}
}
