package Q_10;

import java.util.*;
public class OddText {
    Scanner cursor = new Scanner(System.in);
    String text;

    public void showMiddleLetter(){
        System.out.print("Enter a String with odd number of characters : ");
        text = cursor.nextLine();
        System.out.println(text.charAt(text.length()/2));
    }
}
