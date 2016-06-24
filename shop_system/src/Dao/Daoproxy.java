package Dao;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.sql.SQLException;
import java.util.List;

/**
 *
 * @author zeroxf
 */
public class Daoproxy implements  Dao{
    private  DataBaseConnection dbc;
    private   DaoImpl dao = null;
    public Daoproxy(){
        
        this.dbc= new DataBaseConnection();
        
        this.dao = new DaoImpl(this.dbc.getConnection());
        
    }

    public Daoproxy(Daoproxy daoproxy) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public int getlastid() throws SQLException{
        return this.dao.getlastid();
    }
    
    @Override
    public boolean doCreateSeller(Sellers user) throws Exception {
       // throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        boolean flag = false;
        try{
            flag = this.dao.doCreateSeller(user);
        }catch (Exception e){
            throw  e;
        }finally{
           // this.dbc.close();
            return flag;
        }
    }

    @Override
    public boolean doCreateProduct(Product product) throws Exception {
        return this.dao.doCreateProduct(product);
       
    }
    public List<Product> findCProduct(String sqlString) throws Exception {
        return this.dao.findCProduct(sqlString);
    }
    @Override
    public boolean doCreateCustomer(Customers user) throws Exception {
        boolean flag = false;
        try{
            flag = this.dao.doCreateCustomer(user);
        }catch (Exception e){
            throw  e;
        }finally{
           // this.dbc.close();
            return flag;
        }
    }

    @Override
    public boolean doCreateManager(Managers manager) throws Exception {
                boolean flag = false;
        try{
            flag = this.dao.doCreateManager(manager);
        }catch (Exception e){
            throw  e;
        }finally{
           // this.dbc.close();
            return flag;
        }
    }

    @Override
    public boolean doDeletebyOid(int cid, int pid) throws Exception {
        return this.dao.doDeletebyOid(cid, pid);
    }

    @Override

    public boolean doDeltebyPid(int pid) throws Exception {
        return this.dao.doDeltebyPid(pid);
    }

    @Override
    public boolean doDeleteSeller(int sid) throws Exception {
        return this.dao.doDeleteSeller(sid);
    }

    @Override
    public boolean doDeleteCustomer(int cid) throws Exception {
        return this.dao.doDeleteCustomer(cid);
    }

    @Override
    public boolean doUpdatebyCid(Customers user) throws Exception {
        return this.dao.doUpdatebyCid(user);
    }

    @Override
    public boolean doUpdatebyPid(Product product) throws Exception {
        return this.dao.doUpdatebyPid(product);
    }

    @Override
    public boolean doUpdatebySid(Sellers user) throws Exception {
        return this.dao.doUpdatebySid(user);
    }

    @Override
    public boolean doUpdatebyOid(Orders orders) throws Exception {
        return this.dao.doUpdatebyOid(orders);
    }

    @Override
    public List<Product> findProductbyName(String keyword) throws Exception {
        return this.dao.findProductbyName(keyword);
    }

    /**
     *
     * @param cid
     * @return
     * @throws Exception
     */
    @Override
    public List<Corders> findOrderbyCid(int cid) throws Exception {
        return this.dao.findOrderbyCid(cid);
    }

    @Override
    public List<Sorders> findOrderbySid(int sid) throws Exception {
        return this.dao.findOrderbySid(sid);
    }

    @Override
    public List<Product> findOrder(int cid, int pid) throws Exception {
        return this.dao.findOrder(cid, pid);
    }



    @Override
    public boolean doCreateOrder(Orders orders) throws Exception {
        return this.dao.doCreateOrder(orders);
    }

    @Override
    public Customers findCustomers(int cid, String password) throws Exception {
        return dao.findCustomers(cid, password);
    }

    @Override
    public Sellers findSellers(int sid, String password) throws Exception {
        return dao.findSellers(sid, password);
    }

    @Override
    public Managers findManagers(int mid, String password) throws Exception {
        return this.dao.findManagers(mid, password);
    }

    @Override
    public List<Product> findProduct(String sqlString) throws Exception {
        return this.dao.findProduct(sqlString);
    }

    @Override
    public boolean excutesql(String sql) throws Exception {
        return this.dao.excutesql(sql);
    }

    @Override
    public List<Corders> findCorders(String sql) throws Exception {
        return this.dao.findCorders(sql);
    }

    @Override
    public List<Customers> findCustomers(String sql) throws Exception {
        return this.dao.findCustomers(sql);
    }

    @Override
    public List<Sellers> findSellers(String sql) throws Exception {
        return this.dao.findSellers(sql);
    }


}
