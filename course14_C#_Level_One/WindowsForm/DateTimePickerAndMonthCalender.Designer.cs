namespace PIZZA_ORDER
{
    partial class DateTimePickerAndMonthCalender
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
            dateTimePicker1 = new DateTimePicker();
            button1 = new Button();
            DateTimeFormate = new Label();
            lbDateTimePickerFormat = new Label();
            monthCalendar1 = new MonthCalendar();
            button3 = new Button();
            button4 = new Button();
            button2 = new Button();
            tAthkarTimer = new System.Windows.Forms.Timer(components);
            lbAthkar = new Label();
            button5 = new Button();
            button6 = new Button();
            tBlankTimer = new System.Windows.Forms.Timer(components);
            notifyIcon1 = new NotifyIcon(components);
            button7 = new Button();
            SuspendLayout();
            // 
            // dateTimePicker1
            // 
            dateTimePicker1.CustomFormat = " ";
            dateTimePicker1.Location = new Point(12, 28);
            dateTimePicker1.Name = "dateTimePicker1";
            dateTimePicker1.Size = new Size(200, 23);
            dateTimePicker1.TabIndex = 0;
            dateTimePicker1.ValueChanged += dateTimePicker1_ValueChanged;
            // 
            // button1
            // 
            button1.Location = new Point(27, 100);
            button1.Name = "button1";
            button1.Size = new Size(148, 23);
            button1.TabIndex = 1;
            button1.Text = "show Short Date";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // DateTimeFormate
            // 
            DateTimeFormate.AutoSize = true;
            DateTimeFormate.Location = new Point(348, 55);
            DateTimeFormate.Name = "DateTimeFormate";
            DateTimeFormate.Size = new Size(0, 15);
            DateTimeFormate.TabIndex = 2;
            // 
            // lbDateTimePickerFormat
            // 
            lbDateTimePickerFormat.AutoSize = true;
            lbDateTimePickerFormat.Location = new Point(272, 64);
            lbDateTimePickerFormat.Name = "lbDateTimePickerFormat";
            lbDateTimePickerFormat.Size = new Size(38, 15);
            lbDateTimePickerFormat.TabIndex = 3;
            lbDateTimePickerFormat.Text = "label1";
            // 
            // monthCalendar1
            // 
            monthCalendar1.Location = new Point(425, 28);
            monthCalendar1.Name = "monthCalendar1";
            monthCalendar1.TabIndex = 4;
            // 
            // button3
            // 
            button3.Location = new Point(566, 270);
            button3.Name = "button3";
            button3.Size = new Size(86, 23);
            button3.TabIndex = 6;
            button3.Text = "Start ";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button4
            // 
            button4.Location = new Point(684, 270);
            button4.Name = "button4";
            button4.Size = new Size(104, 23);
            button4.TabIndex = 7;
            button4.Text = "End";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // button2
            // 
            button2.Location = new Point(415, 270);
            button2.Name = "button2";
            button2.Size = new Size(105, 23);
            button2.TabIndex = 9;
            button2.Text = "selected Range";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // tAthkarTimer
            // 
            tAthkarTimer.Interval = 1000;
            tAthkarTimer.Tick += TAthkarTimer_Tick;
            // 
            // lbAthkar
            // 
            lbAthkar.AutoSize = true;
            lbAthkar.Font = new Font("Segoe UI", 18F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lbAthkar.Location = new Point(159, 194);
            lbAthkar.Name = "lbAthkar";
            lbAthkar.Size = new Size(67, 32);
            lbAthkar.TabIndex = 10;
            lbAthkar.Text = "اذكار ";
            // 
            // button5
            // 
            button5.Location = new Point(61, 270);
            button5.Name = "button5";
            button5.Size = new Size(86, 23);
            button5.TabIndex = 11;
            button5.Text = "ابدأ";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button6
            // 
            button6.Location = new Point(209, 270);
            button6.Name = "button6";
            button6.Size = new Size(86, 23);
            button6.TabIndex = 12;
            button6.Text = "توقف";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // tBlankTimer
            // 
            tBlankTimer.Interval = 950;
            tBlankTimer.Tick += tBlankTimer_Tick;
            // 
            // notifyIcon1
            // 
            notifyIcon1.Text = "notifyIcon1";
            notifyIcon1.Visible = true;
            notifyIcon1.BalloonTipClosed += notifyIcon1_BalloonTipClosed;
            notifyIcon1.MouseDoubleClick += notifyIcon1_MouseDoubleClick;
            // 
            // button7
            // 
            button7.Location = new Point(159, 360);
            button7.Name = "button7";
            button7.Size = new Size(173, 23);
            button7.TabIndex = 13;
            button7.Text = "show notify icon";
            button7.UseVisualStyleBackColor = true;
            button7.Click += button7_Click;
            // 
            // DateTimePickerAndMonthCalender
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(button7);
            Controls.Add(button6);
            Controls.Add(button5);
            Controls.Add(lbAthkar);
            Controls.Add(button2);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(monthCalendar1);
            Controls.Add(lbDateTimePickerFormat);
            Controls.Add(DateTimeFormate);
            Controls.Add(button1);
            Controls.Add(dateTimePicker1);
            Name = "DateTimePickerAndMonthCalender";
            Text = "DateTimePicker";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private Button button1;
        private Label DateTimeFormate;
        private Label lbDateTimePickerFormat;
        private MonthCalendar monthCalendar1;
        private Button button3;
        private Button button4;
        private Button button2;
        private System.Windows.Forms.Timer tAthkarTimer;
        private Label lbAthkar;
        private Button button5;
        private Button button6;
        private System.Windows.Forms.Timer tBlankTimer;
        private NotifyIcon notifyIcon1;
        private Button button7;
    }
}