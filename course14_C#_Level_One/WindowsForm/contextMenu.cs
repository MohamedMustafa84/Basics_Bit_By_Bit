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
    public partial class contextMenu : Form
    {
        public contextMenu()
        {
            InitializeComponent();
        }

        private void cmEnabelItem_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = true;

        }

        private void cmClear_Click(object sender, EventArgs e)
        {
            textBox1.Clear();

        }

        private void cmDisable_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = false;
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkVisited = true;
            System.Diagnostics.Process.Start("www.google.com");
        }

        private void InitializeComponent()
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form checkListBoxAndDateTimePiker = new checkListBox_DateTimePiker();

            checkListBoxAndDateTimePiker.ShowDialog();
        }
    }
}
