import java.util.*;
import kotlin.math.*;

fun main() {
    val sc = Scanner(System.`in`);
    val a = sc.nextInt() ;
    val b = sc.nextInt() ;
    val c = sc.nextInt() ;
    val ans = minOf(a , b - 1 , c - 2) ;
    println(ans * 3 + 3) ;
}