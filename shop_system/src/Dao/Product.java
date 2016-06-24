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
import java.util.*;

/** @pdOid d8d6df02-a27b-4e36-9527-bf0e356f7a59 */
public class Product {
   /** @pdOid 8b9559c8-63e9-4831-9375-d7c6fc8f71af */
   public int pid;
   /** @pdOid c15c16a6-17c6-4228-b392-fb608908cb1d */
   public java.lang.String pname;
   /** @pdOid 19a26975-fc3b-48cb-96d7-c7fd7683e332 */
   public int sid;
   /** @pdOid fa3886c4-13d8-495b-903b-06c11e0a4cd9 */
   public double price;
   /** @pdOid ccda828c-94d0-4c2a-8b46-3ccdca0db9f4 */
   public java.lang.String comment;
   /** @pdOid dd8bb3bd-7525-4de9-861d-124e89a2b3ff */
   public int num;
   public int sellnum;
   /** @pdRoleInfo migr=no name=Orders assc=ptoO coll=java.util.Collection impl=java.util.HashSet mult=0..* side=A */
   public java.util.Collection<Orders> orders;
   public String sname;
   
   public Product(int _pid, String _pname, int _sid, double _price, String _comment, int _num, String _sname, int _sellnum){
       pid = _pid;
       pname = _pname;
       sid = _sid;
       price = _price;
       comment = _comment;
       num = _num;
       sname = _sname;
       sellnum = _sellnum;
   }
   
   /** @pdGenerated default getter */
   public java.util.Collection<Orders> getOrders() {
      if (orders == null)
         orders = new java.util.HashSet<Orders>();
      return orders;
   }
   
   /** @pdGenerated default iterator getter */
   public java.util.Iterator getIteratorOrders() {
      if (orders == null)
         orders = new java.util.HashSet<Orders>();
      return orders.iterator();
   }
   
   /** @pdGenerated default setter
     * @param newOrders */
   public void setOrders(java.util.Collection<Orders> newOrders) {
      removeAllOrders();
      for (java.util.Iterator iter = newOrders.iterator(); iter.hasNext();)
         addOrders((Orders)iter.next());
   }
   
   /** @pdGenerated default add
     * @param newOrders */
   public void addOrders(Orders newOrders) {
      if (newOrders == null)
         return;
      if (this.orders == null)
         this.orders = new java.util.HashSet<Orders>();
      if (!this.orders.contains(newOrders))
         this.orders.add(newOrders);
   }
   
   /** @pdGenerated default remove
     * @param oldOrders */
   public void removeOrders(Orders oldOrders) {
      if (oldOrders == null)
         return;
      if (this.orders != null)
         if (this.orders.contains(oldOrders))
            this.orders.remove(oldOrders);
   }
   
   /** @pdGenerated default removeAll */
   public void removeAllOrders() {
      if (orders != null)
         orders.clear();
   }

}