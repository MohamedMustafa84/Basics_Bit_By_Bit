using ContactsBusinessLayer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ContactsWindowsForms
{
    public partial class FrmAddEditContact: Form
    {

        ClsContact.enMode _Mode;
        int _ContactID =-1;
         public ClsContact _Contact;
        public FrmAddEditContact(int ContactID)
        {  

            _ContactID = ContactID;

            if (_ContactID ==-1)
            {
                _Mode = ClsContact.enMode.AddNew;
            }
            else
            {
                _Mode = ClsContact.enMode.Update; 

            }

            InitializeComponent();

        }


        private void _FillCountriesInComboBox()
        {
            DataTable dtCountries = ClsContact.clsCountries.GetAllCountries();

            foreach( DataRow Row in dtCountries.Rows)
            {
                cbCountry.Items.Add(Row["CountryName"]);
            }
        }

        private void _loadData()
        {
            _FillCountriesInComboBox();

            cbCountry.SelectedIndex = 0;

            if(_Mode == ClsContact.enMode.AddNew)
            {
                lbMode.Text = "Add New Contact";
                _Contact = new ClsContact();
                return;
            }

            _Contact = ClsContact.Find(_ContactID);

            if( _Contact == null )
            {
                MessageBox.Show("this form will be close because no contact  with this ID");

                this.Close();
                return;
            }


            lbMode.Text = $"Edit Contact ID {_ContactID}";
            lbContactID.Text = _ContactID.ToString();
            tbFirstName.Text = _Contact.FirstName;
            tbLastName.Text = _Contact.LastName;
            tbEmail.Text = _Contact.Email;
            tbPhone.Text = _Contact.Phone;
            dtDateOfBirth.Value = _Contact.DateOfBirth;

            if(_Contact.ImagePath != "")
            {
                picureBox1.Load(_Contact.ImagePath);
            }

            btnRemoveImage.Visible = _Contact.ImagePath != "";

            cbCountry.SelectedIndex = cbCountry.FindString( ClsContact.clsCountries.FindCountryByID(_ContactID).CountryName);

        }

        private void FrmAddEditContact_Load(object sender, EventArgs e)
        {
            _loadData();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            int CountryID = ClsContact.clsCountries.FindCountryByName(cbCountry.Text);

            _Contact.FirstName = tbFirstName.Text;
            _Contact.LastName = tbLastName.Text;
            _Contact.Email = tbEmail.Text;
            _Contact.Phone = tbPhone.Text;
            _Contact.Address = tbAddress.Text;
            _Contact.DateOfBirth = dtDateOfBirth.Value;
            _Contact.CountryID = CountryID;

            if (picureBox1.ImageLocation != null)
                _Contact.ImagePath = picureBox1.ImageLocation;
            else
                _Contact.ImagePath = "";

            if (_Contact.Save())
                MessageBox.Show("Data Saved Successfully.");
            else
                MessageBox.Show("Error: Data Is not Saved Successfully.");

            _Mode = ClsContact.enMode.Update;
            lbMode.Text = "Edit Contact ID = " + _Contact.ID;
            lbContactID.Text = _Contact.ID.ToString();

        }

        private void btnRemoveImage_Click(object sender, EventArgs e)
        {
            _Contact.ImagePath = "";
            picureBox1.ImageLocation ="";
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
