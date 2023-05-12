// Scala sum program

object Sum {

   def sum(seq: Array[Int]) : Int = {
      var s=0
      for (v<-seq)
         s+=v
      return s
   }

   def main(args: Array[String]) {
      var seq=Array(5,6,1,8,3,7)
      println(sum(seq))
   }

}
