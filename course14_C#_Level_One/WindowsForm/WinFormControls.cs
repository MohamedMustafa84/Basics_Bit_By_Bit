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
    public partial class WinFormControls : Form
    {
        public WinFormControls()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form DateTimePicker = new DateTimePickerAndMonthCalender();

            DateTimePicker.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form TreeViewAndImageList = new TreeViewAndImageList();

            TreeViewAndImageList.Show();

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form errorProviderAndTrakBar = new ErrorProviderAndTrakBar();

            errorProviderAndTrakBar.Show();

        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form TabControll1 = new TabControll();

            TabControll1.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Form ListView = new ListViewControll();
            ListView.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form panelControll = new PanelControll();

            panelControll.Show();
        }
    }
}
