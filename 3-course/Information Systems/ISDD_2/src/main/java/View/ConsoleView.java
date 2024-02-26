/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

package View;

import java.sql.DatabaseMetaData;
import java.sql.SQLException;

/**
 *
 * @author vicky
 */
public class ConsoleView {

   public void consoleViewLogin(String text){
       System.out.println("*****************************");
       System.out.println(text);
       System.out.println("*****************************");
       
    }
   public void consoleViewLogin(String text, String error){
        System.out.println("************************************");
        System.out.println(text);
        System.out.println("Ops, something went wrong ");
        System.out.println(error);
        System.out.println("************************************");
        
  }
  

}
