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
    public partial class Form1 : Form
    {
        Queue<Point> list = new Queue<Point>();
        Point previous = new Point();

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);


        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void getMouse(object sender, MouseEventArgs e)
        {
            Point p = new Point(e.X, e.Y);
            list.Enqueue(p);
            if(list.Count > 1){
                System.Drawing.Graphics e1 = this.CreateGraphics();
                Pen pen = new Pen(Color.Red, 3);
                e1.DrawLine(pen, previous, p);
            }
            previous = p;

        }

        private void Form1_MouseCaptureChanged(object sender, EventArgs e)
        {

        }

        private void keypressed(Object o, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Space)
            {
                System.Drawing.Graphics e1 = this.CreateGraphics();
                Pen pen = new Pen(Color.Red, 3);
                e1.DrawLine(pen, previous, list.ElementAt(0));
                printPoints();
            }

            else if (e.KeyChar == (char)Keys.Return)
            {
                Point[] a;
                System.Drawing.Graphics e1 = this.CreateGraphics();
                e1.Clear(Color.White);
                a = list.ToArray();
                Pen pen = new Pen(Color.Red, 3);
                for (int i = 0; i < a.Length - 1; i++)
                {
                    e1.DrawLine(pen, a[i], a[i + 1]);
                }
                //to redraw the closing line
                e1.DrawLine(pen, a[a.Length - 1], a[0]);

            }
        }

        private void printPoints(){
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Filter = "All Files (*.*)|*.*|Plain Text Files (*.txt)|*.txt";
            saveFileDialog1.FilterIndex = 2;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string name = saveFileDialog1.FileName;
                using (System.IO.StreamWriter file = new System.IO.StreamWriter(name))
                {
                    while (list.Count > 0)
                    {
                        Point point = list.Dequeue();
                        file.WriteLine(point.X + " " + point.Y);
                    }
                    file.Close();
                }
            }
        }

   
    }

   
}
