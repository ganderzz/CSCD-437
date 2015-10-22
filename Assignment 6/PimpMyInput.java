import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.IOException;

public class PimpMyInput {

   public static void main(String...args) {
   
      int a,b;
      Integer c;
      BufferedReader br = null;
      File input,
           output,
           error = new File("errLog.txt");
      FileReader fr = null;
      FileWriter fw = null;
      FileWriter fe = null;
      String firstName = "",
             lastName = "",
             password = "",
             rePassword = "",
             inputFile = "",
             outputFile = "",
             buffer = "",
             errors = "";
      Scanner kb = new Scanner(System.in);

      System.out.print("Please enter your first name: ");
      firstName = kb.nextLine();
      
      System.out.print("Please enter your last name: ");
      lastName = kb.nextLine();
      
      System.out.print("Please enter a number: ");
      a = kb.nextInt();
      
      System.out.print("Please enter another number: ");
      b = kb.nextInt();
      
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
         errors += e.toString();
      }
      catch(IOException e) {
         errors += e.toString();
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
         errors += e.toString();
      }
      try {
         fe.write(errors);
         fe.close();
         fw.close();
         fr.close();
      }
      catch(IOException e) {
         System.out.println(e);
      }
   }
}