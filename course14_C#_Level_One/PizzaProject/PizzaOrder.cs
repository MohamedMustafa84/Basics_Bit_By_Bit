using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LearnWinFromProject
{
    public partial class PizzaOrder: Form
    {
        public PizzaOrder()
        {
            InitializeComponent();
        }


        void UpdateSize()
        {
            UpdateTotalPrice();

            if (rbSmall.Checked)
            {
                lbSize.Text = "Small";
                return;
            }else if(rbMeduim.Checked){

                lbSize.Text = "Medium";
                return;

            }
            else
            {
                lbSize.Text = "Large";
                return;
            }
        }


        

        void UpdateToppns()
        {
            UpdateTotalPrice();

            string strToppngs = "";
            
            if (chkExtraChees.Checked)
            {
                strToppngs += ", Extra Chees";
            }
            if (chkMushrooms.Checked)
            {
                strToppngs += ", Mushrooms";

            }
            
            if (chkTomatoes.Checked)
            {
                strToppngs += ", Tomatos";

            }
            if (chkOnion.Checked)
            {
                strToppngs += ", Onion";

            }
            if (chkOilves.Checked)
            {
                strToppngs += ", Olives";
            }
             if (chkGreenPappers.Checked)
            {
                strToppngs += ", Green Pappers";
            }
            if(strToppngs =="")
            {
                strToppngs = "No Toppngs";
            }

            if (strToppngs.StartsWith(","))
            {
                strToppngs = strToppngs.Substring(1, strToppngs.Length - 1).Trim();
            }

            lbToppngs.Text = strToppngs;
            return;
        }

        float  GetSizePrice()
        {
            if (rbSmall.Checked)
            {
                return Convert.ToSingle(rbSmall.Tag);
            }


            if (rbLarge.Checked)
            {
                return Convert.ToSingle(rbLarge.Tag);
            }

            return Convert.ToSingle(rbMeduim.Tag);
        }

        float GetCrustTypePrice()
        {
            if (rbThinkCrust.Checked)
            {
                return Convert.ToSingle(rbThinkCrust.Tag);
            }

            return Convert.ToSingle(rbThinkCrust.Tag); 
             
            
          
        }

        float GetToppingsPrice()
        {
            float ToppingsPrice = 0.0f;

            if (chkExtraChees.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkExtraChees.Tag);
            }else if (chkMushrooms.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkMushrooms.Tag); 

            }
            else if (chkOilves.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkOilves.Tag); 

            }
            else if (chkOnion.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkOnion.Tag); 

            }
            else if (chkTomatoes.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkTomatoes.Tag); 

            }
            else if (chkGreenPappers.Checked)
            {
                ToppingsPrice += Convert.ToSingle(chkGreenPappers.Tag); 

            }


            return ToppingsPrice;
        }

        float CalculateTotalPrice()
        {
            return (GetSizePrice() + GetCrustTypePrice() + GetToppingsPrice());
        }

        

        void UpdateTotalPrice()
            {
                lbTotalPrice.Text = "$" + CalculateTotalPrice().ToString();

            }



        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            if(MessageBox.Show("Confirm Order ","Confirm",MessageBoxButtons.OKCancel,MessageBoxIcon.Question)== DialogResult.OK)
            {

                MessageBox.Show("Order placed Successfully", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                gbSize.Enabled = false;
                gpCrusrtType.Enabled = false;
                gbToppngs.Enabled = false;
                gbEatingPlace.Enabled = false;
            }
        }

        private void btnResetForm_Click(object sender, EventArgs e)
        {
            gbSize.Enabled = true;
            
            gpCrusrtType.Enabled = true;
            gbToppngs.Enabled = true;
            gbEatingPlace.Enabled = true;

            rbMeduim.Checked = true;

            rbThinCrust.Checked = true;
            rbEatIn.Checked = true;

           

            
        }

        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbMeduim_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();

        }

        private void rbLarge_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }


        private void chkExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppns();
        }



        private void chkMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppns();
        }

        private void chkTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppns();

        }

        private void chkOnion_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppns();
        }

        private void chkOilves_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppns();
        }

        private void chkGreenPappers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppns();
        }

        void UpdateCrustType()
        {

              UpdateTotalPrice();
            if (rbThinCrust.Checked)
            {

                lbCrustType.Text = "Thin Crust";
                return;

            }
            lbCrustType.Text = "Thick Crusrt";
        }

        private void rbThinCrust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();
        }

        private void rbThickCrust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();
        }

        void UpdateWhereToEat()
        {
            if (rbEatIn.Checked)
            {
                lbEatingPlace.Text = "Eat In";
                return;
            }

            lbEatingPlace.Text = "Eat Out";


        }

        private void rbEatIn_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }

        private void rbEatOut_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }


        void UpdateOrderSummary()
        {
            UpdateSize();
            UpdateCrustType();
            UpdateToppns();
            UpdateWhereToEat();
        }
        private void PizzaOrder_Load(object sender, EventArgs e)
        {
            UpdateOrderSummary();

        }

    }
        
}
