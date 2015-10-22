# main.rb  

# Dylan Paulus
# Assignment 5
# CSCD 437
# Secure Coding

require "io/console"

# Print out the menu items
def printOutRules
	puts ""
	puts "a. Social Security Number"
	puts "b. US Phone number"
	puts "c. E-mail address"
	puts "d. Name on a class roster, assuming one or more middle initials - Last name, First name, MI"
	puts "e. Date in MM-DD-YYYY format"
	puts "f. House address - Street number, street name, abbreviation for road, street, boulevard or avenue"
	puts "g. City followed by state followed by zip as it should appear on a letter"
	puts "h. Military time, including seconds"
	puts "i. US Currency down to the penny (ex: $123,456,789.23"
	puts "j. URL, including http://"
	puts "k. A password"
	puts "l. All words containing an odd number of alphabetic characters, ending in ion"
	puts "q. quit"
	puts ""
end

# Checks for eight digits. Will also accept XXX-XX-XXXX
def ssn(input)
	(/(\d){3}(-?)(\d){2}(-?)(\d){4}/ =~ input)? "true" : "false"
end

# Will check if their is a leading 1, plus area code, and finally 7 addtional digits
# which can be separated by dashes or not.
# Checks just a few of the following possible phone numbers
# 	- X(XXX)XXX-XXXX
# 	- XXXXXXXXXX
# 	- (XXX) XXXXXXX
def phoneNumber(input)
	(/(\d)?\(?(\d){3}\)?(\s|-)?(\d){3}(\s|-)?(\d){4}/ =~ input)? "true" : "false"
end

# Checks to see if a string of characters exist, followed by @, followed by more characters
# then a dot (.), following by an domain atleast 2 characters long
def email(input)
	(/(.+?)\@(.+?)\.[a-zA-Z.]{2,}/i =~ input)? "true" : "false"
end

# Looks for last name, followed by first, then middle initial
# Each name can be separated by comma, space, or both
# Middle initial can also end with a period
def name(input)
	(/[a-zA-Z]+(\,|\s)(\s)?[a-zA-Z]+(\,|\s)(\s)?[a-zA-Z]+(\.)?/i =~ input)? "true" : "false"
end

# Checks for a date containing {1-2 digits}{. or - separator}
# {1-2 digits where the first digit can only be between 0-3}{separator}{4 digits}
def date(input)
	(/(\d){1,2}(-|.)?([0-3]){0,1}[1-9]{1}(-|.)?(\d){4}/ =~ input)? "true" : "false"
end

# Looks at a standard address
def address(input)
	(/[0-9]{4}(\s|\,){1}(.+?)(\s|\,){1}(?i)((str)|(street)|(ave)|(avenue)|(rd)|(road)|(blvd)|(boulevard))(\.)?/i =~ input)? "true" : "false"
end

# A standard letter layout with city, state zip
def letter(input)
	(/[a-zA-Z]{2,}(\,)\s?[A-Z]{2}(\s)([0-9]{5}|[0-9]{5}(\-)?[0-9]{4}|[a-zA-Z]{1}[0-9]{1}[a-zA-Z]{1}(\s|\-)?[0-9]{1}[a-zA-Z]{1}[0-9]{1})}/i =~ input)? "true" : "false"
end

# Military time containing 0-9{2} separated by :
def militaryTime(input)
	(/[0-9]{1,2}\:[0-9]{1,2}\:[0-9]{1,2}/i =~ input)? "true" : "false"
end

# Standard US currency which may or may not contain $ and cents
def currency(input)
	(/\$?[+-]?[0-9]{1,3}((\,)?[0-9]{3})*(\.[0-9]{2})?/i =~ input)? "true" : "false"
end

# Checks for website maybe starting with http:// or https://
# then checks if maybe contains www.
# then for sure checks for string, followed by any length of .XXX
# google.au.com   matches
# google.com matches
def website(input)
	(/((http|https)\:\/\/)?(www)?(.+)(\.[a-zA-Z]{2,3})+/i =~ input)? "true" : "false"
end

# Checks for an uppercase, lowercase, digit, and puncuation. 
# Also will deny if more than 2 lowercase characters occur in a row
def password(input)
	(/^(?=.*[^a-zA-Z])(?!.*([a-z])([a-z])([a-z]))(?=.*[a-z])(?=.*[A-Z])\S{10,}$/ =~ input)? "true" : "false"
end

# Looks if any characters are off, and ends with ion
def ion(input)
	(/^[a-zA-Z]{1}([a-zA-Z]{2})*(ion)$/ =~ input)? "true" : "false"
end

# Test input again the regular expression. Returns (boolean) true/false
def testRegExp(command, input)
	return case command
	when "a"
		ssn(input)
	when "b"
		phoneNumber(input)
	when "c"
		email(input)
	when "d"
		name(input)
	when "e"
		date(input)
	when "f"
		address(input)
	when "g"
		letter(input)
	when "h"
		militaryTime(input)
	when "i"
		currency(input)
	when "j"
		website(input)
	when "k"
		password(input)
	when "l"
		ion(input)
	else 
		"Invalid input... try again."
	end
end

# Main... This makes the program run
def main()
	file = File.new("output.txt", "w")

	while true
		printOutRules()

		print "Menu: "
		command = gets
		puts command

		if command.chomp("").eql? "q"
			puts "=========="
			puts "bye."
			puts "=========="
			break
		end

		print "Input: "
		input = gets

		puts input

		puts "========="
		print "Result: "

		output = testRegExp(command.chomp(""), input.chomp(""))
		puts output

		print "========="
		puts ""

		file.puts("===========================")
		file.puts("Menu Item: #{command.chomp('')}")
		file.puts("String to Test: #{input.chomp('')}")
		file.puts("Outcome: #{output}")
		file.puts("===========================\n\n")
	end

	file.close
end

# Start the train, yo
main()