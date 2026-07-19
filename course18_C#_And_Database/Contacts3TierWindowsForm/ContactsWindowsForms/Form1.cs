using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ContactsBusinessLayer;

namespace ContactsWindowsForms
{
    public partial class FrmListContact : Form
    {
        public FrmListContact()
        {
            InitializeComponent();
        }

        private void _RefreshContactsList()
        {
            DgvAllContacts.DataSource = ClsContact.GetContactsList();
        }

        private void FrmListContact_Load(object sender, EventArgs e)
        {
            _RefreshContactsList();

        }





        private void btnAddNewContact_Click(object sender, EventArgs e)
        {
              FrmAddEditContact frmAddContact = new FrmAddEditContact(-1);


            frmAddContact.ShowDialog();
            _RefreshContactsList();

        }

        private void CmsEditContact_Click(object sender, EventArgs e)
        {
            FrmAddEditContact frmEditontactInfo = new FrmAddEditContact((int)DgvAllContacts.CurrentRow.Cells[0].Value);


            frmEditontactInfo.ShowDialog();
            _RefreshContactsList();

        }

        private void CmsDeleteContact_Click(object sender, EventArgs e)
        {

            if ((MessageBox.Show($"Are You Sure  You Want To Delete Contact With ID : {(int)(DgvAllContacts.CurrentRow.Cells[0].Value)}") ==DialogResult.OK ))
            {
                if (ClsContact.DeleteContact((int)(DgvAllContacts.CurrentRow.Cells[0].Value)))
                {
                    MessageBox.Show("Contact Deleted Successfully :)");
                    _RefreshContactsList();
                }
                else
                {
                    MessageBox.Show("Unable To Delete the contact :(");

                }
            }
        }
    }
}
