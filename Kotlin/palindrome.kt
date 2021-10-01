fun isPalindrome(s: String): Boolean {
    // Starting with indices a < b,
    // check chars at these positions match,
    // and that when moving indices inwards each pair also matches.
    // Recurs until all pairs between a and b have been checked.
    tailrec fun pal(a: Int, b: Int, acc: Boolean): Boolean {
        return if (a < b) {
            pal(a + 1, b - 1, acc && (s[a] == s[b]))
        } else {
            acc
        }
    }

    // s is a palindrome if pal is true when given the first and last index of s.
    return pal(0, s.length - 1, true)
}

fun main(args: Array<String>) {
    if (args.size != 1) {
        throw java.lang.IllegalArgumentException(
            "supply 1 string argument"
        )
    }

    val s = args.first()

    val result = isPalindrome(s)

    println(result)
}

/**
 * Sample input/output:
 *
 * - a/true
 * - aa/true
 * - aba/true
 * - tacocat/true
 * - aab/false
 * - palindrome/false
 * - <no arg>/Exception in thread "main" java.lang.IllegalArgumentException: supply 1 string argument
 *
 * Time complexity: O(n + floor(n/2)) = O(n):
 *   Getting length of s is O(n), and pal(a, b, *) is O(floor(max(b - a, 0)/2)).
 *
 * Space complexity: O(1 + floor(n/2)) = O(n):
 *   Each call to pal is O(1) and there are floor(n/2) calls to pal.
 */
