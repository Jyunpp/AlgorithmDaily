import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

// 20200227 10:35 ~ 10:41 
fun main(args: Array<String>) = with (BufferedReader(InputStreamReader(System.`in`))) {
    val sc = Scanner(System.`in`)
    for (t in 1..sc.nextInt()) {
        val n = sc.nextInt()
        if (n<1000) {
            println("${n}")
        } else if (n<1000000) {
            val temp = (n/100)%10
            var num = n/1000
            if (temp>=5) num++
            if (num==1000) {
                println("1M")
            } else {
                println("${num}K")
            }
        } else {
            val temp = (n/100000)%10
            var num = n/1000000
            if (temp>=5) num++
            println("${num}M")
        }
    }
}