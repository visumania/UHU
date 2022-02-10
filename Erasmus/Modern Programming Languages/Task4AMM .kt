import sun.rmi.runtime.Log
import java.util.*
import java.util.concurrent.LinkedBlockingQueue
import java.util.function.Consumer
import kotlin.concurrent.thread
import java.lang.Math.sqrt
import java.util.concurrent.ExecutionException
import java.time.*
import java.time.format.DateTimeFormatter

fun main(args: Array<String>)
{
    /**Exercise 6**/

    /*val l = listOf(
        Employee("Smith", "Eve", "012-12-5678"),
        Employee("Carpenter", "John", "123-06-4901"),
        Employee("Cugar", "Clara", "034-00-1111"),
        Employee("Lionsgate", "Peter", "965-11-4561"),
        Employee("Disney", "Quentin", "888-12-3412")
    )


    val l2 = l.sortedBy { Employee -> Employee.ssn }

    println(l2[0].ssn)
    println(l2[4].ssn)*/

    /**Exercise 7**/

    /*val map = mutableMapOf<Int,Employee>()
     map[0] = l2[0]
     map[1] = l2[1]
     map[2] = l2[2]
     map[3] = l2[3]
     map[4] = l2[4]*/

    /**Exercise 8**/

    /*
    Output: [1, 2, 3, 4]
     */

    /**Exercise 9**/

    /*
    Output: [1, 2, 3, 4]
     */

    /**Exercise 10**/

    /*val l3 = l.filter { it.ssn.startsWith("0") }

    println(l3[0].ssn)
    println(l3[1].ssn)*/

    /**Exercise 11**/

    /*
    val l = listOf<Int>(1,2,3,4).filter { it > 0 }
     */

    /**Exercise 12**/ //???????????????????????????????????????

    val l = listOf<Int>(1,2,3,4)

    /*l.find { it==42 }?.run { throw ExecutionException() }

    l.map { it }.contains(42)?.run { throw ExecutionException("Error") }*/

    /**Exercise 13**/

    /*val l = listOf(
        Parcel(1267395, 1.45),
        Parcel(1515670, 0.46),
        Parcel(8345674, 2.50),
        Parcel(3418566, 1.47),
        Parcel(3491245, 3.04)
    )

    val totalWeight: Double = l.map { it.weight }.sum()
    println(totalWeight)*/

    /**Exercise 14**/

    /*val myClock = ClockTwiceAsFast()
    Log.d("LOG", LocalDateTime.now(myClock).format(
        DateTimeFormatter.ISO_LOCAL_DATE_TIME))
    Thread.sleep(1000L)
    Log.d("LOG", LocalDateTime.now(myClock).format(
        DateTimeFormatter.ISO_LOCAL_DATE_TIME))*/

    /**Exercise 15**/

    println("Hello".matches(Regex(".*||.*")))

}

/**Exercise 1**/

fun lambda(s:String, num:Int)
{
    var aux = ""

    for(i in 1..num)
        aux += s

    println(aux)
}

/**Exercise 2**/

/*val f:(String)->String={s:String->+"!"}*/

fun f2(s:String):String
{
    return s.plus("!")
}

/**Exercise 3**/

data class Quadruple<T1, T2, T3, T4>(val t1: T1, val t2: T2, val t3: T3, val t4: T4)

/**Exercise 4**/

class Sorter<T>(t:T)
{
    private val list: MutableList<T> = mutableListOf()

    fun add(value:T)
    {
        list.add(value)
        /*Collections.sort(list)
        list.sort()*/
    }
}

/**Exercise 5**/

/*
    class Calculator {
      enum class Operator(val oper:String) {
          MULTIPLY("multiply"),
          DIVIDE("divide")
      }
      fun operator(oper:Operator,
                   vararg params:Double): Double {
          val f = Calculator::class.declaredFunctions.
                find { it.name == oper.oper }
          f?.valueParameters?.forEachIndexed { ind, p ->
              p.findAnnotation<NotZero>()?.run {
                  if (params[ind] == 0.0)
                      throw RuntimeException(
                      "Parameter ${ind} not unequal 0.0")

                  if(params[ind]<0)
                      throw RuntimeException(
                          "Parameter ${ind} lower than 0.0")
              }
          }
          val ps = arrayOf(this@Calculator,
                *(params).toList().toTypedArray<Any>())
          return (f?.call(*ps) as Double?) ?: 0.0
      }
      fun multiply(p1:Double, p2:Double) : Double {
          return p1 * p2
      }
      fun divide(p1:Double, @NotZero p2:Double) : Double {
          return p1 / p2
      }

      fun sqrtroot(@NotNegative p1: Double) : Double
      {
          return sqrt(p1)
      }
}


    The @NotNegative annotation makes sure the parameter gets checked when calculator.operation()
    is called. To use the calculator, you write something like this:
    Calculator().operator(Calculator.operator.SQRTROOT,4)
    To see whether the annotation works, try another invocation with <0 as the second parameter
 */

/**Exercise 6**/

data class Employee(val lastName:String, val firstName:String, val ssn:String)

/**Exercise 13**/

data class Parcel(val receiverId:Int, val weight:Double)


/**Exercise 15**/

fun String.extension():String
{
    return ""
}

