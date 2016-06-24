package Dao;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.security.interfaces.RSAKey;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author zeroxf
 */
public class DaoImpl implements Dao{
    private Connection conn = null;
    public DaoImpl(Connection conn){
        this.conn = conn;
    }
    
    
    /**
     *
     * @param user
     * @return
     * @throws Exception
     */
    
    @Override
    public int getlastid() throws SQLException{
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "select last_insert_id()";
        int lastid = -1;
         try{
             pstmt = this.conn.prepareStatement(sql);
            try (ResultSet rs = pstmt.executeQuery()) {
                
                while(rs.next()){
                    lastid = rs.getInt(1);
                }
            }

        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
         return lastid;
    }
    
    public boolean doCreateCustomer(Customers user) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "INSERT INTO Customers(cid,cname,phonenum,sex,age,password) VALUES(?,?,?,?,?,?)";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, user.cid);
            pstmt.setString(2, user.cname);
            pstmt.setString(3, user.phonenum);
            pstmt.setString(4, user.sex);
            pstmt.setInt(5, user.age);
            pstmt.setString(6, user.password);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            throw e;
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
       // throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public boolean doCreateSeller(Sellers user ) {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "INSERT INTO Sellers(sid,sname,phonenum,sex,age,password) VALUES(?,?,?,?,?,?)";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, user.sid);
            pstmt.setString(2, user.sname);
            pstmt.setString(3, user.phonenum);
            pstmt.setString(4, user.sex);
            pstmt.setInt(5, user.age);
            pstmt.setString(6, user.password);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    @Override
    public boolean doCreateProduct(Product product) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "INSERT INTO Product(pid,pname,sid,price,num,comment,sellnum) VALUES(?,?,?,?,?,?,?)";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, product.pid);
            pstmt.setString(2, product.pname);
            pstmt.setInt(3, product.sid);
            pstmt.setDouble(4, product.price);
            pstmt.setInt(5, product.num);
            pstmt.setString(6, product.comment);
             pstmt.setInt(7, product.sellnum);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
        
    }

    @Override
    public boolean doCreateManager(Managers manager) throws Exception {
        
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "INSERT INTO Managers(mid, mname) VALUES(?,?,?)";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, manager.mid);
            pstmt.setString(2, manager.mname);
            pstmt.setString(3, manager.password);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    
    @Override
    public boolean doCreateOrder(Orders orders) throws Exception {
        boolean flag = false;
       /* PreparedStatement pstmt = null;
        String sql = "INSERT INTO Managers(mid, mname) VALUES(?,?,?)";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, orders.cid);
            pstmt.setInt(2, orders.pid);
            pstmt.setInt(3, orders.num);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }*/
        return flag;
    }
    
    @Override
    public boolean doDeletebyOid(int cid, int pid) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "DELETE FROM Orders where cid = ? and pid = ?";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, cid);
            pstmt.setInt(2, pid);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
        
    }

    @Override
    public boolean doDeltebyPid(int pid) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "delete from Product where Product.pid = ?";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, pid);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    @Override
    public boolean doDeleteSeller(int sid) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "delete from Sellers where Sellers.sid = ?";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, sid);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    @Override
    public boolean doDeleteCustomer(int cid) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql;
        sql = "delete from Customers where Customers.cid = ?";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, cid);

            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            throw e;
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    @Override
    public boolean doUpdatebyCid(Customers user) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "update Customers set cname=?,phonenum=?,sex=?,age=?,password=? where cid=?";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setString(1, user.cname);
            pstmt.setString(2, user.phonenum);
            pstmt.setString(3, user.sex);
            pstmt.setInt(4, user.age);
            pstmt.setString(5, user.password);
            pstmt.setString(6, String.valueOf(user.cid));
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            throw e;
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    @Override
    public boolean doUpdatebyPid(Product product) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "update Product set pname = ?,sid=?,price=?,num=?,comment=? where pid=?";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setString(1, product.pname);
            pstmt.setInt(2, product.sid);
            pstmt.setDouble(3, product.price);
            pstmt.setInt(4, product.num);
            pstmt.setString(5, product.comment);
            pstmt.setInt(6, product.pid);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    @Override
    public boolean doUpdatebySid(Sellers user) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "update Sellers set sname=?,phonenum=?,sex=?,age=?,password=? where sid=?";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setString(1, user.sname);
            pstmt.setString(2, user.phonenum);
            pstmt.setString(3, user.sex);
            pstmt.setInt(4, user.age);
            pstmt.setString(5, user.password);
            pstmt.setInt(6, user.sid);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    @Override
    public boolean doUpdatebyOid(Orders orders) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        String sql = "update Orders set num = ? where cid=?,pid=?";
        try {
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, orders.num);
            pstmt.setInt(2, orders.cid);
            pstmt.setInt(3, orders.pid);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    @Override
    public List<Product> findProductbyName(String keyword) throws Exception {
        
        List<Product> all = new ArrayList<Product>();
        
        PreparedStatement pstmt = null;
        
        String sql = "select pid,pname,sid,price,comment,num,sellnum FROM Product WHERE pname LIKE ? OR pid LIKE ? sid LIKE ? OR comment LIKE ?";
        
        try{
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setString(1, "%" + keyword + "%");
            pstmt.setString(2, "%" + keyword + "%");
            pstmt.setString(3, "%" + keyword + "%");
            pstmt.setString(4, "%" + keyword + "%");
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()) {
                Product product;
                product = new Product(rs.getInt(1), rs.getString(2), rs.getInt(3), rs.getDouble(4), rs.getString(5), rs.getInt(6),null,rs.getInt(7));
                all.add(product);
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return all;
    }

    @Override
    public List<Corders> findOrderbyCid(int cid) throws Exception {
         throw new UnsupportedOperationException("Not supported yet."); 
    }

    @Override
    public List<Sorders> findOrderbySid(int sid) throws Exception {
        List<Sorders> all;
        all = new ArrayList<Sorders>();
        
        PreparedStatement pstmt = null;
        
        String sql = "select pid,pname,sid,price,comment,O.num,O.num*price FROM Product P, Seller O  WHERE "
                + "O.pid = P.pid and P.sid = %";
        
        try{
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, sid);
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()) {
                Sorders sorders;
//public Sorders(int pid, int num, String pname, int cid, double price, double sum, String commentString) {
                sorders = new Sorders(rs.getInt(1), rs.getInt(6), rs.getString(2), rs.getInt(3), 
                        rs.getDouble(4), rs.getDouble(7), rs.getString(5));
                all.add(sorders);
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return all;
    }

    @Override
    public List<Product> findOrder(int cid, int pid) throws Exception {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Customers findCustomers(int cid, String password) throws Exception {
        Customers customers = null;
        
        PreparedStatement pstmt = null;
        //int _cid, String _cname, String _phonenum, String _sex, int _age, String _password
        String sql = "select cid,cname,phonenum,sex,age,password FROM Customers WHERE cid = ? and password = ?";
        
        try{
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, cid);
            pstmt.setString(2, password);
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()) {
                customers = new Customers(rs.getInt(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getInt(5), rs.getString(6));
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return customers;
    }

    @Override
    public Sellers findSellers(int sid, String password) throws Exception {
        Sellers sellers = null;
        
        PreparedStatement pstmt = null;
        //int sid, String sname, String phonenum, String sex, int age, String password, Collection<Product> product
        String sql = "select sid,sname,phonenum,sex,age FROM Sellers WHERE sid = ? and password = ?";
        
        try{
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, sid);
            pstmt.setString(2, password);
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()) {
                String name;
                sellers = new Sellers(rs.getInt(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getInt(5), null, null);
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return sellers;
    }

    @Override
    public Managers findManagers(int mid, String password) throws Exception {
        Managers managers = null;
        
        PreparedStatement pstmt = null;
        //int sid, String sname, String phonenum, String sex, int age, String password, Collection<Product> product
        String sql = "select mid,mname FROM Managers WHERE mid = ? and password = ?";
        
        try{
            pstmt = this.conn.prepareStatement(sql);
            pstmt.setInt(1, mid);
            pstmt.setString(2, password);
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()) {
                String name;
                managers = new Managers(rs.getInt(1), rs.getString(2), null);
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return managers;
    }
        public List<Product> findCProduct(String sqlString) throws Exception {
         List<Product> all = new ArrayList<Product>();
        
        PreparedStatement pstmt = null;
        
        String sql = sqlString;
        
        try{
            pstmt = this.conn.prepareStatement(sql);
         /*   pstmt.setString(1, "%" + keyword + "%");
            pstmt.setString(2, "%" + keyword + "%");
            pstmt.setString(3, "%" + keyword + "%");
            pstmt.setString(4, "%" + keyword + "%");*/
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()) {
                Product product;
                product = new Product(rs.getInt(1), rs.getString(2), rs.getInt(3), rs.getDouble(4), rs.getString(5), rs.getInt(6),rs.getString(7),rs.getInt(8));
                all.add(product);
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return all;
    }
    @Override
    public List<Product> findProduct(String sqlString) throws Exception {
         List<Product> all = new ArrayList<Product>();
        
        PreparedStatement pstmt = null;
        
        String sql = sqlString;
        
        try{
            pstmt = this.conn.prepareStatement(sql);
         /*   pstmt.setString(1, "%" + keyword + "%");
            pstmt.setString(2, "%" + keyword + "%");
            pstmt.setString(3, "%" + keyword + "%");
            pstmt.setString(4, "%" + keyword + "%");*/
            ResultSet rs = pstmt.executeQuery();
            while(rs.next()) {
                Product product;
                product = new Product(rs.getInt(1), rs.getString(2), rs.getInt(3), rs.getDouble(4), rs.getString(5), rs.getInt(6),rs.getString(7),rs.getInt(8));
                all.add(product);
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return all;
    }

    @Override
    public boolean excutesql(String sql) throws Exception {
        boolean flag = false;
        PreparedStatement pstmt = null;
        try {
            pstmt = this.conn.prepareStatement(sql);
            if(pstmt.executeUpdate() > 0){
                flag = true;
            }
        } catch (Exception e) {
            try {
                throw e;
            } catch (Exception ex) {
                Logger.getLogger(DaoImpl.class.getName()).log(Level.SEVERE, null, ex);
            }
        }   finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch(Exception e1){
                    
                }
            }
        }
        return flag;
    }

    @Override
    public List<Corders> findCorders(String sql) throws Exception {
        List<Corders> all = new ArrayList<Corders>();
        
        PreparedStatement pstmt = null;
     
        try{
            pstmt = this.conn.prepareStatement(sql);
         /*   pstmt.setString(1, "%" + keyword + "%");
            pstmt.setString(2, "%" + keyword + "%");
            pstmt.setString(3, "%" + keyword + "%");
            pstmt.setString(4, "%" + keyword + "%");*/
            ResultSet rs = pstmt.executeQuery();
            //int _oid, int _pid, String _pname, int _sid,  double _price, int _buynum, String _sname, int _lastnum,double _sum
            while(rs.next()) {
                Corders corders;
                double _sum = rs.getDouble(5)*rs.getInt(6);
                corders = new Corders(rs.getInt(1), rs.getInt(2), rs.getString(3), rs.getInt(4), rs.getDouble(5), rs.getInt(6),rs.getString(7),rs.getInt(8), _sum, rs.getString(9));
                all.add(corders);
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return all;    }

    @Override
    public List<Customers> findCustomers(String sql) throws Exception {
        Customers customers = null;
         List<Customers> all = new ArrayList<Customers>();
        PreparedStatement pstmt = null;
        //int _cid, String _cname, String _phonenum, String _sex, int _age, String _password
        try{
            pstmt = this.conn.prepareStatement(sql);

            ResultSet rs = pstmt.executeQuery();
            while(rs.next()) {
                customers = new Customers(rs.getInt(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getInt(5), rs.getString(6));
                all.add((customers));
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return all;
 }

    @Override
    public List<Sellers> findSellers(String sql) throws Exception {
         List<Sellers> all = new ArrayList<Sellers>();
        Sellers sellers = null;
        
        PreparedStatement pstmt = null;
        //int sid, String sname, String phonenum, String sex, int age, String password, Collection<Product> product
        
        
        try{
            pstmt = this.conn.prepareStatement(sql);

            ResultSet rs = pstmt.executeQuery();
            while(rs.next()) {
                String name;
                sellers = new Sellers(rs.getInt(1), rs.getString(2), rs.getString(3), rs.getString(4), rs.getInt(5), null, null);
                all.add(sellers);
            }
            rs.close();
        }catch (Exception e){
            throw e;
        }finally{
            if(pstmt != null){
                try{
                    pstmt.close();
                }catch (Exception e1){
                    
                }
            }
        }
        return all;
    }


    
}
