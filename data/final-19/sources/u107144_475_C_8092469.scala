import scala.collection._

object C extends App {

  @inline def tokenizeLine = new java.util.StringTokenizer(readLine)
  def readInts(n: Int) = { val tl = tokenizeLine; Array.fill(n)(tl.nextToken.toInt) }
  def readLongs(n: Int) = { val tl = tokenizeLine; Array.fill(n)(tl.nextToken.toLong) }
  def readBigs(n: Int) = { val tl = tokenizeLine; Array.fill(n)(BigInt(tl.nextToken)) }

  val Array(n, m) = readInts(2)
  val ps = Array.fill(n){ readLine.toCharArray.map(_ == 'X') }
  val totalBad = ps.map(_.count(identity)).sum

  var startX, startY = 0
  while (startY < n && !ps(startY)(startX)) {
    while (startX < m && !ps(startY)(startX)) {
      startX += 1
    }
    if (startX == m) {
      startX = 0
      startY += 1
    }
  }

  val rightCnt = Array.fill(n, m)(0) 
  val downCnt = Array.fill(n, m)(0) 

  for (y <- n - 1 to 0 by -1) {
    for (x <- m - 1 to 0 by -1) {
      if (ps(y)(x)) {
        if (x + 1 < m) rightCnt(y)(x) = rightCnt(y)(x + 1) + 1
        else rightCnt(y)(x) = 1
        if (y + 1 < n) downCnt(y)(x) = downCnt(y + 1)(x) + 1
        else downCnt(y)(x) = 1
      }
    }
  }

  var minArea = Int.MaxValue
  for (bY <- 1 to n - startY) {
    for (bX <- 1 to m - startX ) {
      val area = bY * bX
      if (area < minArea && check(bX, bY)) {
        minArea = area
      }
    }
  }
  
  def check(bX: Int, bY : Int): Boolean = {
    var x0 = startX
    var y0 = startY
    var fixed = 0

    if (rightCnt(y0)(x0) > bX && downCnt(y0)(x0) > bY) return false
    if (rightCnt(y0)(x0) < bX && downCnt(y0)(x0) < bY) return false

    for (y <- y0 until y0 + bY) {
      if (rightCnt(y)(x0) < bX) return false
      fixed += bX
    }
    
    var moved = true
    while (moved) {
      if (x0 + bX < m && downCnt(y0)(x0 + bX) >= bY && !(y0 + bY < n && rightCnt(y0 + bY)(x0) > 0)) {
        fixed += bY
        x0 += 1
        moved = true
      } else if (y0 + bY < n && rightCnt(y0 + bY)(x0) >= bX && !(x0 + bX < m && downCnt(y0)(x0 + bX) > 0)) {
        y0 += 1
        fixed += bX
        moved = true
      } else moved = false
    }

    fixed == totalBad
  }
    
  println(if (minArea == Int.MaxValue) -1 else minArea)
}