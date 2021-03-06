import java.util.*

//Exercise 1
//5. Singleton objects may have a constructor.

//Exercise 2

object Singleton
{
    init {
        println("Singleton class invoked.")
    }
    var numberOfTabs = 5
    var windowsTitle = "Astaria"
    var prefsFile = "prefs.properties"

    fun printVarName(){
        println("Number of tabs: " + numberOfTabs + "\nWindows title: " + windowsTitle + "\nPrefs file: " + prefsFile)
    }

}

//Exercise 3

class Triangle ( var position1: Int, var position2: Int, var position3: Int)
{
    companion object
    {
        val NUMBER_OF_CORNERS = 3
    }

    fun info(): Int
    {
        println("Number of corners: ${NUMBER_OF_CORNERS}")
        return NUMBER_OF_CORNERS
    }
}

//Exercise 5

interface ElementaryParticle
{
    fun mass():Double
    fun charge():Double
    fun spin():Double
}

class Electron : ElementaryParticle
{
    override fun mass(): Double
    {
        return 9.11e-31
    }
    override fun charge(): Double
    {
        return -1.0
    }
    override fun spin(): Double
    {
        return 0.5
    }
}

class Proton : ElementaryParticle
{
    override fun mass(): Double
    {
        return 1.67e-27
    }
    override fun charge(): Double
    {
        return 0.5
    }
    override fun spin(): Double
    {
        return 0.5
    }
}

//Exercise 6
//2, 3 and 4

//Exercise 7

interface RandomNumberGenerator {
    fun rnd(minInt:Int, maxInt:Int): Int
}

class StdRandom: RandomNumberGenerator {
    override fun rnd(minInt:Int, maxInt:Int): Int {
        val span = maxInt - minInt + 1;
        return minInt + Math.floor(Math.random()*span).toInt()
    }
}

class RandomRandom: RandomNumberGenerator {
    val rnd: Random = Random()

    override fun rnd(minInt: Int, maxInt: Int): Int {
        return minInt + rnd.nextInt( maxInt - minInt + 1 )
    }
}

//Exercise 8
//Predetermined color is defined as value

//Exercise 9

class A9(var a: Int = 1) {
    init {
        a = 2
    }
    fun b(){
        a = 3
    }
    fun main() {
        a = 4
    }
}

//Exercise 11
//4. It is possible to write val a:Int? = null; val b:Long? = a?.toLong().

//Exercise 12
//d is a value and his value is changed in the function

//Exercise 13
//No problem in this function but it can be written without the return

//Exercise 14
//Yes, the unit is for remark that you aren't going to return anything (like void in other languages)

//Exercise 15

class A(val a:Int,val b:Int):AInterface {
    fun add():Int = a+b
    fun mult():Int = a * b
}

//Exercise 16

interface AInterface
{
    fun add(b:Int):Int
    fun mult(b:Int):Int
}

//Exercise 17
//meth1: 42 7

//Exercise 18

class A18 {
    companion object {
        fun x(a:Int):Int { return a + 7 }
    }
}

//Exercise 19 && Exercise 20

class Person
{
    var firstName:String? = null
    var lastName:String? = null
    var birthDay:String? = null
    var ssn:String? = null

    fun setName(fName:String, lName:String)
    {
        firstName = fName
        lastName = lName
    }

    fun set(lastName:String = "",
            firstName:String = "",
            birthDay:String? = null,
            ssn:String? = null)
    {
        if(!firstName.equals(""))
            this.firstName = firstName
        if(!lastName.equals(""))
            this.lastName = lastName

        if(!birthDay.equals(null))
            this.birthDay = birthDay

        if(!ssn.equals(""))
            this.ssn = ssn
    }
}




fun main(args: Array<String>)
{
    //Exercise 4
    val triangle = Triangle(1, 2, 3)
    val numberOfCorners = triangle.info()

    //Exercise 10
    val a = 42
    val s = "If we add 4 to a we get ".plus((a+4).toString())
    println(s)

    //Exercise 18 --> Like a static in another languages
    println(A18.x(42))

    //Exercise 19
    var person = Person()
    person.firstName = "Joe"
    person.lastName = "Doe"
    person.setName("Jhon", "Doe")

    //Exercise 20
    person.set(lastName = "Smith",ssn = "1234567890")
    println(person.firstName)
    println(person.lastName)
    println(person.birthDay)
    println(person.ssn)
}

