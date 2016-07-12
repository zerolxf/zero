package Dao;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author zeroxf
 */

/** @pdOid c971904c-294a-4dde-bfe4-8feefaaceaef */
public class Orders {
   /** @pdOid 8fe3f417-2803-4b88-a62e-841fd5666ca0 */
   public int cid;
   /** @pdOid e3d7a9ca-14f0-4e91-a6e4-3a7e9e39b0ec */
   public int pid;
   /** @pdOid 2148d59c-7a84-40c6-8383-7a4bdcbc53f2 */
   public int num;

    public Orders(int cid, int pid, int num) {
        this.cid = cid;
        this.pid = pid;
        this.num = num;
    }
   
}

class Sorders{
    
    public int pid;
    
    public int num;
    
    public String pname;
    
    public int cid;
    
    public double price;
    
    public double sum;
    
    public String commentString;

    public Sorders(int pid, int num, String pname, int cid, double price, double sum, String commentString) {
        this.pid = pid;
        this.num = num;
        this.pname = pname;
        this.cid = cid;
        this.price = price;
        this.sum = sum;
        this.commentString = commentString;
    }
    
    
}