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
    public partial class checkListBox_DateTimePiker : Form
    {
        public checkListBox_DateTimePiker()
        {
            InitializeComponent();
        }


        private void button1_Click(object sender, EventArgs e)
        {

            for (int i = 1; i <= 5; i++)
            {
                checkedListBox1.Items.Add("Item" + i);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < checkedListBox1.CheckedItems.Count; i++)
            {
                MessageBox.Show(checkedListBox1.Items[i].ToString());

            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < checkedListBox1.Items.Count; i++)
            {
                checkedListBox1.SetSelected(i, true);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < checkedListBox1.Items.Count; i++)
            {
                checkedListBox1.SetSelected(i, false);
            }

        }

        private void button5_Click(object sender, EventArgs e)
        {
            checkedListBox1.Items.Clear();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            checkedListBox1.Items.RemoveAt(2);
        }
    }
}
