import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args: Array<String>) = with (BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().trim().toInt()
    val arr = readLine().trim().map{it.toChar()}

    var ans = 0
    var curr = 0
    for (i in 0..n-1) {
        if (arr[i] == 'x') {
            curr++
            if (curr>2) {
                ans++
            }
        } else {
            curr = 0
        }
    }
    println(ans)
}
