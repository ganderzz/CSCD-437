import scala.util.matching.Regex
import scala.io.StdIn.readLine
import scala.util.control.Breaks._ 

object RegExp {
	def main(args: Array[String]) {
		val scanner = new java.util.Scanner(System.in)

		printOutRules()

		print(": ")
		for( ln <- io.Source.stdin.getLines; if ln.length() > 0 ) 
		{
			if( ln == "q" )
			{
				println("\n\n=========\nSee ya!\n=========\n\n")
				return
			}

			println(ln)
			print("Enter input: ")

			val input = 

			testRegExp(ln, input)

			print(": ")
		}
	}

	/**
	 * Provides the regexp depending on the menu item chosen.
	 * Then, it tests the regexp against the provided input.
	 *
	 * @param  line   The menu option choice
	 * @param  input  The corresponding string to test
	 */
	def testRegExp(line: String, input : String) {
		val str = input

		val regex = line match {
		  case "a"  => str.matches("(\\d){3}(-?)(\\d){2}(-?)(\\d){4}")
		  case "b"  => str.matches("(\\d)?\\(?(\\d){3}\\)?(\\s|-)?(\\d){3}(\\s|-)?(\\d){4}")
		  case "c"  => str.matches("(.+?)\\@(.+?)\\.[a-zA-Z.]{2,}")
		  case "d"  => str.matches("[a-zA-Z]+(\\,|\\s)(\\s)?[a-zA-Z]+(\\,|\\s)(\\s)?[a-zA-Z]+(\\.)?")
		  case "f"  => str.matches("[0-9]{4}(\\s|\\,){1}(.+?)(\\s|\\,){1}(?i)((str)|(ave)|(rd)|(blvd))(\\.)?")
		  case "g"  => str.matches("[a-zA-Z]{2,}(\\,)\\s?[A-Z]{2}(\\s)([0-9]{5}|[0-9]{5}(\\-)?[0-9]{4}|[a-zA-Z]{1}[0-9]{1}[a-zA-Z]{1}(\\s|\\-)?[0-9]{1}[a-zA-Z]{1}[0-9]{1})")
		  case "h"  => str.matches("[0-9]{1,2}\\:[0-9]{1,2}\\:[0-9]{1,2}")
		  case "i"  => str.matches("\\$?[+-]?[0-9]{1,3}((\\,)?[0-9]{3})*(\\.[0-9]{2})?")
		  case "j"  => str.matches("((http|https)\\:\\/\\/)?(www)?(.+)(\\.[a-zA-Z]{2,3})+")
		  case "k" => str.matches("^(?=.*[^a-zA-Z])(?!.*([a-z])([a-z])([a-z]))(?=.*[a-z])(?=.*[A-Z])\\S{10,}$")
		  case "l" => str.matches("^[a-zA-Z]{1}([a-zA-Z]{2})*(ion)$")
		  case _ => "Invalid Input... Try Again"
		}

		println()
		println("\u001b[0;1m" + regex + "\u001b[0;0m")
		println()
	}

	/**
	 * Prints out the menu items.
	*/
	def printOutRules() {
		println("a. Social Security Number")
		println("b. US Phone number")
		println("c. E-mail address")
		println("d. Name on a class roster, assuming one or more middle initials - Last name, First name, MI")
		println("e. Date in MM-DD-YYYY format")
		println("f. House address - Street number, street name, abbreviation for road, street, boulevard or avenue")
		println("g. City followed by state followed by zip as it should appear on a letter")
		println("h. Military time, including seconds")
		println("i. US Currency down to the penny (ex: $123,456,789.23)")
		println("j. URL, including http://")
		println("k. A password")
		println("l. All words containing an odd number of alphabetic characters, ending in ion")
		println("q. quit")
		println()
	}
}