/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shop_system;

import java.awt.Container;
import javafx.application.Application;
import javafx.stage.Stage;
import javax.swing.JFrame;
import Dao.Daoproxy;
import jiemian.Login;

/**
 *
 * @author liangxianfeng
 */
public class main extends Application {
    String usrtype;
    @Override
    public void start(Stage primaryStage) throws ClassNotFoundException {
         String lookAndFeel = "com.sun.java.swing.plaf.gtk.GTKLookAndFeel";   
     
        JFrame frame = new JFrame();
        Daoproxy daoproxy;
        daoproxy = new Daoproxy();   
        Login tt = new Login(daoproxy,frame);
        tt.setSize(330,250);
        tt.setVisible(true);
        
        frame.setSize(350,300);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container cp=frame.getContentPane();
        cp.setLayout(null);
        
        
        cp.add(tt);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
