/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jiemian;

import Dao.Customers;
import Dao.Daoproxy;
import Dao.Product;
import Dao.Sellers;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author zero
 */
public class Mmain extends javax.swing.JFrame {

    /**
     * Creates new form Mmain
     */
    Login parent;
    int id;
    Daoproxy daoproxy;
    String type;
    public void setconf(Login _parent, int _id, Daoproxy _daoproxy){
        id = _id;
        parent = _parent;
        daoproxy = _daoproxy;
    }
    public Mmain() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jPopupMenu1 = new javax.swing.JPopupMenu();
        jPopupMenu2 = new javax.swing.JPopupMenu();
        jMenu1 = new javax.swing.JMenu();
        jScrollPane1 = new javax.swing.JScrollPane();
        M_jTable = new javax.swing.JTable();
        jPanel2 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        M_jComboBox_type = new javax.swing.JComboBox<>();
        jLabel2 = new javax.swing.JLabel();
        M_jTextField_id = new javax.swing.JTextField();
        M_jButton_search = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();

        jButton1.setText("jButton1");

        jMenu1.setText("jMenu1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        M_jTable.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "用户id", "姓名", "性别", "年龄", "手机号码"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.Integer.class, java.lang.String.class, java.lang.String.class, java.lang.Integer.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        M_jTable.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                M_jTableMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(M_jTable);

        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        jLabel1.setText("管理对象类型:");

        M_jComboBox_type.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "消费者", "商家" }));

        jLabel2.setText("用户id");

        M_jButton_search.setText("搜索");
        M_jButton_search.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                M_jButton_searchActionPerformed(evt);
            }
        });

        jButton4.setText("执行sql");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jButton2.setText("注销");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(M_jComboBox_type, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jLabel2)
                .addGap(18, 18, 18)
                .addComponent(M_jTextField_id, javax.swing.GroupLayout.PREFERRED_SIZE, 58, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(M_jButton_search, javax.swing.GroupLayout.PREFERRED_SIZE, 62, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jButton4)
                .addContainerGap(16, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jButton2)
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addComponent(jButton2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 27, Short.MAX_VALUE)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(M_jComboBox_type, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2)
                    .addComponent(M_jTextField_id, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(M_jButton_search)
                    .addComponent(jButton4))
                .addGap(20, 20, 20))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(42, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 460, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 233, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(63, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void M_jButton_searchActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_M_jButton_searchActionPerformed
        // TODO add your handling code here:
        type = (String)M_jComboBox_type.getSelectedItem();
        String str_id = M_jTextField_id.getText().trim();
        String sql ;
        int id = 0;
        try{
            if(str_id.length()>0)
                id = Integer.valueOf(str_id);
        }catch(Exception ex){
            String message = ex.getMessage();
            int index = message.lastIndexOf(')');
            message = message.substring(index+1);
            JOptionPane.showMessageDialog(this, message+"\n请重新输入");
            return;
        }
        if(type.equals("消费者")) {
            List<Customers> all = null ;
            sql = "select * from Customers ";
            if(str_id.length()>0){
                sql = sql + " where Customers.cid = "+id;
            }
            sql = sql + " order by Customers.cid";
            try {
                all = this.daoproxy.findCustomers(sql);
            } catch (Exception ex) {
                String message = ex.getMessage();
                int index = message.lastIndexOf(')');
                message = message.substring(index+1);
                JOptionPane.showMessageDialog(this, message+"\n请重新输入");
                return;
            }
              DefaultTableModel dtm = (DefaultTableModel)M_jTable.getModel();
            int row = dtm.getRowCount();
            for(int i = 0; i < row; ++i){
                dtm.removeRow(0);
            }
            row = all.size();
            for(int i = 0; i < row; ++i){
                Object[]rowData = {
                    all.get(i).cid,
                    all.get(i).cname,
                    all.get(i).sex,
                    all.get(i).age,
                    all.get(i).phonenum,
                };
                dtm.addRow(rowData);
            }
        }else {
            List<Sellers> all = null ;
            sql = "select * from Sellers ";
            if(str_id.length()>0){
                sql = sql + " where Sellers.sid = "+id;
            }
            sql = sql + " order by Sellers.sid";
            try {
                all = this.daoproxy.findSellers(sql);
            } catch (Exception ex) {
                String message = ex.getMessage();
                int index = message.lastIndexOf(')');
                message = message.substring(index+1);
                JOptionPane.showMessageDialog(this, message+"\n请重新输入");
                return;
            }
              DefaultTableModel dtm = (DefaultTableModel)M_jTable.getModel();
            int row = dtm.getRowCount();
            for(int i = 0; i < row; ++i){
                dtm.removeRow(0);
            }
            row = all.size();
            for(int i = 0; i < row; ++i){
                Object[]rowData = {
                    all.get(i).sid,
                    all.get(i).sname,
                    all.get(i).sex,
                    all.get(i).age,
                    all.get(i).phonenum,
                };
                dtm.addRow(rowData);
            }
        }
    }//GEN-LAST:event_M_jButton_searchActionPerformed

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
        // TODO add your handling code here:
        Msql exsql = new Msql();
        exsql.setconf(daoproxy);
        exsql.setVisible(true);
    }//GEN-LAST:event_jButton4ActionPerformed

    private void M_jTableMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_M_jTableMouseClicked
        // TODO add your handling code here:
        Information editinfo = new Information();
        Sellers sellers = new Sellers(id, type, type, type, id, type, null);
        Customers customers = new Customers(id, type, type, type, id, type);
        if(type.equals("消费者")){
            int row = M_jTable.getSelectedRow();
            customers.cid =  (int)M_jTable.getValueAt(row, 0);
            customers.cname =  (String)M_jTable.getValueAt(row, 1);
            customers.sex =  (String)M_jTable.getValueAt(row, 2);
            customers.age =  (int)M_jTable.getValueAt(row, 3);
            customers.phonenum =  (String)M_jTable.getValueAt(row, 4);
            
        }else if(type.equals("商家")){
             int row = M_jTable.getSelectedRow();
            sellers.sid =  (int)M_jTable.getValueAt(row, 0);
            sellers.sname =  (String)M_jTable.getValueAt(row, 1);
            sellers.sex =  (String)M_jTable.getValueAt(row, 2);
            sellers.age =  (int)M_jTable.getValueAt(row, 3);
            sellers.phonenum =  (String)M_jTable.getValueAt(row, 4);
        }

        //Daoproxy _daoproxy, int _id, String _oldname, String _oldsex, String _oldphonenum, String _oldpassword, String _usrtype, int _oldage){
        try{
            if(type.equals("消费者")){
                editinfo.setconf(daoproxy, customers.cid, customers.cname,customers.sex, customers.phonenum, customers.password, "消费者", customers.age,customers,null);
            }
            else if(type.equals("商家")){
                editinfo.setconf(daoproxy, sellers.sid, sellers.sname,sellers.sex, sellers.phonenum, sellers.password, "商家", sellers.age,null,sellers);
            }
        }catch(Exception ex){
                 Logger.getLogger(Smain.class.getName()).log(Level.SEVERE, null, ex);
            String message = ex.getMessage();
            int index = message.lastIndexOf(')');
            message = message.substring(index+1);
            JOptionPane.showMessageDialog(this, message);
            return;
                }
        editinfo.setVisible(true);
    }//GEN-LAST:event_M_jTableMouseClicked

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        // TODO add your handling code here:
        this.parent.setVisible(true);
        this.parent.frame.setVisible(true);
        this.parent.setinit();
        this.setVisible(false);
    }//GEN-LAST:event_jButton2ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Mmain.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Mmain.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Mmain.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Mmain.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Mmain().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton M_jButton_search;
    private javax.swing.JComboBox<String> M_jComboBox_type;
    private javax.swing.JTable M_jTable;
    private javax.swing.JTextField M_jTextField_id;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton4;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPopupMenu jPopupMenu1;
    private javax.swing.JPopupMenu jPopupMenu2;
    private javax.swing.JScrollPane jScrollPane1;
    // End of variables declaration//GEN-END:variables
}