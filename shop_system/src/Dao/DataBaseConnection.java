package Dao;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author zeroxf
 */
public class DataBaseConnection {
    private static final String DBDRIVER = "com.mysql.jdbc.Driver";
    private static final String DBURL = "jdbc:mysql://119.29.61.178/shop_system";
    private static final String DBUSER = "zeroxf";
    private static final String DBPASS = "123456";
    private Connection conn = null;
    public DataBaseConnection (){
        try{
            Class.forName(DBDRIVER);
        } catch (ClassNotFoundException ex) {
            ex.printStackTrace();
        }
        try {
            conn = DriverManager.getConnection(DBURL, DBUSER, DBPASS);
            if(conn != null) System.out.println("connect is ok");
            
        } catch (SQLException ex) {
            ex.printStackTrace();
           // System.out.println("connect is not ok");
        }
    }
    public Connection getConnection(){
        return this.conn;
    }
    
    public void close(){
        if(this.conn != null){
            try{
                this.conn.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
    }
    
}
