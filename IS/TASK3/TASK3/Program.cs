// See https://aka.ms/new-console-template for more information
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;

namespace RSA
{
    internal class Program
    {
        private static List<int> lim = new List<int>();
        public static bool IsPrime(int n)
        {
            for (int i = 2; i < Math.Sqrt(n); i++)
                if (n % i == 0)
                    return false;
            return true;
        }

        //Euclidean Algorithm
        public static int GCD(int e, int F)
        {
            if (e == 0)
                return F;

            return GCD(F % e, e);
        }

        //extended Euclidean Algorithm
        public static int GCDExtended(int a, int b, int x, int y)
        {
            // Base Case
            if (a == 0)
            {
                x = 0;
                y = 1;
                return b;
            }

            // To store results of
            // recursive call
            int x1 = 1, y1 = 1;
            int gcd = GCDExtended(b % a, a, x1, y1);

            // Update x and y using
            // results of recursive call
            x = y1 - (b / a) * x1;
            y = x1;

            return gcd;
        }

        //search for e in RSA algorithm. 1<e < φ (n)
        public static int FindE(int e, int F)
        {
            while (GCD(e, F) != 1)
            {
                e++;
            }

            return e;
        }

        //search for d im RAS algorithm
        public static int FindD(int d, int e, int F)
        {
            while (d * e % F != 1)
            {
                d++;
            }

            return d;
        }

        //RSA encryption with public key
        public static string Encryption(string plainText, int e, int n)
        {
            byte[] src = Encoding.ASCII.GetBytes(plainText);
            byte[] C = new byte[src.Length];

            for (int i = 0; i < src.Length; i++)
            {
                lim.Add((int)src[i] / n);
                C[i] = (byte)(Math.Pow(src[i] - lim[i] * n, e) % n);
            }

            return Encoding.ASCII.GetString(C);
        }

        public static string Decryption(int n, int e, string plainText)
        {
            byte[] src = Encoding.ASCII.GetBytes(plainText);
            byte[] C = new byte[src.Length];

         
            int p = 2;

            while (true)
            {
                if (IsPrime(p) && n % p == 0)
                    break;
                p++;
            }

            int q = n / p;
            Console.WriteLine($"p = {p} q = {q}");

            int F = (p - 1) * (q - 1);

            int d = FindD(2, e, F);
            Console.WriteLine($"d = {d}");
            Console.WriteLine($"e = {e}");

            for (int i = 0; i < src.Length; i++)
            {
                // if (src[i] != 32)
                // {
                //     C[i] = (byte) (Math.Pow(src[i], d) % n);
                //     C[i] += (byte) (lim[i] * n);
                // }
                // else
                //     C[i] = 32;
                C[i] = (byte)(Math.Pow(src[i], d) % n);
                C[i] += (byte)(lim[i] * n);

            }

            return Encoding.ASCII.GetString(C);
        }

        public static void WriteToFile(string plaunText, int n, int e)
        {
            string[] lines =
            {
                $"{plaunText}", $"{n}", $"{e}"
            };
            File.WriteAllLines("encrypted.txt", lines);
        }

        public static void Main(string[] args)
        {
            //asking for user input data;
            Console.WriteLine("Enter plaint text:");
            string plainText = Console.ReadLine();

            Console.WriteLine("Enter p:");
            int p = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Enter q:");
            int q = Convert.ToInt32(Console.ReadLine());

            //calculations
            int n = p * q;

            int F = (p - 1) * (q - 1);//calculating F(n)

            int e = 2;//Declare e=2 to find to find the lowest GCD with F
            e = FindE(e, F);

            // Console.WriteLine(gcdExtended(35,15,1,1));
            // Console.WriteLine(findD(2,7,60));

            string encrypted = Encryption(plainText, e, n);
            Console.WriteLine($"original text: {plainText}");
            Console.WriteLine($"encrypted text01: {encrypted}");

            // using (StreamWriter writeText = new StreamWriter("encrypted.txt"))
            // {
            //     writeText.WriteLine(encrypted);
            //     //writeText.WriteLine();
            //     writeText.WriteLine(n);
            //     Console.WriteLine($"n = {n}");
            //     writeText.WriteLine(e);
            //     Console.WriteLine($"e = {e}");
            //     //writeText.Close();
            // }

            WriteToFile(encrypted, n, e);

            using (StreamReader readText = new StreamReader("encrypted.txt"))
            {
                encrypted = readText.ReadLine();
                n = Convert.ToInt32(readText.ReadLine());
                e = Convert.ToInt32(readText.ReadLine());
            }
            Console.WriteLine($"encrypted text02: {encrypted}");
            String decrypted = Decryption(n, e, encrypted);
            Console.WriteLine($"decrypted text: {decrypted}");

        }
    }
}

