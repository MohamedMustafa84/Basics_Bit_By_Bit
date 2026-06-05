namespace PIZZA_ORDER
{
    partial class ErrorProviderAndTrakBar
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
            errorProvider1 = new ErrorProvider(components);
            txtFistName = new TextBox();
            txtLastName = new TextBox();
            textBox3 = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            trackBar1 = new TrackBar();
            lbtrakBarValue = new Label();
            numericUpDown1 = new NumericUpDown();
            lbNumericUpdown = new Label();
            ((System.ComponentModel.ISupportInitialize)errorProvider1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)trackBar1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown1).BeginInit();
            SuspendLayout();
            // 
            // errorProvider1
            // 
            errorProvider1.ContainerControl = this;
            // 
            // txtFistName
            // 
            txtFistName.Location = new Point(215, 32);
            txtFistName.Name = "txtFistName";
            txtFistName.Size = new Size(100, 23);
            txtFistName.TabIndex = 0;
            txtFistName.Validating += textBox1_Validating;
            // 
            // txtLastName
            // 
            txtLastName.Location = new Point(215, 155);
            txtLastName.Name = "txtLastName";
            txtLastName.Size = new Size(100, 23);
            txtLastName.TabIndex = 1;
            txtLastName.Validating += txtLastName_Validating;
            // 
            // textBox3
            // 
            textBox3.Location = new Point(215, 94);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(100, 23);
            textBox3.TabIndex = 2;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(145, 35);
            label1.Name = "label1";
            label1.Size = new Size(64, 15);
            label1.TabIndex = 3;
            label1.Text = "First Name";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(145, 94);
            label2.Name = "label2";
            label2.Size = new Size(66, 15);
            label2.TabIndex = 4;
            label2.Text = "Med Name";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(145, 163);
            label3.Name = "label3";
            label3.Size = new Size(63, 15);
            label3.TabIndex = 5;
            label3.Text = "Last Name";
            // 
            // trackBar1
            // 
            trackBar1.LargeChange = 3;
            trackBar1.Location = new Point(337, 204);
            trackBar1.Name = "trackBar1";
            trackBar1.Size = new Size(406, 45);
            trackBar1.TabIndex = 6;
            trackBar1.Scroll += trackBar1_Scroll;
            // 
            // lbtrakBarValue
            // 
            lbtrakBarValue.AutoSize = true;
            lbtrakBarValue.Location = new Point(506, 163);
            lbtrakBarValue.Name = "lbtrakBarValue";
            lbtrakBarValue.Size = new Size(0, 15);
            lbtrakBarValue.TabIndex = 7;
            // 
            // numericUpDown1
            // 
            numericUpDown1.Location = new Point(486, 86);
            numericUpDown1.Name = "numericUpDown1";
            numericUpDown1.Size = new Size(140, 23);
            numericUpDown1.TabIndex = 8;
            numericUpDown1.ValueChanged += numericUpDown1_ValueChanged;
            // 
            // lbNumericUpdown
            // 
            lbNumericUpdown.AutoSize = true;
            lbNumericUpdown.Location = new Point(525, 40);
            lbNumericUpdown.Name = "lbNumericUpdown";
            lbNumericUpdown.Size = new Size(0, 15);
            lbNumericUpdown.TabIndex = 9;
            // 
            // ErrorProviderAndTrakBar
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(lbNumericUpdown);
            Controls.Add(numericUpDown1);
            Controls.Add(lbtrakBarValue);
            Controls.Add(trackBar1);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(textBox3);
            Controls.Add(txtLastName);
            Controls.Add(txtFistName);
            Name = "ErrorProviderAndTrakBar";
            Text = "ErorrProviderControll";
            ((System.ComponentModel.ISupportInitialize)errorProvider1).EndInit();
            ((System.ComponentModel.ISupportInitialize)trackBar1).EndInit();
            ((System.ComponentModel.ISupportInitialize)numericUpDown1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ErrorProvider errorProvider1;
        private Label label3;
        private Label label2;
        private Label label1;
        private TextBox textBox3;
        private TextBox txtLastName;
        private TextBox txtFistName;
        private TrackBar trackBar1;
        private Label lbtrakBarValue;
        private Label lbNumericUpdown;
        private NumericUpDown numericUpDown1;
    }
}