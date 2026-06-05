using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PIZZA_ORDER
{
    public partial class TreeViewAndImageList : Form
    {
        public TreeViewAndImageList()
        {
            InitializeComponent();
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            MessageBox.Show(" This Message After Select Node");

        }

        private void k(object sender, KeyEventArgs e)
        {
            MessageBox.Show(" This Message After Select Node");

        }

        private void treeView1_DoubleClick(object sender, EventArgs e)
        {
            MessageBox.Show(treeView1.SelectedNode.Text);
        }


        private void checkTreeViewNode(TreeNode Node, Boolean isChecked)
        {

            foreach (TreeNode item in Node.Nodes)
            {
                item.Checked = isChecked;

                if (item.Nodes.Count > 0)
                {
                    this.checkTreeViewNode(Node, isChecked);
                }


            }
        }

        private void treeView1_AfterCheck(object sender, TreeViewEventArgs e)
        {
            //checkTreeViewNode(e.Node, e.Node.Checked);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            progressBar1.Value = 0;
            progressBar1.Minimum = 0;
            progressBar1.Maximum = 100;


            for (int i = 0; i <=10; i++)
            {

                if (progressBar1.Value < progressBar1.Maximum)
                {
                    Thread.Sleep(500);

                    progressBar1.Value += 10;

                    label1.Text = ((float)progressBar1.Value / progressBar1.Maximum )*100 + " %";

                    label1.Refresh();
                    progressBar1.Refresh();


                }
                else
                {
                    button1.Enabled = false;
                }
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            label1.Text = "";
            progressBar1.Value = 0;
            button1.Enabled = true;
        }

        
    }
}
