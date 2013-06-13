using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ClassLibrary1
{

    public class Animal
    {
        public string Name { get; protected set; }

        public Animal(string name)
        {
            Name = name;
            Console.WriteLine("In animal constructor.");
        }

        public override string ToString()
        {
            return string.Format("{0}", Name.GetType());
        }

        public virtual void Speak()
        {
            Console.WriteLine("Generic Animal");
        }
    }

    public class Dog : Animal
    {
        public string Breed { get; protected set; }

        public Dog(string name, string breed)
            : base(name)
        {
            Breed = breed;
            Console.WriteLine("In Dog constructor");
        }

        public override string ToString()
        {
            return string.Format("{0}", Name.GetType());
        }

        public override void Speak()
        {
            Console.WriteLine("Generic Dog");
        }
    }

    public class BigDog : Dog
    {
        public BigDog(string name, string breed)
            : base(name, breed) 
        {
            Console.WriteLine("in BidDog constructor.");
        }

        public override string ToString()
        {
            return string.Format("{0}", Name.GetType());
        }

        public override void Speak()
        {
            Console.WriteLine("Woof Woof");
        }

    }

    public class LittleDog : Dog
    {
        public LittleDog(string name, string breed)
            : base(name, breed) 
        {
            Console.WriteLine("in LittleDog constructor");
        }

        public override string ToString()
        {
            return string.Format("{0}", Name.GetType());
        }

        public override void Speak()
        {
            Console.WriteLine("Woof");
        }
    }

     public class AnimalTest
     {
        public static void Main(string[] args)
        {
            Animal A1 = new Animal("Ryan");
            Dog D1 = new Dog("Dozer", "Pit Bull");
            LittleDog LD1 = new LittleDog("Sunny", "Maltese");
            BigDog BD1 = new BigDog("Henry", "Great Dane");

            A1.Speak();
            D1.Speak();
            LD1.Speak();
            BD1.Speak();

            A1.ToString();
            D1.ToString();
            LD1.ToString();
            BD1.ToString();

                
        }
     }


}
