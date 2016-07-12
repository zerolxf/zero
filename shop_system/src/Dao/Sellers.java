package Dao;




/**
 *
 * @author zeroxf
 */
import java.util.*;

/** @pdOid 62c448a2-29ca-4ec6-843b-7d628b49c5d1 */
public class Sellers {
   /** @pdOid c9d71602-5771-4357-9e11-eb669e2203bf */
   public int sid;
   /** @pdOid 31c3a31e-c46f-4baf-92ce-4a39289b302e */
   public java.lang.String sname;
   /** @pdOid dea14083-348d-4e9a-8747-448e4b7fb88f */
   public java.lang.String phonenum;
   /** @pdOid 9cc5f963-a4b7-4e09-9c2c-2c0cf81df95c */
   public java.lang.String sex;
   /** @pdOid dd0738b6-4072-49d6-a4cd-4859ab14b004 */
   public int age;
   /** @pdOid 5e7472d3-4723-480b-a227-7ef9d0b6477c */
   public java.lang.String password;
   
   /** @pdRoleInfo migr=no name=Product assc=stoP coll=java.util.Collection impl=java.util.HashSet mult=0..* */
   public java.util.Collection<Product> product;

    public Sellers() {
    }

    public Sellers(int sid, String sname, String phonenum, String sex, int age, String password, Collection<Product> product) {
        this.sid = sid;
        this.sname = sname;
        this.phonenum = phonenum;
        this.sex = sex;
        this.age = age;
        this.password = password;
        this.product = product;
    }
   
   
   
   
   /** @pdGenerated default getter */
   public java.util.Collection<Product> getProduct() {
      if (product == null)
         product = new java.util.HashSet<Product>();
      return product;
   }
   
   /** @pdGenerated default iterator getter */
   public java.util.Iterator getIteratorProduct() {
      if (product == null)
         product = new java.util.HashSet<Product>();
      return product.iterator();
   }
   
   /** @pdGenerated default setter
     * @param newProduct */
   public void setProduct(java.util.Collection<Product> newProduct) {
      removeAllProduct();
      for (java.util.Iterator iter = newProduct.iterator(); iter.hasNext();)
         addProduct((Product)iter.next());
   }
   
   /** @pdGenerated default add
     * @param newProduct */
   public void addProduct(Product newProduct) {
      if (newProduct == null)
         return;
      if (this.product == null)
         this.product = new java.util.HashSet<Product>();
      if (!this.product.contains(newProduct))
         this.product.add(newProduct);
   }
   
   /** @pdGenerated default remove
     * @param oldProduct */
   public void removeProduct(Product oldProduct) {
      if (oldProduct == null)
         return;
      if (this.product != null)
         if (this.product.contains(oldProduct))
            this.product.remove(oldProduct);
   }
   
   /** @pdGenerated default removeAll */
   public void removeAllProduct() {
      if (product != null)
         product.clear();
   }

}
