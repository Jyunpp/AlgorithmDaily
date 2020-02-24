import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args: Array<String>) = with (BufferedReader(InputStreamReader(System.`in`))) {
    val arr = readLine().split(' ').map { it.toInt() }.sorted()
    println("${arr[3]-arr[0]} ${arr[3]-arr[1]} ${arr[3]-arr[2]}")
}