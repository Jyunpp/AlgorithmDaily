fun main(args: Array<String>) {
	val t = readLine()!!.toInt()
    repeat(t) {
        val (x, y) = readLine()!!.split(" ").map { it.toLong() }
        val mini = if (x>y) y else x
        val a = x - mini + 1
        val b = y - mini + 1
        val c = (x + y - a - b)/2
        println("$a $b $c")
    }
}