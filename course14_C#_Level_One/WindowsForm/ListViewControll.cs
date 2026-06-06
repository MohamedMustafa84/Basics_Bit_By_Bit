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
    public partial class ListViewControll : Form
    {
        public ListViewControll()
        {
            InitializeComponent();
        }

        private void btnAddUser_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(txtID.Text) || string.IsNullOrEmpty(txtUserName.Text))
            {
                MessageBox.Show("Empty ID OR User Name ");

                return;
            }


            ListViewItem Item = new ListViewItem(txtID.Text.Trim());

            if (rbMale.Checked)
            {
                Item.ImageIndex = 0;
            }
            else
            {
                Item.ImageIndex = 1;
            }

            Item.SubItems.Add(txtUserName.Text.Trim());

            listView1.Items.Add(Item);

            txtID.Clear();
            txtUserName.Clear();

            txtID.Focus();
        }

        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (listView1.Items.Count > 0)
            {
                listView1.Items.Remove(listView1.SelectedItems[0]);
            }
        }

        private void btnFillRandom_Click(object sender, EventArgs e)
        {
            for (int i = 1; i <= 10; i++)
            {
                ListViewItem Item = new ListViewItem(i.ToString());

                if (i % 2 == 0)
                {
                    Item.ImageIndex = 0;
                    Item.SubItems.Add("Male" + i);
                }
                else
                {
                    Item.ImageIndex = 1;
                    Item.SubItems.Add("Female" + i);
                }

                listView1.Items.Add(Item);


            }

        }


        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.SmallIcon;
        }

        private void btnLargeView_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.LargeIcon;

        }

        private void rbList_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.List;
        }

        private void rbTail_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.Tile;
        }

    }
}
