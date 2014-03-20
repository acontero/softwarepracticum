using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ConvexHull
{
    //public partial class Form1 : Form
    //{
    //    public Form1()
    //    {
    //        InitializeComponent();
    //    }

    //    private void Form1_Paint(object sender, PaintEventArgs e)
    //    {
    //        System.Drawing.Graphics graphicsObj;

    //        graphicsObj = this.CreateGraphics();
    //        Pen myPen = new Pen(System.Drawing.Color.Red, 5);

    //        //myPen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDotDot;
    //        //myPen.Color = System.Drawing.Color.RoyalBlue;
    //        //myPen.Width = 3;

    //        graphicsObj.DrawLine(myPen, 20, 20, 200, 210);
    //    }
    //}

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void getMouse(object sender, MouseEventArgs e)
        {

            Point p = new Point(0, 0);
            Point p1 = new Point(e.X, e.Y);

            System.Drawing.Graphics e1 = this.CreateGraphics();
            Pen pen = new Pen(Color.Red);
            e1.DrawLine(pen, p, p1);
        }

        private void Form1_MouseCaptureChanged(object sender, EventArgs e)
        {

        }


    }
}

