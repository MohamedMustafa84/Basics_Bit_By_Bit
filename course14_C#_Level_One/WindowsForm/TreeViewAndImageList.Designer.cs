namespace PIZZA_ORDER
{
    partial class TreeViewAndImageList
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) 
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TreeViewAndImageList));
            TreeNode treeNode1 = new TreeNode("Node3");
            TreeNode treeNode2 = new TreeNode("Node1", new TreeNode[] { treeNode1 });
            TreeNode treeNode3 = new TreeNode("Node2");
            TreeNode treeNode4 = new TreeNode("Node0", new TreeNode[] { treeNode2, treeNode3 });
            TreeNode treeNode5 = new TreeNode("Node4");
            TreeNode treeNode6 = new TreeNode("Node5");
            TreeNode treeNode7 = new TreeNode("Node7");
            TreeNode treeNode8 = new TreeNode("Node6", new TreeNode[] { treeNode7 });
            TreeNode treeNode9 = new TreeNode("Node9");
            TreeNode treeNode10 = new TreeNode("Node10");
            TreeNode treeNode11 = new TreeNode("Node11");
            TreeNode treeNode12 = new TreeNode("Node12");
            TreeNode treeNode13 = new TreeNode("Node8", new TreeNode[] { treeNode9, treeNode10, treeNode11, treeNode12 });
            TreeNode treeNode14 = new TreeNode("Node13");
            imageList1 = new ImageList(components);
            treeView1 = new TreeView();
            progressBar1 = new ProgressBar();
            label1 = new Label();
            button1 = new Button();
            button3 = new Button();
            SuspendLayout();
            // 
            // imageList1
            // 
            imageList1.ColorDepth = ColorDepth.Depth32Bit;
            imageList1.ImageStream = (ImageListStreamer)resources.GetObject("imageList1.ImageStream");
            imageList1.TransparentColor = Color.Transparent;
            imageList1.Images.SetKeyName(0, "chatgpt.png");
            imageList1.Images.SetKeyName(1, "me.jpg");
            imageList1.Images.SetKeyName(2, "sinjouner.png");
            imageList1.Images.SetKeyName(3, "chatgpt.png");
            // 
            // treeView1
            // 
            treeView1.CheckBoxes = true;
            treeView1.ImageIndex = 1;
            treeView1.ImageList = imageList1;
            treeView1.Location = new Point(51, 39);
            treeView1.Name = "treeView1";
            treeNode1.Name = "Node3";
            treeNode1.Text = "Node3";
            treeNode2.Checked = true;
            treeNode2.ImageIndex = 3;
            treeNode2.Name = "Node1";
            treeNode2.Text = "Node1";
            treeNode3.Name = "Node2";
            treeNode3.Text = "Node2";
            treeNode4.Checked = true;
            treeNode4.Name = "Node0";
            treeNode4.Text = "Node0";
            treeNode5.ImageIndex = 2;
            treeNode5.Name = "Node4";
            treeNode5.Text = "Node4";
            treeNode6.Name = "Node5";
            treeNode6.Text = "Node5";
            treeNode7.Name = "Node7";
            treeNode7.Text = "Node7";
            treeNode8.Name = "Node6";
            treeNode8.Text = "Node6";
            treeNode9.Name = "Node9";
            treeNode9.Text = "Node9";
            treeNode10.Name = "Node10";
            treeNode10.Text = "Node10";
            treeNode11.Name = "Node11";
            treeNode11.Text = "Node11";
            treeNode12.Name = "Node12";
            treeNode12.Text = "Node12";
            treeNode13.Name = "Node8";
            treeNode13.Text = "Node8";
            treeNode14.Name = "Node13";
            treeNode14.Text = "Node13";
            treeView1.Nodes.AddRange(new TreeNode[] { treeNode4, treeNode5, treeNode6, treeNode8, treeNode13, treeNode14 });
            treeView1.SelectedImageKey = "chatgpt.png";
            treeView1.Size = new Size(391, 235);
            treeView1.TabIndex = 0;
            treeView1.AfterCheck += treeView1_AfterCheck;
            treeView1.AfterSelect += treeView1_AfterSelect;
            treeView1.DoubleClick += treeView1_DoubleClick;
            treeView1.KeyDown += k;
            // 
            // progressBar1
            // 
            progressBar1.Location = new Point(490, 119);
            progressBar1.Name = "progressBar1";
            progressBar1.Size = new Size(237, 34);
            progressBar1.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI Semibold", 14.25F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label1.Location = new Point(567, 77);
            label1.Name = "label1";
            label1.Size = new Size(61, 25);
            label1.TabIndex = 2;
            label1.Text = "label1";
            // 
            // button1
            // 
            button1.Location = new Point(490, 171);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 3;
            button1.Text = "Start";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button3
            // 
            button3.Location = new Point(586, 171);
            button3.Name = "button3";
            button3.Size = new Size(141, 23);
            button3.TabIndex = 5;
            button3.Text = "Reset Progress Bar";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // TreeViewAndImageList
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(button3);
            Controls.Add(button1);
            Controls.Add(label1);
            Controls.Add(progressBar1);
            Controls.Add(treeView1);
            Name = "TreeViewAndImageList";
            Text = "TreeViewAndImageList";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ImageList imageList1;
        private TreeView treeView1;
        private ProgressBar progressBar1;
        private Label label1;
        private Button button1;
        private Button button3;
    }
}