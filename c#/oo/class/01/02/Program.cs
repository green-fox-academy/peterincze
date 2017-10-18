using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Írjunk olyan programot, amely számjegyenként bekér egy 2 jegyű számot, majd kiszámolja ezen szám kétszeresét és 
//kiírja a képernyőre(ehhez ki kell számolni a 10-es számrendszerbeli alak alapján a szám tényleges értékét).

namespace _02
{
	class Program
	{
		static void Main(string[] args)
		{
			string a;
			string b;
			a = Console.ReadLine();
			b = Console.ReadLine();

			int x = int.Parse(a);
			int y = int.Parse(b);

			x = (x * 2) * 10;
			y = y * 2;

			int z = x + y;

			Console.WriteLine("{0}", z);
			Console.ReadLine();


		}
	}
}
