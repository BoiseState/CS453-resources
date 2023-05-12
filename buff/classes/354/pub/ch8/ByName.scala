// scalac ByName.scala && scala ByName

object ByName {

   def main(args: Array[String]) {
        foo(time());
   }

   def time() = {
      println("Getting time in nano seconds")
      System.nanoTime
   }

   def foo(t: => Long) = {
      println("In delayed method")
      println("Time: " + t)
      println("Time: " + t)
   }
}
