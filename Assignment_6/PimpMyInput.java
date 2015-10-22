import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class PimpMyInput {

   public static void main(String...args) {
   
      final String MAX_INT = "4294967295";
      
      int a=0,
          b=0;
      Integer c;
      BufferedReader br = null;
      File input,
           output,
           error = new File("errLog.txt");
      FileReader fr = null;
      FileWriter fw = null,
                 fe = null;
      Matcher m = null;
      Pattern pattern = null;
      String firstName = "",
             lastName = "",
             firstNum = "",
             secondNum = "",
             password = "",
             rePassword = "",
             inputFile = "",
             outputFile = "",
             buffer = "",
             errors = "";
      Scanner kb = new Scanner(System.in);

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
      }
      catch(IllegalArgumentException e) {
         errors += e + "\n";
      }
      try {
         pattern = Pattern.compile("[0-9]{1,10}");
         System.out.print("Please enter a number: ");
         firstNum = kb.nextLine();
         m = pattern.matcher(firstNum);
         if(!(m.matches())) {
            throw new IllegalArgumentException("First number invalid");
         }
         if(firstNum.compareTo(MAX_INT) > 0) {
            throw new IllegalArgumentException("First number too large");
         }
         a = Integer.parseInt(firstNum);
         
         System.out.print("Please enter another number: ");
         secondNum = kb.nextLine();
         m = pattern.matcher(secondNum);
         if(!(m.matches())) {
            throw new IllegalArgumentException("Second number invalid");
         }
         if(firstNum.compareTo(MAX_INT) > 0) {
            throw new IllegalArgumentException("Second number too large");
         }
         b = Integer.parseInt(secondNum);
      }
      catch(IllegalArgumentException e) {
         errors += e + "\n";
      }
      System.out.print("Please enter the name of your input file: ");
      inputFile = kb.nextLine();
      
      System.out.print("Please enter the name of your output file: ");
      outputFile = kb.nextLine();
      
      System.out.print("Please enter your password: ");
      password = kb.nextLine();
      
      System.out.print("Please re-enter your password: ");
      rePassword = kb.nextLine();
      
      output = new File(outputFile);
      input = new File(inputFile);
      try {
         fe = new FileWriter(error);
         fr = new FileReader(input);
         fw = new FileWriter(output);
         br = new BufferedReader(fr);
      }
      catch(FileNotFoundException e) {
         errors += e.toString() + "\n";
      }
      catch(IOException e) {
         errors += e.toString() + "\n";
      }

      try {         
         fw.write(firstName);
         fw.write(lastName);
         c = a + b;
         fw.write(c.toString());
         c = a * b;
         fw.write(c.toString());
      
         do {
            buffer = br.readLine();
            if(buffer.equals(null)) {
               break;
            }
            fw.write(buffer);
         }
         while(!buffer.equals(null));
      }
      catch(Exception e) {
         errors += e.toString() + "\n";
      }
      try {
         fe.write(errors);
         fe.close();
         fw.close();
         fr.close();
      }
      catch(IOException e) {
         System.out.println("An error occurred\n");
      }
   }
}