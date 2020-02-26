import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args: Array<String>) = with (BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().trim().toInt()
    val arr = readLine().trim().split(' ').map{it.toInt()}.reversed().distinct().reversed()
    println(arr.size)
    print(arr.joinToString(" "))
}
