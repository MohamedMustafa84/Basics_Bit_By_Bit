using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Resources;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tic_Tac_Toe_Game.Properties;

namespace Tic_Tac_Toe_Game
{
    public partial class Form1: Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        

        struct stGameInfo
        {
            static public string Winner ="In Progress";
            static public string PlayerTurn = "Player1";
            static  public  short Rounds =0;
        }

       
        

        bool checkBTNValues(Button btn1 , Button btn2 , Button btn3)
        {
            return btn1.Tag.ToString()!="?" && btn1.Tag == btn2.Tag  && btn1.Tag == btn3.Tag ;
        }

        bool checkWinningChoices()
        {
             if(checkBTNValues(button1, button2, button3))
            {
                return true;
            }

            if (checkBTNValues(button4, button5, button6))
            {
                return true;
            }

            if (checkBTNValues(button7, button8, button9))
            {
                return true;
            }

            if (checkBTNValues(button1, button4, button7))
            {
                return true;
            }

            if (checkBTNValues(button2, button5, button8))
            {
                return true;
            }

            if (checkBTNValues(button3, button6, button9))
            {
                return true;
            }

            if (checkBTNValues(button1, button5, button9))
            {
                return true;
            }

            if (checkBTNValues(button3, button5, button7))
            {
                return true;
            }

            return false;
        }


        void SetWinnigMode()
        {
            lbPlayerTurn.Text = "Game Over";
            stGameInfo.Winner = stGameInfo.PlayerTurn;
            lbWinner.Text = stGameInfo.Winner;
            groupBox1.Enabled = false;
        }

        void checkWinner()
        {
            if (checkWinningChoices())
            {
                SetWinnigMode();
                MessageBox.Show("Game over : we have a Winner :) ");
                
            }
        }




         void EndGame()
        {
            lbWinner.Text = "No Winner";
            MessageBox.Show("Game Over With No Winner ! ");
            groupBox1.Enabled = false;


        }


        private void changeBtnImage(Button btn)
        {


            
                if (btn.Tag.ToString() == "?")
                {

                    if (stGameInfo.PlayerTurn == "Player1")
                    {
                        stGameInfo.Rounds++;       
                        btn.Tag = "X";
                        btn.Image = Resources.XIcon;

                        checkWinner();
                        lbPlayerTurn.Text = "Player2";
                        stGameInfo.PlayerTurn = "Player2";

                    }

                    else if (stGameInfo.PlayerTurn == "Player2")
                    {
                        stGameInfo.Rounds++;

                        btn.Tag = "O";
                        btn.Image = Resources.OIcon;
                        
                        checkWinner();
                        lbPlayerTurn.Text = "Player1";
                        stGameInfo.PlayerTurn = "Player1";


                    }


                }
                else
                {
                    MessageBox.Show("wrong Choice this choice is already taken");
                }


            if (stGameInfo.Rounds == 9) { 

                EndGame();
            }
            

        }





        private void button_Click(object sender, EventArgs e)
        {
            changeBtnImage(sender as Button);

        }

        void resetButtons()
        {
            button1.Image = Resources.quetstionIcon;
            button1.Tag = "?";

            button2.Image =  Resources.quetstionIcon ;
            button2.Tag = "?";

            button3.Image =  Resources.quetstionIcon ;
            button3.Tag = "?";


            button4.Image =  Resources.quetstionIcon ;
            button4.Tag = "?";

            button5.Image =  Resources.quetstionIcon ;
            button5.Tag = "?";

            button6.Image =  Resources.quetstionIcon ;
            button6.Tag = "?";


            button7.Image =  Resources.quetstionIcon ;
            button7.Tag = "?";

            button8.Image =  Resources.quetstionIcon ;
            button8.Tag = "?";

            button9.Image =  Resources.quetstionIcon ;
            button9.Tag = "?";
        }



        void resetGameInfo()
        {
            stGameInfo.Winner = "In Progress";
            stGameInfo.PlayerTurn = "Player1";
            stGameInfo.Rounds = 0;
            lbPlayerTurn.Text = "Player1";
            lbWinner.Text = "In Progress";
        }
        private void btnRestart_Click(object sender, EventArgs e)
        {
            groupBox1.Enabled = true;

            resetGameInfo();
            resetButtons();

        }
    }
}
