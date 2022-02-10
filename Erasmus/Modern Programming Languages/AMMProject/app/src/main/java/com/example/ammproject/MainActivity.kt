package com.example.ammproject

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.appcompat.widget.LinearLayoutCompat
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity()
{
    private var num1:Double=0.0
    private var num2:Double=0.0
    private var operation:Int=0

    override fun onCreate(savedInstanceState: Bundle?)
    {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        zeroButton.setOnClickListener{pressNumber("0")}
        oneButton.setOnClickListener{pressNumber("1")}
        twoButton.setOnClickListener{pressNumber("2")}
        threeButton.setOnClickListener{pressNumber("3")}
        fourButton.setOnClickListener{pressNumber("4")}
        fiveButton.setOnClickListener{pressNumber("5")}
        sixButton.setOnClickListener{pressNumber("6")}
        sevenButton.setOnClickListener{pressNumber("7")}
        eightButton.setOnClickListener{pressNumber("8")}
        nineButton.setOnClickListener{pressNumber("9")}
        decimalButton.setOnClickListener{pressNumber(".")}

        clearButton.setOnClickListener{resetAll()}

        sumButton.setOnClickListener{pressOperation(ADD)}
        subtractionButton.setOnClickListener{pressOperation(SUB)}
        productButton.setOnClickListener{pressOperation(MUL)}
        divisionButton.setOnClickListener{pressOperation(DIV)}

        equalButton.setOnClickListener{resolvePressed()}
    }

    private fun pressNumber(digit:String)
    {
        if(result.text=="0" && digit!=".")
            result.text="$digit"
        else
            result.text="${result.text}$digit"

        if(operation== NOT_OPERATION)
            num1=result.text.toString().toDouble()
        else
            num2=result.text.toString().toDouble()
    }

    private fun pressOperation(operation:Int)
    {
        this.operation=operation

        num1=result.text.toString().toDouble()

        result.text="0"
    }

    private fun resolvePressed()
    {
        val res = when(operation)
        {
            ADD -> num1+num2
            SUB -> num1-num2
            MUL -> num1*num2
            DIV -> num1/num2

            else -> 0
        }

        num1 = res as Double

        result.text=if("$res".endsWith(".0")) {
            "$res".replace(".0","")
        }
        else
            "%.2f".format(res)

    }

    private fun resetAll()
    {
        result.text="0"
        num1=0.0
        num2=0.0
    }

    companion object
    {
        const val ADD=1
        const val SUB=2
        const val MUL=3
        const val DIV=4
        const val NOT_OPERATION=0
    }
}