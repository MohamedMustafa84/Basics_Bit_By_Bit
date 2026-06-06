namespace PIZZA_ORDER
{
    partial class ListViewControll
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ListViewControll));
            listView1 = new ListView();
            imageList2 = new ImageList(components);
            imageList1 = new ImageList(components);
            label1 = new Label();
            txtID = new TextBox();
            label2 = new Label();
            txtUserName = new TextBox();
            gbGender = new GroupBox();
            rbFemale = new RadioButton();
            rbMale = new RadioButton();
            btnAddUser = new Button();
            btnRemove = new Button();
            btnFillRandom = new Button();
            groupBox1 = new GroupBox();
            rbTail = new RadioButton();
            rbList = new RadioButton();
            rbSmall = new RadioButton();
            btnLargeView = new RadioButton();
            gbGender.SuspendLayout();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // listView1
            // 
            listView1.LargeImageList = imageList2;
            listView1.Location = new Point(74, 203);
            listView1.Name = "listView1";
            listView1.Size = new Size(643, 235);
            listView1.SmallImageList = imageList1;
            listView1.TabIndex = 0;
            listView1.UseCompatibleStateImageBehavior = false;
            listView1.View = View.SmallIcon;
            // 
            // imageList2
            // 
            imageList2.ColorDepth = ColorDepth.Depth32Bit;
            imageList2.ImageStream = (ImageListStreamer)resources.GetObject("imageList2.ImageStream");
            imageList2.TransparentColor = Color.Transparent;
            imageList2.Images.SetKeyName(0, "1.jpg");
            imageList2.Images.SetKeyName(1, "11.jpg");
            // 
            // imageList1
            // 
            imageList1.ColorDepth = ColorDepth.Depth32Bit;
            imageList1.ImageStream = (ImageListStreamer)resources.GetObject("imageList1.ImageStream");
            imageList1.TransparentColor = Color.Transparent;
            imageList1.Images.SetKeyName(0, "1.jpg");
            imageList1.Images.SetKeyName(1, "WIN_14460307_11_26_22_Pro.jpg");
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(95, 27);
            label1.Name = "label1";
            label1.Size = new Size(44, 15);
            label1.TabIndex = 1;
            label1.Text = "User ID";
            // 
            // txtID
            // 
            txtID.Location = new Point(150, 27);
            txtID.Name = "txtID";
            txtID.Size = new Size(100, 23);
            txtID.TabIndex = 2;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(74, 58);
            label2.Name = "label2";
            label2.Size = new Size(65, 15);
            label2.TabIndex = 3;
            label2.Text = "User Name";
            // 
            // txtUserName
            // 
            txtUserName.Location = new Point(150, 58);
            txtUserName.Name = "txtUserName";
            txtUserName.Size = new Size(100, 23);
            txtUserName.TabIndex = 4;
            // 
            // gbGender
            // 
            gbGender.Controls.Add(rbFemale);
            gbGender.Controls.Add(rbMale);
            gbGender.Location = new Point(74, 106);
            gbGender.Name = "gbGender";
            gbGender.Size = new Size(200, 70);
            gbGender.TabIndex = 5;
            gbGender.TabStop = false;
            gbGender.Text = "Gender :";
            // 
            // rbFemale
            // 
            rbFemale.AutoSize = true;
            rbFemale.Location = new Point(112, 34);
            rbFemale.Name = "rbFemale";
            rbFemale.Size = new Size(63, 19);
            rbFemale.TabIndex = 1;
            rbFemale.Tag = "Female";
            rbFemale.Text = "Female";
            rbFemale.UseVisualStyleBackColor = true;
            // 
            // rbMale
            // 
            rbMale.AutoSize = true;
            rbMale.Checked = true;
            rbMale.Location = new Point(31, 34);
            rbMale.Name = "rbMale";
            rbMale.Size = new Size(51, 19);
            rbMale.TabIndex = 0;
            rbMale.TabStop = true;
            rbMale.Tag = "Male";
            rbMale.Text = "Male";
            rbMale.UseVisualStyleBackColor = true;
            // 
            // btnAddUser
            // 
            btnAddUser.Location = new Point(444, 23);
            btnAddUser.Name = "btnAddUser";
            btnAddUser.Size = new Size(75, 23);
            btnAddUser.TabIndex = 6;
            btnAddUser.Text = "Add ";
            btnAddUser.UseVisualStyleBackColor = true;
            btnAddUser.Click += btnAddUser_Click;
            // 
            // btnRemove
            // 
            btnRemove.Location = new Point(544, 27);
            btnRemove.Name = "btnRemove";
            btnRemove.Size = new Size(75, 23);
            btnRemove.TabIndex = 7;
            btnRemove.Text = "Remove";
            btnRemove.UseVisualStyleBackColor = true;
            btnRemove.Click += btnRemove_Click;
            // 
            // btnFillRandom
            // 
            btnFillRandom.Location = new Point(636, 26);
            btnFillRandom.Name = "btnFillRandom";
            btnFillRandom.Size = new Size(105, 23);
            btnFillRandom.TabIndex = 8;
            btnFillRandom.Text = "Fill Random";
            btnFillRandom.UseVisualStyleBackColor = true;
            btnFillRandom.Click += btnFillRandom_Click;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(rbTail);
            groupBox1.Controls.Add(rbList);
            groupBox1.Controls.Add(rbSmall);
            groupBox1.Controls.Add(btnLargeView);
            groupBox1.Location = new Point(398, 76);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(390, 100);
            groupBox1.TabIndex = 9;
            groupBox1.TabStop = false;
            groupBox1.Text = "View :";
            // 
            // rbTail
            // 
            rbTail.AutoSize = true;
            rbTail.Location = new Point(238, 30);
            rbTail.Name = "rbTail";
            rbTail.Size = new Size(42, 19);
            rbTail.TabIndex = 3;
            rbTail.Text = "Tail";
            rbTail.UseVisualStyleBackColor = true;
            rbTail.CheckedChanged += rbTail_CheckedChanged;
            // 
            // rbList
            // 
            rbList.AutoSize = true;
            rbList.Location = new Point(180, 30);
            rbList.Name = "rbList";
            rbList.Size = new Size(43, 19);
            rbList.TabIndex = 2;
            rbList.Text = "List";
            rbList.UseVisualStyleBackColor = true;
            rbList.CheckedChanged += rbList_CheckedChanged;
            // 
            // rbSmall
            // 
            rbSmall.AutoSize = true;
            rbSmall.Checked = true;
            rbSmall.Location = new Point(20, 30);
            rbSmall.Name = "rbSmall";
            rbSmall.Size = new Size(54, 19);
            rbSmall.TabIndex = 1;
            rbSmall.TabStop = true;
            rbSmall.Text = "Small";
            rbSmall.UseVisualStyleBackColor = true;
            rbSmall.CheckedChanged += rbSmall_CheckedChanged;
            // 
            // btnLargeView
            // 
            btnLargeView.AutoSize = true;
            btnLargeView.Location = new Point(107, 30);
            btnLargeView.Name = "btnLargeView";
            btnLargeView.Size = new Size(54, 19);
            btnLargeView.TabIndex = 0;
            btnLargeView.Text = "Large";
            btnLargeView.UseVisualStyleBackColor = true;
            btnLargeView.CheckedChanged += btnLargeView_CheckedChanged;
            // 
            // ListViewControll
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(groupBox1);
            Controls.Add(btnFillRandom);
            Controls.Add(btnRemove);
            Controls.Add(btnAddUser);
            Controls.Add(gbGender);
            Controls.Add(txtUserName);
            Controls.Add(label2);
            Controls.Add(txtID);
            Controls.Add(label1);
            Controls.Add(listView1);
            Name = "ListViewControll";
            Text = "ListViewControll";
            gbGender.ResumeLayout(false);
            gbGender.PerformLayout();
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListView listView1;
        private Label label1;
        private TextBox txtID;
        private Label label2;
        private TextBox txtUserName;
        private GroupBox gbGender;
        private RadioButton rbFemale;
        private RadioButton rbMale;
        private Button btnAddUser;
        private ImageList imageList1;
        private ImageList imageList2;
        private Button btnRemove;
        private Button btnFillRandom;
        private GroupBox groupBox1;
        private RadioButton btnLargeView;
        private RadioButton rbSmall;
        private RadioButton rbTail;
        private RadioButton rbList;
    }
}