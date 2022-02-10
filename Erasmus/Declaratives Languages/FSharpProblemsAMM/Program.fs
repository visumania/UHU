// Learn more about F# at http://docs.microsoft.com/dotnet/fsharp

open System
open System.Numerics;;

//Exercise 1: 

let list1 = [1 .. 15]

let list2 = [2; -3; 4; -5; 6; -7; 8; -9; 10; -11; 12; -13; 14; -15] //

//Exercise 2:

let r n = [for i in 1 .. n do
                for _ in i .. -1 .. 1 do i ]   

r 6

//Exercise 3: 

let func (lista : int list) (n:int) = [for i in 0 .. lista.Length-1 do
                                        if lista.[i]= n then i]

func [2; -3; 4; -5; 6; -7; 8; -9; 10; -11; 12; -13; 14; -15] 8

//Exercise 4:

let funct (lista1 : int list) (lista2 : int list) =
    let sortedl1 = List.sort lista1
    let sortedl2 = List.sort lista2
    let mutable ret = true
    for i in 0 .. sortedl1.Length-1 do
        if i<lista2.Length then
            if sortedl1.[i] <> sortedl2.[i] then ret <- false
        else ret <- false
    ret

funct [1 .. 5] [1 .. 6]
funct [1;1;1;2;2;2] [1;2;3;4;5]

//Exercise 5: 

//Section a) 

Complex.Divide(new Complex(1.0,1.0), new Complex(1.0,-1.0));;

//Section b) 

Complex.Divide(new Complex(0.0, 2.0), new Complex(1.0,1.0));

//Section c) 

Complex.Divide(new Complex(4.0,-3.0), new Complex(4.0,3.0))

//Section d)

Complex.Sqrt(new Complex(-3.0, -4.0))

//Section e) 

Complex.Sqrt(new Complex(8.0, 6.0))

//Section f) 

Complex.Pow(new Complex(1.0,1.0), 10.0)

//Section g) 

Complex.Pow(new Complex(2.0,sqrt(12.0)), 5.0)

//Section h) 

Complex.Pow(new Complex(-1.0,0.0), 0.25)

