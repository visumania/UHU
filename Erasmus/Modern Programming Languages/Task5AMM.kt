import sun.rmi.runtime.Log
import java.util.*
import java.util.concurrent.LinkedBlockingQueue
import java.util.function.Consumer
import kotlin.concurrent.thread
import java.lang.Math.sqrt
import java.util.concurrent.ExecutionException


fun main(args: Array<String>)
{
    /**Exercise 1**/

    w1.start()
    w2.start()

    /**Exercise 2**/

    w21.start()
    w22.start()

    /**Exercise 3**/

    w31.start()
    w32.start()

    /**Exercise 4**/

    Peterson(100)

}

/**Exercise 1**/

var wants1 = false
var wants2 = false
var who_waiting = 1

val w1 = Thread()
{
    while (true)
    {
        //local section
        wants1=true
        while (wants2)
        {
            if(who_waiting==1)
            {
                wants1=false
                while (who_waiting==1)
                {
                    //do nothing
                }
                wants1=true
            }
        }
        //critical section
        who_waiting=1
        wants1=false
    }
}

val w2 = Thread()
{
    while (true)
    {
        //local section
        wants2=true
        while (wants1)
        {
            if(who_waiting==2)
            {
                wants2=false
                while (who_waiting==2)
                {
                    //do nothing
                }
                wants2=true
            }
        }
        //critical section
        who_waiting=2
        wants2=false
    }
}

/**Exercise 2**/

val w21=thread()
{
    while (true)
    {
        // local section
        wants1 = true;
        if (wants2)
        {
            if(who_waiting == 1)
            {
                wants1 = false;
                while(who_waiting == 1)
                {
                    // do nothing
                }
                wants1 = true;
                while (wants2)
                {
                    // do nothing
                }
            }
        }
        // critical section
        wants1 = false;
        who_waiting = 1;
    }
}

val w22=thread()
{
    while(true)
    {
        // local section
        wants2 = true;

        if(wants1)
        {
            if (who_waiting == 2)
            {
                wants2 = false;
                while (who_waiting == 2)
                {
                    // do nothing
                }
                wants2 = true;
                while (wants1)
                {
                    // do nothing
                }
            }
            // critical section
            wants2 = false;
            who_waiting = 2;
        }
    }
}

/**Exercise 3**/

val w31=thread()
{
    while(true)
    {
        //local section
        wants1 = true;
        who_waiting = 1;
        while(wants2 && who_waiting == 1)
        {
            // do nothing
        }
        // critical section
        wants1 = false;
    }
}

val w32=thread()
{
    while(true)
    {
        // local section
        wants2 = true;
        who_waiting = 2;
        while (wants2 && who_waiting == 2)
        {
            // do nothing
        }
        // critical section
        wants2 = false;
    }
}

/**Exercise 4**/

fun Peterson (N: Int)
{
    val wants = (1..N).toList().toTypedArray()
    val waiting = (1 until N-1).toList().toTypedArray()

    for (i in 1 until N)
    {
        thread(start = true)
        {
            while (true)
            {
                // local section
                for (barrier in 1 until N - 1) {
                    wants[i] = barrier
                    waiting[barrier] = i
                    var j = 0
                    while (i != j && (wants[++j] >= barrier) && (waiting[barrier] == i)) {
                        // do nothing
                    }
                }
                // critical section
                wants[i] = 0
            }
        }
    }
}