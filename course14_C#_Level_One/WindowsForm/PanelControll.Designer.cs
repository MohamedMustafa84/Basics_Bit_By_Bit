namespace PIZZA_ORDER
{
    partial class PanelControll
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
            panel1 = new Panel();
            maskedTextBox11 = new MaskedTextBox();
            maskedTextBox10 = new MaskedTextBox();
            maskedTextBox9 = new MaskedTextBox();
            maskedTextBox8 = new MaskedTextBox();
            maskedTextBox7 = new MaskedTextBox();
            maskedTextBox6 = new MaskedTextBox();
            maskedTextBox5 = new MaskedTextBox();
            maskedTextBox4 = new MaskedTextBox();
            maskedTextBox3 = new MaskedTextBox();
            maskedTextBox2 = new MaskedTextBox();
            maskedTextBox1 = new MaskedTextBox();
            comboBox1 = new ComboBox();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.AutoScroll = true;
            panel1.Controls.Add(maskedTextBox11);
            panel1.Controls.Add(maskedTextBox10);
            panel1.Controls.Add(maskedTextBox9);
            panel1.Controls.Add(maskedTextBox8);
            panel1.Controls.Add(maskedTextBox7);
            panel1.Controls.Add(maskedTextBox6);
            panel1.Controls.Add(maskedTextBox5);
            panel1.Controls.Add(maskedTextBox4);
            panel1.Controls.Add(maskedTextBox3);
            panel1.Controls.Add(maskedTextBox2);
            panel1.Controls.Add(maskedTextBox1);
            panel1.Location = new Point(211, 64);
            panel1.Name = "panel1";
            panel1.Size = new Size(391, 425);
            panel1.TabIndex = 0;
            // 
            // maskedTextBox11
            // 
            maskedTextBox11.Location = new Point(274, 176);
            maskedTextBox11.Mask = "00000-9999";
            maskedTextBox11.Name = "maskedTextBox11";
            maskedTextBox11.Size = new Size(100, 23);
            maskedTextBox11.TabIndex = 9;
            // 
            // maskedTextBox10
            // 
            maskedTextBox10.Location = new Point(274, 120);
            maskedTextBox10.Mask = "90:00";
            maskedTextBox10.Name = "maskedTextBox10";
            maskedTextBox10.Size = new Size(100, 23);
            maskedTextBox10.TabIndex = 8;
            maskedTextBox10.ValidatingType = typeof(DateTime);
            // 
            // maskedTextBox9
            // 
            maskedTextBox9.Location = new Point(274, 56);
            maskedTextBox9.Mask = "90:00";
            maskedTextBox9.Name = "maskedTextBox9";
            maskedTextBox9.Size = new Size(100, 23);
            maskedTextBox9.TabIndex = 7;
            maskedTextBox9.ValidatingType = typeof(DateTime);
            // 
            // maskedTextBox8
            // 
            maskedTextBox8.Location = new Point(145, 223);
            maskedTextBox8.Mask = "00:00";
            maskedTextBox8.Name = "maskedTextBox8";
            maskedTextBox8.Size = new Size(100, 23);
            maskedTextBox8.TabIndex = 3;
            maskedTextBox8.ValidatingType = typeof(DateTime);
            // 
            // maskedTextBox7
            // 
            maskedTextBox7.Location = new Point(157, 158);
            maskedTextBox7.Mask = "00/00/0000 90:00";
            maskedTextBox7.Name = "maskedTextBox7";
            maskedTextBox7.Size = new Size(100, 23);
            maskedTextBox7.TabIndex = 6;
            maskedTextBox7.ValidatingType = typeof(DateTime);
            // 
            // maskedTextBox6
            // 
            maskedTextBox6.Location = new Point(145, 120);
            maskedTextBox6.Mask = "00/00/0000";
            maskedTextBox6.Name = "maskedTextBox6";
            maskedTextBox6.Size = new Size(100, 23);
            maskedTextBox6.TabIndex = 5;
            maskedTextBox6.ValidatingType = typeof(DateTime);
            // 
            // maskedTextBox5
            // 
            maskedTextBox5.Location = new Point(31, 223);
            maskedTextBox5.Mask = "00000-9999";
            maskedTextBox5.Name = "maskedTextBox5";
            maskedTextBox5.Size = new Size(100, 23);
            maskedTextBox5.TabIndex = 4;
            // 
            // maskedTextBox4
            // 
            maskedTextBox4.Location = new Point(20, 90);
            maskedTextBox4.Mask = "(999) 000-0000";
            maskedTextBox4.Name = "maskedTextBox4";
            maskedTextBox4.Size = new Size(100, 23);
            maskedTextBox4.TabIndex = 3;
            // 
            // maskedTextBox3
            // 
            maskedTextBox3.Location = new Point(31, 158);
            maskedTextBox3.Mask = "00000";
            maskedTextBox3.Name = "maskedTextBox3";
            maskedTextBox3.Size = new Size(100, 23);
            maskedTextBox3.TabIndex = 2;
            maskedTextBox3.ValidatingType = typeof(int);
            // 
            // maskedTextBox2
            // 
            maskedTextBox2.Location = new Point(145, 72);
            maskedTextBox2.Mask = "000-0000";
            maskedTextBox2.Name = "maskedTextBox2";
            maskedTextBox2.Size = new Size(100, 23);
            maskedTextBox2.TabIndex = 1;
            // 
            // maskedTextBox1
            // 
            maskedTextBox1.Location = new Point(31, 32);
            maskedTextBox1.Mask = "00:00";
            maskedTextBox1.Name = "maskedTextBox1";
            maskedTextBox1.Size = new Size(100, 23);
            maskedTextBox1.TabIndex = 0;
            maskedTextBox1.ValidatingType = typeof(DateTime);
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { "Option 1", "Option2", "Option3", "Option4", "Option5" });
            comboBox1.Location = new Point(613, 348);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(121, 23);
            comboBox1.TabIndex = 10;
            comboBox1.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            // 
            // PanelControll
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(comboBox1);
            Controls.Add(panel1);
            Name = "PanelControll";
            Text = "PanelControll";
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private Panel panel1;
        private MaskedTextBox maskedTextBox1;
        private MaskedTextBox maskedTextBox4;
        private MaskedTextBox maskedTextBox3;
        private MaskedTextBox maskedTextBox2;
        private MaskedTextBox maskedTextBox5;
        private MaskedTextBox maskedTextBox11;
        private MaskedTextBox maskedTextBox10;
        private MaskedTextBox maskedTextBox9;
        private MaskedTextBox maskedTextBox8;
        private MaskedTextBox maskedTextBox7;
        private MaskedTextBox maskedTextBox6;
        private ComboBox comboBox1;
    }
}