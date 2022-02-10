import sun.applet.Main

//Exercise 1 --> 3

class simple_rectangle() {
    val coordinates:Array<Pair<Double,Double>>
            = arrayOf()
}

//Exercise 2 --> 4

/*class Invoice() {
    var total:Double = 0.0
}*/

//Exercise 3 --> You can't modify the value. You can fix it using var

//Exercise 4 --> The variables are defined as val and have to be var

//Exercise 5 --> blue is not initialized inside the init

//Exercise 6

class Invoice(
    val buyerFirstName: String,
    val buyerLastName: String,
    val date: String,
    val goodName: String,
    val amount: Int,
    val pricePerItem: Double
) {
    val buyerFullName = buyerFirstName + " " + buyerLastName
    val totalPrice = amount * pricePerItem

    fun goodInfo():String //Exercise 7
    {
        return amount.toString() + goodName
    }

}

//Exercise 8

class Person(var firstName:String, var lastName:String, var ssn:String, var dateOfBith:String, var gender:Char)
{

}

//Exercise 10

class NumberGuess
{
    class GameUser
    {

    }
}

//Exercise 13

class Person13(var firstName:String, var lastName:String, var dateOfBith:String, var gender:Char, var ssn:String="")
{

}

//Exercise 14

class NumberGuess14
{
    class GameUser (var name: String,
                    var userName: String,
                    var birthday: String = "",
                    var registrationNumber: Int,
                    var userRank: Double = 0.0
    )
    {

    }
}

//Exercise 15

class Person15 ( var firstName: String,
                 var lastName: String,
                 var ssn : String = "",
                 var dateOfBirth: String,
                 var gender: Char,
) {
    constructor(firstName: String,
                lastName: String,
                ssn : String,
                gender: Char,): this(firstName, lastName, ssn, "0000-00-00", gender)
}



fun main(args: Array<String>)
{
    //Exercise 9
    var person1 = Person("John","Smith", "0123456789", "1997-10-23", 'M')

    //Exercise 11
    val person2 = Person(firstName = "John", lastName = "Smith", ssn = "0123456789", dateOfBith = "1997-10-23", gender = 'M')

    /*val person13 = Person13(firstName = "John", lastName = "Smith", dateOfBith = "1997-10-23", gender = 'M')
    if(person13.ssn.equals(""))
        println("Empty")*/

    /*val person15 = Person15(firstName = "John", lastName = "Smith", gender = 'M', ssn = "3248390")
    println(person15.dateOfBirth)*/

    //Exercise 12
    var gameUser = GameUser(name = "John Doe", userName = "jdoe", birthday = "1900-01-01", registrationNumber = 0, userRank = 0.0)
}
