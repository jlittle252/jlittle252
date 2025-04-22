// Grade Distribution
//  Input: A list of integer values that represent
//         grades, followed by a negative number
// Output: A distribution of grades, as a percentage for
//         each of the categories 0-9, 10-19, . . .,
//         90-100.
import java.io.*;
// The exception definition to deal with the end of data
class NegativeInputException extends Exception {
  public NegativeInputException() {
    System.out.println("End of input data reached");
  }  //** end of constructor
}  //** end of NegativeInputException class
class GradeDist {
  int newGrade,
      index,
       limit_1,
       limit_2;
  int [] freq = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void buildDist() throws  IOException {
  DataInputStream in =  new  DataInputStream(System.in);
  try {
    while (true) {
      System.out.println("Please input a grade");
      newGrade = Integer.parseInt(in.readLine());
      if (newGrade < 0)
        throw new NegativeInputException();
      index = newGrade / 10;
      try {
        freq[index]++;
      }  //** end of inner try clause
      catch(ArrayIndexOutOfBoundsException e) {
        if (newGrade == 100)
          freq [9]++;
        else
          System.out.println("Error - new grade: " +
                     newGrade + " is out of range");
      }  //** end of catch (ArrayIndex. . .
    }  //** end of while (true) . . .
  }  //** end of outer try clause
  catch(NegativeInputException e) {
    System.out.println ("\nLimits    Frequency\n");
    for (index = 0; index < 10; index++) {
      limit_1 = 10 * index;
      limit_2 = limit_1 + 9;
      if (index == 9)
        limit_2 = 100;
      System.out.println("" + limit_1 + " - " +
                      limit_2 + "   " + freq [index]);
    }  //** end of for (index = 0; ...
  }  //** end of catch (NegativeInputException ...
}  //** end of method buildDist
}
