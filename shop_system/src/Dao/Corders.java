/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Dao;

/**
 *
 * @author zero
 */
public class Corders{
    public int oid;
    public int pid;
    
    
    
    public int buynum;
    
    public String pname;
    
    public int sid;
    
    public double price;
    
    public double sum;
    public String sname;
    public int lastnum;
    public String comment;
//select oid,pid,pname,P.sid,price,num,S.sname,P.sellnum FROM Product P, Sellers S WHERE P.sid = S.sid";
    public Corders(int _oid, int _pid, String _pname, int _sid,  double _price, int _buynum, String _sname, int _lastnum,double _sum, String _comment) {
        this.pid = _pid;
        this.buynum = _buynum;
        this.pname = _pname;
        this.sid = _sid;
        this.price = _price;
        this.sum = _sum;
        this.oid = _oid;
        this.sname = _sname;
        this.lastnum = _lastnum;
        this.comment = _comment;
    }
    
    
}
