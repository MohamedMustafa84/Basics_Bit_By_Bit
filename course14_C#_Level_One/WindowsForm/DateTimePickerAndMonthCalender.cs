using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Metrics;
using System.Drawing;
using System.Linq;
using System.Runtime.Intrinsics.X86;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PIZZA_ORDER
{
    public partial class DateTimePickerAndMonthCalender : Form
    {
        public DateTimePickerAndMonthCalender()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(dateTimePicker1.Value.ToShortDateString());
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            lbDateTimePickerFormat.Text = dateTimePicker1.Value.ToString("dd-MM-yyyy") + Environment.NewLine;

            lbDateTimePickerFormat.Text += dateTimePicker1.Value.ToString("dddd-MM-yyyy") + Environment.NewLine;

            lbDateTimePickerFormat.Text += dateTimePicker1.Value.ToString("MM-dd-yyyy") + Environment.NewLine;

            lbDateTimePickerFormat.Text += dateTimePicker1.Value.ToString("dd-MM-yy") + Environment.NewLine;
            lbDateTimePickerFormat.Text += dateTimePicker1.Value.ToString("dddd,dd-MM-yyyy") + Environment.NewLine;

        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show(monthCalendar1.SelectionRange.ToString());
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show(monthCalendar1.SelectionStart.ToString());
        }

        private void button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show(monthCalendar1.SelectionEnd.ToString());
        }



        private void button6_Click(object sender, EventArgs e)
        {
            tAthkarTimer.Enabled = false;
        }

        private void button5_Click(object sender, EventArgs e)
        {

            tAthkarTimer.Enabled = true;
            tBlankTimer.Enabled = true;

            counter = 1;
            thkerCounter = 1;

        }

        private void tBlankTimer_Tick(object sender, EventArgs e)
        {
            lbAthkar.Text = "";
        }




        private short counter = 1;
        private short thkerCounter = 1;
        private void PrintThker(string Thiker)
        {


            if (thkerCounter == 100)
            {

                lbAthkar.Text = Thiker;
                tBlankTimer.Enabled = false;
                tAthkarTimer.Enabled = false;
            }
            else
            {
                lbAthkar.Text = Thiker + " -" + counter.ToString();

            }



        }

        private void TAthkarTimer_Tick(object sender, EventArgs e)
        {

            string Thiker = "";

            if (thkerCounter <= 33)
            {

                Thiker = "استغفر الله";


            }
            else if (thkerCounter > 33 && thkerCounter <= 66)
            {
                if (thkerCounter == 34)
                {
                    counter = 1;
                }

                Thiker = "الحمد لله";
            }
            else if (thkerCounter > 66 && thkerCounter <= 99)
            {
                if (thkerCounter == 67)
                {
                    counter = 1;
                }

                Thiker = "الله اكبر";

            }

            if (thkerCounter == 100)
            {
                Thiker = "لا اله الا الله ";
            }



            PrintThker(Thiker);

            counter++;
            thkerCounter++;

        }

        private void button7_Click(object sender, EventArgs e)
        {
            notifyIcon1.Icon = SystemIcons.Application;
            notifyIcon1.BalloonTipIcon = ToolTipIcon.Info;
            notifyIcon1.BalloonTipTitle = "This Is A Title";
            notifyIcon1.BalloonTipText = "This IS Message";
            notifyIcon1.ShowBalloonTip(20000);
        }

        private void notifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            MessageBox.Show("You Respond To The NotifyIcon And That Distraction" ,"Future Self");
        }

        private void notifyIcon1_BalloonTipClosed(object sender, EventArgs e)
        {
            MessageBox.Show("thinks for a voiding the Distration and ignoring this Notify ballloon ", " Future Self ");
        }
    }
}
