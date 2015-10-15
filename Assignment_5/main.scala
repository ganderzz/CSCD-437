import scala.util.control._

object RegExp {
	def main(args: Array[String]) {
		printOutRules()

		val loop = new Breaks

		loop.breakable {
			for( ln <- io.Source.stdin.getLines ) 
			{
				if( ln == "q" )
					loop.break

				performOperation(ln)
			}
		}

		println("\n\n=========\nSee ya!\n=========\n\n")
	}

	def performOperation(input : String) {
		input match {
		  case "a"  => println("January")
		  case "b"  => println("February")
		  case "c"  => println("March")
		  case "d"  => println("April")
		  case "f"  => println("May")
		  case "g"  => println("June")
		  case "h"  => println("July")
		  case "i"  => println("August")
		  case "j"  => println("September")
		  case "k" => println("October")
		  case "l" => println("November")
		  case _ => println("\nInvalid Input... Try Again")
		}
	}

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
		println("")
	}
}