import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) = with (BufferedReader(InputStreamReader(System.`in`))) {
    val sc = Scanner(System.`in`)

    for (t in 1..sc.nextInt()) {
        val n = sc.nextInt()
        val arr = Array(n*2) { sc.nextInt() }.sorted()
        println(arr[n]-arr[n-1])
    }
}