﻿using System.Runtime.InteropServices;

TestRunner.Run();

class Windows
{
    [DllImport("kernel32.dll")]
    public static extern IntPtr LoadLibrary(string dllToLoad);
};


class TestRunner
{
    public static void Run()
    {
        Serializer serializer = new Serializer();

        var object1 = new Ship();
        object1.name = "ooooookay lets go";
        var object2 = new SomeListyBoi();
        object2.ids.Add(2);
        object2.ids.Add(1);
        object2.ids.Add(3);

        List<byte> buffer = new List<byte>();

        serializer.Serialize(object1, buffer);
        serializer.Serialize(object2, buffer);

        object1 = new Ship();
        object2 = new SomeListyBoi();

        int offsetAfter;
        serializer.Deserialize(out object1, buffer.ToArray(), 0, out offsetAfter);
        serializer.Deserialize(out object2, buffer.ToArray(), offsetAfter, out offsetAfter);

        IntPtr result = Windows.LoadLibrary("../x64/Debug/Injected.dll");

        Console.WriteLine("I'm here so you have something to break on :)");
    }
}
