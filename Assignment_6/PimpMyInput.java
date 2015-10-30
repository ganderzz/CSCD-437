import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.util.regex.Pattern;
import java.util.regex.Matcher;


public class PimpMyInput {

   public static void main(String...args) {
   
      final String MAX_INT = ((Integer) Integer.MAX_VALUE).toString();
      final String MIN_INT = ((Integer) Integer.MIN_VALUE).toString();
      
      BigInteger a,b,c;
      BufferedReader brEndfile = null,
                     brPassword = null;
      File inputFile,
           outputFile,
           errorFile = new File("errLog.txt"),
           passwordFile = new File("password.txt");
      FileReader frEndfile = null,
                 frPassword = null;
      FileWriter fwEndfile = null,
                 fwErrorFile = null,
                 fwPassword = null;
      Matcher m = null;
      MessageDigest md = null;
      Pattern pattern = null;
      SecureRandom sr = new SecureRandom();
      String firstName = "",
             lastName = "",
             firstNum = "",
             secondNum = "",
             pw_hashed = "",
             password = "",
             pw_filename = "pw.txt",
             rePassword = "",
             input = "",
             output = "",
             buffer = "",
             err_string = "",
             password_pattern = "(^(?=.*[A-Z]+)(?=.*[a-z]+)(?=.*[0-9]+)"+
                           "(?=.*[,.;:!?]+))([a-zA-Z0-9,.;:!?]{8,32}$)",
             seed = "";
      Scanner kb = new Scanner(System.in);
      
      // Names
      while(true) {
         try {
            pattern = Pattern.compile("[A-Za-z]{1,50}");
            System.out.print("Please enter your first name: ");
            firstName = kb.nextLine();
            m = pattern.matcher(firstName);
            if(!(m.matches())) {
               throw new IllegalArgumentException("First name invalid");
            }
            System.out.print("Please enter your last name: ");
            lastName = kb.nextLine();
            m = pattern.matcher(lastName);
            if(!(m.matches())) {
               throw new IllegalArgumentException("Last name invalid");
            }
            break;
         }
         catch(IllegalArgumentException e) {
            err_string += e + "\n";
         }
      }//endwhile
      
      //Integers
      while(true) {
         try {
            pattern = Pattern.compile("^-?[0-9]{1,10}$");
            System.out.print("Please enter a number (no decimals): ");
            firstNum = kb.nextLine();
            m = pattern.matcher(firstNum);
            if(!(m.matches())) {
               throw new IllegalArgumentException("First number invalid");
            }
            if(firstNum.length() == MAX_INT.length()) {
               if(firstNum.compareTo(MAX_INT) > 0) {
                  throw new IllegalArgumentException("First number too large");
               }
            }
            else if(firstNum.length() > MAX_INT.length()) {
               if(firstNum.length() == MIN_INT.length() && firstNum.charAt(0) == '-') {
                  if(firstNum.compareTo(MIN_INT) > 0) {
                     throw new IllegalArgumentException("First number too small");
                  }
               }
               else
                  throw new IllegalArgumentException("First number too large");
            }
            a = new BigInteger(firstNum);
            
            System.out.print("Please enter another number: ");
            secondNum = kb.nextLine();
            m = pattern.matcher(secondNum);
            if(!(m.matches())) {
               throw new IllegalArgumentException("Second number invalid");
            }
            if(secondNum.length() == MAX_INT.length()) {
               if(secondNum.compareTo(MAX_INT) > 0) {
                  throw new IllegalArgumentException("First number too large");
               }
            }
            else if(secondNum.length() > MAX_INT.length()) {
               if(secondNum.length() == MIN_INT.length() && secondNum.charAt(0) == '-') {
                  if(secondNum.compareTo(MIN_INT) > 0) {
                     throw new IllegalArgumentException("Second number too small");
                  }
               }
               else
                  throw new IllegalArgumentException("Second number too large");
            }
            b = new BigInteger(secondNum);
            break;
         }
         catch(IllegalArgumentException e) {
            err_string += e + "\n";
         }
      }//endwhile
      
      // I/O Files
      while(true) {
         try {
            pattern = Pattern.compile("[a-zA-Z0-9_-]{1,32}(\\.txt)$");
            System.out.print("Please enter the name of your input file: ");
            input = kb.nextLine();
            m = pattern.matcher(input);
            if(!m.matches()) {
               throw new IllegalArgumentException("Input file name invalid");
            }
            System.out.print("Please enter the name of your output file: ");
            output = kb.nextLine();
            m = pattern.matcher(output);
            if(!m.matches() || input.equalsIgnoreCase(output)) {
               throw new IllegalArgumentException("Output file name invalid");
            }
            outputFile = new File(output);
            inputFile = new File(input);
            frEndfile = new FileReader(inputFile);
            break;
         }
         catch(IllegalArgumentException e) {
            err_string += e + "\n";
            System.out.println("Invalid file name");
         }
         catch(IOException e) {
            err_string += e + "\n";
            System.out.println("No such file exists");
         }
      }//endwhile
      
      // MD Algorithm Catch
      try {
         md = MessageDigest.getInstance("SHA-256");
      }
      catch(NoSuchAlgorithmException e) {
         err_string += e + "\n";
      }
      // Password
      while(true) {
         try {
            pattern = Pattern.compile(password_pattern);
            System.out.print("Please enter your password (between 8-32 characters,"+
                              "at least one capital,\nlowercase, number, and"+
                              " punctuation mark: ");
            password = kb.nextLine();
            m = pattern.matcher(password);
            if(!m.matches()) {
               throw new IllegalArgumentException("Password invalid");
            }
            seed = new BigInteger(1, sr.generateSeed(20)).toString(20);
            password = seed + password;
            md.update(password.getBytes("UTF-8"));
            pw_hashed = new BigInteger(1, md.digest()).toString();
            break;
         }
         catch(Exception e) {
            err_string += e + "\n";
         }
      }//endwhile
      
      //Store Password
      try {
         fwPassword = new FileWriter(new File(pw_filename));
         fwPassword.write(seed + "\n" + pw_hashed);
         fwPassword.close();
      }
      catch(IOException e) {
         System.out.println(e);
      }
      //Re-Enter Password
      while(true) {
         try {
            System.out.print("Please re-enter your password: ");
            password = kb.nextLine();
            m = pattern.matcher(password);
            if(!m.matches()) {
               throw new IllegalArgumentException("Password invalid");
            }
            frPassword = new FileReader(pw_filename);
            brPassword = new BufferedReader(frPassword);
            seed = brPassword.readLine();
            rePassword = brPassword.readLine();
            password = seed + password;
            md.update(password.getBytes("UTF-8"));
            pw_hashed = new BigInteger(1, md.digest()).toString();
            
            if(!(pw_hashed.equals(rePassword))) {
               throw new Exception("Passwords do not match!");
            }
            break;
         }
         catch(Exception e) {
            err_string += e + "\n";
            System.out.println("P1: " + rePassword + "\nP2: " + pw_hashed);
            seed = "";
            rePassword = "";
         }
      }//endwhile
      try {
         brPassword.close();
      } catch(IOException e) {
         err_string += e + "\n";
      }
      // Open readers
      try {
         fwErrorFile = new FileWriter(errorFile);
         fwEndfile = new FileWriter(outputFile);
         brEndfile = new BufferedReader(frEndfile);
      }
      catch(FileNotFoundException e) {
         err_string += e.toString() + "\n";
      }
      catch(IOException e) {
         err_string += e.toString() + "\n";
      }
      // Write to output file
      try {         
         fwEndfile.write(firstName + "\n");
         fwEndfile.write(lastName + "\n");
         c = a;
         c = c.add(b);
         fwEndfile.write(c.toString() + "\n");
         c = a;
         c = c.multiply(b);
         fwEndfile.write(c.toString() + "\n");

         do {
            buffer = brEndfile.readLine();
            if(buffer == null) {
               break;
            }
            fwEndfile.write(buffer + "\n");
         }
         while(!buffer.equals(null));
      }
      catch(Exception e) {
         err_string += e.toString() + "\n";
      }
      try {
         fwErrorFile.write(err_string);
         fwErrorFile.close();
         fwEndfile.close();
         frEndfile.close();
      }
      catch(IOException e) {
         System.out.println("An errorFile occurred\n");
      }
   }
}