/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jiemian;

import Dao.Customers;
import Dao.Daoproxy;
import Dao.Sellers;
import static java.sql.Types.NULL;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 *
 * @author liangxianfeng
 */
public class Register extends javax.swing.JPanel {

    /**
     * Creates new form Register
     */
    String name, sex, phonenum, usrtype, password1, password2;
    int age, id;
    Daoproxy daoproxy;
    Login parent;
    JFrame frame;
    public Register(Login _parent, JFrame _frame) {
        parent = _parent;
        frame = _frame;
        this.daoproxy = new Daoproxy();
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

        buttonGroup1 = new javax.swing.ButtonGroup();
        buttonGroup2 = new javax.swing.ButtonGroup();
        R_Lable_name = new javax.swing.JLabel();
        jTextField_name = new javax.swing.JTextField();
        R_Lable_password = new javax.swing.JLabel();
        R_jPasswordField1 = new javax.swing.JPasswordField();
        R_Lable_phonenum = new javax.swing.JLabel();
        R_jTextField_phonenum = new javax.swing.JTextField();
        R_jComboBox_Sex = new javax.swing.JComboBox<>();
        R_jComboBox_type = new javax.swing.JComboBox<>();
        R_Lable_usertype = new javax.swing.JLabel();
        R_Lable_name1 = new javax.swing.JLabel();
        R_Lable_age = new javax.swing.JLabel();
        R_jTextField_age = new javax.swing.JTextField();
        R_jButton_register = new javax.swing.JButton();
        R_jButton_cancle = new javax.swing.JButton();
        R_Lable_password1 = new javax.swing.JLabel();
        R_jPasswordField2 = new javax.swing.JPasswordField();

        R_Lable_name.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        R_Lable_name.setText("用户名:");
        R_Lable_name.setToolTipText("");

        jTextField_name.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        jTextField_name.setText("必填");
        jTextField_name.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jTextFieldFocusGained_Rname(evt);
            }
        });

        R_Lable_password.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        R_Lable_password.setText("密码:");
        R_Lable_password.setToolTipText("");

        R_jPasswordField1.setText("        ");
        R_jPasswordField1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                R_jPasswordField1ActionPerformed(evt);
            }
        });

        R_Lable_phonenum.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        R_Lable_phonenum.setText("手机:");
        R_Lable_phonenum.setToolTipText("");

        R_jTextField_phonenum.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        R_jTextField_phonenum.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                R_jTextField_phonenumjTextFieldFocusGained_Rname(evt);
            }
        });

        R_jComboBox_Sex.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "男", "女" }));
        R_jComboBox_Sex.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                R_jComboBox_SexActionPerformed(evt);
            }
        });

        R_jComboBox_type.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "消费者", "商家" }));

        R_Lable_usertype.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        R_Lable_usertype.setText("用户类型:");
        R_Lable_usertype.setToolTipText("");

        R_Lable_name1.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        R_Lable_name1.setText("性别:");
        R_Lable_name1.setToolTipText("");

        R_Lable_age.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        R_Lable_age.setText("年龄:");
        R_Lable_age.setToolTipText("");

        R_jTextField_age.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        R_jTextField_age.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                R_jTextField_agejTextFieldFocusGained_Rname(evt);
            }
        });

        R_jButton_register.setText("确认");
        R_jButton_register.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                R_jButton_registerActionPerformed(evt);
            }
        });

        R_jButton_cancle.setText("取消");
        R_jButton_cancle.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                R_jButton_cancleActionPerformed(evt);
            }
        });

        R_Lable_password1.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        R_Lable_password1.setText("密码:");
        R_Lable_password1.setToolTipText("");

        R_jPasswordField2.setText("        ");
        R_jPasswordField2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                R_jPasswordField2ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(56, 56, 56)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(R_Lable_name, javax.swing.GroupLayout.PREFERRED_SIZE, 57, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(R_Lable_usertype, javax.swing.GroupLayout.PREFERRED_SIZE, 57, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(R_jComboBox_type, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jTextField_name, javax.swing.GroupLayout.PREFERRED_SIZE, 148, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(R_Lable_name1, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(R_Lable_phonenum, javax.swing.GroupLayout.PREFERRED_SIZE, 57, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(R_Lable_password, javax.swing.GroupLayout.PREFERRED_SIZE, 57, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addComponent(R_jComboBox_Sex, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(R_Lable_age, javax.swing.GroupLayout.PREFERRED_SIZE, 43, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(R_jTextField_age, javax.swing.GroupLayout.PREFERRED_SIZE, 43, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(R_jPasswordField1)
                            .addComponent(R_jTextField_phonenum)))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(R_jButton_register)
                        .addGap(40, 40, 40)
                        .addComponent(R_jButton_cancle)
                        .addGap(13, 13, 13))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(R_Lable_password1, javax.swing.GroupLayout.PREFERRED_SIZE, 57, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(R_jPasswordField2)))
                .addGap(0, 97, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(29, 29, 29)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(R_jComboBox_type, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(R_Lable_usertype, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(R_Lable_name, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextField_name, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(R_Lable_password, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(R_jPasswordField1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(R_Lable_password1, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(R_jPasswordField2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(1, 1, 1)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(R_Lable_phonenum, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(R_jTextField_phonenum, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(R_jTextField_age, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 22, Short.MAX_VALUE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(R_jComboBox_Sex, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(R_Lable_age, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addComponent(R_Lable_name1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(27, 27, 27)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(R_jButton_register)
                    .addComponent(R_jButton_cancle))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void jTextFieldFocusGained_Rname(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jTextFieldFocusGained_Rname
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextFieldFocusGained_Rname

    private void R_jPasswordField1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_R_jPasswordField1ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_R_jPasswordField1ActionPerformed

    private void R_jTextField_phonenumjTextFieldFocusGained_Rname(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_R_jTextField_phonenumjTextFieldFocusGained_Rname
        // TODO add your handling code here:
    }//GEN-LAST:event_R_jTextField_phonenumjTextFieldFocusGained_Rname

    private void R_jTextField_agejTextFieldFocusGained_Rname(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_R_jTextField_agejTextFieldFocusGained_Rname
        // TODO add your handling code here:
    }//GEN-LAST:event_R_jTextField_agejTextFieldFocusGained_Rname

    private void R_jButton_cancleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_R_jButton_cancleActionPerformed
        // TODO add your handling code here:
        parent.setSize(330,250);
        parent.setVisible(true);
        
        frame.setSize(350,300);
        this.setVisible(false);
        parent.setVisible(true);
    }//GEN-LAST:event_R_jButton_cancleActionPerformed

    private void R_jButton_registerActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_R_jButton_registerActionPerformed
        // TODO add your handling code here:
        
        usrtype = (String) R_jComboBox_type.getSelectedItem();
        name = jTextField_name.getText();
        phonenum = R_jTextField_phonenum.getText();
        sex = String.valueOf(R_jComboBox_Sex.getSelectedItem());
        password1 = R_jPasswordField1.getText();
        password2 = R_jPasswordField2.getText();
        String stringage;
        stringage = R_jTextField_age.getText();
        age = Integer.valueOf(stringage);
        id = -1;
        if(!password1.equals(password2)){
            JOptionPane.showMessageDialog(null, "两次密码不一致");
        }else{
            if(usrtype.equals("消费者")){
                Customers customers;
                customers = new Customers(0, name, phonenum, sex, age, password1);
                try {
                    daoproxy.doCreateCustomer(customers);
                    id = daoproxy.getlastid();
                     JOptionPane.showMessageDialog(null, "注册成功,消费者id是"+id);
                } catch (Exception ex) {
                    Logger.getLogger(Register.class.getName()).log(Level.SEVERE, null, ex);
                     JOptionPane.showMessageDialog(null, "注册失败");
                     return;
                     
                }
                
            }
            else if(usrtype.equals("商家")){
                Sellers sellers;
              //  int sid, String sname, String phonenum, String sex, int age, String password, Collection<Product> product
                sellers = new Sellers(0, name, phonenum, sex, age, password1,null);
                try {
                    boolean ok = daoproxy.doCreateSeller(sellers);
                     id = daoproxy.getlastid();
                     JOptionPane.showMessageDialog(null, "注册成功,商家id是"+id);
                } catch (Exception ex) {
                    Logger.getLogger(Register.class.getName()).log(Level.SEVERE, null, ex);
                     JOptionPane.showMessageDialog(null, "注册失败");
                     return;
                }
            }
        }
        parent.setSize(330,250);
        parent.setVisible(true);
        frame.setSize(350,300);
        this.setVisible(false);
        parent.setVisible(true);
    }//GEN-LAST:event_R_jButton_registerActionPerformed

    private void R_jPasswordField2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_R_jPasswordField2ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_R_jPasswordField2ActionPerformed

    private void R_jComboBox_SexActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_R_jComboBox_SexActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_R_jComboBox_SexActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel R_Lable_age;
    private javax.swing.JLabel R_Lable_name;
    private javax.swing.JLabel R_Lable_name1;
    private javax.swing.JLabel R_Lable_password;
    private javax.swing.JLabel R_Lable_password1;
    private javax.swing.JLabel R_Lable_phonenum;
    private javax.swing.JLabel R_Lable_usertype;
    private javax.swing.JButton R_jButton_cancle;
    private javax.swing.JButton R_jButton_register;
    private javax.swing.JComboBox<String> R_jComboBox_Sex;
    private javax.swing.JComboBox<String> R_jComboBox_type;
    private javax.swing.JPasswordField R_jPasswordField1;
    private javax.swing.JPasswordField R_jPasswordField2;
    private javax.swing.JTextField R_jTextField_age;
    private javax.swing.JTextField R_jTextField_phonenum;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.ButtonGroup buttonGroup2;
    private javax.swing.JTextField jTextField_name;
    // End of variables declaration//GEN-END:variables
}
