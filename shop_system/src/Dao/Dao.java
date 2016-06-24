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
public interface Dao {
    
    public boolean doCreateSeller(Sellers user) throws Exception;
    
    public boolean doCreateProduct(Product product) throws Exception;
    
    public boolean doCreateCustomer(Customers user) throws Exception;
    
    public boolean doCreateManager(Managers manager) throws Exception;
    
    /**
     *
     * @param orders
     * @return
     * @throws Exception
     */
    public boolean doCreateOrder(Orders orders) throws  Exception;
    
    public boolean doDeletebyOid(int cid, int pid) throws  Exception;
    
    public boolean doDeltebyPid(int pid) throws Exception;
    
    public boolean doDeleteSeller(int sid) throws Exception;
    
    public boolean doDeleteCustomer(int cid) throws Exception;
    
    public boolean doUpdatebyCid(Customers user) throws Exception;
    
    public boolean doUpdatebyPid(Product product) throws Exception;
    
    public boolean doUpdatebySid(Sellers user) throws Exception;
    
    public boolean doUpdatebyOid(Orders orders) throws Exception;
    public boolean excutesql(String sql) throws Exception;
    public List<Product> findProductbyName(String keyword)throws Exception;
    public List<Product> findProduct(String sqlString)throws Exception;
  //  public List<List<object>> findProduct(String sqlString)throws Exception;
    /**
     *
     * @param cid
     * @return
     * @throws Exception
     */
    public List<Corders> findOrderbyCid(int cid)throws Exception;
    public List<Corders> findCorders(String sql)throws Exception;
    
    /**
     *
     * @param sid
     * @return
     * @throws Exception
     */
    public List<Sorders> findOrderbySid(int sid)throws Exception;
    
    public List<Product> findOrder(int cid, int pid)throws Exception;
    
    public Customers findCustomers(int cid, String password)throws Exception;
    
    public Sellers findSellers(int sid, String password)throws Exception;
    public List<Customers> findCustomers(String sql)throws Exception;
    
    public List<Sellers> findSellers(String sql)throws Exception;
    public Managers findManagers(int mid, String password)throws Exception;
    
    public int getlastid() throws SQLException;
}
