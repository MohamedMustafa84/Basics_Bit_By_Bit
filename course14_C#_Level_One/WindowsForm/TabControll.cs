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
    public partial class TabControll : Form
    {
        public TabControll()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.BackColor = colorDialog1.Color;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            fontDialog1.ShowColor = true;

            fontDialog1.ShowApply = true;
            fontDialog1.ShowEffects = true;

            fontDialog1.ShowHelp = true;

            fontDialog1.Font = label1.Font;

            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                label1.Font = fontDialog1.Font;
                label1.ForeColor = fontDialog1.Color;
            }
        }



        private void fontDialog1_Apply_1(object sender, EventArgs e)
        {
            label1.Font = fontDialog1.Font;
            label1.ForeColor = fontDialog1.Color;

        }
    }
}
