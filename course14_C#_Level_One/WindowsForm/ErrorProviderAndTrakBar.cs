using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PIZZA_ORDER
{
    public partial class ErrorProviderAndTrakBar : Form
    {
        public ErrorProviderAndTrakBar()
        {
            InitializeComponent();
        }

        private void textBox1_Validating(object sender, CancelEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtFistName.Text))
            {
                e.Cancel = true;

                txtFistName.Focus();

                errorProvider1.SetError(txtFistName, "The First Name Should have a Value ! ");

            }
            else
            {
                e.Cancel = false;
                errorProvider1.SetError(txtFistName, "");
            }
        }

        private void txtLastName_Validating(object sender, CancelEventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtLastName.Text))
            {
                e.Cancel = true;

                txtFistName.Focus();

                errorProvider1.SetError(txtLastName, "The Last Name Should have a Value ! ");

            }
            else
            {
                e.Cancel = false;
                errorProvider1.SetError(txtLastName, "");
            }
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            lbtrakBarValue.Text = trackBar1.Value.ToString();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            lbNumericUpdown.Text = numericUpDown1.Value.ToString();
        }
    }
}
