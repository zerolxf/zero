package Dao;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




import java.util.*;

/** @pdOid 9ce02c5f-ecbd-4065-ab38-987db3715b78 */
public class Customers {
   /** @pdOid b682ae90-05f8-4166-a097-82c361035e20 */
   public int cid;
   /** @pdOid a3633014-6600-4612-b5f2-17f06cadf998 */
   public java.lang.String cname;
   /** @pdOid ce24747b-9e88-4139-94d1-0498ae51aa5c */
   public java.lang.String phonenum;
   /** @pdOid fe38e9d8-d5a9-42b2-bfde-38febf0e8c3f */
   public java.lang.String sex;
   /** @pdOid 8bc352f8-eefd-4b4f-bb29-298eecdaaf06 */
   public int age;
   /** @pdOid 7e499aca-4fe3-4c44-818a-2c05804fbfe0 */
   public java.lang.String password;
   
   /** @pdRoleInfo migr=no name=Orders assc=ctoO coll=java.util.Collection impl=java.util.HashSet mult=1..* */
   public java.util.Collection<Orders> orders;

    public Customers(int _cid, String _cname, String _phonenum, String _sex, int _age, String _password) {
        cid = _cid;
        cname = _cname;
        password = _password;
        phonenum = _phonenum;
        sex = _sex;
        age = _age;
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