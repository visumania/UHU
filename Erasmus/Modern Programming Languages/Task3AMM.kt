import sun.security.pkcs11.wrapper.CK_C_INITIALIZE_ARGS
import java.util.*
import java.util.concurrent.LinkedBlockingQueue
import java.util.function.Consumer
import kotlin.concurrent.thread

fun main(args: Array<String>)
{
    /**Exercise 1**/

    val club = Club()
    club.addMembers("Hughes, John", "Smith, Alina", "Curtis, Solange")

    /**Exercise 14**/

    val arr = IntArray(100, { i -> i + 1}).reversed()

    /**Exercise 15**/

    val boolarr = booleanArrayOf(true, false, true)

    /**Exercise 16**/

    val fruits = mutableSetOf("Apple", "Banana", "Grape", "Engine")
    fruits.add("Cherry")
    fruits.remove("Engine")
    val fruits5 = fruits.filter { it.length == 5 }
    println(fruits5)

    /**Exercise 17**/

    val list = IntRange(1, 100).toList()
    val sum = list.reduce { sum, element -> sum * element }

    /**Exercise 18**/

    val fruits1 = listOf("Bananas", "Apples", "Oranges")
    val prices = listOf(1.69, 2.19, 2.79)

    val f = arrayOf<Fruit>()
    f[0]= Fruit(fruits1[0],prices[0])
    f[1]= Fruit(fruits1[1],prices[1])
    f[2]= Fruit(fruits1[2],prices[2])

    /**Exercise 19**/

    /*
    1. True
    2. True
    3. True
     */

    /**Exercise 20**/

    /*
    1. True
    2. True
    3. False
     */

}

/**Exercise 1**/

class Club ()
{
    fun addMembers(vararg names: String)
    {
        println("Number: " + names.size)
        println(names.joinToString(" : "))
    }
}

/**Exercise 2**/

/*
The output would be:
B.y() -> a = 7
A.q() -> a = 7
*/

/**Exercise 3**/

/*
The output would be:
A.x() : g = 99
B.y() : g = 8
A.q() : g = 99
 */

/**Exercise 4**/

/*
The output would be:
A.x() : g = 8
B.y() : g = 8
A.q() : g = 8
 */

/**Exercise 5**/

/*
1. Valid
2. Valid
3. Not valid, a should be defined before being used in println()
4. Valid
5. Not valid, in function2 a has no type
 */

/**Exercise 6**/

/*
We are changing the values X1 and Y1 to X2 and Y2
 */

/**Exercise 7**/

/*
class Util
{
    fun add10(a:Int) = a + 10
    fun add100(a:Int) = a + 100
}

var util:Util = TODO()

class AA(q:Int)
{
    val x10:Int = util.add10(q)
    val x100:Int = util.add100(q)
}
 */

/**Exercise 8**/

/*
import java.lang.Math.*

class A
{
    fun calc(a:Double) = log(a)
}
*/

/**Exercise 9**/

/*
1. False, because 0!=1 and 1!=0
2. False, because one point of Point3D is unmatched
3. True, because x of both 2D and 3D are 1
4. True, because double 1 and 1.0 is the same
5. True, because x and y of both have the same values
 */

/**Exercise 10**/

/*
Set it (the value) as final
 */

/**Exercise 11**/

/*
var str = this.toString()
 */

/**Exercise 12**/

/*
class Vector constructor(vx:Int, vy:Int)
{
    var dx = vx
    var dy = vy

    operator fun plus(v2:Vector)
    {
        dx += v2.dx
        dy += v2.dy
    }

    operator fun minus(v2:Vector)
    {
        dx -= v2.dx
        dy -= v2.dy
    }
}
 */

/**Exercise 13**/

class Concatenator()
{
    var text =""

    fun add(s:String)
    {
        text+= s
    }
}

/**Exercise 18**/
data class Fruit(val name:String, val price:Double)
